#pragma once
#include <unordered_map>
#include <Estructuras.h>
#include <string>

#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <RakNetTypes.h>  // MessageID

#include <InGameHUD.h>

#include <EventListener.h>

#include <AsyncEnemyFactory.h>

class Partida : public EventListener {
public:

	Partida();
	~Partida();

	void inicializar();

	virtual void handleEvent(Event* e) override;

	void muestraTabla();

	void muestraMarcador();

	void ordenaTabla();

	const std::string& getCurrentMap() const { return gameInfo.map; }

	bool isAllReady() { return allPlayerReady; }

	bool isFinished() { return finished; }

	void setPlayerReady(bool t) { allPlayerReady = t; }

	void setFinished(bool finish) { finished = finish; }

	void apagar();

private:

	void empezarCuentaAtras();

	void nuevoPlayer(TFilaTabla fila);

	void aumentaKill(RakNet::RakNetGUID &guid);

	void aumentaMuerte(RakNet::RakNetGUID &guid);

	std::unordered_map <unsigned long, TFilaTabla> m_tabla;

	InGameHUD* ingame;

	TGameInfo gameInfo;

	std::vector<TFilaTabla> ordenado;

	bool allPlayerReady;

	bool finished;

};