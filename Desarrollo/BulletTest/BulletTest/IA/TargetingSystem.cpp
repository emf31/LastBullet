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

	std::list<Entity*> SensedBots;
	SensedBots = m_pOwner->GetSensoryMemory()->GetListOfRecentlySensedEnemies();

	std::list<Entity*>::const_iterator curBot = SensedBots.begin();
	for (curBot; curBot != SensedBots.end(); ++curBot)
	{
		//make sure the bot is alive and that it is not the owner
		if (*curBot != m_pOwner)//TODO Hay que comprobar que el target tenga vida mayor que 0: (*curBot)->getLifeComponent().getVida()>0) && 
		{

			/*double dist = Vec2DDistanceSq((*curBot)->getRenderPosition(), m_pOwner->getRenderPosition());//TODO Pasar a 3dimensiones

			if (dist < ClosestDistSoFar)
			{
				ClosestDistSoFar = dist;
				m_pCurrentTarget = *curBot;
			}*/
		}
	}
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
/*
Vector2D TargetingSystem::GetLastRecordedPosition()const
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
}*/