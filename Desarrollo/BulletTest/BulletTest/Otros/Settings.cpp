#include "Settings.h"

std::string separador(":");
const std::string fileConfiguration = "../settings.bullet";


void Settings::LoadSettings()
{
	if (FileExists(fileConfiguration))
	{
		Open(fileConfiguration);

		std::string line, key, value;
		std::size_t position = 0;

		//Load values in the map
		while (getline(stream, line))
		{
			position = line.find(separador);
			if (position != std::string::npos)
			{
				key = line.substr(0, position);
				value = line.substr(position + 1);
				mSettings.insert(std::make_pair(key, value));
			}
		}

		Close();


	}
}

const std::string& Settings::GetValue(const std::string & value)
{
	auto found = mSettings.find(value);
	if (found != mSettings.end())
		return found->second;

	return "";
}



bool Settings::FileExists(const std::string& filename)
{
	std::ifstream ifile(filename);
	return (bool)ifile;
}

void Settings::Open(const std::string& filename)
{
	stream.open(filename);

	if (!stream)
		throw std::string("El fichero " + filename + " no existe");
}

void Settings::Close()
{
	stream.close();
}
