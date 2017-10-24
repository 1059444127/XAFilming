#pragma once

#include "gtest/gtest.h"
#include <vector>
#include "XAFilmingJobBase.h"
#include "XAFilmingMock.h"
#include "XAFilmingMacro.h"

/// \class XAJobTests
/// \brief XAFilmingJob Test suite class 
///
class FilmingJobTests : public testing::Test
{
public:
	FilmingJobTests(): _filePaths(), _job(nullptr), _filmingProxy(nullptr)
	{
		for (int i = 0; i < 4; i++)
			_filePaths.push_back("1.dcm");
		_filmingProxy = new XAFilmingMock();
	}

	~FilmingJobTests()
	{
		SAFE_DELETE_ELEMENT(_filmingProxy);	
	}


protected:
	virtual void SetUp();
	virtual void TearDown();
	std::vector<std::string> _filePaths;
	XAFilmingJobBase* _job;
	IXAFilming* _filmingProxy;
};