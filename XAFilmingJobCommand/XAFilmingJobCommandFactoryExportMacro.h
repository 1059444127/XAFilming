#pragma once

#ifdef XA_XAFilmingJobCommand_LIB
#define XA_XAFilmingJobCommand_Export __declspec (dllexport)
#else //!defined(XA_XAFilmingJobCommand_LIB)
#define XA_XAFilmingJobCommand_Export __declspec (dllimport)
#endif
