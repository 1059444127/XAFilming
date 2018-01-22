#pragma once
#include "XAFilmingMacro.h"
#include <McsfFileParser/mcsf_ifile_parser.h>
#include <boost/thread/mutex.hpp>

class AbstractConfig
{
public:
	AbstractConfig(const std::string& configFilePath);
	virtual ~AbstractConfig();

protected:
	MCSF_NAMESPACE_FOR_XA::IFileParser* _pFileParser;

	std::string _configFilePath;

	boost::mutex _configReadMutex;
};
