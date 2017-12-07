#include "XAFilmingJobFactory.h"
#include "XAJob.h"
#include "BatchPrintJob.h"
#include <XAFilmingLogger.h>
#include "XADicom.h"
#include <DicomDataHeaderPacketHeader.h>
#include "FilmingJob.h"
#include "FilmingJobMetaData.h"
#include "../../../XParameters/Contract/CommunicationCommandID.h"
#include "DataPacketHeader.h"

using namespace std;

XAFilmingJobFactory* XAFilmingJobFactory::_instance = new XAFilmingJobFactory();
int XAFilmingJobFactory::_maxJobID = 0; //TODO; Get Max JobID From DB ,write in XAFilmingWrapper

XAFilmingJobFactory* XAFilmingJobFactory::Instance()
{
    return _instance;
}

XAFilmingJobBase* XAFilmingJobFactory::CreateJob()
{
    return new XAJob(++_maxJobID);
}

XAFilmingJobBase* XAFilmingJobFactory::CreateFilmingJob(const vector<string>& dicomFiles)
{
    return new BatchPrintJob(++_maxJobID, dicomFiles);
}

XAFilmingJobBase* XAFilmingJobFactory::CreateFilmingJob(const std::string& serializedDataheader)
{
	string dicomFilePath;
	DicomDataHeaderPacketHeader dicom_data_header_packet_header;

	if(!SaveStringToDicomFile(serializedDataheader, dicomFilePath, dicom_data_header_packet_header))
	{
		LOG_ERROR_XA_FILMING << "Failed to save serialized DataHeader to dicom file , printing failed" << LOG_END;
		return nullptr;
	}

	vector<string> filePaths;  filePaths.push_back(dicomFilePath);
	return new FilmingJob(++_maxJobID, filePaths, new FilmingJobMetaData(dicom_data_header_packet_header));
}

bool XAFilmingJobFactory::SplitSerializedDataheaderPacket(const string& serializedParameter, string& packetHeader, string& serializedDataheader)
{
	auto packetHeaderIndex = serializedParameter.find(PARAMETER_LIST_SEPARATOR+PARAMETER_LIST_SEPARATOR);
	if(packetHeaderIndex == serializedParameter.npos)
	{
		LOG_ERROR_XA_FILMING << "No packet header in serialziedParameter to build filming job" << LOG_END;
		return false;
	}

	packetHeader = serializedParameter.substr(0, packetHeaderIndex);
	serializedDataheader = serializedParameter.substr(packetHeaderIndex+1);
	return true;
}


XAFilmingJobBase* XAFilmingJobFactory::BuildFilmingJob(const string& serializedParameter)
{
	string packetHeader ;
	string serializedDataheader;
	if(!SplitSerializedDataheaderPacket(serializedParameter, packetHeader, serializedDataheader))
	{
		LOG_ERROR_XA_FILMING << "Fail to split serialziedParameter to build filming job" << LOG_END;
		return nullptr;
	}

	DataPacketHeader data_packet_header;
	data_packet_header.DeserializeFrom(packetHeader);

	DicomDataHeaderPacketHeader dicom_data_header_packet_header;
	dicom_data_header_packet_header.SetIndex(data_packet_header.index);
	dicom_data_header_packet_header.SetTotal(data_packet_header.total);

	string dicomFilePath;
	if(!SaveStringToDicomFile(serializedDataheader, dicomFilePath, dicom_data_header_packet_header))
	{
		LOG_ERROR_XA_FILMING << "Failed to save serialized DataHeader to dicom file" << LOG_END;
		return nullptr;
	}

	auto packageUid = data_packet_header.uid;
	if(_jobBuilders.find(packageUid) == _jobBuilders.end())
	{
		_jobBuilders[packageUid] = new FilmingJobBuilder(dicom_data_header_packet_header, data_packet_header.total);
	}
	auto jobBuilder = _jobBuilders[packageUid];
	jobBuilder->AddDicomFile(dicomFilePath);

	if(jobBuilder->IsComplete())
	{
		return new FilmingJob(++_maxJobID, jobBuilder->GetDicomFiles(), jobBuilder);
	}

	return nullptr;
}

XAFilmingJobFactory::~XAFilmingJobFactory()
{
	for(auto iter = _jobBuilders.begin(); iter!= _jobBuilders.end(); iter++)
	{
		SAFE_DELETE_ELEMENT(iter->second);
	}
	SAFE_DELETE_ELEMENT(_instance);
}
