#include "PathFollow.h"
#include <Enemy_Bot.h>
#include <Map.h>
#include <Util.h>

PathFollow::PathFollow(Enemy_Bot * bot)
{
	m_owner = bot;

	m_cBehaviour = stop;
	//creamos un Path
	m_pPath = new Path();
}

PathFollow::~PathFollow()
{
	delete m_pPath;
}

Vec2f PathFollow::Calculate()
{

	Vec2f direction(0,0);

	if (m_cBehaviour == follow_path) {
		direction = FollowPath();
	}

	if (m_cBehaviour == stop) {
		direction.x = 0;
		direction.y = 0;
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


	if (dist > 1)
	{
		return ToTarget.Normalize();
	}

	return Vec2f(0, 0);
}

Vec2f PathFollow::FollowPath()
{
	if (m_owner->isAtPosition(vec3ToVec2 (m_pPath->CurrentWaypoint())))
	{
		m_pPath->SetNextWaypoint();
	}

	if (!m_pPath->Finished())
	{
		return Seek(vec3ToVec2(m_pPath->CurrentWaypoint()));
	}

	else
	{
		return Arrive(vec3ToVec2 (m_pPath->CurrentWaypoint()));
	}

}