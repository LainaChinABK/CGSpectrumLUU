#include "Message.h"

Message::Message(std::string sender, std::time_t time, std::string text)
	: m_sender(sender)
	, m_time(time)
	, m_text(text)
{

}

Message::~Message()
{

}

void Message::DisplayContent()
{
	// TODO: fix time display
	std::cout << m_time << " " + m_sender << ": " + m_text << std::endl;
}