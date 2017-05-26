#include "Partida.h"
#include <events/PlayerEvent.h>
#include <events/KillEvent.h>
#include <events/MuerteEvent.h>
#include <events\GameStartEvent.h>
#include <events/EndGameEvent.h>
#include <EventSystem.h>
#include <GUIManager.h>
#include <NetworkManager.h>

Partida::Partida() : EventListener(), allPlayerReady(false), finished(false)
{
	
}

Partida::~Partida()
{
}

void Partida::inicializar()
{
	ingame = static_cast<InGameHUD*>(GUIManager::i().getGUIbyName("InGameHUD"));
}

void Partida::handleEvent(Event* e)
{
	switch (e->event_type)
	{
		case E_NUEVO_PLAYER: {
			PlayerEvent* p_ev = static_cast<PlayerEvent*>(e);
			nuevoPlayer(p_ev->m_fila);
			break;
		}

		case E_AUMENTA_KILL: {
			KillEvent* k_ev = static_cast<KillEvent*>(e);
			aumentaKill(k_ev->m_guid);
			break;
		}


		case E_AUMENTA_MUERTE: {
			MuerteEvent* m_ev = static_cast<MuerteEvent*>(e);
			aumentaMuerte(m_ev->m_guid);
			break;
		}

		case E_FIN_PARTIDA: {
			EndGameEvent* end_ev = static_cast<EndGameEvent*>(e);
			muestraTabla();
			ingame->muestraFinPartida(EntityManager::i().getRaknetEntity(end_ev->guid)->getName());
			break;
		}
		case E_GAME_START: {
			GameStartEvent* g_ev = static_cast<GameStartEvent*>(e);
			gameInfo = g_ev->m_info;


			break;
		}
		case E_ALLPLAYERS_READY: {
			//Todos los enemigos estan listos empieza la cuenta atras

			empezarCuentaAtras();

			break;
		}

	}
}

void Partida::muestraTabla()
{
	//queremos hacer una copia asi que no hacemos puntero aqui
	int a = 1;
	for (auto i = ordenado.begin(); i != ordenado.end(); ++i) {

		switch (a) {
		case 1:
			ingame->setPlayerName(1, i->name);
			ingame->setPlayerKills(1, i->kills);
			ingame->setPlayerDeaths(1, i->deaths);
			ingame->setPlayerPoints(1, i->puntuacion);
			break;

		case 2:
			ingame->setPlayerName(2, i->name);

			ingame->setPlayerKills(2, i->kills);
			ingame->setPlayerDeaths(2, i->deaths);
			ingame->setPlayerPoints(2, i->puntuacion);
			break;

		case 3:
			ingame->setPlayerName(3, i->name);

			ingame->setPlayerKills(3, i->kills);
			ingame->setPlayerDeaths(3, i->deaths);
			ingame->setPlayerPoints(3, i->puntuacion);
			break;

		case 4:
			ingame->setPlayerName(4, i->name);

			ingame->setPlayerKills(4, i->kills);
			ingame->setPlayerDeaths(4, i->deaths);
			ingame->setPlayerPoints(4, i->puntuacion);
			break;
		}
		a++;
	}
}

void Partida::muestraMarcador()
{
	ordenaTabla();
	int rank = 1;
	Entity* ent = EntityManager::i().getEntity(PLAYER);

	if (ent) {
		for (auto i = ordenado.begin(); i != ordenado.end(); ++i) {

			if (i->guid == ent->getGuid()) {
				ingame->setKills(i->kills);
				ingame->setDeaths(i->deaths);
				ingame->setRanking(rank);
			}

			rank++;
		}
	}

	
	//a = 0;
}

void Partida::ordenaTabla()
{
	std::unordered_map <unsigned long, TFilaTabla> aux;
	int max = -1;
	RakNet::RakNetGUID guid;
	TFilaTabla fila;
	aux = m_tabla;
	ordenado.clear();
	while (aux.size() > 0) {
		for (auto i = aux.begin(); i != aux.end(); ++i) {
			if (i->second.kills > max) {
				max = i->second.kills;
				guid = i->second.guid;
			}

		}
		ordenado.push_back(aux.find(RakNet::RakNetGUID::ToUint32(guid))->second);
		aux.erase(RakNet::RakNetGUID::ToUint32(guid));
		max = -1;
	}

}

void Partida::apagar()
{
	allPlayerReady = false; 
	finished = false;

	ordenado.clear();
	m_tabla.clear();

	ingame->clear();
}

void Partida::empezarCuentaAtras()
{
	InGameHUD* ingame = static_cast<InGameHUD*>(GUIManager::i().getGUIbyName("InGameHUD"));
	ingame->empezarCuentaAtras();
}

void Partida::nuevoPlayer(TFilaTabla fila) {
	m_tabla[RakNet::RakNetGUID::ToUint32(fila.guid)] = fila;
}

void Partida::aumentaKill(RakNet::RakNetGUID & guid) {
	TFilaTabla *fila;
	fila = &m_tabla.find(RakNet::RakNetGUID::ToUint32(guid))->second;
	fila->kills++;
	fila->puntuacion = fila->puntuacion + 100;
}

void Partida::aumentaMuerte(RakNet::RakNetGUID & guid) {
	TFilaTabla *fila;
	fila = &m_tabla.find(RakNet::RakNetGUID::ToUint32(guid))->second;
	fila->deaths++;
}
