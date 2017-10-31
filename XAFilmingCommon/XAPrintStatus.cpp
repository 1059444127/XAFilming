#include "XAPrintStatus.h"

#include <boost/thread/mutex.hpp>

bool is_printing = false;

boost::mutex is_printing_mutex;

typedef boost::mutex::scoped_lock scoped_lock;

bool IsPrinting()
{
	scoped_lock(is_printing_mutex);
	return is_printing;
}

void SetIsPrinting(bool isPrinting)
{
	scoped_lock(is_printing_mutex);
	is_printing = isPrinting;
}