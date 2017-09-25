#pragma once

#define XA_FILMING_DISALLOW_COPY(classname) \
    classname(const classname & );
#define XA_FILMING_DISALLOW_ASSIGN(classname) \
    void operator = (const classname & );
#define XA_FILMING_DISALLOW_COPY_AND_ASSIGN(classname) \
    XA_FILMING_DISALLOW_COPY  (classname)\
    XA_FILMING_DISALLOW_ASSIGN(classname)


#define MCSF_NAMESPACE_FOR_XA       Mcsf

#define EMPTY_STRING ""
#define LOG_END "\n"


#ifndef SAFE_DELETE_ELEMENT
#define SAFE_DELETE_ELEMENT(ptr) {\
if (ptr != nullptr)\
{\
delete ptr;\
ptr = nullptr;\
}\
}
#endif

