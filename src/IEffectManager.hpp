//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_IEFFECTMANAGER_HPP
#define SOKULIB_IEFFECTMANAGER_HPP

//From swrs.h (SWRSToys)

#include "AnimationObject.hpp"
#include "SokuAddresses.hpp"
#include "UnionCast.hpp"
#include "HandleManager.hpp"

namespace SokuLib
{
	// this is used to simulate the double inheritance in EffectManager
	extern void* const __EffectManager_lower_vtable[];

	struct IEffectManager {
		virtual ~IEffectManager() {}
		virtual void LoadPattern(const char* fileName, int reserve) = 0;
		virtual void ClearPattern() = 0;
		virtual v2::EffectObjectBase* CreateEffect(int action, float x, float y, char dir, char layer, int unknown164) = 0;
		virtual void ClearEffects() = 0;
		virtual void Update() = 0;
		virtual void Render(char layer) = 0;
		virtual void vfUnknown7() = 0; // do nothing
		virtual void vfUnknown8(int unknown164) = 0;
	};

namespace v2 {
	template<class T>
	class EffectManager : public IEffectManager {
	private:
		static_assert(std::is_base_of<EffectObjectBase, T>::value);
		// this is used to simulate the double inheritance in EffectManager
		void** __lower_vtable = (void**)__EffectManager_lower_vtable;

	public:
		HandleManagerEx<T> handles;
		List<T*> effects;
		Vector<int> textureIds;
		Deque<SequenceData> patterns;
		Map<int, SequenceData*> patternById;

		EffectManager() = default;
		virtual ~EffectManager() = default;
		void LoadPattern(const char* fileName, int reserve) override;
		void ClearPattern() override;
		v2::EffectObjectBase* CreateEffect(int action, float x, float y, char dir, char layer, int unknown164) override;
		void ClearEffects() override;
		void Update() override;
		void Render(char layer) override;
		void vfUnknown7() override;
		void vfUnknown8(int unknown164) override;
	};

	using EffectManager_Effect = EffectManager<EffectObject>;
	using EffectManager_InfoEffect = EffectManager<InfoEffectObject>;
	using EffectManager_Select = EffectManager<SelectEffectObject>;
	using EffectManager_Weather = EffectManager<WeatherEffectObject>;

	class SystemEffectManager {
	public:
		HandleManagerEx<SystemEffectObject> handles;
		List<SystemEffectObject*> objects;

		virtual ~SystemEffectManager() = default;
		SystemEffectObject* createEffect(const char* textureName, short actionId, float x, float y); // 0x460560
	}; // 0x60
}
}

#endif //SOKULIB_IEFFECTMANAGER_HPP
