//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_NETOBJECT_HPP
#define SOKULIB_NETOBJECT_HPP


#include <vector>
#include <winsock.h>
#include "UnionCast.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
    //! @brief The information used to connect to an opponent in VS Network.
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

    //! @brief The information exchanged during character select.
	struct NetObject {
		char unknown[4];
		char profile1name[32];
		char profile2name[32];
		char unknown2[0x378];
		// UDP�l�b�g���[�N�I�u�W�F�N�g
		// CNetworkBase
		NetworkBase netUdp;
	};

	NetObject &getNetObject();
}


#endif //SOKULIB_NETOBJECT_HPP
