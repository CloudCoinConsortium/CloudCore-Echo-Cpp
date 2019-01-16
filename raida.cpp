#include "raida.h"
#include <iostream>
#include <stdio.h>
#include <curl/curl.h>
using namespace std;

string curl_data; //will hold the url's contents
/**
 * Function is called when CURL gets data
 * @param  buffer Pointer to the data that curl has for us
 * @param  size   size * nmemb is the size of the buffer
 * @param  nmemb  size * nmemb is the size of the buffer
 * @param  userp  [description]
 * @return        tell curl how many bytes we handled
 */
size_t write_data(char *buffer, size_t size, size_t nmemb, void *userp)
{
	for (unsigned int c = 0; c < (size * nmemb); c++)
		curl_data.push_back(buffer[c]); 
	return size * nmemb;
}

void Raida::echo()
{
	CURL* curl; //our curl object
	CURLcode res;
	string url = "https://raida" + to_string(m_index) + ".cloudcoin.global/service/echo";
	// Eg. https://raida1.cloudcoin.global/service/echo

	// curl_global_init(CURL_GLOBAL_DEFAULT);
	curl_global_init(CURL_GLOBAL_ALL);
	// init the curl session
	curl = curl_easy_init();

	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &write_data);
	}
	

	curl_data = "";
	/* Perform the request, res will get the return code */ 
	res = curl_easy_perform(curl);

	cout << "Response: " << curl_data;

	curl_easy_cleanup(curl);
	curl_global_cleanup();
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