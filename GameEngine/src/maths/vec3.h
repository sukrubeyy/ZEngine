#pragma once
#include <iostream>

namespace ZEngine {
	namespace maths {

		struct vec3
		{
			float x, y,z;
			vec3();
			vec3(const float& x, const float& y, const float& z);

			vec3& add(const vec3& other);
			vec3& distance(const vec3& other);
			vec3& multply(const vec3& other);
			vec3& divide(const vec3& other);

			friend vec3 operator+(vec3 left, vec3& right);
			friend vec3 operator-(vec3 left, vec3& right);
			friend vec3 operator*(vec3 left, vec3& right);
			friend vec3 operator/(vec3 left, vec3& right);

			bool operator==(const vec3& other);
			bool operator!=(const vec3& other);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vect);
		};

	}
}