#include "FilmingCommunicator.h"
#include "XAFilmingLogger.h"
#include "XAFilmingSerializer.h"
#include <McsfJobManagerInfoWrapper.h>
#include "XACommand.h"
#include "XADB.h"
#include "IPrintCallbackHandler.h"

using namespace std;

using namespace MCSF_NAMESPACE_FOR_XA;

FilmingCommunicator::FilmingCommunicator(ICommunicationProxy* pProxy, IPrintCallbackHandler* pCallbackHandler): _pProxy(pProxy), _pCallbackHandler(pCallbackHandler)
{
}

void FilmingCommunicator::PublishJobProgress(const vector<XAFilmingJobBase*>& jobs)
{
    LOG_INFO_XA_FILMING << "publish job progress" << LOG_END;

	PushJobProgressToJobManager(jobs, _pProxy);
}



void FilmingCommunicator::Print(const vector<std::string>& files)
{
	LOG_INFO_XA_FILMING << "Print" << LOG_END;
	SendPrintCommand(files, _pProxy, _pCallbackHandler);
}

void FilmingCommunicator::Register(IPrintResultObserver* pObserver)
{
	_pCallbackHandler->Register(pObserver);
}

void FilmingCommunicator::UpdatePrintStatus(const IFilmingJobMetaData* filmingJobMetaData)
{
	auto db = XADB::GetInstance(_pProxy);
	db->UpdateImagesPrintStatus(filmingJobMetaData);
}

void FilmingCommunicator::SendEHCMessage(const std::string& message)
{
	LOG_INFO_XA_FILMING << "SendEHCMessage [" << message << "]" << LOG_END;
	bool bResult = string_to_bool(message);
	if(bResult) {return;}

	//TODO: send EHC Message

}
