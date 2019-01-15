/**
 * Raid class
 * Author: Dipen Chauhan
 * Description: Class for RAIDA. 
 * 		Member variables get populated after echo() function is called.
 */
class Raida
{
	string m_server_name;
	string m_status;
	string m_message;
	string m_version;
	string m_time;
public:
	
	void echo();
	void displayOutput();
	bool isAvailable();

	string getServerName();
	string getStatus();
	string getMessage();
	string getVersion();
	string getTime();
};