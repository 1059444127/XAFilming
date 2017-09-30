//#include <boost/thread/mutex.hpp>

#include "XAFilmingJobCommandFactory.h"

XAFilmingJobCommandFactory* XAFilmingJobCommandFactory::_pInstance = new XAFilmingJobCommandFactory();

//static boost::mutex lock_mutex;

XAFilmingJobCommandFactory* XAFilmingJobCommandFactory::GetInstance()
{
	//if(nullptr == _pInstance)
	//{
	//	boost::mutex::scoped_lock singleton_lock(lock_mutex);
		//if(nullptr == _pInstance)
		//{
			//_pInstance = new XAFilmingJobCommandFactory();			
		//}
	//}
	return _pInstance;
}
