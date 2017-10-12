#include "FilmingCommunicator.h"
#include "XAFilmingLogger.h"
#include "XAFilmingSerializer.h"
#include <McsfJobManagerInfoWrapper.h>

using namespace MCSF_NAMESPACE_FOR_XA;

FilmingCommunicator::FilmingCommunicator(ICommunicationProxy* pProxy): _pProxy(pProxy), _pNotifier(nullptr)
{
}

void FilmingCommunicator::PublishJobProgress(const vector<XAFilmingJobBase*>& jobs)
{
    LOG_INFO_XA_FILMING << "publish job progress" << LOG_END;

	PushJobProgressToJobManager(jobs, _pProxy);
}



void FilmingCommunicator::Print(const vector<std::string>& files)
{
    string serializedString = serialize(files);
    LOG_INFO_XA_FILMING << "Print " << serializedString << LOG_END;
}

void FilmingCommunicator::Register(INofifyPrintStatus* pNotifier)
{
	_pNotifier = pNotifier;
}
