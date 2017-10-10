#pragma once
class IPriority
{
public:
	virtual void TopPriority() = 0;
    virtual int GetPriority() = 0;
    virtual void ResetPriority() = 0;
};