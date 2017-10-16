#include "FilmingCommunicator.h"
#include "XAFilmingLogger.h"
#include "XAFilmingSerializer.h"
#include <McsfJobManagerInfoWrapper.h>
#include "XACommand.h"

using namespace MCSF_NAMESPACE_FOR_XA;

FilmingCommunicator::FilmingCommunicator(ICommunicationProxy* pProxy, ICommandCallbackHandler* pCallbackHandler): _pProxy(pProxy), _pCallbackHandler(pCallbackHandler), _pNotifier(nullptr)
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

void FilmingCommunicator::Register(IPrintStatusObserver* pNotifier)
{
	_pNotifier = pNotifier;
}
