#include "XAConfig.h"

XAConfig XAConfig::_instance;

XAConfig* XAConfig::Instance()
{
	return &_instance;
}
