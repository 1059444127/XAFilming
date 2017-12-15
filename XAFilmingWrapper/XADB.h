#pragma once
#include "IFilmingJobMetaData.h"
#include "XAFilmingWrapperExportMacro.h"
#include "XAFilmingMacro.h"
#include <McsfNetBase/mcsf_netbase_icommunication_proxy.h>
#include <McsfDatabase/mcsf_database_factory.h>

class XA_FilmingWrapper_Export XADB
{
public:
	static XADB* GetInstance(MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy);
	void UpdateImagesPrintStatus(const IFilmingJobMetaData* filming_job_meta_data);

private:
	static XADB* _pInstance;
	XADB(MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy);
	void UpdateImagePrintStatus(const std::string sopInstanceUid) const;
	void UpdateUpLevelPrintStatus(std::set<const std::string> sopInstanceUids) const;

	MCSF_NAMESPACE_FOR_XA::IDatabasePtr m_pDatabase;

	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XADB);
};
