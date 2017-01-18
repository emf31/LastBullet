#include "PathFollow.h"
#include <Enemy_Bot.h>
#include <Map.h>
PathFollow::PathFollow(Enemy_Bot * bot)
{
	m_owner = bot;
}

Vec2f PathFollow::Calculate()
{

	//Si se cumple hemos llegado al objetivo
	if (m_owner->isAtPosition(m_vTarget) && !m_currentPath->empty()) {

		//Marcamos como objetivo actual el siguiente nodo del camino
		m_vTarget = m_currentPath->front();

		//Como es nuestro objetivo lo eliminamos ya de la lista
		m_currentPath->pop_front();

		//Es el ultimo nodo
		if (m_currentPath->size() == 0) {
			ArriveOn();
		}
	}


	Vec2f direction;

	if (m_cBehaviour == seek) {
		direction = Seek(m_vTarget);
	}
	else if (m_cBehaviour == arrive) {
		direction = Arrive(m_vTarget);
	}


	return direction;
}

Vec2f PathFollow::Seek(const Vec2f & target)
{
	Vec2f dir(target - vec3ToVec2(m_owner->getRenderState()->getPosition()));

	return dir.Normalize();
}

Vec2f PathFollow::Arrive(const Vec2f & target)
{

	Vec2f ToTarget = target - vec3ToVec2(m_owner->getRenderState()->getPosition());

	//calculate the distance to the target
	double dist = ToTarget.Magnitude();


	if (dist > 3)
	{
		return ToTarget.Normalize();
	}

	return Vec2f(0, 0);
}
