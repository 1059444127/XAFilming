#pragma once
class IPacketHeader
{
public:
	virtual ~IPacketHeader(){}

	virtual int GetIndex() = 0;
	virtual int GetTotal() = 0;
};