#include <GunRecoil.h>
#include <math.h>
#include <Player.h>
#include <EntityManager.h>
#include <stdlib.h>     /* srand, rand */

GunRecoil::GunRecoil(Camera& camera) :m_camera(camera), m_recoilActive(false), tiempo(0.2f)
{
}

void GunRecoil::RecoilOn()
{
	m_recoilActive = true;
	m_recoilTime.restart();
}

void GunRecoil::update(bool isShooting)
{


	if (m_recoilActive) {
		if (m_recoilTime.getElapsedTime().asSeconds() < tiempo || isShooting) {

			//generamos los numeros randomizados
			srand(m_recoilTime.getElapsedTime().asMilliseconds());
			int randomX = rand() % 100 +1;
			int randomY = rand() % 100 +1;
			int randomZ = rand() % 100 +1;

			int signoX = (rand() % 3)-1;//devuelve -1 o 0 o 1

			int signoY = rand() % 2;//devuelve 0 o 1

			int signoZ = (rand() % 3) -1;//devuelve -1 o 0 o 1

			//comprobamos si la mira no se ha ido muy para arriba

			if (randomAcumulativo.getY() > 6) {
				randomY = 0;
			}	

			//seteamos la camara en la posicion adecuada

			Vec3<float>  randomf = Vec3<float>(signoX*(float(randomX)/700),signoY*(float(randomY)/1000),signoZ*(float(randomZ)/700));

			m_camera.setTarget(Vec3<float>(m_camera.getTarget().getX()+ randomf.getX(), m_camera.getTarget().getY() + randomf.getY(), m_camera.getTarget().getZ()+randomf.getZ()));

			randomAcumulativo += randomf;

			//Actualizamos los valores de xini xfin y velocidad para despues hacer un mru y devolver la camara a la posicion inicial

			xfin = Vec3<float>(m_camera.getTarget().getX() - randomAcumulativo.getX(), m_camera.getTarget().getY() - randomAcumulativo.getY(), m_camera.getTarget().getZ() - randomAcumulativo.getZ());
			xini = Vec3<float>(m_camera.getTarget().getX(), m_camera.getTarget().getY(), m_camera.getTarget().getZ());
			velocidad = (xfin - xini) / tiempo;

		}
		else if (m_recoilTime.getElapsedTime().asSeconds() < tiempo*2) {

			m_camera.setTarget(xini+(velocidad*(m_recoilTime.getElapsedTime().asSeconds()- tiempo)));
			
		}
		else {
			m_recoilActive = false;
			randomAcumulativo = Vec3<float>(0, 0, 0);
		}
	}
}