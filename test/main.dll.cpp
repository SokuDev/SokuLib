#include <windows.h>
#include <filesystem>
#include <SokuLib.hpp>
#include <fstream>

extern "C" __declspec(dllexport) bool CheckVersion(const BYTE hash[16]) { return true; }
extern "C" __declspec(dllexport) void AtExit() {}
BOOL WINAPI DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) { return true; }

namespace {
	bool _initialized = false;

	void* (__fastcall* orig_LoadMainMenu)(int, int, int);
}

static void* __fastcall hook_LoadMainMenu(int self, int a, int b) {
	void* ret = orig_LoadMainMenu(self, a, b);
	if (b == SokuLib::SCENE_TITLE && !_initialized) {
		_initialized = true;
		// TODO tests
	} return ret;
}

// global variable initialization
std::filesystem::path modulePath;
static bool GetModulePath(HMODULE handle, std::filesystem::path& result) {
	// use wchar for better path handling
	std::wstring buffer;
	int len = MAX_PATH + 1;
	do {
		buffer.resize(len);
		len = GetModuleFileNameW(handle, buffer.data(), buffer.size());
	} while(len > buffer.size());

	if (len) result = std::filesystem::path(buffer.begin(), buffer.begin()+len).parent_path();
	return len;
}

extern "C" __declspec(dllexport) bool Initialize(HMODULE hMyModule, HMODULE hParentModule) {
	GetModulePath(hMyModule, modulePath);
	DWORD dwOld;
	VirtualProtect((LPVOID)TEXT_SECTION_OFFSET, TEXT_SECTION_SIZE, PAGE_READWRITE, &dwOld);

	orig_LoadMainMenu = SokuLib::TamperDword((DWORD)0x861af0, hook_LoadMainMenu);

	VirtualProtect((LPVOID)TEXT_SECTION_OFFSET, TEXT_SECTION_SIZE, dwOld, &dwOld);
	return true;
}
