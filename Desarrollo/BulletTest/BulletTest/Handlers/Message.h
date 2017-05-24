#pragma once

#include <string>
//Fordward declaration (es mejor porque solo declara el tipo y no incluye todo el fichero)
class Entity;

struct Message {
	Entity* entity;							//Entidad que recibe
	std::string mensaje;					//Mensaje
	void* data;								//Por si quieres pasar algo(es void* para que puedas pasar cualquier tipo)

	Message(Entity* entity, const std::string& mensaje, void* data) :
		entity(entity), 
		mensaje(mensaje),
		data(data)
	{
	}
	Message() {
		
	}
};

