//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_UNKNOWNSTUFF_HPP
#define SOKULIB_UNKNOWNSTUFF_HPP


#include "SokuAddresses.hpp"

namespace SokuLib
{
	#pragma pack(push, 4)
	// �悭�킩��Ȃ�����
	struct UnknownF {
		void *Unknown[3];
		float Aaxis;
		float Baxis;
	};
	#pragma pack(pop)

	// �R���o�[�g�f�[�^���p�t���O
	// bool
	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline bool useCVxData()
	{
		//TODO: Find this for version 1.10a
		return *(bool*)ADDR_USE_CV_X_DATA;
	}

	// �p���b�g�I�u�W�F�N�g
	// void *
	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline void *getPaletter()
	{
		//TODO: Find this for version 1.10a
		return *(void **)ADDR_PALETTER;
	}
}


#endif //SOKULIB_UNKNOWNSTUFF_HPP
