//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_SOKUFCT_HPP
#define SOKULIB_SOKUFCT_HPP

//From swrs.h (SWRSToys)

namespace SokuLib
{
	// union_cast
	template<typename TDest, typename TSrc>
	__forceinline TDest union_cast(TSrc src) {
		static_assert(sizeof(TDest) == sizeof(TSrc), "size_mismatch");
		union {  TDest dst; TSrc src; } c;
		c.src = src;
		return c.dst;
	}
}

#endif //SOKULIB_SOKUFCT_HPP
