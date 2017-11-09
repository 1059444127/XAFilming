#pragma once
#include "IStudyInfo.h"
#include "IPacketHeader.h"

class DicomDataHeaderPacketHeader : public IStudyInfo, public IPacketHeader
{
public:
	virtual std::string GetPatientID() {return _patientID;}
	virtual std::string GetPatientName() {return _patientName;}
	virtual int GetIndex() {return _index;}
	virtual int GetTotal() {return _total;}

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
