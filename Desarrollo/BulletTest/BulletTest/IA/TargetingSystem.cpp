#include "TargetingSystem.h"
#include "Enemy_Bot.h"




TargetingSystem::TargetingSystem(Enemy_Bot* owner) :
	m_pOwner(owner)
{
}

void TargetingSystem::Update()
{


	double ClosestDistSoFar = MaxDouble;
	m_pCurrentTarget = 0;

	//grab a list of all the opponents the owner can sense

	std::list<Character*> SensedBots;
	SensedBots = m_pOwner->GetSensoryMemory()->GetListOfRecentlySensedEnemies();


	std::list<Character*>::const_iterator curBot = SensedBots.begin();
	for (curBot; curBot != SensedBots.end(); ++curBot)
	{

		//make sure the bot is alive and that it is not the owner
		if (*curBot != m_pOwner)//TODO Hay que comprobar que el target tenga vida mayor que 0: (*curBot)->getLifeComponent().getVida()>0) && 
		{



			float distancia = Vec3<float>::getDistance((*curBot)->getRenderState()->getPosition(), m_pOwner->getRenderState()->getPosition());

			if (distancia < ClosestDistSoFar)
			{
				ClosestDistSoFar = distancia;
				m_pCurrentTarget = *curBot;
			}

		}


	}

	if (m_pCurrentTarget != 0)
		m_pOwner->lookAt(vec3ToVec2(m_pCurrentTarget->getRenderState()->getPosition()));

}


TargetingSystem::~TargetingSystem()
{
}

bool TargetingSystem::isTargetWithinFOV()const
{
	return m_pOwner->GetSensoryMemory()->isEnemyInFOV(m_pCurrentTarget);
}

bool TargetingSystem::isTargetShootable()const
{
	return m_pOwner->GetSensoryMemory()->isEnemyShootable(m_pCurrentTarget);
}

Vec3<float> TargetingSystem::GetLastRecordedPosition()const
{
	return m_pOwner->GetSensoryMemory()->GetLastRecordedPositionOfOpponent(m_pCurrentTarget);
}

double TargetingSystem::GetTimeTargetHasBeenVisible()const
{
	return m_pOwner->GetSensoryMemory()->GetTimeOpponentHasBeenVisible(m_pCurrentTarget);
}

double TargetingSystem::GetTimeTargetHasBeenOutOfView()const
{
	return m_pOwner->GetSensoryMemory()->GetTimeOpponentHasBeenOutOfView(m_pCurrentTarget);
}
