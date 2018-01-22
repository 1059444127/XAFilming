#include "TestConfig.h"
#include "XAFilmingLogger.h"
#include <boost/lexical_cast.hpp>

void TestConfig::ReadConfigFromFile()
{
	try
	{
		AbstractConfig::ReadConfigFromFile();
		
		std::string toDelayJobString = GetStringByTag("ToDelayJob");
		_toDelayJob = boost::lexical_cast<bool>(toDelayJobString);
		std::string delaySecondsString = GetStringByTag("DelaySeconds");
		_delaySeconds = boost::lexical_cast<int>(delaySecondsString);

	}
	catch (std::exception& e)
	{
		LOG_ERROR_XA_FILMING << "Exception: " << e.what() << LOG_END;
	}
}
