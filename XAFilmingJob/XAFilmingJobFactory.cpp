#include "XAFilmingJobFactory.h"
#include "XAJob.h"
#include "BatchPrintJob.h"
#include <XAFilmingLogger.h>
#include "XADicom.h"
#include <DicomDataHeaderPacketHeader.h>
#include "FilmingJob.h"
#include "FilmingJobMetaData.h"

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

XAFilmingJobBase* XAFilmingJobFactory::BuildFilmingJob(std::string serializedDataheader)
{
	string dicomFilePath;
	DicomDataHeaderPacketHeader dicom_data_header_packet_header;

	if(!SaveStringToDicomFile(serializedDataheader, dicomFilePath, dicom_data_header_packet_header))
	{
		LOG_ERROR_XA_FILMING << "Failed to save serialized DataHeader to dicom file , printing failed" << LOG_END;
	}


	//vector<string> filePaths;  filePaths.push_back(dicomFilePath);
	//auto job = CreateFilmingJob(filePaths);

	//return job;
	return nullptr;
}
