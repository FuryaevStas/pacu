#include	"header.h"

CConfigFile::CConfigFile(SSetting _defaultSettings[], 
						int _settingsNum,
						string _fileName)
{	
	this->settingsNum = _settingsNum;
	this->currentSettings = new SSetting[this->settingsNum];
	this->fileName = _fileName;
	this->configFile = fopen(this->fileName.c_str(), "r");
	if (this->configFile == NULL)
		this->writeSettings(_defaultSettings);
	else
		fclose(this->configFile);
	this->readSettings(this->currentSettings);
}

CConfigFile::~CConfigFile()
{
	this->writeSettings(this->currentSettings);
	delete[] this->currentSettings;
}

void CConfigFile::writeSettings(SSetting _settings[])
{
	this->configFile = fopen(this->fileName.c_str(), "w");
	for (int i(0); i < this->settingsNum; i++)
		fprintf(this->configFile, "%s=%s\n",
				_settings[i].name.c_str(),
				_settings[i].value.c_str());
	fclose(this->configFile);
}

void CConfigFile::readSettings(SSetting _settings[])
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
		for (int i(0); i < this->settingsNum; i++)
			_settings[i] = { arg.c_str(), val.c_str() };
	}
	fclose(this->configFile);
}

string CConfigFile::getPar(int _setting)
{
	return this->currentSettings[_setting].value;
}