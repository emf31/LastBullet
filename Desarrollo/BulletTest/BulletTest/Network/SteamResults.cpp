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
	menu->setNameOnPlayerSlot(msgSteam->memberName.C_String());
}


 void SteamResults::MessageResult(RakNet::Notification_Console_MemberLeftRoom *message) {
	RakNet::Notification_Console_MemberLeftRoom_Steam *msgSteam = (RakNet::Notification_Console_MemberLeftRoom_Steam *) message;
	RakNet::RakString msg;
	msgSteam->DebugMsg(msg);
	MenuGUI* menu = static_cast<MenuGUI*>(GUIManager::i().getGUIbyName("MenuGUI"));
	menu->setSlotFree(msgSteam->memberName.C_String());

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
	MenuGUI* menu = static_cast<MenuGUI*>(GUIManager::i().getGUIbyName("MenuGUI"));
	menu->setNameOnPlayerSlot(SteamFriends()->GetPersonaName());
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
