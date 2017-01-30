#include <list>
#include <cassert>

#include <Vec2f.h>




class Path
{
private:

	std::list<Vec2f> m_WayPoints;

	std::list<Vec2f>::iterator curWaypoint;


public:

	Path() {}


	Vec2f CurrentWaypoint() { 
		if (!Finished()) {
			return *curWaypoint;
		}
		return m_WayPoints.back();
	}

	bool        Finished() { return !(curWaypoint != m_WayPoints.end()); }

	inline void SetNextWaypoint();


	void Set(std::list<Vec2f> new_path) { m_WayPoints = new_path; curWaypoint = m_WayPoints.begin(); }
	void Set(const Path& path) { m_WayPoints = path.GetPath(); curWaypoint = m_WayPoints.begin(); }


	void Clear() { m_WayPoints.clear(); }

	std::list<Vec2f> GetPath()const { return m_WayPoints; }


};



void Path::SetNextWaypoint()
{
	assert(m_WayPoints.size() > 0);


	if (!Finished()) {
		curWaypoint++;
	}

}



