//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_NETOBJECT_HPP
#define SOKULIB_NETOBJECT_HPP

#include <vector>
#include <winsock.h>
#include "SokuFct.hpp"
#include "SokuAddresses.hpp"

//From swrs.h (SWRSToys)

namespace SokuLib
{
	struct CNetworkBase {
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
		char unknown2[0x378];
		// UDP�l�b�g���[�N�I�u�W�F�N�g
		// CNetworkBase
		CNetworkBase netUdp;
	};

	// �l�b�g�I�u�W�F�N�g���\�b�h
	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline void NetObject_CreateProfileStringTexture(void *p)
	{
		SokuLib_Ccall(p, ADDR_NOBJ_CREATE_PROF_STR_TEXTURE, void, ())();
	}

	__forceinline NetObject *getNetObject()
	{
		return *reinterpret_cast<NetObject **>(ADDR_PNETOBJECT);
	}
}


#endif //SOKULIB_NETOBJECT_HPP
