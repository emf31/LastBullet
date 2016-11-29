#pragma once

#define GLEW_STATIC
#include <GLEW/glew.h>

#include <iostream>
using namespace std;
#include <assimp/Importer.hpp>

class Texture {
public:
	GLuint id;
	string type;
	aiString path;

	static GLint TextureFromFile();
};

