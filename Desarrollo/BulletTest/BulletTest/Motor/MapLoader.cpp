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
			std::cout << *it << '\n';
		}
	}
	//std::cout << j.dump() << std::endl;
}

