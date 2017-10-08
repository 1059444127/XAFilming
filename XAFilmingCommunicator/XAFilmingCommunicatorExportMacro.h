#pragma once

#ifdef XA_FilmingCommunicator_LIB
#define XA_FilmingCommunicator_Export __declspec (dllexport)
#else //!defined(XA_FilmingCommunicator_LIB)
#define XA_FilmingCommunicator_Export __declspec (dllimport)
#endif