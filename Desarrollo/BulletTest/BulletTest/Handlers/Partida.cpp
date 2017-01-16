#include "Partida.h"
#include <events/PlayerEvent.h>
#include <events/KillEvent.h>
#include <events/MuerteEvent.h>

void Partida::onNotify(Event& event)
{
	switch (event.event_type)
	{
		case E_NUEVO_PLAYER: {
			PlayerEvent* p_ev = static_cast<PlayerEvent*>(&event);
			nuevoPlayer(p_ev->m_fila);
		
		}
		break;
		case E_AUMENTA_KILL: {
			KillEvent* k_ev = static_cast<KillEvent*>(&event);
			aumentaKill(k_ev->m_guid);
		}
		break;
		case E_AUMENTA_MUERTE: {
			MuerteEvent* m_ev = static_cast<MuerteEvent*>(&event);
			aumentaMuerte(m_ev->m_guid);
		}
		break;

	}

}

void Partida::muestraTabla(InGameHUD * ingame)
{
	//queremos hacer una copia asi que no hacemos puntero aqui
	std::unordered_map <unsigned long, TFilaTabla> aux;
	std::vector<TFilaTabla> ordenado;
	int max = -1;
	RakNet::RakNetGUID guid;
	TFilaTabla fila;
	aux = m_tabla;
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

void Partida::nuevoPlayer(TFilaTabla fila) {
	m_tabla[RakNet::RakNetGUID::ToUint32(fila.guid)] = fila;
}

void Partida::aumentaKill(RakNet::RakNetGUID & guid) {
	TFilaTabla *fila;
	fila = &m_tabla.find(RakNet::RakNetGUID::ToUint32(guid))->second;
	fila->kills++;
}

void Partida::aumentaMuerte(RakNet::RakNetGUID & guid) {
	TFilaTabla *fila;
	fila = &m_tabla.find(RakNet::RakNetGUID::ToUint32(guid))->second;
	fila->deaths++;
}
