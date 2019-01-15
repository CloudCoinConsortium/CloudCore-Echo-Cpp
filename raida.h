/**
 * Raida class
 * Author: Dipen Chauhan
 * Description: Class for RAIDA. 
 * 		Member variables get populated after echo() function is called.
 */
#ifndef RAIDA_H
#define RAIDA_H

#include <string>
using namespace std;

class Raida
{
	unsigned int m_index; // RAIDA number. Eg. raida1.cloudcoin.global
	string m_server_name;
	string m_status;
	string m_message;
	string m_version;
	string m_time;
	string m_https_response;
	bool m_available; // True when "status" is "ready". False otherwise

public:	
	Raida()
	{
		m_available = false;
	}
	void echo();	// Contacts the RAIDA server
	void displayOutput();	// Displays output from RAIDA server

	// Getters and Setters
	unsigned int getIndex();
	void setIndex(unsigned int index);
	string getServerName();
	string getStatus();
	string getMessage();
	string getVersion();
	string getTime();
	bool getAvailable();
};

#endif /* RAIDA_H */