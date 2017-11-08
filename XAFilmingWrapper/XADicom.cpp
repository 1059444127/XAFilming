#include "XADicom.h"
#include <McsfDataHeader/mcsf_data_header_element_map_interface.h>
#include <XAFilmingLogger.h>
#include <McsfDicomConvertor/mcsf_dicom_convertor_factory.h>
#include "XAFilmingFile.h"
#include "../XAFilmingCommon/XAFilmingConst.h"

using namespace MCSF_NAMESPACE_FOR_XA;
using namespace std;


typedef boost::shared_ptr<IDataHeaderElementMap> IDataHeaderElementMapPtr;

bool SaveStringToDicomFile(const string& sSerializedDataHeader, string& dicomFilePath, string& serializedPacketHeader)
{
	IDataHeaderElementMapPtr pHeaders(Mcsf::IDataHeaderElementMap::CreateDataHeader());
	if (!pHeaders)
	{
		LOG_ERROR_XA_FILMING << "Unexpected Result: IDataHeaderElementMap::CreateDataHeader() failed!"<< LOG_END;
		return false;
	}
	if (!Mcsf::IDataHeaderElementMap::Deserialize(sSerializedDataHeader, pHeaders.get()))
	{
		LOG_ERROR_XA_FILMING << "Unexpected Result: DataHeader Deserialize() failed!"<< LOG_END;
		return false;
	}
	// create DICOM converter object
	auto pConvertor = Mcsf::DICOMConvertorFactory::Instance()->CreateSimpleConvertor();
	if (!pConvertor)
	{
		LOG_ERROR_XA_FILMING << "Unexpected Result: CreateSimpleConvertor() failed!"<< LOG_END;
		return false;
	}
	// save IDataHeaderElementMap data to DICOM file
	dicomFilePath = CreateDicomFilePath();
	if (!pConvertor->SaveFile(pHeaders.get(), dicomFilePath)) 
	{
		LOG_ERROR_XA_FILMING << "Unexpected Result: SaveFile() failed!"<< LOG_END;
		return false;
	}

	ConstUInt16Array constUint16Array;
	int arraySize;
	if(!pHeaders.get()->GetUInt16ArrayByTag(XA_DICOM_DATAHEADER_PACKET_HEADER_TAG, &constUint16Array, &arraySize))
	{
		LOG_WARN_XA_FILMING << "Failed to get serialized packet header from tag [" << XA_DICOM_DATAHEADER_PACKET_HEADER_TAG << "]" << LOG_END;
	}
	else
	{
		//TODO: deserialzed constUint8Array to string
	}


	LOG_INFO_XA_FILMING << "Succeed to save DataHeader as a Dicom file : " << dicomFilePath<< LOG_END;

	return true;
}


