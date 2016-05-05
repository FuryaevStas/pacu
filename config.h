#ifndef	_CONFIG_H_
#define	_CONFIG_H_

#define SETTINGS_NUM 1

enum settings {
	LIST_PATH
};

struct SSetting {
	string name;
	string value;	
};

SSetting	defaultSettings[] = {
	{"listPath", "none"}
};

template<typename SettingType>
class CConfigFile
{
public:
	void	writeSettings(SettingType _settings[]);
	void	readSettings(SettingType _settings[]);

	CConfigFile(SettingType _defaultSettings[],
				int _settingsNum,
				string _fileName);
	~CConfigFile();
	
	string	getPar(settings _setting);
	
private:
	SettingType	currentSettings	[SETTINGS_NUM];
	
	string	fileName;
	FILE	*configFile;
};

template<typename SettingType>
CConfigFile<SettingType>::CConfigFile(SettingType _defaultSettings[], 
						int _settingsNum,
						string _fileName)
{	
	this->fileName = _fileName;
	this->configFile = fopen(this->fileName.c_str(), "r");
	if (this->configFile == NULL)
		this->writeSettings(_defaultSettings);
	else
		fclose(this->configFile);
	this->readSettings(this->currentSettings);
}

template<typename SettingType>
CConfigFile<SettingType>::~CConfigFile()
{
	this->writeSettings(this->currentSettings);
}

template<typename SettingType>
void CConfigFile<SettingType>::writeSettings(SettingType _settings[])
{
	this->configFile = fopen(this->fileName.c_str(), "w");
	for (int i(0); i < SETTINGS_NUM; i++)
		fprintf(this->configFile, "%s=%s",
				_settings[i].name.c_str(),
				_settings[i].value.c_str());
	fclose(this->configFile);
}

template<typename SettingType>
void CConfigFile<SettingType>::readSettings(SettingType _settings[])
{
	this->configFile = fopen(this->fileName.c_str(), "r");
	char ch(0);
	string arg(""), val("");
	while (!feof(this->configFile))
	{
		while ((ch = fgetc(this->configFile)) != '=' && !feof(this->configFile))
		 	arg += ch;
		while ((ch = fgetc(this->configFile)) != '\n' && !feof(this->configFile))
			val += ch;
		for (int i(0); i < SETTINGS_NUM; i++)
			_settings[i] = { arg, val };
	}
	fclose(this->configFile);
}

template<typename SettingType>
string CConfigFile<SettingType>::getPar(settings _setting)
{
	return this->currentSettings[_setting].value;
}

#endif