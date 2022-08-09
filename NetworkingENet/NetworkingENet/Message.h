#pragma once
#include <iostream>
#include <time.h>

class Message
{
public:
	Message(std::string sender, std::string text);
	~Message();

	std::string GetSender() { return m_sender; }
	std::time_t GetTimeStamp() { return m_time; }
	std::string GetText() { return m_text; }

	void DisplayContent();

private:
	std::string m_sender;
	std::time_t m_time;
	std::string m_text;
};