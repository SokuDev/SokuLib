//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_SCENESIZE_HPP
#define SOKULIB_SCENESIZE_HPP

//From swrs.h (SWRSToys.h)

#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �N���X�T�C�Y�I�y�����h
	 #ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline unsigned int CLogo_Size()
	{
		return (*(unsigned int *)ADDR_LOGO_SIZE);
	}

	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline unsigned int Opening_Size()
	{
		return *(unsigned int *)ADDR_OPENING_SIZE;
	}

	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline unsigned int CLoading_Size()
	{
		return *(unsigned int *)ADDR_LOADING_SIZE;
	}

	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline unsigned int CTitle_Size()
	{
		return *(unsigned int *)ADDR_TITLE_SIZE;
	}

	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline unsigned int CSelect_Size()
	{
		return *(unsigned int *)ADDR_SELECT_SIZE;
	}

	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline unsigned int CSelectScenario_Size()
	{
		return *(unsigned int *)ADDR_SELECT_SCENARIO_SIZE;
	}

	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline unsigned char CBattle_Size()
	{
		return *(unsigned char *)ADDR_BATTLE_SIZE;
	}

	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline unsigned int Ending_Size()
	{
		return *(unsigned int *)ADDR_ENDING_SIZE;
	}

	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline unsigned int CLoadingSV_Size()
	{
		return *(unsigned int *)ADDR_LOADINGSV_SIZE;
	}

	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline unsigned int CLoadingCL_Size()
	{
		return *(unsigned int *)ADDR_LOADINGCL_SIZE;
	}

	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline unsigned char CBattleCL_Size()
	{
		return *(unsigned char *)ADDR_BATTLECL_SIZE;
	}

	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline unsigned int CLoadingWatch_Size()
	{
		return *(unsigned int *)ADDR_LOADING_WATCH_SIZE;
	}

	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline unsigned char CBattleWatch_Size()
	{
		return *(unsigned char *)ADDR_BATTLE_WATCH_SIZE;
	}

	__forceinline unsigned int CSelectCL_Size()
	{
		return *reinterpret_cast<unsigned int *>(ADDR_SELECT_CL_SIZE);
	}

	__forceinline unsigned int CSelectSV_Size()
	{
		return *reinterpret_cast<unsigned int *>(ADDR_SELECT_SV_SIZE);
	}

	__forceinline unsigned int CBattleManager_Size()
	{
		return *reinterpret_cast<unsigned int *>(ADDR_BATTLE_MANAGER_SIZE);
	}

}

#endif //SOKULIB_SCENESIZE_HPP
