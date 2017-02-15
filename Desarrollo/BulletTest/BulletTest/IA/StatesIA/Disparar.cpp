#include "Disparar.h"
#include "Enemy_Bot.h"
#include "PathFollow.h"


void Disparar::Enter(Enemy_Bot* pEnemy) {

}

void Disparar::Execute(Enemy_Bot* pEnemy) {


	pEnemy->getPathFollow()->FollowOff();



}

void Disparar::Exit(Enemy_Bot* pEnemy) {

}
