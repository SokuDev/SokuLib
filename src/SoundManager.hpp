//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_SOUNDMANAGER_HPP
#define SOKULIB_SOUNDMANAGER_HPP


namespace SokuLib
{
	// SE�Đ�
	extern void (* const playSEWaveBuffer)(int id);
	extern void (* const playNetBell)(int id);

	static void playBGM(const char *path)
	{
		((void (*)(const char *))0x43ff10)(path);
	}
}



#endif //SOKULIB_SOUNDMANAGER_HPP
