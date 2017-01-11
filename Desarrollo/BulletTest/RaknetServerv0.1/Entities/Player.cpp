#include "Player.h"


Player::Player(const std::string& name, RakNet::RakNetGUID guid) : Entity(name, guid)	//El player siempre tendra ID 1
{
}


Player::~Player()
{
}

void Player::inicializar()
{
}



void Player::borrarContenido()
{

}
