#include <ctime>

#include <McsfFilming/mcsf_filming_libary_interface.h>
#include <McsfFilming/mcsf_filming_libary_factory.h>

#include "XAFilmingLogger.h"
#include "XAFilmingMacro.h"

#include "XAPrint.h"

namespace MCSF_NAMESPACE_FOR_XA
{
	void SetPrintJobObject(const vector<string>& dicomFilePaths, McsfPrintJobObject* const pPrintJobObject)
	{
		LOG_INFO_XA_FILMING << "SetPrintJobObject with dicom file paths : " << LOG_END;
		LOG_COLLECTION_XA_FILMING(dicomFilePaths)

		pPrintJobObject->SetJobID(1);
		pPrintJobObject->SetCopies(1);
		pPrintJobObject->SetMyAETitle("local");
		pPrintJobObject->SetTargetAETitle("PRINT_SCP");
		pPrintJobObject->SetTargetHostName("127.0.0.1");
		pPrintJobObject->SetTargetPort(10006);
		pPrintJobObject->SetLayout("STANDARD\\1,1");
		pPrintJobObject->SetFilmSize("8INX10IN");
		//vector<string> fileList;
		//fileList.push_back("e:\\1.dcm");
		pPrintJobObject->SetFileNameList(dicomFilePaths);
	}

	bool printBy(IFilmingLibary* pIFilmingLibary)
	{
		try
		{
			LOG_INFO_XA_FILMING << (!pIFilmingLibary->ConnectPrinter() ? "Connect printer succeed" : "Connect printer failed") << LOG_END;

			if(-1 == pIFilmingLibary->CreatePrintObject())
			{
				LOG_WARN_XA_FILMING<< "CreatePrintObject failure" << LOG_END;
			}

			if(!pIFilmingLibary->DoPrint())
			{
				LOG_INFO_XA_FILMING << "Print succeed" << LOG_END;
				return true;
			}
			LOG_INFO_XA_FILMING << "Print failed" << LOG_END;
		}
		catch (...)
		{
			LOG_ERROR_XA_FILMING << "Exception" << LOG_END;
		}
		return false;
	}

	bool print(const vector<string>& dicomFilePaths)
	{
		LOG_INFO_XA_FILMING << "Begin to print" << LOG_END;
		LOG_COLLECTION_XA_FILMING(dicomFilePaths)

		McsfFilmingLibaryFactory* pFilming = McsfFilmingLibaryFactory::Instance();
		auto filmingDb = McsfFilmingDB::GetInstance();
		McsfPrintJobObject * pPrintJobObject = new McsfPrintJobObject();

		SetPrintJobObject(dicomFilePaths, pPrintJobObject);	//TODO-PRINT: Print Config

		IFilmingLibary * pIFilmingLibary = pFilming->CreateFilmingLibary(pPrintJobObject, filmingDb);

		auto printResult = printBy(pIFilmingLibary);


		pIFilmingLibary->SetSetFilmBoxTimeOut(10);
        pIFilmingLibary->DisConnectPrinter();

		SAFE_DELETE_ELEMENT(pPrintJobObject);
		return printResult;
	}

	bool print(const std::vector<std::string>& dicomFilePaths, ResultNotifier resultNotifier)
	{
		resultNotifier(print(dicomFilePaths));
	}
}
