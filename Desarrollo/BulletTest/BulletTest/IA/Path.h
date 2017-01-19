#include <list>
#include <cassert>

#include <Vec2f.h>




class Path
{
private:

	std::list<Vec2f>            m_WayPoints;

	//current waypoint iterator
	std::list<Vec2f>::iterator  curWaypoint;


public:

	Path() {}



	//returns the current waypoint
	Vec2f CurrentWaypoint() { 
		if (!Finished()) {
			return *curWaypoint;
		}
		return m_WayPoints.back();
	}

	//returns true if the end of the list has been reached
	bool        Finished() { return !(curWaypoint != m_WayPoints.end()); }

	//moves the iterator on to the next waypoint in the list
	inline void SetNextWaypoint();


	//adds a waypoint to the end of the path
	void AddWayPoint(Vec2f new_point);

	//methods for setting the path with either another Path or a list of vectors
	void Set(std::list<Vec2f> new_path) { m_WayPoints = new_path; curWaypoint = m_WayPoints.begin(); }
	void Set(const Path& path) { m_WayPoints = path.GetPath(); curWaypoint = m_WayPoints.begin(); }


	void Clear() { m_WayPoints.clear(); }

	std::list<Vec2f> GetPath()const { return m_WayPoints; }

	//renders the path in orange
	void Render() const;
};




//-------------------- Methods -------------------------------------------

inline void Path::SetNextWaypoint()
{
	assert(m_WayPoints.size() > 0);


	if (!Finished()) {
		curWaypoint++;
	}

}



