#include "IXAFilming.h"
#include <cassert>

class IXAFilmingProxy : public IXAFilming
{
public:
	virtual void SetFilmingProxy(IXAFilming* pFilming)
	{
		_pFilming = pFilming;
	}

	virtual void Print(const std::vector<std::string>& filePaths)
	{
		assert(nullptr != _pFilming);
		_pFilming->Print(filePaths);
	}
private:
	IXAFilming* _pFilming;
};
