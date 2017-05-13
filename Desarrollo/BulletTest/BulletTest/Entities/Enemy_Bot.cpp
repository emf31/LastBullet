#include <Enemy_Bot.h>
#include <GraphicEngine.h>
#include <PhysicsEngine.h>
#include <PathPlanner.h>
#include <PathFollow.h>
#include <Player.h>

#include <NetworkManager.h>
#include <Color4f.h>

#include <MachineState.h>
#include <StatesIA\Patrullar.h>
#include <StatesIA\BuscarVida.h>
#include <StatesIA\BuscarWeapon.h>
#include <Map.h>
#include <TriggerSystem.h>
#include <LogIA.h>

Enemy_Bot::Enemy_Bot(const std::string & name, RakNet::RakNetGUID guid) : Character(-1, NULL, name, guid)
{
	//Creates object to send and receive packets
	m_network.reset();
	m_network = NetworkManager::i().createNetBot(this);

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

	weaponSystem = new WeaponSystem(this, 1, 2, 20);

	weaponSystem->Inicializar();

	Camera* camaraBot = GraphicEngine::i().createCamera(m_name, Vec3<float>(10, 10, 10), Vec3<float>(0, 0, 0));
	camaraBot->asignarEntity(this);



	sense = new SensoryMemory(this,20);

	//angulo de vision
	FOV = DegToRad(45) ;


	m_pStateMachine = new MachineState(this);
	//m_pStateMachine->SetGlobalState(&Patrullar::i());
	//GraphicEngine::i().setActiveCamera("CamaraAerea");

}

void Enemy_Bot::resetAll() {



	weaponSystem->WeaponSystemResetAll();

	life_component->resetVida();

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


	if (valorCiclos < 25) {

		++ciclo;

		if (ciclo == valorCiclos) {

			ciclo = 0;

			updateAnimation();

			updateMovement();

			life_component->update();

			p_controller->updateAction(PhysicsEngine::i().m_world, elapsedTime.asSeconds());


			m_renderState.updatePositions(Vec3<float>(
				p_controller->getGhostObject()->getWorldTransform().getOrigin().x(),
				p_controller->getGhostObject()->getWorldTransform().getOrigin().y() - (height / 2) - radius,
				p_controller->getGhostObject()->getWorldTransform().getOrigin().z()));

			targetingSystem->Update();
			sense->updateVision();

			weaponSystem->TakeAimAndShoot();

			if (!this->getMachineState()->isInState("BuscarVida"))
				FuzzyLifeObject();

			m_pStateMachine->Update();


			if (GraphicEngine::i().getActiveCamera()->getNameCamera() == m_name) {

				Vec3<float> posCam = GraphicEngine::i().getActiveCamera()->getPosition();

				GraphicEngine::i().setTargetActiveCamera(Vec3<float>(m_vHeading.x + m_renderState.getRenderPos().getX(), m_renderState.getRenderPos().getY(), m_vHeading.y + m_renderState.getRenderPos().getZ()));
				std::cout << "TargetCamara" << m_vHeading.x + posCam.getX() << " " << posCam.getY() << " " << m_vHeading.y + posCam.getZ() << std::endl;
				

			}
			//GraphicEngine::i().createNode((Vec3<float>(m_vHeading.x  + m_renderState.getRenderPos().getX(), m_renderState.getRenderPos().getY(), m_vHeading.y  + m_renderState.getRenderPos().getZ())), Vec3<float>(1.f, 1.f, 1.f), "", "../media/box.obj");
			
			if (m_network->isConnected()) {

				unsigned char useTimeStamp; // Assign this to ID_TIMESTAMP
				RakNet::Time timeStamp; // Put the system time in here returned by RakNet::GetTime()
				unsigned char typeId; // This will be assigned to a type I've added after ID_USER_PACKET_ENUM, lets say ID_SET_TIMED_MINE
				bool isDying;
				Vec3<float> position;
				Vec3<float> rotation;
				RakNet::RakNetGUID guid;

				useTimeStamp = ID_TIMESTAMP;
				timeStamp = RakNet::GetTime();
				typeId = MOVIMIENTO;
				RakNet::BitStream myBitStream;
				myBitStream.Write(useTimeStamp);
				myBitStream.Write(timeStamp);
				myBitStream.Write(typeId);
				myBitStream.Write(getLifeComponent().isDying());
				myBitStream.Write(getRenderState()->getPosition());
				myBitStream.Write(getRenderState()->getRotation());
				myBitStream.Write(getGuid());

				m_network->peer->Send(&myBitStream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, m_network->getServerGUID(), false);

			}
		}

		if (m_renderState.getPosition().getY() < -200) {
			getLifeComponent().restaVida(100, m_guid);
		}

	}



	
}

