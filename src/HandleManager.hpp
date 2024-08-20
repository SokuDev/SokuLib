//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_HANDLEMANAGER_HPP
#define SOKULIB_HANDLEMANAGER_HPP


#include <windows.h>
#include "SokuAddresses.hpp"
#include "Deque.hpp"
#include "Vector.hpp"
#include "List.hpp"

namespace SokuLib
{
	// used in HandleManager
	class CriticalSection {
	public:
		CRITICAL_SECTION mutex; // sizeof() = 24
		inline virtual ~CriticalSection() { DeleteCriticalSection(&mutex); }
		inline CriticalSection() { InitializeCriticalSection(&mutex); }
		CriticalSection(const CriticalSection&) = delete;
		CriticalSection(CriticalSection&&) = delete;

		inline void lock() { EnterCriticalSection(&mutex); }
		inline void unlock() noexcept { LeaveCriticalSection(&mutex); }
		inline bool try_lock() noexcept { return TryEnterCriticalSection(&mutex); }
	};

	template<class T>
	class HandleManager {
	public:
		Deque<T> deque;
		Vector<T*> vector;
		Vector<unsigned int> usedIndexes;
		List<unsigned int> unusedIndexes;
		unsigned int nextBase = 0;
		CriticalSection mutex;

		virtual ~HandleManager() = default;

		inline T* Allocate(unsigned int& retId) {
			int index;
			mutex.lock();
			if(unusedIndexes.size()) {
				index = unusedIndexes.back();
				if(++nextBase > 0xffff) nextBase = 1;
				retId = (index & 0xffff) | (nextBase << 16);
				unusedIndexes.pop_back();
				usedIndexes[index] = retId >> 16;
			} else {
				index = deque.size();
				if(++nextBase > 0xffff) nextBase = 1;
				retId = (index & 0xffff) | (nextBase << 16);
				deque.emplace_back();
				vector.push_back(&deque.back());
				usedIndexes.push_back(retId >> 16);
			}
			T* ret = vector.at(index);
			mutex.unlock();
			return ret;
		}

		inline void Deallocate(unsigned int id) {
			mutex.lock();
			int index = id & 0xffff;
			if (usedIndexes.at(index) == (id >> 16)) {
				usedIndexes[index] = 0;
				unusedIndexes.push_back(index);
			}
			mutex.unlock();
		}

		inline T* Get(unsigned int id) {
			T* ret = 0;
			mutex.lock();
			if (usedIndexes.at(id & 0xffff) == (id >> 16)) ret = vector.at(id & 0xffff);
			mutex.unlock();
			return ret;
		}
	};

	template<class T>
	class HandleManagerEx {
		static_assert(std::has_virtual_destructor<T>::value);
	public:
		Vector<T*> vector;
		Vector<unsigned int> usedIndexes;
		List<unsigned int> unusedIndexes;
		unsigned int nextBase = 0;
		CriticalSection mutex;

		virtual ~HandleManagerEx() { for(auto t : vector) delete t; }

		template<typename... Args>
		inline T* Allocate(unsigned int& retId, Args... args) {
			int index; T* ret;
			mutex.lock();
			if(unusedIndexes.size()) {
				index = unusedIndexes.back();
				if(++nextBase > 0xffff) nextBase = 1;
				retId = (index & 0xffff) | (nextBase << 16);
				unusedIndexes.pop_back();
				usedIndexes[index] = retId >> 16;
				ret = vector.at(index);
				if (ret) new (ret) T(args...);
			} else {
				index = vector.size();
				if(++nextBase > 0xffff) nextBase = 1;
				retId = (index & 0xffff) | (nextBase << 16);
				vector.push_back(ret = new T(args...));
				usedIndexes.push_back(retId >> 16);
			}
			mutex.unlock();
			return ret;
		}

		inline void Deallocate(unsigned int id) {
			mutex.lock();
			int index = id & 0xffff;
			if (usedIndexes.at(index) == (id >> 16)) {
				usedIndexes[index] = 0;
				unusedIndexes.push_back(index);
				vector.at(index)->~T();
			}
			mutex.unlock();
		}

		inline T* Get(unsigned int id) {
			T* ret = 0;
			mutex.lock();
			if (usedIndexes.at(id & 0xffff) == (id >> 16)) ret = vector.at(id & 0xffff);
			mutex.unlock();
			return ret;
		}
	};

	inline __declspec(naked) void **CHandleManager_Allocate(void *p, int *ret)
	{
		__asm push edi
		__asm mov edi, [esp+8]
		__asm push [esp+12]
		__asm mov eax, ADDR_ALLOCATE_FUNCTION
		__asm call eax
		__asm pop edi
		__asm retn
	}

	inline __declspec(naked) void CHandleManager_Deallocate(void *p, int id)
	{
		__asm mov eax, [esp+4]
		__asm push [esp+8]
		__asm mov ecx, ADDR_DEALLOCATE_FUNCTION
		__asm call ecx
		__asm retn
	}
}


#endif //SOKULIB_HANDLEMANAGER_HPP
