#pragma once
class IPacketHeader
{
public:
	virtual ~IPacketHeader(){}

	virtual int GetIndex() const = 0;
	virtual int GetTotal() const = 0;
};