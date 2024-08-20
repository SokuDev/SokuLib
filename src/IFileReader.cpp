#include "IFileReader.hpp"
#include "SokuAddresses.hpp"
#include "UnionCast.hpp"

namespace {
	// private
	void** const _vtable_file = (void** const)SokuLib::ADDR_VTBL_FILEREADER;
	void** const _vtable_package = (void** const)SokuLib::ADDR_VTBL_PACKAGEREADER;
}

namespace SokuLib
{
	IFileReader::~IFileReader() { if (fp) CloseHandle(fp); }

	bool FileReader::Read(LPVOID lpBuffer, DWORD nNumberOfBytesToRead)
		{ return (this->*union_cast<bool(IFileReader::*)(LPVOID, DWORD)>(_vtable_file[1]))(lpBuffer, nNumberOfBytesToRead); }
	DWORD FileReader::GetReadLength()
		{ return (this->*union_cast<DWORD(IFileReader::*)()>(_vtable_file[2]))(); }
	LONG FileReader::Seek(LONG lDistanceToMove, DWORD dwMoveMethod)
		{ return (this->*union_cast<LONG(IFileReader::*)(LONG, DWORD)>(_vtable_file[3]))(lDistanceToMove, dwMoveMethod); }
	DWORD FileReader::GetLength()
		{ return (this->*union_cast<DWORD(IFileReader::*)()>(_vtable_file[4]))(); }

	HANDLE (__stdcall * const PackageReader::findFile)(LPCSTR, LPLONG, LPLONG)
		= reinterpret_cast<HANDLE (__stdcall *)(LPCSTR, LPLONG, LPLONG)>(SokuLib::ADDR_PACKAGE_OPENFILE);
	bool PackageReader::Read(LPVOID lpBuffer, DWORD nNumberOfBytesToRead)
		{ return (this->*union_cast<bool(IFileReader::*)(LPVOID, DWORD)>(_vtable_package[1]))(lpBuffer, nNumberOfBytesToRead); }
	DWORD PackageReader::GetReadLength()
		{ return (this->*union_cast<DWORD(IFileReader::*)()>(_vtable_package[2]))(); }
	LONG PackageReader::Seek(LONG lDistanceToMove, DWORD dwMoveMethod)
		{ return (this->*union_cast<LONG(IFileReader::*)(LONG, DWORD)>(_vtable_package[3]))(lDistanceToMove, dwMoveMethod); }
	DWORD PackageReader::GetLength()
		{ return (this->*union_cast<DWORD(IFileReader::*)()>(_vtable_package[4]))(); }
}
