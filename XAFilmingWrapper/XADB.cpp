#include "XADB.h"
#include <McsfDatabase/mcsf_database_factory.h>
#include <boost/thread/mutex.hpp>
#include <XAFilmingLogger.h>

using namespace std;

boost::mutex XA_DB_MUTEX;
XADB* XADB::_pInstance;

XADB* XADB::GetInstance(Mcsf::ICommunicationProxy* pProxy)
{
		if(nullptr == _pInstance)
	{
		boost::mutex::scoped_lock lock(XA_DB_MUTEX);
		if(nullptr == _pInstance)
		{
			_pInstance = new XADB(pProxy);	
		}		
	}
	return _pInstance;
}

void XADB::UpdateUpLevelPrintStatus(std::set<const std::string> sopInstanceUids) const
{
	vector<string> imageInstanceUIDVector(sopInstanceUids.begin(), sopInstanceUids.end());

	int iRet = m_pDatabase->UpdateStatusByImageUIDList(imageInstanceUIDVector, Mcsf::STATUS_FILMING);
	if(iRet != ERROR_DB_NULL)
	{
		LOG_ERROR_XA_FILMING  << "Update Study and Series Print Status Failed!" << LOG_END; 
	}
}

void XADB::UpdateImagesPrintStatus(const IFilmingJobMetaData* filming_job_meta_data)
{
	auto sopInstanceUids = filming_job_meta_data->GetSopInstanceUids();
		for (auto iter = sopInstanceUids.begin(); iter != sopInstanceUids.end(); iter++)
	{
		UpdateImagePrintStatus(*iter);
	}

	UpdateUpLevelPrintStatus(sopInstanceUids);
}

XADB::XADB(Mcsf::ICommunicationProxy* pProxy)
{
	m_pDatabase = Mcsf::IDatabaseFactory::Instance() ->CreateDBWrapper();
	if(!m_pDatabase->Initialize())
    {
        LOG_ERROR_XA_FILMING << "can't connnect to DB!" << LOG_END;
        return ;
    }
	m_pDatabase->SetAutoNotifyOn(pProxy);
}

void XADB::UpdateImagePrintStatus(const std::string sopInstanceUid) const
{
    string uid = "SOPInstanceUID='" + sopInstanceUid + "'";
    ostringstream os;
    os << "PrintStatus=" << "'" << 1 << "'";
    string sStatement = os.str();

	int iDBAccessResult = m_pDatabase->Update("imagetable", uid, sStatement);

    if( ERROR_DB_NULL != iDBAccessResult)
    {
        LOG_WARN_XA_FILMING << "Something Wrong when Update Printing Status of a Image Object For DX" << LOG_END; 
    }

}


