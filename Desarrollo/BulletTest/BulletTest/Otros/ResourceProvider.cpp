#include "ResourceProvider.h"

void ResourceProvider::setResourceGroupDirectory(const std::string & resourceGroup, const std::string & directory)
{
	if (directory.length() == 0)
		return;

	const std::string separator("/");

	//Si el usuario no añade '/' al final, lo añadimos
	if (std::string::npos == separator.find(directory[directory.length() - 1]))
		m_resourceGroups[resourceGroup] = directory + '/';
	else
		m_resourceGroups[resourceGroup] = directory;
}

const std::string & ResourceProvider::getResourceGroupDirectory(const std::string & resourceGroup)
{
	return m_resourceGroups[resourceGroup];
}

void ResourceProvider::clearResourceGroupDirectory(const std::string & resourceGroup)
{
	ResourceGroupMap::iterator iter = m_resourceGroups.find(resourceGroup);

	if (iter != m_resourceGroups.end())
		m_resourceGroups.erase(iter);
}

std::string ResourceProvider::getFinalFilename(const std::string & filename, const std::string & resourceGroup) const
{
	std::string final_filename;

	if (resourceGroup.empty()) {
		return final_filename;
	}
	// search resource group directory
	ResourceGroupMap::const_iterator iter = m_resourceGroups.find(resourceGroup);

	// si encontramos una entrada para este grupo, usamos su directorio como
	// la primera parte del path
	if (iter != m_resourceGroups.end())
		final_filename = (*iter).second;

	// añadimos la parte del nombre del fichero
	final_filename += filename;


	return final_filename;
}
