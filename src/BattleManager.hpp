//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_BATTLEMANAGER_HPP
#define SOKULIB_BATTLEMANAGER_HPP


#include "SokuAddresses.hpp"
#include "CharacterManager.hpp"
#include "BattleMode.hpp"
#include "String.hpp"

namespace SokuLib
{
	struct BattleManager {
		struct BattleManager_VTABLE *vtable;
		// 0x004
		unsigned frameCount;
		// 0x008
		char unknown[0x4];
		// 0x00C
		CharacterManager &leftCharacterManager;
		// 0x010
		CharacterManager &rightCharacterManager;
		// 0x014
		// 0x01C: Box collisionBuffer
		// 0x02C: List<v2::GameObjectBase*> colliderBufferA[2];
		// 0x044: List<v2::GameObjectBase*> colliderBufferB[2];
		// 0x05C: List<v2::GameObjectBase*> colliderBufferC[2];
		char offset_0x014[0x74];
		// 0x088
		char matchState; // this one is read as 4bytes on switches
		// 0x089
		// 0x08C: vtable[3]: (CScenarioData, SystemObjectManager, HandleManagerEx)
		// 0x0E4: List<> SystemObjects
		// 0x100: FontDescription (0x12C)
		// 0x288: FontDescription (0x12C)
		// 0x434: CDesign (0x34)
		// 0x488: CTile (0xA4)
		// 0x568: CSprite[5] (end in 0x84C)
		// 0x85C: List<Unknown>
		char offset_0x089[0x87B];
		// 0x904
		char currentRound;

		// UpdateCount:
		// for(p : players) {
		//   p->objectList.VUnknown10();
		//   FUN_00463ce0(p);
		//   p->update();
		//   p->objectList.VUnknown0C();
		//   p->VUnknown40();
		// }

		// UpdateMovement:
		// for(p : players) {
		//   FUN_0046a330(p);
		//   FUN_0046a240(p);
		//   FUN_00463550(p);
		// }
	};

	//! @brief Changes the current battle mode
	extern void (__cdecl * const setBattleMode)(BattleMode comm, BattleSubMode sub);
	BattleManager &getBattleMgr();
}


#endif //SOKULIB_BATTLEMANAGER_HPP
