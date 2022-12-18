#include "vec4.h"

namespace ZEngine {
	namespace maths {

		vec4::vec4() {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
		}

		vec4::vec4(const float& x, const float& y, const float& z, const float& w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		vec4& vec4::add(const vec4& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;
		}

		vec4& vec4::distance(const vec4& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;
		}
		vec4& vec4::multply(const vec4& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return *this;
		}
		vec4& vec4::divide(const vec4& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return *this;
		}
		vec4& vec4::operator+=(const vec4& other) {
			return add(other);
		}
		vec4& vec4::operator-=(const vec4& other) {
			return distance(other);
		}
		vec4& vec4::operator*=(const vec4& other) {
			return multply(other);
		}
		vec4& vec4::operator/=(const vec4& other) {
			return divide(other);
		}
		vec4 operator+(vec4 left, vec4& const right) {
			return left.add(right);
		}
		vec4 operator/(vec4 left, vec4& const right) {
			return left.divide(right);
		}
		vec4 operator*(vec4 left, vec4& const right) {
			return left.multply(right);
		}
		vec4 operator-(vec4 left, vec4& const right) {
			return left.distance(right);
		}

		std::ostream& operator<<(std::ostream& stream, const vec4& vect)
		{
			stream << "vec4(" << vect.x << "," << vect.y << "," << vect.z << "," << vect.w << ")";
			return stream;
		}
		bool vec4::operator==(const vec4& other) {
			return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
		}
		bool vec4::operator!=(const vec4& other) {
			return !(*this == other);
		}
	}
}