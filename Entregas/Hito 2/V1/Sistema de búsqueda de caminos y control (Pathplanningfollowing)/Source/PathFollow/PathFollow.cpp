#include "PathFollow.h"
#include <Enemy_Bot.h>
#include <Map.h>
#include <Util.h>

PathFollow::PathFollow(Enemy_Bot * bot)
{
	m_owner = bot;

	//creamos un Path
	m_pPath = new Path();
}

PathFollow::~PathFollow()
{
	delete m_pPath;
}

Vec2f PathFollow::Calculate()
{

	Vec2f direction;

	if (m_cBehaviour == follow_path) {
		direction = FollowPath();
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

	double dist = ToTarget.Magnitude();


	if (dist > 5)
	{
		return ToTarget.Normalize();
	}

	return Vec2f(0, 0);
}

Vec2f PathFollow::FollowPath()
{
	if (m_owner->isAtPosition(m_pPath->CurrentWaypoint()))
	{
		m_pPath->SetNextWaypoint();
	}

	if (!m_pPath->Finished())
	{
		return Seek(m_pPath->CurrentWaypoint());
	}

	else
	{
		return Arrive(m_pPath->CurrentWaypoint());
	}

}
