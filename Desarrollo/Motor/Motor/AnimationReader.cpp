#include "AnimationReader.h"
#include "dirent.h"


void AnimationReader::LoadMeshesFromDirectory(const std::string & directory, std::vector<TMeshGroup*>& vector)
{
	vector.clear();

	DIR *dir;
	struct dirent *ent;
	int zizu = 0;
	bool estoesmuysucio = false;
	std::string carpeta = "assets/";
	if ((dir = opendir(directory.c_str())) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL) {
			if (zizu > 1) {
				if (estoesmuysucio == true) {
					std::cout << directory + "/" + ent->d_name << std::endl;
					//este por si queremos tener las texturas en la misma carpeta del personaje
					TMeshGroup* meshes = ResourceManager::i().getMesh(directory + "/" + ent->d_name);
					//este por si queremeos tener los obj en la carpeta pero las texturas con el resto de texturas en la carpeta assets
					//TMeshGroup* meshes = ResourceManager::i().getMesh(carpeta + ent->d_name);
					vector.push_back(meshes);
				}
				estoesmuysucio = !estoesmuysucio;
			}
			zizu++;

		}
		closedir(dir);
	}
	else {
		/* could not open directory */
		throw std::runtime_error("Error el directorio: " + directory + "no existe" );
	}

}
