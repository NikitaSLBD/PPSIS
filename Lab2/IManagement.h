#pragma once



template <class C1, class C2>

class IManagement
{
	virtual void add(C1&, C2) = 0;
	virtual void remove(C1&, C2) = 0;
	virtual void change(C1&, C2, C2) = 0;
};