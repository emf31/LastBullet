#pragma once
#include <unordered_map>
#include <Estructuras.h>
#include <string>

#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <RakNetTypes.h>  // MessageID
#include <Observer.h>

#include <InGameHUD.h>

class Partida : public Observer {
public:

	Partida(InGameHUD* hud) : ingame(hud) {  }
	~Partida(){ }

	virtual void onNotify(Event& event) override;


	void muestraTabla();

private:

	void nuevoPlayer(TFilaTabla fila);

	void aumentaKill(RakNet::RakNetGUID &guid);

	void aumentaMuerte(RakNet::RakNetGUID &guid);

	std::unordered_map <unsigned long, TFilaTabla> m_tabla;

	InGameHUD* ingame;
};