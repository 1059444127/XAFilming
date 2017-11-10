#include "XABoost.h"
#include <boost/date_time/posix_time/posix_time.hpp>  

std::string XANow()
{
	//TODO: Get Now using boost
    std::string strTime = boost::posix_time::to_iso_string(boost::posix_time::second_clock::local_time());    
        
    // ��ʱ��strTime����ʱ��ĸ�ʽ��YYYYMMDDTHHMMSS�����ں�ʱ���ô�д��ĸT������    
    
	//TODO-MayBe: Replace XANow algorithm with year month day hour minute seconds composition
	strTime.replace(4,0,std::string("-"));
	strTime.replace(7,0,std::string("-"));
	
    int pos = strTime.find('T');    
    strTime.replace(pos,1,std::string("/"));    
    strTime.replace(pos + 3,0,std::string(":"));    
    strTime.replace(pos + 6,0,std::string(":"));   
	std::stringstream ss;
	

	return strTime;
}
