#pragma once

#ifdef XA_FilmingJobStatus_LIB
#define XA_FilmingJobStatus_Export __declspec (dllexport)
#else //!defined(XA_FilmingJobStatus_LIB)
#define XA_FilmingJobStatus_Export __declspec (dllimport)
#endif