#pragma once

#include <iostream>
#include <unordered_map>

//Esta clase ayuda a la localizacion de paths de resources, agrupandolos en group resources
class ResourceProvider {

public:
	ResourceProvider() {}
	~ResourceProvider() {}

	//Set the directory associated with a given resource group.
	//resourceGroup :: nombre resource (identificador) EX : "personajes", "armas", etc.
	//directory :: La ruta almacenada internamente en el mapa
	void setResourceGroupDirectory(const std::string& resourceGroup, const std::string& directory);

	// Return the directory associated with the specified resource group identifier.
	const std::string& getResourceGroupDirectory(const std::string& resourceGroup);

	// clears any currently set directory for the specified resource group identifier.
	void clearResourceGroupDirectory(const std::string& resourceGroup);

	// Return the final path and filename, taking into account the given
	//resource group identifier that should be used when we load the data(cargar contenido)
	std::string getFinalFilename(const std::string& filename, const std::string& resourceGroup) const;

private:

	typedef std::unordered_map<std::string, std::string> ResourceGroupMap;
	ResourceGroupMap    m_resourceGroups;

};