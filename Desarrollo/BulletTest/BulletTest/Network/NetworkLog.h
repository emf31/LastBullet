#pragma once

#include <iostream>
#include <unordered_map>
#include <RakNetTypes.h>
#include <vec3.hpp>

class NetworkLog
{
	struct TClientEntity {
		RakNet::RakNetGUID guid;
		std::string classType;
		std::string name;
		Vec3<float> position;
		int localID;
		bool available;
	};

public:
	std::string generarTabla();
	std::string updateAndGenerateTable();

private:
	std::unordered_map<unsigned long, TClientEntity> m_tabla;

	std::string generarFila(TClientEntity& fila);

	void updatearTabla();

	std::string vec3ToString(Vec3<float> &vec);
};

