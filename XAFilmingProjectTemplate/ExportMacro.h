#pragma once

#ifdef XA_FilmingProjectTemplate_LIB
#define XA_FilmingProjectTemplate_Export __declspec (dllexport)
#else //!defined(XA_FilmingProjectTemplate_LIB)
#define XA_FilmingProjectTemplate_Export __declspec (dllimport)
#endif