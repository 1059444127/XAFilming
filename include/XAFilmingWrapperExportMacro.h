#pragma once

#ifdef XA_FilmingWrapper_LIB
#define XA_FilmingWrapper_Export __declspec (dllexport)
#else //!defined(XA_FilmingWrapper_LIB)
#define XA_FilmingWrapper_Export __declspec (dllimport)
#endif
