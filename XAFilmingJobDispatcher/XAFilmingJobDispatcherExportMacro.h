#pragma once

#ifdef XA_FilmingJobDispatcher_LIB
#define XA_FilmingJobDispatcher_Export __declspec (dllexport)
#else //!defined(XA_FilmingJobDispatcher_LIB)
#define XA_FilmingJobDispatcher_Export __declspec (dllimport)
#endif