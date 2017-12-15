#include "IXAFilming.h"
#include <cassert>

class XA_FilmingInterface_Export IXAFilmingProxy : public IXAFilming
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

	//TODO: Print set<sopInstanceUid>
	virtual void UpdatePrintStatus(const IFilmingJobMetaData* filmingJobMetaData)
	{
		_pFilming->UpdatePrintStatus(filmingJobMetaData);
	}
private:
	IXAFilming* _pFilming;
};
