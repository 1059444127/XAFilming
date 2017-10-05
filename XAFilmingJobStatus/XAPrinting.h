#pragma once
#include "XAFilmingJobStatusBase.h"

class XAPrinting :
    public XAFilmingJobStatusBase
{
public:
   virtual std::string ToString() const ;    
};

