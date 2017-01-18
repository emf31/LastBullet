#include "PathFollow.h"
#include <Enemy_Bot.h>

PathFollow::PathFollow(Enemy_Bot * bot)
{
	m_owner = bot;
}

void PathFollow::update()
{

	if (m_cBehaviour == seek) {
		Seek(m_vTarget);
	}
	else if (m_cBehaviour == arrive) {
		Arrive(m_vTarget);
	}


}

Vec2f PathFollow::Seek(const Vec2f & target)
{
	return Vec2f();
}

Vec2f PathFollow::Arrive(const Vec2f & target)
{
	return Vec2f();
}
