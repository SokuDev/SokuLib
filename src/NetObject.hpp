//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_NETOBJECT_HPP
#define SOKULIB_NETOBJECT_HPP


#include <winsock.h>
#include "Vector.hpp"
#include "Deque.hpp"
#include "Sprite.hpp"
#include "UnionCast.hpp"
#include "SokuAddresses.hpp"
#include "InfoManager.hpp"

namespace SokuLib
{
	struct NetworkBase {
		char unknown[0x28];
		SOCKET socket;
		char offset_0x2C[0xC];
		// �T�[�o�A�h���X
		// in_addr
		in_addr g_ptoAddr;
		char offset_0x3C[0x84];
		sockaddr_in opponent;
		char offset_0xD0[0x38];
		// �s�A���
		// vector<SWRClientInfo> ?
		// 0x108
		Vector<struct ClientInfo> g_psvClients;
	};

	struct NetObject {
		char unknown[4];
		char profile1name[32];
		char profile2name[32];
		char unknown2[84];
		int frameId;
		// 0x9C
		char offset_0x9C[0x5C];
		// 0xF8
		KeymapManager p1InputMgr;
		Deque<unsigned short> p1Inputs;
		// 0x174
		KeymapManager p2InputMgr;
		Deque<unsigned short> p2Inputs;
		char offset_0x1F0[0x8C];
		// 0x27C
		int p1ProfileNameTexture;
		int p2ProfileNameTexture;
		Sprite p1ProfileNameSprite;
		Sprite p2ProfileNameSprite;
		char offset_0x3AC[0x10];
		// UDP�l�b�g���[�N�I�u�W�F�N�g
		// CNetworkBase, 0x3BC
		NetworkBase netUdp;
	};

	NetObject &getNetObject();
}


#endif //SOKULIB_NETOBJECT_HPP
