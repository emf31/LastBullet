#include <Enemy_Bot.h>
#include <GraphicEngine.h>
#include <PhysicsEngine.h>
#include <PathPlanner.h>
#include <PathFollow.h>
#include <Player.h>
#include <MachineState.h>
#include <StatesIA\Patrullar.h>
#include <StatesIA\BuscarVida.h>
#include <Map.h>
#include <TriggerSystem.h>

Enemy_Bot::Enemy_Bot(const std::string & name, RakNet::RakNetGUID guid) : Entity(-1, NULL, name, guid) ,
	life_component(this)
{
	dwTriggerFlags = kTrig_EnemyShootSound;
	TriggerSystem::i().RegisterEntity(this);
}

Enemy_Bot::~Enemy_Bot()
{
	
}

void Enemy_Bot::inicializar()
{

	crearFuzzyRules();

	m_PathPlanner = new PathPlanner(this);
	m_PathFollow = new PathFollow(this);


	targetingSystem = new TargetingSystem(this);

	weaponSystem = new WeaponSystem(this, 1,400, 20);
	weaponSystem->Inicializar();

	m_pStateMachine = new MachineState(this);
	m_pStateMachine->SetCurrentState(&Patrullar::i());
	//m_pStateMachine->SetGlobalState(&Patrullar::i());

	sense = new SensoryMemory(this,20);

	//angulo de vision
	FOV = DegToRad(45) ;


}


void Enemy_Bot::lookAt(Vec2f at) {

	m_vHeading = at - vec3ToVec2(m_renderState.getPosition());

	float angle = std::atan2(m_vHeading.x, m_vHeading.y);

	m_renderState.updateRotations(Vec3<float>(0, RadToDeg(angle), 0));

}

Vec2f Enemy_Bot::getFacing()
{
	return m_vHeading;
}

float Enemy_Bot::getFOV()
{
	return FOV;
}

void Enemy_Bot::update(Time elapsedTime)
{

	updateAnimation();

	updateMovement();

	life_component.update();

	p_controller->updateAction(PhysicsEngine::i().m_world, elapsedTime.asSeconds());


	m_renderState.updatePositions(Vec3<float>(
		p_controller->getGhostObject()->getWorldTransform().getOrigin().x(),
		p_controller->getGhostObject()->getWorldTransform().getOrigin().y() - (height / 2) - p_controller->getStepHeight() / 2,
		p_controller->getGhostObject()->getWorldTransform().getOrigin().z()));


	float angle = std::atan2(m_vHeading.x, m_vHeading.y);

	m_renderState.updateRotations(Vec3<float>(0, RadToDeg(angle), 0));

	targetingSystem->Update();
	sense->updateVision();


	weaponSystem->TakeAimAndShoot();

	if (!this->getMachineState()->isInState("BuscarVida"))
	FuzzyLifeObject();

	m_pStateMachine->Update();
	
}

void Enemy_Bot::handleInput()
{
}

void Enemy_Bot::cargarContenido()
{

	//Creas el nodo(grafico)
	m_nodo = GraphicEngine::i().createAnimatedNode(Vec3<float>(0, 100, 0), Vec3<float>(0.05f, 0.05f, 0.05f), "", "../media/ArmyPilot.b3d");
	m_nodo.get()->setTexture("../media/body01.png", 1);
	m_nodo.get()->setTexture("../media/head01.png", 0);
	m_nodo.get()->setTexture("../media/m4tex.png", 2);

	GraphicEngine::i().createBillboardText(m_nodo, m_name, Vec2f(100, 10), Vec3<float>(0, 30, 0));

	animation.addAnimation("Default", 0, 0);
	animation.addAnimation("Run_Forwards", 1, 69);
	animation.addAnimation("Run_backwards", 70, 138);
	animation.addAnimation("Walk", 139, 183);
	animation.addAnimation("Jump", 184, 219);
	animation.addAnimation("Jump2", 184, 219);
	animation.addAnimation("Idle", 220, 472);
	animation.addAnimation("AimRunning", 473, 524);

	m_animState = andando;

	radius = 1.2f;
	height = 7.3f;
	mass = 70.f;


	//m_rigidBody = PhysicsEngine::i().createBoxRigidBody(this, Vec3<float>(5.f, 5.f, 5.f), mass, false, Vec3<float>(0,0,0), DISABLE_DEACTIVATION);

	/*btBroadphaseProxy* proxy = m_rigidBody->getBroadphaseProxy();
	proxy->m_collisionFilterGroup = col::Collisions::Enemy;
	proxy->m_collisionFilterMask = col::enemyCollidesWith;*/

	p_controller = PhysicsEngine::i().createCapsuleKinematicCharacter(this, radius, height, mass);


	btBroadphaseProxy* proxy = p_controller->getGhostObject()->getBroadphaseHandle();
	proxy->m_collisionFilterGroup = col::Collisions::Enemy;
	proxy->m_collisionFilterMask = col::enemyCollidesWith;

	

	p_controller->m_acceleration_walk = 4.3f;
	p_controller->m_deceleration_walk = 6.5f;
	p_controller->m_maxSpeed_walk = 2.f;

	setPosition(Map::i().searchSpawnPoint());
	lookAt(Vec2f(0, 0));

}

