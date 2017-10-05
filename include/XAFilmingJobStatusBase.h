#pragma once

class IXAFilmingJob;

class XAFilmingJobStatusBase
{
    virtual void Continue(IXAFilmingJob job);
};

