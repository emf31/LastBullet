#pragma once
#include <btBulletCollisionCommon.h>
#include <Engine/EngineDevice.h>
#include <Util.h>

class DebugDraw : public btIDebugDraw
{

public:

	DebugDraw() :
		mode(DBG_NoDebug)//, driver(NULL)
	{

	}

	//drawLine es un metodo virtual de btIDebugDraw que es lo que enlaza en este caso Bullet con Irrlicht
	//para pintar por pantalla el modo debug(habra que cambiarlo al cambiar el motor grafico...)
	void drawLine(const btVector3& from, const btVector3& to, const btVector3& color)
	{
		//workaround to bullet's inconsistent debug colors which are either from 0.0 - 1.0 or from 0.0 - 255.0
		/*irr::video::SColor newColor(255, (irr::u32)color[0], (irr::u32)color[1], (irr::u32)color[2]);
		if (color[0] <= 1.0 && color[0] > 0.0)
			newColor.setRed((irr::u32)(color[0] * 255.0));
		if (color[1] <= 1.0 && color[1] > 0.0)
			newColor.setGreen((irr::u32)(color[1] * 255.0));
		if (color[2] <= 1.0 && color[2] > 0.0)
			newColor.setBlue((irr::u32)(color[2] * 255.0));*/

		SceneManager::i().drawLine(glm::vec3(from.getX(), from.getY(), from.getZ()), glm::vec3(to.getX(), to.getY(), to.getZ()));
	}

	void drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color)
	{
		/*static const irr::video::SColor CONTACTPOINT_COLOR(255, 255, 255, 0); //bullet's are black :(

																			  //   this->drawLine(PointOnB, PointOnB + normalOnB*distance, CONTACTPOINT_COLOR);

		const btVector3 to(PointOnB + normalOnB*distance);

		this->driver->draw3DLine(
			irr::core::vector3df(PointOnB[0], PointOnB[1], PointOnB[2]),
			irr::core::vector3df(to[0], to[1], to[2]),
			CONTACTPOINT_COLOR);*/
	}

	void reportErrorWarning(const char* text)
	{
		//this->logger->log(text, irr::ELL_ERROR);
	}

	void draw3dText(const btVector3& location, const char* text) { }

	void setDebugMode(int mode) { this->mode = mode; }

	int getDebugMode() const { return this->mode; }

private:

	int mode;

	//EngineDevice* const driver;

};