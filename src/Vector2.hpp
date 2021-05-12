//
// Created by PinkySmile on 12/05/2021.
//

#ifndef SOKULIB_VECTOR2_HPP
#define SOKULIB_VECTOR2_HPP

namespace SokuLib
{
	template <typename T>
	struct Vector2 {
		T x;
		T y;
	};

	typedef Vector2<float>              Vector2f;
	typedef Vector2<int>                Vector2i;
	typedef Vector2<unsigned>           Vector2u;
	typedef Vector2<long>               Vector2l;
	typedef Vector2<unsigned long>      Vector2ul;
	typedef Vector2<long long>          Vector2ll;
	typedef Vector2<unsigned long long> Vector2ull;
	typedef Vector2<double>             Vector2d;
}


#endif //SOKULIB_VECTOR2_HPP
