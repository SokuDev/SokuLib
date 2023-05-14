//
// Created by DPhoenix on 05/06/2022.
//

#ifndef SOKULIB_ANIMATIONOBJECT_HPP
#define SOKULIB_ANIMATIONOBJECT_HPP

#include "Sprite.hpp"
#include "FrameData.hpp"
#include "CharacterManager.hpp"

namespace SokuLib {
namespace v2 {
	class AnimationObject {
	public:
		SpriteEx sprite; // this is actually EffectSprite, but it's a child with identical structure

		// offset 0x0EC
		Vector2f position;
		Vector2f speed;
		Vector2f gravity;
		Direction direction;
		// align 0x3

		// offset 0x108
		Vector2f center = {0, 0};
		RenderInfo renderInfos;
		// ^ maybe EffectSprite comes until here (0x438bb0)

		// offset 0x130
		Vector<int>* textures;
		bool isGui = false;
		bool isActive = false;
		// align 0x2
		float unknown138; // displacement in Y (Player objects sets this to -6)

		// offset 0x13C
		struct FrameState {
			Action actionId;
			unsigned short sequenceId;
			unsigned short poseId;
			unsigned short poseFrame;
			unsigned int currentFrame;
			unsigned short sequenceSize;
			char unknown14A[2]; // align 0x2?
			unsigned short poseDuration;
			char unknown14E[2]; // align 0x2?
		} frameState;
		v2::FrameData* frameData;
		IColor* unknown154 = 0;

		inline AnimationObject() = default;
		virtual ~AnimationObject();
		virtual void setActionSequence(short, short) = 0;
		virtual bool setAction(short) = 0;
		virtual void setSequence(short) = 0;
		virtual void resetSequence() = 0;
		virtual bool nextSequence() = 0;
		virtual void prevSequence() = 0;
		virtual void setPose(short) = 0;
		virtual bool nextPose() = 0;
		virtual void prevPose() = 0;
		virtual void update() = 0;
		virtual void render() = 0;
		virtual void render2() = 0;
		virtual void applyTransform() = 0;
		virtual void onRenderEnd() = 0;

		bool advanceFrame(); // 0x438c60
	};

	class EffectObjectBase : public AnimationObject {
	public:
		int unknown158 = 1;
		int unknown15C = 0;
		Map<unsigned int, SequenceData*>* patternMap;
		int unknown164;
		SequenceData* currentSequence;
		char layer;
		// align 0x3

		// adds a virtual
		virtual bool initSequence() = 0;
	};

	class EffectObject : public EffectObjectBase {
	public:
		char unknown170[0x8];
	};

	class InfoEffectObject : public EffectObjectBase {
	public:
		char unknown170[0x8];
	};

	class SelectEffectObject : public EffectObjectBase {
	};

	class WeatherEffectObject : public EffectObjectBase {
	public:
		char unknown170[0x10];
	};
}
}

#endif //SOKULIB_ANIMATIONOBJECT_HPP
