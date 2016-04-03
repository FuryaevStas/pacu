#include	"header.h"

string settingsName[] = {
	"listPath"	
};

CConfigFile::CConfigFile()
{
	for (int i(0); i < SETTINGS_NUM; i++)
	{
		this->currentSettings[i].name = settingsName[LISTPATH];
		this->currentSettings[i].value = "none";
		this->defaultSettings[i].name = settingsName[LISTPATH];
		this->defaultSettings[i].value = "none";
	}
	
	this->configFile = fopen("pacu.cfg", "r");
	if (this->configFile == NULL)
	{
		this->configFile = fopen("pacu.cfg", "w");
		this->writeSettings(this->defaultSettings);
	}
	fclose(this->configFile);
	this->readSettings(this->currentSettings);
}

CConfigFile::~CConfigFile()
{
	this->writeSettings(this->currentSettings);
}

void CConfigFile::writeSettings(SSetting _settings[])
{
	
}

void CConfigFile::readSettings(SSetting _settings[])
{
	this->configFile = fopen("pacu.cfg", "r");
	char ch(0);
	string arg(""), val("");
	while (!feof(this->configFile))
	{
		while ((ch = getc(this->configFile)) != '=' || !feof(this->configFile))
			arg += ch;
		while ((ch = getc(this->configFile)) != '\n' || !feof(this->configFile))
			val += ch;
		for (int i(0); i < SETTINGS_NUM; i++){
			if (arg == _settings[i].name)
				_settings[i].value = val;
		}
	}
	
	fclose(this->configFile);
}

string CConfigFile::getPar(settings _setting)
{
	return this->currentSettings[_setting].value;
}