#pragma once

#include <GLEW/glew.h>

#include <iostream>

#include <assimp/Importer.hpp>

class Texture {
public:
	GLuint id;
	std::string type;
	aiString path;
};