void Enemy_Bot::handleInput()
{

}

void Enemy_Bot::cargarContenido()
{

	//Creas el nodo(grafico)
	m_nodo = GraphicEngine::i().createNode(Vec3<float>(0, 100, 0), Vec3<float>(0.075f, 0.075f, 0.075f), "", "../media/Personaje/personaje.obj");
	//m_nodo->setTexture("../media/body01.png", 1);
	//m_nodo->setTexture("../media/head01.png", 0);
	//m_nodo->setTexture("../media/m4tex.png", 2);

	//nodo, size, relposition, color
	//GraphicEngine::i().createBillboardText(m_nodo, m_name, Vec2f(9, 3), Vec3<float>(0, 250, 0), Color4f(255, 0, 255, 0));

	animation.addAnimation("Default", 0, 0);
	animation.addAnimation("Run_Forwards", 1, 69);
	animation.addAnimation("Run_backwards", 70, 138);
	animation.addAnimation("Walk", 139, 183);
	animation.addAnimation("Jump", 184, 219);
	animation.addAnimation("Jump2", 184, 219);
	animation.addAnimation("Idle", 220, 472);
	animation.addAnimation("AimRunning", 473, 524);

	m_animState = andando;

	radius = 0.5f;
	height = 3.f;
	mass = 70.f;


	p_controller = PhysicsEngine::i().createCapsuleKinematicCharacter(this, radius, height, mass);


	btBroadphaseProxy* proxy = p_controller->getGhostObject()->getBroadphaseHandle();
	proxy->m_collisionFilterGroup = col::Collisions::Bot;
	proxy->m_collisionFilterMask = col::BotCollidesWith;

	

	p_controller->m_acceleration_walk = 0.8f;
	p_controller->m_deceleration_walk = 5.f;
	p_controller->m_maxSpeed_walk = 0.7f;

	setPosition(Map::i().searchSpawnPoint());

	lookAt(Vec2f(0, 0));

	m_pStateMachine->SetCurrentState(&BuscarWeapon::i());


}

void Enemy_Bot::borrarContenido()
{
	delete m_PathFollow;
	delete m_PathPlanner;
	delete sense;
	delete weaponSystem;
	delete targetingSystem;

	PhysicsEngine::i().removeKinematic(p_controller);


}

void Enemy_Bot::handleMessage(const Message & message)
{
	if (message.mensaje == "COLISION_BALA") {
		if (life_component->isDying() == false) {

			TImpactoBala impacto = *static_cast<TImpactoBala*>(message.data);

			getLifeComponent().restaVida(impacto.damage, impacto.guidDisparado);

			static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->relojHit.restart();

		}
	}
	else if (message.mensaje == "COLISION_ROCKET") {
		NetworkManager::i().dispatchMessage(*(TImpactoRocket*)message.data, IMPACTO_ROCKET);
		delete message.data;

		static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->relojHit.restart();
	}
	else if (message.mensaje == "MATASTE") {
		decisionAfterKill();
	}
	else if (message.mensaje == "COLISION_GRANADA") {
		TImpactoRocket granada = *static_cast<TImpactoRocket*>(message.data);
		getLifeComponent().restaVida(granada.damage, granada.guidDisparado);
		static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->relojHit.restart();
	}
	
}

