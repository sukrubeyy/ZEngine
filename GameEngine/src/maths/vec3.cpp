#include "vec3.h"

namespace ZEngine {
	namespace maths {

		vec3::vec3() {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		vec3::vec3(const float& x, const float& y, const float& z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3& vec3::add(const vec3& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		vec3& vec3::distance(const vec3& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}
		vec3& vec3::multply(const vec3& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}
		vec3& vec3::divide(const vec3& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;
		}
		vec3& vec3::operator+=(const vec3& other) {
			return add(other);
		}
		vec3& vec3::operator-=(const vec3& other) {
			return distance(other);
		}
		vec3& vec3::operator*=(const vec3& other) {
			return multply(other);
		}
		vec3& vec3::operator/=(const vec3& other) {
			return divide(other);
		}
		vec3 operator+(vec3 left, vec3& const right) {
			return left.add(right);
		}
		vec3 operator/(vec3 left, vec3& const right) {
			return left.divide(right);
		}
		vec3 operator*(vec3 left, vec3& const right) {
			return left.multply(right);
		}
		vec3 operator-(vec3 left, vec3& const right) {
			return left.distance(right);
		}

		std::ostream& operator<<(std::ostream& stream, const vec3& vect)
		{
			stream << "vec3(" << vect.x << "," << vect.y << "," << vect.z << ")";
			return stream;
		}
		bool vec3::operator==(const vec3& other) {
			return this->x == other.x && this->y == other.y && this->z == other.z;
		}
		bool vec3::operator!=(const vec3& other) {
			return !(*this == other);
		}
	}
}