#pragma once

#ifdef XA_FilmingInterface_LIB
#define XA_FilmingInterface_Export __declspec (dllexport)
#else //!defined(XA_FilmingInterface_LIB)
#define XA_FilmingInterface_Export __declspec (dllimport)
#endif