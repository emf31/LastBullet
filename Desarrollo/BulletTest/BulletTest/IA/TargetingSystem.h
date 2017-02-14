#pragma once
#include "Entity.h"

class Enemy_Bot;


class TargetingSystem
{
public:
	TargetingSystem(Enemy_Bot* owner);
	~TargetingSystem();

	void       Update();

	bool       isTargetPresent()const { return m_pCurrentTarget != 0; }

	bool       isTargetWithinFOV()const;

	bool       isTargetShootable()const;

	Vec3<float>   GetLastRecordedPosition()const;

	double      GetTimeTargetHasBeenVisible()const;

	double      GetTimeTargetHasBeenOutOfView()const;

	Entity* GetTarget()const { return m_pCurrentTarget; }

	void       ClearTarget() { m_pCurrentTarget = 0; }
private:
	
	Enemy_Bot* m_pOwner;
	Entity* m_pCurrentTarget;

};

