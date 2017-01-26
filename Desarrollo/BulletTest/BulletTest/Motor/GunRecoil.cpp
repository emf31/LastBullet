#include <GunRecoil.h>
#include <math.h>
#include <Player.h>
#include <EntityManager.h>
#include <stdlib.h>     /* srand, rand */

GunRecoil::GunRecoil(Camera& camera) :m_camera(camera), m_recoilActive(false)
{
}

void GunRecoil::RecoilOn()
{
	m_recoilActive = true;
	m_recoilTime.restart();
	/**/
//randomAcumulado=Vec3<float>(0,0,0);
	/*if (static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getCurrentWeaponName() == "Asalto") {
		m_amplitud = 0.4;
	}
	if (static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getCurrentWeaponName() == "Pistola") {
		m_amplitud = 0.1;
	}
	if (static_cast<Player*>(EntityManager::i().getEntity(PLAYER))->getCurrentWeaponName() == "RocketLauncher") {
		m_amplitud = 0.6;
	}*/
}

void GunRecoil::update()
{
	int cont = 0;
	if (m_recoilActive) {
		if (m_recoilTime.getElapsedTime().asSeconds() < 0.1f) {
			//printf("entro1\n");
			srand(++cont);
			int randomX = rand() % 100 +1;
			int randomY = rand() % 100 +1;
			int randomZ = rand() % 100 +1;

			//std::cout << randomX << " " << randomY << " " << randomZ<<std::endl;

			int signoX = (rand() % 3)-1;//devuelve 0 o 1
			//if (signoX == 0)
			//	signoX--;

			int signoY = rand() % 2;//devuelve 0 o 1
			//if (signoY == 0)
				//signoY--;

			int signoZ = (rand() % 3) -1;//devuelve 0 o 1


			Vec3<float>  randomf = Vec3<float>(signoX*(float(randomX)/700),signoY*(float(randomY)/600),signoZ*(float(randomZ)/700));
			randomStack.push(randomf);

			m_camera.setTarget(Vec3<float>(m_camera.getTarget().getX()+ randomf.getX(), m_camera.getTarget().getY() + randomf.getY(), m_camera.getTarget().getZ()+randomf.getZ()));


		}
		else if(m_recoilTime.getElapsedTime().asSeconds() < 0.2f && !randomStack.empty()){
			//Vec3<float>  pop = randomStack.top();
			//printf("entro2\n");
			//std::cout << randomStack.size() << std::endl;
			m_camera.setTarget(Vec3<float>(m_camera.getTarget().getX() - randomStack.top().getX(), m_camera.getTarget().getY() - randomStack.top().getY(), m_camera.getTarget().getZ() - randomStack.top().getZ()));
			randomStack.pop();
			
			
		}
		else {
			m_recoilActive = false;
			while (!randomStack.empty()) {
				randomStack.pop();
			}

		}

	}
}