#pragma once
#include "IStudyInfo.h"
#include "IPacketHeader.h"

class DicomDataHeaderPacketHeader : public IStudyInfo, public IPacketHeader
{
public:
	virtual std::string GetPatientID() const {return _patientID;}
	virtual std::string GetPatientName() const {return _patientName;}
	virtual int GetIndex() const {return _index;}
	virtual int GetTotal() const {return _total;}

	void SetPatientID(const std::string& patientID) {_patientID=patientID;}
	void SetPatientName(const std::string patientName) {_patientName=patientName;}
	void SetIndex(int index) {_index=index;}
	void SetTotal(int total) {_total=total;}

private:
	std::string _patientID;
	std::string _patientName;
	int _index;
	int _total;
};
