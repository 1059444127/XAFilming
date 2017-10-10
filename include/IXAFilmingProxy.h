#include <IXAFilming.h>

class IXAFilmingProxy : public IXAFilming
{
	virtual void SetFilmingProxy(IXAFilming* pFilming) = 0;
};
