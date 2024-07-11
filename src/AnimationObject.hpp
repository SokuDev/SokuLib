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
			unsigned short actionId;
			unsigned short sequenceId;
			unsigned short poseId;
			unsigned short poseFrame;
			unsigned int currentFrame;
			unsigned short sequenceSize;
			unsigned short unknown;
			unsigned short poseDuration;
			// align 0x2
		} frameState;
		// offset 0x150
		v2::FrameData* frameData;
		SpriteEx* unknown154 = nullptr;

		inline AnimationObject() = default;
		virtual ~AnimationObject();
		virtual void setActionSequence(short action, short sequence);
		virtual bool setAction(short action);
		virtual void setSequence(short sequence) = 0;
		virtual void resetSequence() = 0;
		virtual bool nextSequence() = 0;
		virtual void prevSequence() = 0;
		virtual void setPose(short pose) = 0;
		virtual bool nextPose() = 0;
		virtual void prevPose() = 0;
		virtual void update() = 0;
		virtual void render();
		virtual void render2();
		virtual void applyTransform();
		virtual void onRenderEnd();

		void resetRenderInfo(); // 0x438BB0
		bool advanceFrame(); // 0x438c60
	};

	class SystemEffectObject {
	public:
		int unknown04 = 1;
		int unknown08 = 0;
		SpriteEx sprite; // this is actually EffectSprite, but it's a child with identical structure

		// offset 0xF4
		Vector2f position;
		Vector2f speed;
		Vector2f gravity;
		Direction direction;
		// align 0x3

		// offset 0x110
		Vector2f center = {0, 0};
		RenderInfo renderInfos;
		// ^ maybe EffectSprite comes until here (0x438bb0)

		// offset 0x138
		int textureId = 0;
		int actionId; // this is actually an integer
		int unknown140; // some custom data (actionIds 0, 1 and 2)

		virtual ~SystemEffectObject();
		virtual void update();
		virtual void initializeAction();
		virtual void render();
	}; // 0x144

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
		virtual bool initializeAction() = 0;
	};

#define DECL_EFFECTOBJECT_VIRTUALS() \
	virtual void setActionSequence(short, short) override; \
	virtual bool setAction(short) override; \
	virtual void setSequence(short) override; \
	virtual void resetSequence() override; \
	virtual bool nextSequence() override; \
	virtual void prevSequence() override; \
	virtual void setPose(short) override; \
	virtual bool nextPose() override; \
	virtual void prevPose() override; \
	virtual void update() override; \
	virtual void render() override; \
	virtual void render2() override; \
	virtual void applyTransform() override; \
	virtual void onRenderEnd() override; \
	virtual bool initializeAction() override;

	class EffectObject : public EffectObjectBase {
	public:
		char unknown170[0x8];
		DECL_EFFECTOBJECT_VIRTUALS()
	};

	class InfoEffectObject : public EffectObjectBase {
	public:
		char unknown170[0x4];
		float unknown174;
		DECL_EFFECTOBJECT_VIRTUALS()
	};

	class SelectEffectObject : public EffectObjectBase {
	public:
		DECL_EFFECTOBJECT_VIRTUALS()
	};

	class WeatherEffectObject : public EffectObjectBase {
	public:
		char unknown170[0x10];
		DECL_EFFECTOBJECT_VIRTUALS()
	};
}
}

#endif //SOKULIB_ANIMATIONOBJECT_HPP
