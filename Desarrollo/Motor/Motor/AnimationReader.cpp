#include "AnimationReader.h"
#include "dirent.h"


void AnimationReader::LoadMeshesFromDirectory(const std::string & directory, unsigned int numAnimations, std::vector<std::string>& vector)
{
	vector.clear();

	/*DIR *dir;
	struct dirent *ent;*/
	int zizu = 0;
	std::vector<std::string> strings;

	for (std::size_t i = 0; i < numAnimations; i++) {
		std::string path = directory + "/0" + std::to_string(i) + ".obj";
		vector.push_back(path);
		//ResourceManager::i().getAnimationMesh();

		std::cout << path << std::endl;
	}
	//std::string carpeta = "assets/";

	/*if ((dir = opendir(directory.c_str())) != NULL) {
		// skip firts two lines
		readdir(dir);
		readdir(dir);

		while ((ent = readdir(dir)) != NULL) {

			std::string name(ent->d_name);
			std::size_t found = name.find(".mtl");
			if (found != std::string::npos) {
				continue;
			}
			
			strings.push_back(std::string(ent->d_name));
		}
		closedir(dir);
		std::sort(strings.begin(), strings.end());

		for (std::string& name : strings) {
			TMeshGroup* meshes = ResourceManager::i().getMesh(directory + "/" + ent->d_name);
			vector.push_back(meshes);
		}







	}
	else {
		
		throw std::runtime_error("Error el directorio: " + directory + "no existe" );
	}*/

}
