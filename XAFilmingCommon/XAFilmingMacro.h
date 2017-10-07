#pragma once

#define XA_FILMING_DISALLOW_COPY(classname) \
    classname(const classname & );
#define XA_FILMING_DISALLOW_ASSIGN(classname) \
    void operator = (const classname & );
#define XA_FILMING_DISALLOW_COPY_AND_ASSIGN(classname) \
    XA_FILMING_DISALLOW_COPY  (classname)\
    XA_FILMING_DISALLOW_ASSIGN(classname)


#ifdef XA_FilmingCommon_LIB
#define XA_FilmingCommon_Export __declspec (dllexport)
#else //!defined(XA_FilmingCommon_LIB)
#define XA_FilmingCommon_Export __declspec (dllimport)
#endif


#define MCSF_NAMESPACE_FOR_XA       Mcsf

#define XA_FILMING_EMPTY_STRING ""



#ifndef SAFE_DELETE_ELEMENT
#define SAFE_DELETE_ELEMENT(ptr) {\
if (ptr != nullptr)\
{\
delete ptr;\
ptr = nullptr;\
}\
}
#endif

#ifndef SAFE_DELETE_COLLECTION
#define SAFE_DELETE_COLLECTION(collection) {\
    for(auto iter = collection.begin(); iter != collection.end(); iter++)\
    {\
        SAFE_DELETE_ELEMENT(*iter)\
    }\
}
#endif
