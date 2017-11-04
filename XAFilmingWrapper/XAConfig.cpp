#include "XAConfig.h"
#include "Common/McsfSystemEnvironmentConfig/mcsf_systemenvironment_factory.h"
#include "XAFilmingConst.h"

using namespace MCSF_NAMESPACE_FOR_XA;


XAConfig XAConfig::_instance;

XAConfig* XAConfig::Instance()
{
	return &_instance;
}

XAConfig::XAConfig()
{
	ISystemEnvironmentConfig *pSysConfig =
		ConfigSystemEnvironmentFactory::Instance()->GetSystemEnvironment();
	auto sFilmingPath = pSysConfig->GetApplicationPath(XA_FILMING_CONFIG_PATH);
	_printerConfigPath = sFilmingPath + XA_PRINT_CONFIG_FILE_NAME;
}
