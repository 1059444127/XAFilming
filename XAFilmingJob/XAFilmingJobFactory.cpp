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

XAFilmingJobBase* XAFilmingJobFactory::CreateFilmingJob(vector<string> dicomFiles)
{
    return new BatchPrintJob(++_maxJobID, dicomFiles);
}

XAFilmingJobBase* XAFilmingJobFactory::CreateFilmingJob(std::string serializedDataheader)
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

bool XAFilmingJobFactory::SplitSerializedDataheaderPacket(const string serializedParameter, string& packetHeader, string& serializedDataheader)
{
	auto packetHeaderIndex = serializedParameter.find(";");
	if(packetHeaderIndex == serializedParameter.npos)
	{
		LOG_ERROR_XA_FILMING << "No packet header in serialziedParameter to build filming job" << LOG_END;
		return false;
	}

	packetHeader = serializedParameter.substr(0, packetHeaderIndex);
	serializedDataheader = serializedParameter.substr(packetHeaderIndex+1);
	return true;
}


//TODO: change const string to const string&
XAFilmingJobBase* XAFilmingJobFactory::BuildFilmingJob(const string serializedParameter)
{
	string packetHeader ;
	string serializedDataheader;
	if(SplitSerializedDataheaderPacket(serializedParameter, packetHeader, serializedDataheader))
	{
		LOG_ERROR_XA_FILMING << "Fail to split serialziedParameter to build filming job" << LOG_END;
		return nullptr;
	}

	//DataPacketHeader data_packet_header;
	//data_packet_header.DeserializeFrom(packetHeader);

	DicomDataHeaderPacketHeader dicom_data_header_packet_header;
	//dicom_data_header_packet_header.SetIndex(data_packet_header.index);
	//dicom_data_header_packet_header.SetTotal(data_packet_header.total);

	string dicomFilePath;
	if(!SaveStringToDicomFile(serializedDataheader, dicomFilePath, dicom_data_header_packet_header))
	{
		LOG_ERROR_XA_FILMING << "Failed to save serialized DataHeader to dicom file" << LOG_END;
	}

	return nullptr;
}
