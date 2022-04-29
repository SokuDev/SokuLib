//
// Created by PinkySmile on 12/05/2021.
//

#ifndef SOKULIB_VECTOR2_HPP
#define SOKULIB_VECTOR2_HPP


#include <d3dx9.h>

namespace SokuLib
{
	template<typename T>
	struct Vector2 {
		T x;
		T y;

		template<typename T2>
		bool operator==(const Vector2<T2> &other) const
		{
			return this->x == other.x && this->y == other.y;
		}

		template<typename T2>
		Vector2<T> &operator-=(Vector2<T2> other)
		{
			this->x -= other.x;
			this->y -= other.y;
			return *this;
		}

		template<typename T2>
		Vector2<T> operator-(const Vector2<T2> &other) const
		{
			return {
				static_cast<T>(this->x - other.x),
				static_cast<T>(this->y - other.y)
			};
		}

		template<typename T2>
		Vector2<T> operator-(T2 other) const
		{
			return {
				static_cast<T>(this->x - other),
				static_cast<T>(this->y - other)
			};
		}

		template<typename T2>
		Vector2<T> &operator+=(Vector2<T2> other)
		{
			this->x += other.x;
			this->y += other.y;
			return *this;
		}

		template<typename T2>
		Vector2<T> operator+(const Vector2<T2> &other) const
		{
			return {
				static_cast<T>(this->x + other.x),
				static_cast<T>(this->y + other.y)
			};
		}

		template<typename T2>
		Vector2<T> &operator*=(T2 scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			return *this;
		}

		template<typename T2>
		auto operator*(T2 scalar) const
		{
			return Vector2<decltype(this->x * scalar)>{
				this->x * scalar,
				this->y * scalar
			};
		}

		template<typename T2>
		Vector2<T> &operator/=(T2 scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
			return *this;
		}

		template<typename T2>
		auto operator/(T2 scalar) const
		{
			return Vector2<decltype(this->x / scalar)>{
				this->x / scalar,
				this->y / scalar
			};
		}

		Vector2<float> rotate(float angle, const Vector2<T> &center) const noexcept
		{
			if (angle == 0.f)
				return {
					static_cast<float>(this->x),
					static_cast<float>(this->y)
				};

			float c = cos(angle);
			float s = sin(angle);

			Vector2<float> result{
				static_cast<float>(c * (static_cast<float>(this->x) - center.x) - s * (static_cast<float>(this->y) - center.y) + center.x),
				static_cast<float>(s * (static_cast<float>(this->x) - center.x) + c * (static_cast<float>(this->y) - center.y) + center.y)
			};

			return result;
		}

		template<typename T2>
		Vector2<T2> to() const
		{
			return {
				static_cast<T2>(this->x),
				static_cast<T2>(this->y)
			};
		}

		operator D3DXVECTOR2() const
		{
			return {
				static_cast<float>(this->x),
				static_cast<float>(this->y)
			};
		}
	};

	typedef Vector2<float>              Vector2f;
	typedef Vector2<int>                Vector2i;
	typedef Vector2<unsigned>           Vector2u;
	typedef Vector2<long>               Vector2l;
	typedef Vector2<unsigned long>      Vector2ul;
	typedef Vector2<long long>          Vector2ll;
	typedef Vector2<unsigned long long> Vector2ull;
	typedef Vector2<double>             Vector2d;
	typedef Vector2<bool>               Vector2b;
}


#endif //SOKULIB_VECTOR2_HPP
