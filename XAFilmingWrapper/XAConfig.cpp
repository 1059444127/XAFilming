#include "XAConfig.h"
#include "Common/McsfSystemEnvironmentConfig/mcsf_systemenvironment_factory.h"
#include "XAFilmingConst.h"
#include "XAFilmingMacro.h"
#include "PrinterConfig.h"

using namespace MCSF_NAMESPACE_FOR_XA;

boost::mutex XA_CONFIG_MUTEX;


XAConfig* XAConfig::_pInstance;

XAConfig* XAConfig::Instance()
{
	if(nullptr == _pInstance)
	{
		boost::mutex::scoped_lock lock(XA_CONFIG_MUTEX);
		if(nullptr == _pInstance)
		{
			_pInstance = new XAConfig();	
		}		
	}
	return _pInstance;
}

IXADicomPrinterProperty* XAConfig::GetPrinterConfig()
{
	//TODO: lock and create PrintConfig
	if(nullptr == _pPrinterConfig)
	{
		boost::mutex::scoped_lock(_printerConfigMutex);
		if(nullptr == _pPrinterConfig)
		{
			_pPrinterConfig = new PrinterConfig(GetPrinterConfigPath());
		}
	}	

	if(_pPrinterConfig->ReadConfigBeforeUsing()) {_pPrinterConfig->ReadConfig();}

	return _pPrinterConfig;
}

XAConfig::~XAConfig()
{
	SAFE_DELETE_ELEMENT(_pPrinterConfig);
	SAFE_DELETE_ELEMENT(_pInstance);
}

XAConfig::XAConfig(): _pPrinterConfig(nullptr)
{
	ISystemEnvironmentConfig* pSysConfig =
		ConfigSystemEnvironmentFactory::Instance()->GetSystemEnvironment();
	auto sFilmingPath = pSysConfig->GetApplicationPath(XA_FILMING_CONFIG_PATH);
	_printerConfigPath = sFilmingPath + XA_PRINT_CONFIG_FILE_NAME;
}
