#ifndef	_CONFIG_H_
#define	_CONFIG_H_

#define SETTINGS_NUM 1

enum settings {
	LISTPATH
};

struct SSetting {
	string name;
	string value;	
};

class CConfigFile
{
public:
	void	writeSettings(SSetting *_settings);
	void	readSettings(SSetting *_settings);

	CConfigFile();
	~CConfigFile();	
	
	string	getPar(settings _setting);
	
private:
	SSetting defaultSettings[SETTINGS_NUM];
	SSetting currentSettings[SETTINGS_NUM];
	
	FILE	*configFile;
};

#endif