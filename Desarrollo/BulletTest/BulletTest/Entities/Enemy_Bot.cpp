#include "Enemy_Bot.h"
#include <GraphicEngine.h>
#include <PhysicsEngine.h>
#include <PathPlanner.h>
#include <PathFollow.h>
#include <Player.h>

Enemy_Bot::Enemy_Bot(const std::string & name, RakNet::RakNetGUID guid) : Entity(-1, NULL, name, guid) ,
	life_component(this)
{
}

Enemy_Bot::~Enemy_Bot()
{
	delete sense;
}

void Enemy_Bot::inicializar()
{
	m_PathPlanner = new PathPlanner(this);
	m_PathFollow = new PathFollow(this);

	asalto = new Asalto();
	asalto->inicializar();
	asalto->cargarContenido();
	asalto->CalcularRules();

	rocket = new RocketLauncher();
	rocket->inicializar();
	rocket->cargarContenido();
	rocket->CalcularRules();

	pistola = new Pistola();
	pistola->inicializar();
	pistola->cargarContenido();
	pistola->CalcularRules();

	sniper = new Sniper();
	sniper->inicializar();
	sniper->cargarContenido();
	sniper->CalcularRules();

	listaWeapons = new Lista();

	listaWeapons->insertar(asalto);
	listaWeapons->insertar(sniper);
	listaWeapons->insertar(pistola);
	listaWeapons->insertar(rocket);
	sniper->setEquipada(true);

	sense = new SensoryMemory(this,20);

	/*
	FuzzyModule fm;

	FuzzyVariable& DistToTarget = fm.CreateFLV("DistToTarget");
	FuzzyVariable& Desirability = fm.CreateFLV("Desirability");
	FuzzyVariable& AmmoStatus = fm.CreateFLV("AmmoStatus");

	FzSet Target_Close = DistToTarget.AddLeftShoulderSet("Target_Close", 0, 25, 150);
	FzSet Target_Medium = DistToTarget.AddTriangularSet("Target_Medium", 25, 150, 300);
	FzSet Target_Far = DistToTarget.AddRightShoulderSet("Target_Far", 150, 300, 500);

	FzSet Undesirable = Desirability.AddLeftShoulderSet("Underisable", 0, 25, 50);
	FzSet Desirable = Desirability.AddTriangularSet("Desirable", 25, 50, 75);
	FzSet VeryDesirable = Desirability.AddRightShoulderSet("Target_Far", 50, 75, 100);

	FzSet Ammo_Low = AmmoStatus.AddLeftShoulderSet("Ammo_Low", 0, 0, 10);
	FzSet Ammo_Okay = AmmoStatus.AddTriangularSet("Ammo_Okay", 0, 10, 30);
	FzSet Ammo_Loads = AmmoStatus.AddRightShoulderSet("Ammo_Loads", 10, 30, 40);

	fm.AddRule(FzAND(Target_Close, Ammo_Low), Undesirable);
	fm.AddRule(FzAND(Target_Close, Ammo_Okay), Undesirable);
	fm.AddRule(FzAND(Target_Close, Ammo_Loads), Undesirable);

	fm.AddRule(FzAND(Target_Medium, Ammo_Low), Desirable);
	fm.AddRule(FzAND(Target_Medium, Ammo_Okay), VeryDesirable);
	fm.AddRule(FzAND(Target_Medium, Ammo_Loads), VeryDesirable);

	fm.AddRule(FzAND(Target_Far, Ammo_Low), Undesirable);
	fm.AddRule(FzAND(Target_Far, Ammo_Okay), Desirable);
	fm.AddRule(FzAND(Target_Far, Ammo_Loads), Desirable);

	std::cout << "Desirability: "<< calcularDesirability(fm, 25, 0); 
	std::cout << "\n";

	*/
	std::cout << "El arma actual es: " << listaWeapons->valorActual()->getClassName();
	std::cout << "\n";
	elegirWeapon();
	std::cout << "He elegido arma \n";
	std::cout << "El arma actual es: " << listaWeapons->valorActual()->getClassName();
	std::cout << "\n";

}

double Enemy_Bot::calcularDesirability(FuzzyModule& fm, double dist, double ammmo) {
	
	fm.Fuzzify("DistToTarget", dist);
	fm.Fuzzify("AmmoStatus", ammmo);

	return fm.DeFuzzify("Desirability", FuzzyModule::max_av);

}

void Enemy_Bot::elegirWeapon() {

	double DistToTarget = 100;  //TODO: Hay que hacer un metodo que calcule la distancia entre el Bot y el Player

	listaWeapons->armaMasDeseada(DistToTarget);


}

Vec3<float> Enemy_Bot::getFacing()
{
	return m_renderState.getRotation();
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

	sense->updateVision();

	
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
}

void Enemy_Bot::borrarContenido()
{
	delete m_PathFollow;
	delete m_PathPlanner;

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
	return false;
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