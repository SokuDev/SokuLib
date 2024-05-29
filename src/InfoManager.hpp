//
// Created by DPhoenix on 19/07/2023.
//

#ifndef SOKULIB_INFO_MANAGER_HPP
#define SOKULIB_INFO_MANAGER_HPP

#include "Design.hpp"
#include "IEffectManager.hpp"
#include "Player.hpp"

namespace SokuLib {
namespace v2 {

	class InfoManagerBase {
	public:
		void** vtable;
		// 0x004
		EffectManager_InfoEffect effects;
		// 0x098
		CDesign battleUpper, battleUnder, comboGui;
		// 0x134
		char unknown134[0x10];
		// 0x144
		CDesign::Sprite* unknown144[6];
		// 0x15C
		char unknown15C[0x10];
		// 0x16C
		struct {
			CDesign* design;
			Player* player;
			char unknown08[0x18]; // align 3 on end
			Deque<int> unknown20;
		} unknown16C[2];
		// 0x1D4
		struct {
			void* unknown000;
			Sprite unknown004, unknown098;
			char unknown12C[0x28];
		} unknown1D4[2];
		// 0x47C
		Sprite* unknown47C;
		Sprite* unknown480;
		int unknown484;
		float unknown488;
		CDesign::Number* unknown48C;
		CDesign::Number* unknown490;
		char unknown494[0x04];

		static InfoManagerBase*& instance; // 0x8985e8
	};

	class InfoManager : public InfoManagerBase {
	public:
		// 0x498
		struct {
			char id;
			// align 3
			float bigCardSize;
			float smallCardRatio;
			int lifebarYellowValue;
			int lifebarRedValue;
			// 0x14
			EffectManager_InfoEffect* effects;
			Player* player;
			CDesign::Gauge* lifebarYellow;
			CDesign::Gauge* lifebarRed;
			// 0x24
			CDesign::Gauge* orbsGauge[5];
			CDesign::Gauge* orbsCrushGauge[5];
			CDesign::Sprite* orbsFull[5];
			CDesign::Sprite* orbsEmpty[5];
			CDesign::Sprite* orbsCrushEmpty[5];
			// 0x88
			CDesign::Gauge* cardGauge[5];
			CDesign::Sprite* cardFaceDown[5];
			CDesign::Sprite* cardSlotA[5];
			CDesign::Sprite* cardSlotB[5];
			// 0xD8
			char unknownD8[0x14];
			// 0xEC
			CDesign::Sprite* winMarkA;
			CDesign::Sprite* winMarkB;
			CDesign::Sprite* winMarkC;
		} playerHUD[2];
	};

}
}

#endif
