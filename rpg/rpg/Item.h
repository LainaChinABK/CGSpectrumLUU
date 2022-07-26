#pragma once
#include <iostream>

class Item
{
protected:
	int m_id;
	std::string m_name;

public:
	Item(int id);
	virtual ~Item();

	int GetID() const { return m_id; }
	std::string GetName() const { return m_name; }
};