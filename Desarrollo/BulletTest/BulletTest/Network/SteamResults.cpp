#include <SteamResults.h>
#include <NetworkManager.h>
#include <GUIManager.h>
#include <MenuGUI.h>

 void SteamResults::MessageResult(RakNet::Notification_Console_MemberJoinedRoom * message) {
	RakNet::Notification_Console_MemberJoinedRoom_Steam *msgSteam = (RakNet::Notification_Console_MemberJoinedRoom_Steam *) message;
	RakNet::RakString msg;
	msgSteam->DebugMsg(msg);

	printf("%s\n", msg.C_String());
	// Guy with the lower ID connects to the guy with the higher ID
	uint64_t mySteamId = SteamUser()->GetSteamID().ConvertToUint64();
	if (mySteamId < msgSteam->srcMemberId) {
		// Steam's NAT punch is implicit, so it takes a long time to connect. Give it extra time
		unsigned int sendConnectionAttemptCount = 24;
		unsigned int timeBetweenSendConnectionAttemptsMS = 500;
		RakNet::ConnectionAttemptResult car = RakNet::RakPeerInterface::GetInstance()->Connect(msgSteam->remoteSystem.ToString(false), msgSteam->remoteSystem.GetPort(), 0, 0, 0, 0, sendConnectionAttemptCount, timeBetweenSendConnectionAttemptsMS);
		RakAssert(car == CONNECTION_ATTEMPT_STARTED);
	}
	MenuGUI* menu = static_cast<MenuGUI*>(GUIManager::i().getGUIbyName("MenuGUI"));
	if (menu != nullptr) {
		menu->changeStateToLobbyView();
		MenuGUI::PlayerSlot* playerSlot;
		playerSlot = menu->setNameOnPlayerSlot(msgSteam->memberName.C_String());
		playerSlot->setReady(false);
	}
	
	NetworkManager::i().getNetPlayer()->addPlayerInLobby(msgSteam->srcMemberId);

	NetworkManager::i().getNetPlayer()->sendServerIPtoNewClient();

	NetworkManager::i().getNetPlayer()->sendReadyPlayersToNewClient();
	
}


 void SteamResults::MessageResult(RakNet::Notification_Console_MemberLeftRoom *message) {
	RakNet::Notification_Console_MemberLeftRoom_Steam *msgSteam = (RakNet::Notification_Console_MemberLeftRoom_Steam *) message;
	RakNet::RakString msg;
	msgSteam->DebugMsg(msg);

	MenuGUI* menu = static_cast<MenuGUI*>(GUIManager::i().getGUIbyName("MenuGUI"));
	if (menu != nullptr) {
		menu->setSlotFree(msgSteam->memberName.C_String());
		NetworkManager::i().getNetPlayer()->substractPlayerInLobby(msgSteam->srcMemberId);
	}
 }

 void SteamResults::MessageResult(RakNet::Console_GetRoomDetails * message) {
	 RakNet::Console_GetRoomDetails_Steam *msgSteam = (RakNet::Console_GetRoomDetails_Steam *) message;
	
 }

 void SteamResults::MessageResult(RakNet::Notification_Console_RoomChatMessage * message) {
	 RakNet::Notification_Console_RoomChatMessage_Steam *msgSteam = (RakNet::Notification_Console_RoomChatMessage_Steam *) message;

	 std::cout << "MENSAJE: " << msgSteam->message.C_String() << std::endl;

	 std::string s = msgSteam->message.C_String();
	 std::string delimiter = "|";
	 size_t pos = 0;
	 pos = s.find(delimiter);

	 std::string value = s.substr((pos + delimiter.length()), s.length() - pos);
	 std::string token = s.substr(0, s.find(delimiter));

	 if (token == "IP") {
		 NetworkManager::i().getNetPlayer()->setHostIp(value);
	 } else if(token == "R") {
		 pos = value.find(delimiter);
		 std::string name = value.substr((pos+delimiter.length()), value.length() - pos);
		 value = value.substr(0, value.find(delimiter));
		 if (value == "1") {
			 //ready
			 NetworkManager::i().getNetPlayer()->playerReadyCallback(name);
		 } else {
			 //Not ready
			 NetworkManager::i().getNetPlayer()->playerNotReadyCallback(name);
		 }
	 } else if (token == "RC") {
		 NetworkManager::i().getNetPlayer()->setReadyPlayers(stoi(value));
	 }
 }


 void SteamResults::oninvite(GameLobbyJoinRequested_t * pCallback) {
	 std::cout << "CALLBACK_INVITE" << std::endl;
	 NetworkManager::i().getNetPlayer()->joinSteamLobby(pCallback->m_steamIDLobby.ConvertToUint64());

 }

 void SteamResults::MessageResult(RakNet::Console_CreateRoom * message) {
	RakNet::Console_CreateRoom_Steam *msgSteam = (RakNet::Console_CreateRoom_Steam*) message;
	RakNet::RakString msg;
	msgSteam->DebugMsg(msg);
	std::cout << "Console_CreateRoom called" << std::endl;
	std::cout << "Room ID: " << NetworkManager::i().getNetPlayer()->getLobbyID() << std::endl;
	
}

 void SteamResults::MessageResult(RakNet::Console_SearchRooms * message) {
	RakNet::Console_SearchRooms_Steam *msgSteam = (RakNet::Console_SearchRooms_Steam *) message;
	RakNet::RakString msg;
	msgSteam->DebugMsg(msg);
	std::cout << "SEARCH" << std::endl;
	printf("%s\n", msg.C_String());
	if (msgSteam->roomIds.GetSize()>0) {
		lastRoom = msgSteam->roomIds[0];
	}
}

 void SteamResults::ExecuteDefaultResult(RakNet::Lobby2Message * message) {
	RakNet::RakString out;
	message->DebugMsg(out);
	printf("%s\n", out.C_String());
}