void Enemy_Bot::borrarContenido()
{
	delete m_PathFollow;
	delete m_PathPlanner;
	delete sense;
	delete weaponSystem;
	delete targetingSystem;

	PhysicsEngine::i().removeKinematic(p_controller);

	GraphicEngine::i().removeNode(m_nodo);
}

void Enemy_Bot::handleMessage(const Message & message)
{
	if (message.mensaje == "COLISION_BALA") {
		if (life_component.isDying() == false) {
			//TODO si la IA esta en el server habra que cambiar esta funcion
			//Este float * es una referencia a una variable de clase asi que no hay problema
			/*TImpactoBala impacto;
			impacto.damage = *static_cast<float*>(message.data);
			impacto.guid = m_guid;

			Cliente::i().dispatchMessage(impacto, IMPACTO_BALA);*/

			life_component.restaVida(*static_cast<float*>(message.data));


			static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->relojHit.restart();
		}
	}
	
}

bool Enemy_Bot::handleTrigger(TriggerRecordStruct * Trigger)
{
	Entity* ent = EntityManager::i().getEntity(Trigger->idSource);
	if (ent->getID() != m_id && Trigger->eTriggerType == kTrig_EnemyShootSound) {
		printf("Trigger tipo sonido de arma enemigo\n");
		sense->updateSound(ent);
	}
	return true;
}

void Enemy_Bot::setPosition(const Vec3<float>& pos)
{
	p_controller->reset(PhysicsEngine::i().m_world);
	m_renderState.setPosition(pos);
	p_controller->warp(btVector3(pos.getX(), pos.getY(), pos.getZ()));
	m_nodo->setPosition(pos);
}



//Devuelve true si el bot esta en esa posicion

bool Enemy_Bot::isAtPosition(Vec2f pos)
{
	const static double tolerance = 3.0;
	Vec2f curr_pos = vec3ToVec2(m_renderState.getPosition());

	return Vec2f(curr_pos - pos).Magnitude() < tolerance * tolerance;
}

void Enemy_Bot::updateMovement()
{
	if (life_component.isDying() == false) {
		Vec2f direccion = m_PathFollow->Calculate();

		if (!direccion.Zero()) {
			m_vHeading = direccion;
		}


		btVector3 vel = btVector3(direccion.x, 0, direccion.y);

		p_controller->setWalkDirection(vel);
	}
	else {
		p_controller->reset(PhysicsEngine::i().m_world);
	}
	
	
}

void Enemy_Bot::createPathToPosition(Vec2f vec) {


	//Camino actual a seguir
	std::list<Vec2f> m_camino;

	m_PathPlanner->CreatePathToPosition(vec, m_camino);

	m_PathFollow->SetPath(m_camino);

	m_PathFollow->FollowOn();

}

void Enemy_Bot::createPathToItem(const std::string& tipo)
{

	//Camino actual a seguir
	std::list<Vec2f> m_camino;

	m_PathPlanner->CreatePathToItem(tipo, m_camino);

	m_PathFollow->SetPath(m_camino);

	m_PathFollow->FollowOn();
}

void Enemy_Bot::updateAnimation()
{
	/*switch (m_animState)
	{
	case quieto:
		if (animation.getActualAnimation() != "Idle") {
			m_nodo.get()->setAnimation(animation.getAnimationStart("Idle"), animation.getAnimationEnd("Idle"));
		}
		break;

	case andando:
		if (animation.getActualAnimation() != "Walk") {
			m_nodo.get()->setAnimation(animation.getAnimationStart("Walk"), animation.getAnimationEnd("Walk"));
		}
		break;

	case saltando:
		if (animation.getActualAnimation() != "Jump") {
			m_nodo.get()->setAnimation(animation.getAnimationStart("Jump"), animation.getAnimationEnd("Jump"));
		}
		break;
	case saltando2:
		if (animation.getActualAnimation() != "Jump2") {
			m_nodo.get()->setAnimation(animation.getAnimationStart("Jump2"), animation.getAnimationEnd("Jump2"));
		}
		break;

	}*/
}

