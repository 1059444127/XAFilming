#include "FilmingCommunicator.h"
#include "XAFilmingLogger.h"
#include "XAFilmingSerializer.h"

void FilmingCommunicator::PublishJobProgress(const vector<XAFilmingJobBase*>& jobs)
{
    LOG_INFO_XA_FILMING << "publish job progress" << LOG_END;
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
