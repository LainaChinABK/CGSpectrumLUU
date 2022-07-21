#pragma once
class Vehicle
{
protected:
	int m_miles;

public:
	Vehicle();
	~Vehicle();
	
	int getMiles() { return m_miles; }

	virtual void Drive() = 0;
};