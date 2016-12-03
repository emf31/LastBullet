#include "MapLoader.h"
#include "../json/json.hpp"

// for convenience
using json = nlohmann::json;

void MapLoader::readMap(const std::string & name)
{	
	std::ifstream i("rust_export.json");
	json j;
	i >> j;
	std::cout << j.dump() << std::endl;
}

