//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_IFILEREADER_HPP
#define SOKULIB_IFILEREADER_HPP

//From swrs.h (SWRSToys)

#include <Windows.h>

namespace SokuLib
{
	#pragma pack(push, 4)

	// �t�@�C�����[�_�C���^�[�t�F�[�X
	struct __declspec(novtable) IFileReader {
		virtual ~IFileReader() {}
		virtual bool Read(LPVOID lpBuffer, DWORD nNumberOfBytesToRead) = 0;
		virtual DWORD GetReadLength() = 0;
		virtual LONG Seek(LONG lDistanceToMove, DWORD dwMoveMethod) = 0;
		virtual DWORD GetLength() = 0;
	};
	#pragma pack(pop)
}

#endif //SOKULIB_IFILEREADER_HPP
