#pragma once

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>

class Settings {

public:
	static Settings& i() {
		static Settings singleton;
		return singleton;
	}

	void LoadSettings();
	const std::string& GetValue(const std::string& value);

private:
	Settings() { }

	std::ifstream stream;

	bool FileExists(const std::string& filename);

	void Open(const std::string& filename);

	void Close();

	std::unordered_map<std::string, std::string> mSettings;
};