#pragma once
#include <unordered_map>
#include <Estructuras.h>
#include <string>

#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h>  // MessageID

class Partida {
public:

	void nuevoPlayer(TFilaTabla fila) {
		m_tabla[RakNet::RakNetGUID::ToUint32(fila.guid)] = fila;
	}

	void aumentaKill(RakNet::RakNetGUID &guid) {
		TFilaTabla *fila;
		fila = &m_tabla.find(RakNet::RakNetGUID::ToUint32(guid))->second;
		fila->kills++;
	}

	void aumentaMuerte(RakNet::RakNetGUID &guid) {
		TFilaTabla *fila;
		fila = &m_tabla.find(RakNet::RakNetGUID::ToUint32(guid))->second;
		fila->deaths++;
	}
	void muestraTabla();

private:
	std::unordered_map <unsigned long, TFilaTabla> m_tabla;


};