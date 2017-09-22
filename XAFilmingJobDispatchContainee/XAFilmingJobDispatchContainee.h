#pragma once

#include "XAFilmingMacro.h"
#include <McsfContainee/mcsf_containee_interface.h>
using namespace MCSF_NAMESPACE_FOR_XA;

class ICommunicationProxy;
class IEventHandler;
class ICommandHandler;
class IBigDataHandler;

class XAFilmingJobDispatchContainee : public IContainee
{


private:
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingJobDispatchContainee)
};

DECLARE_CONTAINEE(XAFilmingJobDispatchContainee);

