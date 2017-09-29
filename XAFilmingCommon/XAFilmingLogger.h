#pragma once

#include "McsfLogger/mcsf_logger.h"

const string XA_FILMING_LOGGER_SOURCE = "XA/Filming";
const int XA_FILMING_LOGGER_UID = 001035010;

#ifndef CONSOLE_LOG

#define LOG_INFO_XA_FILMING             \
	LOG_DEV_INFO_2(            \
	XA_FILMING_LOGGER_SOURCE,  \
	XA_FILMING_LOGGER_UID     \
	)                             

#define LOG_WARN_XA_FILMING              \
	LOG_DEV_WARNING_2(            \
	XA_FILMING_LOGGER_SOURCE,  \
	XA_FILMING_LOGGER_UID     \
	)                             

#define LOG_ERROR_XA_FILMING             \
	LOG_DEV_ERROR_2(                  \
	XA_FILMING_LOGGER_SOURCE,  \
	XA_FILMING_LOGGER_UID     \
	)                               

#define LOG_SVC_ERROR_XA_FILMING             \
	LOG_SVC_ERROR_2(                  \
	XA_FILMING_LOGGER_SOURCE,  \
	XA_FILMING_LOGGER_UID     \
	)                               

#define LOG_SVC_WARN_XA_FILMING             \
	LOG_SVC_WARNING_2(                  \
	XA_FILMING_LOGGER_SOURCE,  \
	XA_FILMING_LOGGER_UID     \
	)                               

#define LOG_SVC_INFO_XA_FILMING             \
	LOG_SVC_INFO_2(                  \
	XA_FILMING_LOGGER_SOURCE,  \
	XA_FILMING_LOGGER_UID     \
	)         

#else

#define LOG_INFO_XA_FILMING  std::cout

#define LOG_WARN_XA_FILMING  std::cout                        

#define LOG_ERROR_XA_FILMING  std::cout                           

#define LOG_SVC_ERROR_XA_FILMING  std::cout                           

#define LOG_SVC_WARN_XA_FILMING  std::cout                           

#define LOG_SVC_INFO_XA_FILMING  std::cout       

#endif
