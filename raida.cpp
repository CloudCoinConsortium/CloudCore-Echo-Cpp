#include "raida.h"
#include <iostream>
using namespace std;

void Raida::echo()
{

}

void Raida::displayOutput()
{
	cout << m_https_response;
}

// Getters and Setters
unsigned int Raida::getIndex()
{
	return m_index;
}
void Raida::setIndex(unsigned int index)
{
	m_index = index;
}

string Raida::getServerName()
{
	return m_server_name;
}

string Raida::getStatus()
{
	return m_status;
}

string Raida::getMessage()
{
	return m_message;
}

string Raida::getVersion()
{
	return m_version;
}

string Raida::getTime()
{
	return m_time;
}

bool Raida::getAvailable()
{
	return m_available;
}