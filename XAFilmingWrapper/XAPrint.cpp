#include <ctime>

#include <McsfFilming/mcsf_filming_libary_interface.h>
#include <McsfFilming/mcsf_filming_libary_factory.h>

#include "XAFilmingLogger.h"
#include "XAFilmingMacro.h"

#include "XAPrint.h"
#include "XAFilmingConst.h"
#include "XAConfig.h"
#include "../XAFilmingCommon/XAFilmingSerializer.h"

namespace MCSF_NAMESPACE_FOR_XA
{
	void SetPrintJobObject(const vector<string>& dicomFilePaths, McsfPrintJobObject* const pPrintJobObject)
	{
		LOG_INFO_XA_FILMING << "SetPrintJobObject with dicom file paths : " << LOG_END;
		LOG_COLLECTION_XA_FILMING(dicomFilePaths)

		pPrintJobObject->SetJobID(1);
		pPrintJobObject->SetCopies(1);
		pPrintJobObject->SetMyAETitle(XA_AE);
		pPrintJobObject->SetLayout(XA_PRINT_LAYOUT_1_X_1);		

		auto printerConfig = XAConfig::Instance()->GetPrinterConfig();

		
		pPrintJobObject->SetTargetAETitle(printerConfig->GetAE());
		pPrintJobObject->SetTargetHostName(printerConfig->GetIP());
		pPrintJobObject->SetTargetPort(printerConfig->GetPort());
		pPrintJobObject->SetFilmSize(printerConfig->GetFilmSize());
		//vector<string> fileList;
		//fileList.push_back("e:\\1.dcm");
		pPrintJobObject->SetFileNameList(dicomFilePaths);
	}

	std::string printBy(IFilmingLibary* pIFilmingLibary)
	{
		try
		{
			if(pIFilmingLibary->ConnectPrinter()) 
			{
				LOG_WARN_XA_FILMING << "Connect printer failed" << LOG_END;
				return "UID_XACommon_Filming_Failed_Connect_Printer";
			}

			LOG_INFO_XA_FILMING << "Connect printer succeed" << LOG_END;

			if(-1 == pIFilmingLibary->CreatePrintObject())
			{
				LOG_WARN_XA_FILMING<< "CreatePrintObject failure" << LOG_END;
				return "UID_XACommon_Filming_Failed_Create_Print_Object";
			}

			if(!pIFilmingLibary->DoPrint())
			{
				LOG_INFO_XA_FILMING << "Print succeed" << LOG_END;
				return bool_to_string(true);
			}

			LOG_ERROR_XA_FILMING<< "Print failed" << LOG_END;			
		}
		catch (...)
		{
			LOG_ERROR_XA_FILMING << "Exception" << LOG_END;
			return "UID_XACommon_Filming_Exception";
		}
		return "UID_XACommon_Filming_Failed";
	}

	std::string print(const vector<string>& dicomFilePaths)
	{
		LOG_INFO_XA_FILMING << "Begin to print" << LOG_END;
		LOG_COLLECTION_XA_FILMING(dicomFilePaths)

		McsfFilmingLibaryFactory* pFilming = McsfFilmingLibaryFactory::Instance();
		auto filmingDb = McsfFilmingDB::GetInstance();
		McsfPrintJobObject * pPrintJobObject = new McsfPrintJobObject();

		SetPrintJobObject(dicomFilePaths, pPrintJobObject);	

		IFilmingLibary * pIFilmingLibary = pFilming->CreateFilmingLibary(pPrintJobObject, filmingDb);

		auto printResult = printBy(pIFilmingLibary);


		pIFilmingLibary->SetSetFilmBoxTimeOut(10);
        pIFilmingLibary->DisConnectPrinter();

		SAFE_DELETE_ELEMENT(pPrintJobObject);
		return printResult;
	}

	void print(const std::vector<std::string>& dicomFilePaths, ResultNotifier resultNotifier)
	{
		resultNotifier(print(dicomFilePaths));
	}
}
