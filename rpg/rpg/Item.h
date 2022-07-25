#pragma once
#include <string>

class Item
{
protected:
	int m_id;
	std::string m_name;

public:
	Item(int id);
	~Item();

	std::string GetName() { return m_name; }
};