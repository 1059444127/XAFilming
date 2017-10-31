#pragma once

#ifdef XA_Filming_LIB
#define XA_Filming_Export __declspec (dllexport)
#else //!defined(XA_Filming_LIB)
#define XA_Filming_Export __declspec (dllimport)
#endif
