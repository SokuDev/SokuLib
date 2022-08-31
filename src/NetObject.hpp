//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_NETOBJECT_HPP
#define SOKULIB_NETOBJECT_HPP


#include <vector>
#include <winsock.h>
#include "UnionCast.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	struct NetworkBase {
		char unknown[0x3C];
		// �T�[�o�A�h���X
		// in_addr
		in_addr g_ptoAddr;
		char unknown2[0xD0 - sizeof(in_addr)];
		// �s�A���
		// vector<SWRClientInfo> ?
		std::vector<struct ClientInfo> g_psvClients;
	};

	struct NetObject {
		char unknown[4];
		char profile1name[32];
		char profile2name[32];
		char unknown2[84];
		int frameId;
		char unknown3[0x320];
		// UDP�l�b�g���[�N�I�u�W�F�N�g
		// CNetworkBase
		NetworkBase netUdp;
	};

	NetObject &getNetObject();
}


#endif //SOKULIB_NETOBJECT_HPP