void Enemy_Bot::crearFuzzyRules() {


	//LifeDrop


	fm.AddRule(FzAND(Life_Low, Life_LowTarget), UndesirableLifeDrop);
	fm.AddRule(FzAND(Life_Low, Life_OkayTarget), DesirableLifeDrop);
	fm.AddRule(FzAND(Life_Low, Life_LoadsTarget), VeryDesirableLifeDrop);

	fm.AddRule(FzAND(Life_Okay, Life_LowTarget), UndesirableLifeDrop);
	fm.AddRule(FzAND(Life_Okay, Life_OkayTarget), UndesirableLifeDrop);
	fm.AddRule(FzAND(Life_Okay, Life_LoadsTarget), DesirableLifeDrop);

	fm.AddRule(FzAND(Life_Loads, Life_LowTarget), UndesirableLifeDrop);
	fm.AddRule(FzAND(Life_Loads, Life_OkayTarget), UndesirableLifeDrop);
	fm.AddRule(FzAND(Life_Loads, Life_LoadsTarget), UndesirableLifeDrop);

	//Asalto

	fm.AddRule(FzAND(Target_Close, Ammo_LowAsalto), DesirableAsalto);
	fm.AddRule(FzAND(Target_Close, Ammo_OkayAsalto), VeryDesirableAsalto);
	fm.AddRule(FzAND(Target_Close, Ammo_LoadsAsalto), VeryDesirableAsalto);

	fm.AddRule(FzAND(Target_Medium, Ammo_LowAsalto), UndesirableAsalto);
	fm.AddRule(FzAND(Target_Medium, Ammo_OkayAsalto), DesirableAsalto);
	fm.AddRule(FzAND(Target_Medium, Ammo_LoadsAsalto), DesirableAsalto);

	fm.AddRule(FzAND(Target_Far, Ammo_LowAsalto), UndesirableAsalto);
	fm.AddRule(FzAND(Target_Far, Ammo_OkayAsalto), UndesirableAsalto);
	fm.AddRule(FzAND(Target_Far, Ammo_LoadsAsalto), UndesirableAsalto);

	//Sniper

	fm.AddRule(FzAND(Target_Close, Ammo_LowSniper), UndesirableSniper);
	fm.AddRule(FzAND(Target_Close, Ammo_OkaySniper), UndesirableSniper);
	fm.AddRule(FzAND(Target_Close, Ammo_LoadsSniper), UndesirableSniper);

	fm.AddRule(FzAND(Target_Medium, Ammo_LowSniper), UndesirableSniper);
	fm.AddRule(FzAND(Target_Medium, Ammo_OkaySniper), UndesirableSniper);
	fm.AddRule(FzAND(Target_Medium, Ammo_LoadsSniper), DesirableSniper);

	fm.AddRule(FzAND(Target_Far, Ammo_LowSniper), VeryDesirableSniper);
	fm.AddRule(FzAND(Target_Far, Ammo_OkaySniper), VeryDesirableSniper);
	fm.AddRule(FzAND(Target_Far, Ammo_LoadsSniper), VeryDesirableSniper);


}

void Enemy_Bot::elegirWeapon(float Dist) {

	double mejorScore = 0;
	std::string bestWeapon = "Pistola";

	double DistToTarget = Dist;

	fm.Fuzzify("DistToTarget", DistToTarget);

	if (weaponSystem->buscar("Asalto")) {

		fm.Fuzzify("AmmoStatusAsalto", weaponSystem->getAmmoAsalto());

		double DesAsalto = fm.DeFuzzify("DesirabilityAsalto", FuzzyModule::max_av);


		if (DesAsalto > mejorScore) {
			mejorScore = DesAsalto;
			bestWeapon = "Asalto";
		}

	}

	if (weaponSystem->buscar("Sniper")) {

		fm.Fuzzify("AmmoStatusSniper", weaponSystem->getAmmoSniper());

		double DesSniper = fm.DeFuzzify("DesirabilitySniper", FuzzyModule::max_av);


		if (DesSniper > mejorScore) {
			mejorScore = DesSniper;
			bestWeapon = "Sniper";
		}


	}


	weaponSystem->Equipar(bestWeapon);
}

void Enemy_Bot::FuzzyLifeObject() {



	fm.Fuzzify("Life", life_component.getVida());
	fm.Fuzzify("LifeTarget", damageTarget);

	double k = fm.DeFuzzify("DesirabilityLifeDrop", FuzzyModule::max_av);
	//std::cout << "Valor FuzzyLifeObject: " << k << std::endl;

	if (fm.DeFuzzify("DesirabilityLifeDrop", FuzzyModule::max_av)>40) {
		m_pStateMachine->SetCurrentState(&BuscarVida::i());
	}


}