#include "MapLoader.h"
#include "../json/json.hpp"

// for convenience
using json = nlohmann::json;

void MapLoader::readMap(const std::string & name)
{	
	std::ifstream i("../media/terminal_export.json");
	if(i){
		json j = json::parse(i);

		for (json::iterator it = j.begin(); it != j.end(); ++it) {
			
			json obj = *it;
			std::cout << "----------------------------"<<'\n';
			std::cout << "Nombre " << obj["nombre"] << '\n';
			std::cout << "Posicion "<<obj["posX"] <<','<< obj["posY"] <<  ','<< obj["posZ"] << '\n';
			std::cout << "Rotacion " << obj["rotX"] << ',' << obj["rotY"] << ',' << obj["rotZ"] << '\n';
			std::cout << "Escalado " << obj["sizeX"] << ',' << obj["sizeY"] << ',' << obj["sizeZ"] << '\n';
		}
	}
	//std::cout << j.dump() << std::endl;
}

