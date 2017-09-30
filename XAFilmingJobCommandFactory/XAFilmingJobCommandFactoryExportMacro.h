#pragma once

#ifdef XA_XAFilmingJobCommandFactory_LIB
#define XA_XAFilmingJobCommandFactory_Export __declspec (dllexport)
#else //!defined(XA_XAFilmingJobCommandFactory_LIB)
#define XA_XAFilmingJobCommandFactory_Export __declspec (dllimport)
#endif
