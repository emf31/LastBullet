#include "AssetsReader.h"
#include <Engine\ResourceManager.h>


void AssetsReader::read(std::string directory, std::queue<std::string>& colaAssets)
{
	DIR *dir;
	struct dirent *ent;
	//std::cout << "-------------------------------------------------" << std::endl;
	if ((dir = opendir(directory.c_str())) != NULL) {
		// skip firts two lines
		readdir(dir);
		readdir(dir);
		while ((ent = readdir(dir)) != NULL) {
			std::string name(ent->d_name);
			std::size_t p = name.find(".");
			if (p != std::string::npos) {
				std::string formato = name.substr(p);
				if (formato == ".obj") {
					colaAssets.push(directory + "/" + name);
				}
				else {
					continue;
				}

			}
				
		}
		closedir(dir);
	}
}

