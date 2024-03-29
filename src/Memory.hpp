//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_MEMORY_HPP
#define SOKULIB_MEMORY_HPP


namespace SokuLib
{
	extern void *(* const NewFct)(size_t size);
	extern void (* const DeleteFct)(void *p);

	// new/delete
	template<typename T = void, typename ...Args>
	T *New(size_t size, Args &&...args)
	{
		auto allocated = reinterpret_cast<T *>(NewFct(size * sizeof(T)));

		if constexpr(!std::is_trivially_constructible<T, Args...>::value)
			new (allocated) T(args...);
		return allocated;
	}

	template<typename T>
	void Delete(T *ptr)
	{
		if constexpr(!std::is_trivially_destructible<T>::value)
			ptr->~T();
		DeleteFct(ptr);
	}
}


#endif //SOKULIB_MEMORY_HPP
