#include "PathFollow.h"
#include <Enemy_Bot.h>

PathFollow::PathFollow(Enemy_Bot * bot)
{
	m_owner = bot;
}

Vec2f PathFollow::Calculate()
{

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
	dir = dir.Normalize();

	return dir;
}

Vec2f PathFollow::Arrive(const Vec2f & target)
{

	Vec2f ToTarget = target - vec3ToVec2(m_owner->getRenderState()->getPosition());

	//calculate the distance to the target
	double dist = ToTarget.Magnitude();


	if (dist > 1)
	{
		return ToTarget.Normalize();
	}

	return Vec2f(0, 0);
}
