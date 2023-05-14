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
		virtual v2::EffectObjectBase* CreateEffect(int action, float x, float y, Direction dir, char layer, int unknown164) = 0;
		virtual void ClearEffects() = 0;
		virtual void Update() = 0;
		virtual void Render(char layer) = 0;
		virtual void vfUnknown7() = 0; // do nothing
		virtual void vfUnknown8(int unknown164) = 0;
	};

namespace v2 {
	template<class T, void** base_vtable = (void**)ADDR_VTBL_FXMANAGER_EFFECT>
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
		virtual void LoadPattern(const char* fileName, int reserve) override
			{ return (this->*union_cast<void(IEffectManager::*)(LPCSTR, int)>(base_vtable[1]))(fileName, reserve); }
		virtual void ClearPattern() override
			{ return (this->*union_cast<void(IEffectManager::*)()>(base_vtable[2]))(); }
		virtual EffectObjectBase* CreateEffect(int action, float x, float y, Direction dir, char layer, int unknown164) override
			{ return (this->*union_cast<EffectObjectBase*(IEffectManager::*)(int, float, float, Direction, char, int)>(base_vtable[3]))(action, x, y, dir, layer, unknown164); }
		virtual void ClearEffects() override
			{ return (this->*union_cast<void(IEffectManager::*)()>(base_vtable[4]))(); }
		virtual void Update() override
			{ return (this->*union_cast<void(IEffectManager::*)()>(base_vtable[5]))(); }
		virtual void Render(char arg_0) override
			{ return (this->*union_cast<void(IEffectManager::*)(int)>(base_vtable[6]))(arg_0); }
		virtual void vfUnknown7() override
			{ return (this->*union_cast<void(IEffectManager::*)()>(base_vtable[7]))(); }
		virtual void vfUnknown8(int arg_0) override
			{ return (this->*union_cast<void(IEffectManager::*)(int)>(base_vtable[8]))(arg_0); }
	};

	using EffectManager_Effect = EffectManager<EffectObject, (void**)ADDR_VTBL_FXMANAGER_EFFECT>;
	using EffectManager_InfoEffect = EffectManager<InfoEffectObject, (void**)ADDR_VTBL_FXMANAGER_INFOFX>;
	using EffectManager_Select = EffectManager<SelectEffectObject, (void**)ADDR_VTBL_FXMANAGER_SELECT>;
	using EffectManager_Weather = EffectManager<WeatherEffectObject, (void**)ADDR_VTBL_FXMANAGER_WEATHER>;
}
}

#endif //SOKULIB_IEFFECTMANAGER_HPP
