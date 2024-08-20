//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_IFILEREADER_HPP
#define SOKULIB_IFILEREADER_HPP

#include <Windows.h>

namespace SokuLib
{
	struct IFileReader {
		HANDLE fp;

		inline void close() {
			if (fp) CloseHandle(fp);
			fp = 0;
		}

		inline bool isOpen() { return fp != 0; }

		virtual ~IFileReader();
		virtual bool Read(LPVOID lpBuffer, DWORD nNumberOfBytesToRead) = 0;
		virtual DWORD GetReadLength() = 0;
		virtual LONG Seek(LONG lDistanceToMove, DWORD dwMoveMethod) = 0;
		virtual DWORD GetLength() = 0;
	};

	struct FileReader : public IFileReader {
		DWORD lastRead;

		inline void open(const char* filename) {
			this->close();
			fp = CreateFileA(filename, FILE_READ_DATA, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
			if (fp == INVALID_HANDLE_VALUE) fp = 0;
		}

		virtual bool Read(LPVOID lpBuffer, DWORD nNumberOfBytesToRead) override;
		virtual DWORD GetReadLength() override;
		virtual LONG Seek(LONG lDistanceToMove, DWORD dwMoveMethod) override;
		virtual DWORD GetLength() override;
	};

	struct PackageReader : public IFileReader {
		DWORD lastRead;
		LONG size;
		LONG begin;
		LONG offset;
		char decryptKey;

		static HANDLE (__stdcall * const findFile)(LPCSTR name, LPLONG outSize, LPLONG outBegin);

		inline void open(const char* name) {
			this->close();
			fp = this->findFile(name, &size, &begin);
			offset = begin;
			decryptKey = (begin >> 1) | 0x23;
		}

		virtual bool Read(LPVOID lpBuffer, DWORD nNumberOfBytesToRead) override;
		virtual DWORD GetReadLength() override;
		virtual LONG Seek(LONG lDistanceToMove, DWORD dwMoveMethod) override;
		virtual DWORD GetLength() override;
	};
}

#endif //SOKULIB_IFILEREADER_HPP
