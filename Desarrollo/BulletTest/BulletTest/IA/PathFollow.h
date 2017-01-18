
#include <Vec2f.h>


enum behaviour_type {
	seek = 0,
	arrive = 1
};

class Enemy_Bot;

class PathFollow {
public:
	PathFollow(Enemy_Bot* bot);

	void update();

	void      SetTarget(Vec2f t) { m_vTarget = t; }
	Vec2f  Target()const { return m_vTarget; }

	void SeekOn() { m_cBehaviour = seek; }
	void ArriveOn() { m_cBehaviour = arrive; }

	//this behavior moves the agent towards a target position
	Vec2f Seek(const Vec2f &target);

	//this behavior is similar to seek but it attempts to arrive 
	//at the target with a zero velocity
	Vec2f Arrive(const Vec2f    &target);


private:
	Enemy_Bot* m_owner;
	
	//Current Target
	Vec2f m_vTarget;

	//current behaviour
	behaviour_type m_cBehaviour;
	
};