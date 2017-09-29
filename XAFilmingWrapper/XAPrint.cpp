#include <ctime>

#include <McsfFilming/mcsf_filming_libary_interface.h>
#include <McsfFilming/mcsf_filming_libary_factory.h>

#include "XAFilmingLogger.h"
#include "XAFilmingMacro.h"

#include "XAPrint.h"

namespace MCSF_NAMESPACE_FOR_XA
{
	bool Print(const vector<string>& dicomFilePaths)
	{
		LOG_INFO_XA_FILMING << "Begin to print" ;

		McsfFilmingLibaryFactory* pFilming = McsfFilmingLibaryFactory::Instance();
		auto filmingDb = McsfFilmingDB::GetInstance();
		McsfPrintJobObject * pPrintJobObject = new McsfPrintJobObject();

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

		IFilmingLibary * pIFilmingLibary = pFilming->CreateFilmingLibary(pPrintJobObject, filmingDb);

		if(!pIFilmingLibary->ConnectPrinter())
		{
			LOG_INFO_XA_FILMING << "Connect printer succeed" << LOG_END;
		}
		else
		{
			LOG_INFO_XA_FILMING << "Connect printer failed" << LOG_END;
		}

		if(-1 == pIFilmingLibary->CreatePrintObject())
		{
			LOG_INFO_XA_FILMING << "CreatePrintObject failure" << LOG_END;
		}

		if(!pIFilmingLibary->DoPrint())
		{
			LOG_INFO_XA_FILMING << "Print succeed" << LOG_END;
		}
		else
		{
			LOG_INFO_XA_FILMING << "Print failed" << LOG_END;
		}

		pIFilmingLibary->SetSetFilmBoxTimeOut(10);
        pIFilmingLibary->DisConnectPrinter();

		delete pPrintJobObject;
		return false;
	}

char * rand_str(char *str, const int len)
{
	srand((unsigned int)time(NULL));
	for (int i=0; i<len; i++)
	{
		str[i] = rand()%2 ? 'a'+rand()%26 : '0'+rand()%10;
	}
	return str;
}


	string CreateDicomFileName()
	{
		char fileName[20];
		return TEMP_DIRECTORY + rand_str(fileName, 20);
	}

}
