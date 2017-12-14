#include "XADicom.h"
#include <McsfDataHeader/mcsf_data_header_element_map_interface.h>
#include "McsfDataHeader/mcsf_data_header_tags.h"
#include <XAFilmingLogger.h>
#include <McsfDicomConvertor/mcsf_dicom_convertor_factory.h>
#include "XAFilmingFile.h"
#include "XAFilmingConst.h"
#include "DicomDataHeaderPacketHeader.h"
#include "../XAFilmingCommon/XAFilmingSerializer.h"


using namespace MCSF_NAMESPACE_FOR_XA;
using namespace std;


typedef boost::shared_ptr<IDataHeaderElementMap> IDataHeaderElementMapPtr;

string GetStringByTagFromDataHeader(IDataHeaderElementMap* data_header_element_map, const Tag tag)
{
	ConstString resultString;
	int size;
	if(!data_header_element_map->GetStringByTag(tag, &resultString, &size))
	{
		LOG_WARN_XA_FILMING << "Failed to get string from tag [" << tag << "]" << LOG_END;
		return XA_FILMING_EMPTY_STRING;
	}
	return resultString;
}

void Convert(IDataHeaderElementMap* data_header_element_map, DicomDataHeaderPacketHeader& dicom_data_header_packet_header)
{
	auto patientName = GetStringByTagFromDataHeader(data_header_element_map, kTagDcm_PatientName);
	dicom_data_header_packet_header.SetPatientName(patientName);

	auto patientID = GetStringByTagFromDataHeader(data_header_element_map, kTagDcm_PatientID);
	dicom_data_header_packet_header.SetPatientID(patientID);

	auto instanceNumber = GetStringByTagFromDataHeader(data_header_element_map, kTagDcm_InstanceNumber);
	dicom_data_header_packet_header.SetIndex(string_to_int(instanceNumber));

	auto total = GetStringByTagFromDataHeader(data_header_element_map, XA_DICOM_DATAHEADER_PACKET_HEADER_TAG);
	dicom_data_header_packet_header.SetTotal(string_to_int(total));
	
	auto studyInstanceUid = GetStringByTagFromDataHeader(data_header_element_map, kTagDcm_StudyInstanceUID);
	dicom_data_header_packet_header.SetStudyInstanceUid(studyInstanceUid);

	auto sopInstanceUid = GetStringByTagFromDataHeader(data_header_element_map, kTagDcm_SOPInstanceUID);
	dicom_data_header_packet_header.SetSopInstanceUid(sopInstanceUid);

	ConstUInt16Array constUint16Array;
	ConstInt16Array constint16Array;
	ConstInt32Array constint32Array;
	ConstUInt32Array constUint32Array;
	ConstUInt8Array constUint8Array;
	ConstString constString;
	VoidPointer voidPointer;
	//ItemPointer itemPointer;
	//ItemPointerArray itemPointerArray;
	int arraySize;
	if(data_header_element_map->GetUInt16ArrayByTag(XA_DICOM_DATAHEADER_PACKET_HEADER_TAG, &constUint16Array, &arraySize))
	{
		LOG_WARN_XA_FILMING << "Succeed to get serialized packet header from UInt16Array tag [" << XA_DICOM_DATAHEADER_PACKET_HEADER_TAG << "]" << LOG_END;
	}
	else if(data_header_element_map->GetInt16ArrayByTag(XA_DICOM_DATAHEADER_PACKET_HEADER_TAG, &constint16Array, &arraySize))
	{
		LOG_WARN_XA_FILMING << "Succeed to get serialized packet header from Int16Array tag [" << XA_DICOM_DATAHEADER_PACKET_HEADER_TAG << "]" << LOG_END;
		//TODO: deserialzed constUint8Array to string
	}else if(data_header_element_map->GetInt32ArrayByTag(XA_DICOM_DATAHEADER_PACKET_HEADER_TAG, &constint32Array, &arraySize))
	{
		LOG_WARN_XA_FILMING << "Succeed to get serialized packet header from Int32Array tag [" << XA_DICOM_DATAHEADER_PACKET_HEADER_TAG << "]" << LOG_END;
	}else if(data_header_element_map->GetUInt32ArrayByTag(XA_DICOM_DATAHEADER_PACKET_HEADER_TAG, &constUint32Array, &arraySize))
	{
		LOG_WARN_XA_FILMING << "Succeed to get serialized packet header from UInt32Array tag [" << XA_DICOM_DATAHEADER_PACKET_HEADER_TAG << "]" << LOG_END;
	}else if(data_header_element_map->GetUInt8ArrayByTag(XA_DICOM_DATAHEADER_PACKET_HEADER_TAG, &constUint8Array, &arraySize))
	{
		LOG_WARN_XA_FILMING << "Succeed to get serialized packet header from UInt8Array tag [" << XA_DICOM_DATAHEADER_PACKET_HEADER_TAG << "]" << LOG_END;
	}else if(data_header_element_map->GetStringByTag(XA_DICOM_DATAHEADER_PACKET_HEADER_TAG, &constString, &arraySize))
	{
		LOG_WARN_XA_FILMING << "Succeed to get serialized packet header from string tag [" << XA_DICOM_DATAHEADER_PACKET_HEADER_TAG << "]" << LOG_END;
	//}else if(data_header_element_map->GetItemPointerByTag(XA_DICOM_DATAHEADER_PACKET_HEADER_TAG, &itemPointer, arraySize))
	//{
	//	LOG_WARN_XA_FILMING << "Succeed to get serialized packet header from ItemPointer tag [" << XA_DICOM_DATAHEADER_PACKET_HEADER_TAG << "]" << LOG_END;
	//}else if(data_header_element_map->GetItemPointerArrayByTag(XA_DICOM_DATAHEADER_PACKET_HEADER_TAG, &itemPointerArray, arraySize))
	//{
	//	LOG_WARN_XA_FILMING << "Succeed to get serialized packet header from voidPointer tag [" << XA_DICOM_DATAHEADER_PACKET_HEADER_TAG << "]" << LOG_END;		
	}else if(data_header_element_map->GetVoidPointerByTag(XA_DICOM_DATAHEADER_PACKET_HEADER_TAG, &voidPointer))
	{
		LOG_WARN_XA_FILMING << "Succeed to get serialized packet header from voidPointer tag [" << XA_DICOM_DATAHEADER_PACKET_HEADER_TAG << "]" << LOG_END;		
	}else
	{
		LOG_INFO_XA_FILMING << "Don't know how to get serialized packet header string tag" << LOG_END;
	}
}

bool SaveStringToDicomFile(const string& sSerializedDataHeader, string& dicomFilePath, DicomDataHeaderPacketHeader& dicomDataHeaderPacketHeader)
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

	// Get StudyInfo from DataHeader
	Convert(pHeaders.get(), dicomDataHeaderPacketHeader);

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


	LOG_INFO_XA_FILMING << "Succeed to save DataHeader as a Dicom file : " << dicomFilePath<< LOG_END;

	return true;
}


