
#include <Vec2f.h>

class Enemy_Bot;

class PathFollow {
public:
	PathFollow(Enemy_Bot* bot);

	void setTarget();

private:
	Enemy_Bot* m_owner;

	
};