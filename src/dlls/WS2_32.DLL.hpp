//
// Created by PinkySmile on 11/05/2021.
//

#ifndef SOKULIB_WS2_32_DLL_HPP
#define SOKULIB_WS2_32_DLL_HPP


#include <windows.h>

namespace SokuLib::DLL
{
	struct DLLWS2_32 {
		u_short (__stdcall *ntohs)(u_short netshort);
		int (__stdcall *WSACleanup)(void);
		int (__stdcall *WSAGetLastError)(void);
		int (__stdcall *WSAStartup)(WORD wVersionRequired, LPWSADATA lpWSAData);
		u_long (__stdcall *ntohl)(u_long netlong);
		hostent *(__stdcall *gethostbyname)(char * name);
		int (__stdcall *bind)(SOCKET s, sockaddr * addr, int namelen);
		int (__stdcall *recvfrom)(SOCKET s, char * buf, int len, int flags, sockaddr * from, int * fromlen);
		int (__stdcall *shutdown)(SOCKET s, int how);
		SOCKET (__stdcall *socket)(int af, int type, int protocol);
		int (__stdcall *closesocket)(SOCKET s);
		int (__stdcall *sendto)(SOCKET s, char * buf, int len, int flags, sockaddr * to, int tolen);
		u_short (__stdcall *htons)(u_short hostshort);
		u_long (__stdcall *inet_addr)(char * cp);
	};

	extern DLLWS2_32 &ws2_32;
}


#endif //SOKULIB_WS2_32_DLL_HPP
