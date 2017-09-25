#include "StdAfx.h"
#include "PrintDataHeaderCommandHandler.h"

#include "McsfDataHeader/mcsf_data_header_element_map_interface.h"
#include "McsfDicomConvertor/mcsf_dicom_convertor_factory.h"

#include "FilmingUtility.h"
#include "XAFilmingLogger.h"
#include <XAFilmingMacro.h>


MCSF_FILMING_BEGIN_NAMESPACE

typedef boost::shared_ptr<IDataHeaderElementMap> IDataHeaderElementMapPtr;


int PrintDataHeaderCommandHandler::HandleCommand(const CommandContext* pContext,std::string* pReplyObject)
{
	*pReplyObject = EMPTY_STRING;
	assert(nullptr != pContext);
	assert(nullptr != pReplyObject);

	LOG_INFO_XA_FILMING << "Received Command [" << pContext->iCommandId << "] from [" << pContext->sSender << LOG_END;

	string sSerializedDataHeader = pContext->sSerializeObject;

	IDataHeaderElementMapPtr pHeaders(IDataHeaderElementMap::CreateDataHeader());
	if (!pHeaders)
	{
		LOG_ERROR_XA_FILMING << "Unexpected Result: IDataHeaderElementMap::CreateDataHeader() failed!"<< LOG_END;
		return -1;
	}
	if (!IDataHeaderElementMap::Deserialize(sSerializedDataHeader, pHeaders.get()))
	{
		LOG_ERROR_XA_FILMING << "Unexpected Result: DataHeader Deserialize() failed!"<< LOG_END;
		return -1;
	}
	// create DICOM converter object
	auto pConvertor = DICOMConvertorFactory::Instance()->CreateSimpleConvertor();
	if (!pConvertor)
	{
		LOG_ERROR_XA_FILMING << "Unexpected Result: CreateSimpleConvertor() failed!"<< LOG_END;
		return -1;
	}
	// save IDataHeaderElementMap data to DICOM file
	string dicomFilePath = CreateDicomFileName();
	if (!pConvertor->SaveFile(pHeaders.get(), dicomFilePath)) 
	{
		LOG_ERROR_XA_FILMING << "Unexpected Result: SaveFile() failed!"<< LOG_END;
		return -1;
	}

	LOG_INFO_XA_FILMING << "Succeed to save DataHeader as a Dicom file : " << dicomFilePath<< LOG_END;

	vector<string> dicomFilePaths;
	dicomFilePaths.push_back(dicomFilePath);

	Print(dicomFilePaths);

	return 0;
}
MCSF_FILMING_END_NAMESPACE