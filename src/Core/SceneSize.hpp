//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_SCENESIZE_HPP
#define SOKULIB_SCENESIZE_HPP


#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �N���X�T�C�Y�I�y�����h
	 #ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline unsigned int CLogo_Size()
	{
		//TODO: Add this for version 1.10a
		return (*(unsigned int *)ADDR_LOGO_SIZE);
	}

	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline unsigned int Opening_Size()
	{
		//TODO: Add this for version 1.10a
		return *(unsigned int *)ADDR_OPENING_SIZE;
	}

	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline unsigned int CLoading_Size()
	{
		//TODO: Add this for version 1.10a
		return *(unsigned int *)ADDR_LOADING_SIZE;
	}

	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline unsigned int CTitle_Size()
	{
		//TODO: Add this for version 1.10a
		return *(unsigned int *)ADDR_TITLE_SIZE;
	}

	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline unsigned int CSelect_Size()
	{
		//TODO: Add this for version 1.10a
		return *(unsigned int *)ADDR_SELECT_SIZE;
	}

	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline unsigned int CSelectScenario_Size()
	{
		//TODO: Add this for version 1.10a
		return *(unsigned int *)ADDR_SELECT_SCENARIO_SIZE;
	}

	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline unsigned char CBattle_Size()
	{
		//TODO: Add this for version 1.10a
		return *(unsigned char *)ADDR_BATTLE_SIZE;
	}

	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline unsigned int Ending_Size()
	{
		//TODO: Add this for version 1.10a
		return *(unsigned int *)ADDR_ENDING_SIZE;
	}

	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline unsigned int CLoadingSV_Size()
	{
		//TODO: Add this for version 1.10a
		return *(unsigned int *)ADDR_LOADINGSV_SIZE;
	}

	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline unsigned int CLoadingCL_Size()
	{
		//TODO: Add this for version 1.10a
		return *(unsigned int *)ADDR_LOADINGCL_SIZE;
	}

	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline unsigned char CBattleCL_Size()
	{
		//TODO: Add this for version 1.10a
		return *(unsigned char *)ADDR_BATTLECL_SIZE;
	}

	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline unsigned int CLoadingWatch_Size()
	{
		//TODO: Add this for version 1.10a
		return *(unsigned int *)ADDR_LOADING_WATCH_SIZE;
	}

	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline unsigned char CBattleWatch_Size()
	{
		//TODO: Add this for version 1.10a
		return *(unsigned char *)ADDR_BATTLE_WATCH_SIZE;
	}

	extern const unsigned int &CSelectCL_Size;
	extern const unsigned int &CSelectSV_Size;
	extern const unsigned int &CBattleManager_Size;
}


#endif //SOKULIB_SCENESIZE_HPP
