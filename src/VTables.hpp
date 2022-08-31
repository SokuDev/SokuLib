//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_VTABLES_HPP
#define SOKULIB_VTABLES_HPP


#include "Menus/PauseMenu.hpp"
#include "BattleManager.hpp"
#include "Scenes.hpp"
#include "SokuAddresses.hpp"
#include "Menus.hpp"

namespace SokuLib
{
	template<typename T>
	struct Scene_VTABLE {
		T *(T::*destructor)(char unknown);
		int (T::*onProcess)();
		int (T::*onRender)();
		void (T::*unknown)();
		void (T::*unknown2)();
		void (T::*unknown3)();
		void (T::*unknown4)();
	};

	template<typename T>
	struct Menu_VTABLE {
		T *(T::*onDestruct)(unsigned char param);
		void *unknown;
		int (T::*onProcess)();
		int (T::*onRender)();
	};

	struct BattleManager_VTABLE {
		BattleManager *(BattleManager::*destructor)(char unknown);
		void (BattleManager::*onArenaStart)(void *param);
		void (BattleManager::*onExit)();
		int (BattleManager::*onProcess)();
		int (BattleManager::*onSayStart)();
		int (BattleManager::*afterBlackScreen)();
		int (BattleManager::*maybeOnProgress)();
		int (BattleManager::*onRoundEnd)();
		int (BattleManager::*onKO)();
		int (BattleManager::*onGirlsTalk)();
		int (BattleManager::*unknownFunction)();
		void (BattleManager::*battleResultScreen)(); //When showing the cards earned in the battle
		void (BattleManager::*onRoundStart)();
		void (BattleManager::*onShowLogo)(int param);
		void (BattleManager::*onRender)();       // After select arena render or draw()
		void (BattleManager::*updateEffects)();
		void (BattleManager::*maybeOnRender2)(); // After select arena render???? Last function???
	};

	extern Scene_VTABLE<Select>        &VTable_Select;
	extern Scene_VTABLE<Logo>          &VTable_Logo;
	extern Scene_VTABLE<Title>         &VTable_Title;
	extern Scene_VTABLE<Battle>        &VTable_Battle;
	extern Scene_VTABLE<BattleClient>  &VTable_BattleClient;
	extern Scene_VTABLE<BattleServer>  &VTable_BattleServer;
	extern Scene_VTABLE<BattleWatch>   &VTable_BattleWatch;
	extern Scene_VTABLE<SelectServer>  &VTable_SelectServer;
	extern Scene_VTABLE<SelectClient>  &VTable_SelectClient;
	extern Scene_VTABLE<Loading>       &VTable_Loading;
	extern Scene_VTABLE<LoadingServer> &VTable_LoadingServer;
	extern Scene_VTABLE<LoadingClient> &VTable_LoadingClient;
	extern Scene_VTABLE<LoadingWatch>  &VTable_LoadingWatch;
	extern Menu_VTABLE<MenuConnect>    &VTable_ConnectMenu;
	extern Menu_VTABLE<ProfileDeckEdit>&VTable_ProfileDeckEdit;
	extern Menu_VTABLE<MenuResult>     &VTable_Result;
	extern Menu_VTABLE<PauseMenu>      &VTable_PauseMenu;
	extern BattleManager_VTABLE        &VTable_BattleManager;

	struct _vtable_offset_helper {
		virtual int r0();  virtual int r1();  virtual int r2();  virtual int r3();
		virtual int r4();  virtual int r5();  virtual int r6();  virtual int r7();
		virtual int r8();  virtual int r9();  virtual int r10(); virtual int r11();
		virtual int r12(); virtual int r13(); virtual int r14(); virtual int r15();
		virtual int r16(); virtual int r17(); virtual int r18(); virtual int r19();
	};

	template<class T> struct _vtable_info {
		static const int baseAddr;
		template <typename F> static inline F& get(int index) {
			static_assert(std::is_member_function_pointer<F>::value);
			return reinterpret_cast<F*>(baseAddr)[index];
		}

		template <typename F> static inline F T::*& get(F T::* f) {
			static_assert(std::is_member_function_pointer<decltype(f)>::value);
			_vtable_offset_helper vt;
			return reinterpret_cast<F T::**>(_vtable_info<T>::baseAddr)
				[(vt.*reinterpret_cast<int (_vtable_offset_helper::*)()>(f))()];
		}

		// Reference arguments must be declared (no deduction)
		template <unsigned int index, typename R = void, typename ... A>
		static inline R call(T* This, A& ... a) {
			return (This->*reinterpret_cast<R(T::**)(A...)>(baseAddr)[index])(a...);
		}
	};

	/// *Only use with virtual functions*
	template<class T, typename F>
	inline DWORD GetVirtualTableOf(F T::* f) {
		return reinterpret_cast<DWORD>(&_vtable_info<T>::get(f));
	}

	/// *Only use with virtual functions*
	template<class T, typename F>
	inline F T::*& GetVirtualFunc(F T::* f) {
		return _vtable_info<T>::get(f);
	}
}


#endif //SOKULIB_VTABLES_HPP
