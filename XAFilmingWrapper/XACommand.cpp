#include "XACommand.h"
#include <XAFilmingLogger.h>
#include "XAFilmingSerializer.h"

void SendCommand(int commandID, const std::string& serializedCommandParameter, MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy)
{
	
}


void SendPrintCommand(const std::vector<std::string>& files, MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy)
{
    std::string serializedString = serialize(files);
    LOG_INFO_XA_FILMING << "Print " << serializedString << LOG_END;

	
}
