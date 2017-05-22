#pragma once

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <ResourceProvider.h>

class Settings {

public:
	static Settings& i() {
		static Settings singleton;
		return singleton;
	}

	void LoadSettings();
	const std::string GetValue(const std::string& value);

	void SetValue(const std::string& property, const std::string& value);

	ResourceProvider& GetResourceProvider() { return m_resourceProvider; }

private:
	Settings() { }

	std::ifstream stream;

	bool FileExists(const std::string& filename);

	void Open(const std::string& filename);

	void Close();

	std::unordered_map<std::string, std::string> mSettings;

	ResourceProvider m_resourceProvider;

	void Settings::WriteMapToFile();
};