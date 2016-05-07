#ifndef	_CONFIG_H_
#define	_CONFIG_H_

#include	"header.h"

#define SETTINGS_NUM 1

enum settings {
	LIST_PATH
};

struct SSetting {
	string	name;
	string	value;
};

class CConfigFile
{
public:
	void	writeSettings(SSetting _settings[]);
	void	readSettings(SSetting _settings[]);

	CConfigFile(SSetting _defaultSettings[],
				int _settingsNum,
				string _fileName);
	~CConfigFile();
	
	string	getPar(int _setting);
	
private:
	int	settingsNum;

	SSetting	*currentSettings;
	
	string	fileName;
	FILE	*configFile;
};

#endif