
#include <Vec2f.h>
#include <list>
#include <Path.h>


enum behaviour_type {
	seek = 0,
	arrive = 1,
	follow_path = 2
};

//used in path following
const float WaypointSeekDist = 2;

class Enemy_Bot;

class PathFollow {
public:
	PathFollow(Enemy_Bot* bot);
	~PathFollow();

	Vec2f Calculate();

	void   SetTarget(Vec2f& t) { m_vTarget = t; }
	Vec2f  Target()const { return m_vTarget; }

	void  SetPath(std::list<Vec2f>& new_path) { m_pPath->Set(new_path); }

	//void SeekOn() { m_cBehaviour = seek; }
	//void ArriveOn() { m_cBehaviour = arrive; }
	void FollowOn() { m_cBehaviour = follow_path; }

	//this behavior moves the agent towards a target position
	Vec2f Seek(const Vec2f &target);

	//this behavior is similar to seek but it attempts to arrive 
	//at the target with a zero velocity
	Vec2f Arrive(const Vec2f    &target);

	Vec2f FollowPath();


private:
	Enemy_Bot* m_owner;
	
	//Current Target
	Vec2f m_vTarget;

	//current behaviour
	behaviour_type m_cBehaviour;

	//curren path
	Path* m_pPath;

	//Distancia a la que alcanzas un waypoint
	float m_dWaypointSeekDistSq;
	

};