#pragma once
#include "IXADicomPrinterProperty.h"
#include "XAFilmingMacro.h"
#include "boost/thread/thread.hpp"
#include <McsfFileParser/mcsf_ifile_parser.h>
#include "XAFilmingWrapperExportMacro.h"

class XA_FilmingWrapper_Export PrinterConfig : public IXADicomPrinterProperty
{
public:
	PrinterConfig(const std::string& configFilePath);
	virtual ~PrinterConfig();

	virtual std::string GetAE();
	virtual std::string GetIP();
	virtual unsigned short GetPort();
	virtual std::string GetFilmSize();
	void ReadConfig();
	bool ReadConfigBeforeUsing();
private:
	bool _bReadConfigBeforeUsing;
	std::string _ae;
	std::string _ip;
	unsigned short _port;
	std::string _filmSize;

	std::string _configFilePath;
	MCSF_NAMESPACE_FOR_XA::IFileParser* _pFileParser;

	boost::mutex _configReadMutex;

	std::string GetStringByTag(const std::string& tag);
	void ReadConfigFromFile();
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(PrinterConfig)
};
