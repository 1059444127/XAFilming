#pragma once

#ifdef XA_FilmingJob_LIB
#define XA_FilmingJob_Export __declspec (dllexport)
#else //!defined(XA_FilmingJob_LIB)
#define XA_FilmingJob_Export __declspec (dllimport)
#endif