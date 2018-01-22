#pragma once
#include "XAFilmingWrapperExportMacro.h"

#include "XAFilmingMacro.h"
#include <McsfFileParser/mcsf_ifile_parser.h>
#include <boost/thread/mutex.hpp>

class XA_FilmingWrapper_Export AbstractConfig
{
public:
	AbstractConfig(const std::string& configFilePath);
	virtual ~AbstractConfig();
	void ReadConfig();
	bool ReadConfigBeforeUsing();
	virtual void ReadConfigFromFile();

protected:
	MCSF_NAMESPACE_FOR_XA::IFileParser* _pFileParser;

	std::string GetStringByTag(const std::string& tag);

	std::string _configFilePath;

	boost::mutex _configReadMutex;

private:
	bool _bReadConfigBeforeUsing;
};