bool Enemy_Bot::handleTrigger(TriggerRecordStruct * Trigger)
{
	Entity* ent = EntityManager::i().getEntity(Trigger->idSource);
	if (ent->getID() != m_id && Trigger->eTriggerType == kTrig_EnemyShootSound) {

		sense->updateSound(static_cast<Character*>(ent));
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

void Enemy_Bot::impulsar(Vec3<float> force)
{
	btVector3 fuerza(force.getX(), force.getY(), force.getZ());
	p_controller->applyImpulse(fuerza);
}



//Devuelve true si el bot esta en esa posicion

bool Enemy_Bot::isAtPosition(Vec2f pos)
{
	const static double tolerance = 0.7;
	Vec2f curr_pos = vec3ToVec2(m_renderState.getPosition());

	return Vec2f(curr_pos - pos).Magnitude() < tolerance * tolerance;
}

void Enemy_Bot::updateMovement()
{
	if (life_component->isDying() == false) {
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

void Enemy_Bot::lookAt(Vec2f at) {

	m_vHeading = at - vec3ToVec2(m_renderState.getPosition());

	float angle = std::atan2(m_vHeading.x, m_vHeading.y);

	m_renderState.updateRotations(Vec3<float>(0, RadToDeg(angle), 0));

}

void Enemy_Bot::updateFacing()
{
	float angle = std::atan2(m_vHeading.x, m_vHeading.y);

	m_renderState.updateRotations(Vec3<float>(0, RadToDeg(angle), 0));
}

Vec2f Enemy_Bot::createPathToPosition(Vec3<float> vec) {


	//Camino actual a seguir
	std::list<Vec3<float>> m_camino;

	m_PathPlanner->CreatePathToPosition(vec, m_camino);

	m_PathFollow->SetPath(m_camino);

	m_PathFollow->FollowOn();
	LogIA::log.push_back("CreatePathToPosition" + std::to_string(m_camino.back().getX()) + " " + std::to_string(m_camino.back().getZ()));

	return vec3ToVec2( m_camino.back());

}

//tipo es un drop xD
float Enemy_Bot::createPathToItem(const std::string& tipo)
{
	//std::cout << "Create camino to" << tipo << std::endl;
	//Camino actual a seguir
	std::list<Vec3<float>> m_camino;

	float result = m_PathPlanner->CreatePathToItem(tipo, m_camino);

	m_PathFollow->SetPath(m_camino);

	m_PathFollow->FollowOn();


	LogIA::log.push_back("Tamano: " + m_camino.size());
	LogIA::log.push_back("CreatePathToItemTo: "+ std::to_string(m_camino.back().getX())+" "+ std::to_string(m_camino.back().getX()));

	return result;
}

Vec2f Enemy_Bot::createRandomPath()
{
	//Camino actual a seguir
	std::list<Vec3<float>> m_camino;

	m_PathPlanner->CreateRandomPath(m_camino);

	m_PathFollow->SetPath(m_camino);

	m_PathFollow->FollowOn();
	LogIA::log.push_back("CreateRandomPath" + std::to_string(m_camino.back().getX()) + " " + std::to_string(m_camino.back().getZ()));

	return vec3ToVec2(m_camino.back());

}

void Enemy_Bot::followPathAlreadyCreated(std::list<Vec3<float>> &camino)
{
	m_PathFollow->SetPath(camino);

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

	/*

	fm.AddRule(Life_Far, UndesirableLifeDrop);
	fm.AddRule(Life_Medium, DesirableLifeDrop);
	fm.AddRule(Life_Close, VeryDesirableLifeDrop);

	*/

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

	//RocketLauncher

	fm.AddRule(FzAND(Target_Close, Ammo_LowRocketLauncher), UndesirableRocketLauncher);
	fm.AddRule(FzAND(Target_Close, Ammo_OkayRocketLauncher), UndesirableRocketLauncher);
	fm.AddRule(FzAND(Target_Close, Ammo_LoadsRocketLauncher), UndesirableRocketLauncher);

	fm.AddRule(FzAND(Target_Medium, Ammo_LowRocketLauncher), DesirableRocketLauncher);
	fm.AddRule(FzAND(Target_Medium, Ammo_OkayRocketLauncher), VeryDesirableRocketLauncher);
	fm.AddRule(FzAND(Target_Medium, Ammo_LoadsRocketLauncher), VeryDesirableRocketLauncher);

	fm.AddRule(FzAND(Target_Far, Ammo_LowRocketLauncher), UndesirableRocketLauncher);
	fm.AddRule(FzAND(Target_Far, Ammo_OkayRocketLauncher), UndesirableRocketLauncher);
	fm.AddRule(FzAND(Target_Far, Ammo_LoadsRocketLauncher), DesirableRocketLauncher);

}

void Enemy_Bot::elegirWeapon(float Dist) {

	double mejorScore = 0;
	std::string bestWeapon = "Pistola";

	desiAsalto = 0;
	desiSniper = 0;
	desiRocketLauncher = 0;

	double DistToTarget = Dist;

	double Desirability;

	fm.Fuzzify("DistToTarget", DistToTarget);

	if (weaponSystem->buscar("Asalto")) {

		if (weaponSystem->getAmmoAsalto() > 0) {

			fm.Fuzzify("AmmoStatusAsalto", weaponSystem->getAmmoAsalto());

			Desirability = fm.DeFuzzify("DesirabilityAsalto", FuzzyModule::max_av);

			desiAsalto = (float)Desirability;

			if (Desirability > mejorScore) {
				mejorScore = Desirability;
				bestWeapon = "Asalto";
			}
		}


	}

	if (weaponSystem->buscar("Sniper")) {

		if (weaponSystem->getAmmoSniper() > 0) {

			fm.Fuzzify("AmmoStatusSniper", weaponSystem->getAmmoSniper());

			Desirability = fm.DeFuzzify("DesirabilitySniper", FuzzyModule::max_av);

			desiSniper = (float)Desirability;

			if (Desirability > mejorScore) {
				mejorScore = Desirability;
				bestWeapon = "Sniper";
			}

		}

	}

	if (weaponSystem->buscar("RocketLauncher")) {

		if (weaponSystem->getAmmoRocketLauncher() > 0) {


			fm.Fuzzify("AmmoStatusRocketLauncher", weaponSystem->getAmmoRocketLauncher());

			Desirability = fm.DeFuzzify("DesirabilityRocketLauncher", FuzzyModule::max_av);

			desiRocketLauncher = (float)Desirability;

			if (Desirability > mejorScore) {
				mejorScore = Desirability;
				bestWeapon = "RocketLauncher";
			}

		}

	}


	weaponSystem->Equipar(bestWeapon);
}

void Enemy_Bot::FuzzyLifeObject() {

	if (getTargetBot()) {


		std::list<Vec2f> m_camino;

	//	fm.Fuzzify("DistToLifeObject", getPathPlanning()->CreatePathToItem("LifeObject", m_camino));

		fm.Fuzzify("Life", life_component->getVida());
		fm.Fuzzify("LifeTarget", getTargetBot()->getVida());

	//	std::cout << "Deseabilidad de fuzzyLifeObject: " << fm.DeFuzzify("DesirabilityLifeDrop", FuzzyModule::max_av) << std::endl;

		if (fm.DeFuzzify("DesirabilityLifeDrop", FuzzyModule::max_av) > 40) {
			if(!m_pStateMachine->isInState("BuscarVida"))
				m_pStateMachine->ChangeState(&BuscarVida::i());
		}

	}
}


void Enemy_Bot::decisionAfterKill() {


	if (getVida() < 70) {
		if (!m_pStateMachine->isInState("BuscarVida"))
		m_pStateMachine->ChangeState(&BuscarVida::i());
	}
	else {
		m_pStateMachine->RevertToPreviousState();
	}

}



float Enemy_Bot::getVida() {
	return life_component->getVida();
}

bool Enemy_Bot::isDying() {
	return life_component->isDying();
}

float Enemy_Bot::getDesiAsalto() {
	return desiAsalto;
}

float Enemy_Bot::getDesiRocketLauncher() {
	return desiRocketLauncher;
}

float Enemy_Bot::getDesiSniper() {
	return desiSniper;
}

void Enemy_Bot::vaciarArma(std::string arma) {

	weaponSystem->vaciarArma(arma);

}

void Enemy_Bot::InsertarArmaDebug(std::string arma) {

	weaponSystem->InsertarArmaDebug(arma);

}

std::string Enemy_Bot::getStateActual() {

	return m_pStateMachine->getCurrentStateName();

}

void Enemy_Bot::setNumCiclos(int num) {

	if (num == 0)
		valorCiclos = 1;
	else
		valorCiclos = num;

	ciclo = 0;
}