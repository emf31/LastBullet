#pragma once
#include <unordered_map>
#include <Estructuras.h>
#include <string>

#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <RakNetTypes.h>  // MessageID

#include <InGameHUD.h>

#include <EventListener.h>

class Partida : public EventListener {
public:

	Partida();
	~Partida();

	void inicializar();

	virtual void handleEvent(Event* e) override;


	void muestraTabla();

	const std::string& getCurrentMap() const { return gameInfo.map; }

private:

	void nuevoPlayer(TFilaTabla fila);

	void aumentaKill(RakNet::RakNetGUID &guid);

	void aumentaMuerte(RakNet::RakNetGUID &guid);

	std::unordered_map <unsigned long, TFilaTabla> m_tabla;

	InGameHUD* ingame;

	TGameInfo gameInfo;
};