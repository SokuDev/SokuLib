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

static void test_Vector() {
	using namespace SokuLib;
	Vector<short> vector;
	assert(vector.empty());

	vector.push_back(5);
	vector.push_back(2);
	vector.push_back(7);
	assert(!vector.empty() && vector.size() == 3);
	assert((int)vector.m_last - (int)vector.m_first == 6);
	assert(vector[1] == 2);
	assert(vector.at(2) == 7);
	assert(vector.front() == 5);
	assert(vector.back() == 7);

	Vector<short>* v2 = new Vector<short>(vector);
	assert(v2->size() == 3);
	int c = 0; for (auto val : *v2) {
		assert(vector[c++] == val);
	} delete v2;
	assert(c == 3);

	vector.pop_back();
	assert(vector.size() == 2);
	int i = 0; for (auto iter = vector.begin(); i < 3; ++i, ++iter) {
		switch (i) {
			case 0: assert(*iter == 5); break;
			case 1: assert(*iter == 2); break;
			case 2: assert(iter == vector.end()); break;
		}
	}

	vector.clear();
	assert(vector.empty());
	assert(vector.m_first == nullptr);

	vector.reserve(10);
	assert(vector.size() == 0);
	assert(vector.capacity() >= 10);
}

static void test_List() {
	using namespace SokuLib;
	List<short> list;
	assert(list.empty());

	list.push_back(5);
	list.push_back(2);
	list.push_back(7);
	assert(!list.empty() && list.size() == 3);
	assert(list.front() == 5);
	assert(list.back() == 7);

	List<short>* v2 = new List<short>(list);
	assert(v2->size() == 3);
	int c = 0; for (auto val : *v2) {
		static const short v[] = {5, 2, 7};
		assert(v[c++] == val);
	} delete v2;
	assert(c == 3);

	list.pop_back();
	assert(list.size() == 2);
	int i = 0; for (auto iter = list.begin(); i < 3; ++i, ++iter) {
		switch (i) {
			case 0: assert(*iter == 5); break;
			case 1: assert(*iter == 2); break;
			case 2: assert(iter == list.end()); break;
		}
	}

	list.insert(++list.begin(), 4);
	list.insert(list.begin(), 9);
	c = 0; for (auto val : list) {
		static const short v[] = {9, 5, 4, 2};
		assert(v[c++] == val);
	}
	assert(c == 4);
	list.erase(++list.begin(), --list.end());
	c = 0; for (auto val : list) {
		static const short v[] = {9, 2};
		assert(v[c++] == val);
	}
	assert(c == 2);

	list.clear();
	assert(list.empty());
	assert(list.size() == 0);
}

static void test_Deque() {
	using namespace SokuLib;
	Deque<short> deque;
	assert(deque.empty());

	deque.push_back(5);
	deque.push_back(2);
	deque.push_back(7);
	assert(!deque.empty() && deque.size() == 3);
	assert(deque[1] == 2);
	assert(deque.at(2) == 7);
	assert(deque.front() == 5);
	assert(deque.back() == 7);

	Deque<short>* v2 = new Deque<short>(deque);
	assert(v2->size() == 3);
	int c = 0; for (auto val : *v2) {
		assert(deque[c++] == val);
	} delete v2;
	assert(c == 3);

	deque.pop_front();
	assert(deque.size() == 2);
	int i = 0; for (auto iter = deque.begin(); i < 3; ++i, ++iter) {
		switch (i) {
			case 0: assert(*iter == 2); break;
			case 1: assert(*iter == 7); break;
			case 2: assert(iter == deque.end()); break;
		}
	}

	deque.push_front(8);
	deque.pop_back();
	assert(deque.size() == 2);
	i = 0; for (auto iter = deque.begin(); i < 3; ++i, ++iter) {
		switch (i) {
			case 0: assert(*iter == 8); break;
			case 1: assert(*iter == 2); break;
			case 3: assert(iter == deque.end()); break;
		}
	}

	deque.insert(deque.begin()+1, 4);
	deque.insert(deque.begin(), 9);
	c = 0; for (auto val : deque) {
		static const short v[] = {9, 8, 4, 2};
		assert(v[c++] == val);
	}
	assert(c == 4);
	deque.erase(deque.begin()+1, deque.end()-1);
	c = 0; for (auto val : deque) {
		static const short v[] = {9, 2};
		assert(v[c++] == val);
	}
	assert(c == 2);

	deque.clear();
	assert(deque.empty());
	assert(deque.size() == 0);
}

static void* __fastcall hook_LoadMainMenu(int self, int a, int b) {
	void* ret = orig_LoadMainMenu(self, a, b);
	if (b == SokuLib::SCENE_TITLE && !_initialized) {
		_initialized = true;

		test_Vector();
		test_List();
		test_Deque();
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
	VirtualProtect((LPVOID)0x861af0, 4, PAGE_READWRITE, &dwOld);
	orig_LoadMainMenu = SokuLib::TamperDword((DWORD)0x861af0, hook_LoadMainMenu);
	VirtualProtect((LPVOID)0x861af0, 4, dwOld, &dwOld);
	return true;
}
