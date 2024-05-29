//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_BATTLEMANAGER_HPP
#define SOKULIB_BATTLEMANAGER_HPP


#include "SokuAddresses.hpp"
#include "CharacterManager.hpp"
#include "BattleMode.hpp"
#include "String.hpp"
#include "IEffectManager.hpp"
#include "SceneScript.hpp"
#include "Design.hpp"

namespace SokuLib
{
	class ScenarioData {
	public:
		v2::SystemEffectManager effects;
		// 0x64
		KeymapManager* inputCluster;
		SWRFont fontObject;
		// 0x1FC
		FontDescription fontDesc;
		// 0x328
		Vector2f unknown328; // position of the text bubble
		Vector2i unknown330; // width matches the text bubble, but not the height
		char unknown338[4];
		Map<String, ManagedSprite> unknown33C; // portrait mapping
		// 0x348
		List<ManagedSprite> unknown348, unknown354, unknown360;
		// 0x36C
		CommandParser commandParser; // constructor is inlined
		// 0x3A0
		struct {
			char unknown00[0x8];
			CDesign resultGui;
			// 0x3C
			CDesign::Sprite* resultTitle;
			CDesign::Sprite* panelA;
			CDesign::Sprite* panelB;
			CDesign::Sprite* panelC;
			// 0x4C
			CDesign::Object* anchorA;
			CDesign::Object* anchorB;
			CDesign::Object* anchorC;
			int texRankFont = 0;
			CTile rankFont;
			// 0x100
			int unknown100[3]; // = 3
		} resultPanel;
		// 0x4AC
		char unknown4AC[0x1C];
		// 0x4C8
		struct {
			int textureIds[5] = {0};
			Sprite sprites[5];
			// 0x2F8
			int leftWidth, rightWidth, centerWidth, loopHeight;
			struct UnknownDataC {char data[0xC4];};
			List<UnknownDataC> unknown308;
		} scenarioEffect;
		// 0x7DC
		char unknown7DC[0xC];
		String bubbleText, unknown804, unknown820;
		// 0x83C
		char unknown83C[0x38];

		virtual void VUnknown00(); // reset state (not destructor)
		virtual void VUnknown04(); // clear (maybe destructor)
		virtual void VUnknown08(); // maybe update
		virtual void render();
	}; // 0x874

	struct BattleManager {
		struct BattleManager_VTABLE *vtable;
		// 0x004
		unsigned frameCount;
		// 0x008
		int fightFXreachesFrame30;
		// 0x00C
		CharacterManager &leftCharacterManager;
		// 0x010
		CharacterManager &rightCharacterManager;
		// 0x014
		CharacterManager* characterManager3;
		CharacterManager* characterManager4;
		// 0x01C
		Box collisionBuffer;
		List<ObjectManager*> attackColliders[2];
		List<ProjectileManager*> densityColliders[2];
		List<ObjectManager*> canHitProjectileColliders[2];
		// 0x074
		int lastHpDamage[2]; // unsure
		int lastCardDamage[2]; // unsure
		int leaveCode; // 1 = select screen, 2 = title screen
		// 0x088
		int matchState;
		// 0x08C
		ScenarioData scenario;
		char unknown900[4];
		// 0x904
		char currentRound;

		// UpdateCount:
		// for(p : players) {
		//   p->objectList.VUnknown10();
		//   FUN_00463ce0(p);
		//   p->update();
		//   p->objectList.VUnknown0C();
		//   p->updatePhysics();
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
