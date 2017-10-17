#include "XADicom.h"
#include <McsfDataHeader/mcsf_data_header_element_map_interface.h>
#include <XAFilmingLogger.h>
#include <McsfDicomConvertor/mcsf_dicom_convertor_factory.h>
#include <XAFilmingMacro.h>

using namespace MCSF_NAMESPACE_FOR_XA;

bool SaveStringToDicomFiles(std::string& serializedDataheader, std::vector<std::string>& _filePaths)
{
	//	IDataHeaderElementMapPtr pHeaders(Mcsf::IDataHeaderElementMap::CreateDataHeader());
	//if (!pHeaders)
	//{
	//	LOG_ERROR_XA_FILMING << "Unexpected Result: IDataHeaderElementMap::CreateDataHeader() failed!"<< LOG_END;
	//	return -1;
	//}
	//if (!Mcsf::IDataHeaderElementMap::Deserialize(sSerializedDataHeader, pHeaders.get()))
	//{
	//	LOG_ERROR_XA_FILMING << "Unexpected Result: DataHeader Deserialize() failed!"<< LOG_END;
	//	return -1;
	//}
	//// create DICOM converter object
	//auto pConvertor = Mcsf::DICOMConvertorFactory::Instance()->CreateSimpleConvertor();
	//if (!pConvertor)
	//{
	//	LOG_ERROR_XA_FILMING << "Unexpected Result: CreateSimpleConvertor() failed!"<< LOG_END;
	//	return -1;
	//}
	//// save IDataHeaderElementMap data to DICOM file
	//string dicomFilePath = CreateDicomFileName();
	//if (!pConvertor->SaveFile(pHeaders.get(), dicomFilePath)) 
	//{
	//	LOG_ERROR_XA_FILMING << "Unexpected Result: SaveFile() failed!"<< LOG_END;
	//	return -1;
	//}

	//LOG_INFO_XA_FILMING << "Succeed to save DataHeader as a Dicom file : " << dicomFilePath<< LOG_END;

	//vector<string> dicomFilePaths;
	//dicomFilePaths.push_back(dicomFilePath);
	return true;
}
