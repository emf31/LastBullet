#ifndef SHADER_H
#define SHADER_H

#include <GLEW/glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
	GLuint Program;
	
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath, const GLchar* geometryPath = nullptr);
	// Metodo para usar el shader
	void Use() { glUseProgram(this->Program); }

private:
	void checkCompileErrors(GLuint shader, std::string type);
};

#endif