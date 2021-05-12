//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_MEMORY_HPP
#define SOKULIB_MEMORY_HPP


namespace SokuLib
{
	extern void *(* const NewFct)(size_t size);
	extern void (* const Delete)(void *p);

	// new/delete
	template<typename T = void>
	T *New(size_t size)
	{
		return reinterpret_cast<T *>(NewFct(size * sizeof(T)));
	}
}


#endif //SOKULIB_MEMORY_HPP
