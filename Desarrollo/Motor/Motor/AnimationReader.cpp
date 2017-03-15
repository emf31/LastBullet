#include <AnimationReader.h>
#include <dirent.h>


void AnimationReader::LoadMeshesFromDirectory(const std::string & directory, std::vector<TMeshGroup*>& vector)
{
	vector.clear();

	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(directory.c_str())) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL) {
			TMeshGroup* meshes = ResourceManager::i().getMesh(directory + "/" + ent->d_name);
			vector.push_back(meshes);
		}
		closedir(dir);
	}
	else {
		/* could not open directory */
		throw std::runtime_error("Error el directorio: " + directory + "no existe" );
	}

}
