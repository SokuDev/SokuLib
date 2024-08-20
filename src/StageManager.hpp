//
// Created by DPhoenix on 27/07/2023.
//

#ifndef SOKULIB_STAGE_MANAGER_HPP
#define SOKULIB_STAGE_MANAGER_HPP

#include "Map.hpp"
#include "Player.hpp"
#include "Stage.hpp"

namespace SokuLib {
namespace v2 {
	class BackgroundBase {
	public:
		Vector<int> texIdsA;
		Vector<SpriteEx> spritesA; // these are the real backgrounds
		Vector<int> texIdsB;
		Vector<SpriteEx> spritesB; // these hold extra(animated) sprites
		// 0x44:
		int paramA[2] = {0};
		float fadeTimer = 0;
		// 0x50:
		float paramB[3] = {0};
		int fadeFlag;
		float fadeRatio;
		int unknown64;

		BackgroundBase() = default;
		virtual ~BackgroundBase();
		virtual void update();
		virtual void renderA();
		virtual void renderB();
		virtual void renderC();
		virtual void stageTransform(SpriteEx*);

		void loadResources(Stage stageId, unsigned int verticalShift, bool isInMapFormat); // 46fe40
	};

	class StageManager {
	public:
		List<std::pair<int, float>> createQueue; // unsure content
		char unknown0C;
		// align 3
		uint32_t threadHandleA;
		uint32_t threadIdA;
		uint32_t threadHandleB;
		uint32_t threadIdB;
		uint32_t threadHandleC;
		uint32_t threadIdC;
		// 0x28:
		List<BackgroundBase*> activeBackground;
		List<BackgroundBase*> destroyQueue;
		struct {
			void** vtable;
			Vector2f unknown04;
			struct NotDxVertex {
				float x, y, z, w;
				unsigned int color;
				char unknown14[0x08];
				Vector2f unknown1C;
			} unknown0C[4];
		} baseEffect;
		unsigned int unknownDC;
		float unknownE0[4]; // = {.0,.0,.3,.3}
		char unknownF0[0x08];
		char unknownF8; //  = 0xff
		// align 3
		unsigned int unknownFC; // = 0
		// 0x100
		float paramB[3]; // = {.0}
		// 0x10C
		int paramA[2]; // = {0}
		unsigned int unknown114; // some frame count

		void loadStage(Stage stage, int divider, bool useThread); // 471500

		static StageManager*& instance;
	}; // 0x118
}
}

#endif
