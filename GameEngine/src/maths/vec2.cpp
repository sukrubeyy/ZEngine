#include "vec2.h"

namespace ZEngine {
	namespace maths {

		vec2::vec2() {
			x = 0.0f;
			y = 0.0f;
		}

		vec2::vec2(const float& x, const float& y) {
			this->x = x;
			this->y = y;
		}

		vec2& vec2::add(const vec2& other) {
			x += other.x;
			y += other.y;
			return *this;
		}

		vec2& vec2::distance(const vec2& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}
		vec2& vec2::multply(const vec2& other) {
			x *= other.x;
			y *= other.y;
			return *this;
		}
		vec2& vec2::divide(const vec2& other) {
			x /= other.x;
			y /= other.y;
			return *this;
		}
		vec2& vec2::operator+=(const vec2& other) {
			return add(other);
		}
		vec2& vec2::operator-=(const vec2& other) {
			return distance(other);
		}
		vec2& vec2::operator*=(const vec2& other) {
			return multply(other);
		}
		vec2& vec2::operator/=(const vec2& other) {
			return divide(other);
		}

		vec2 operator+(vec2 left, vec2& const right) {
			return left.add(right);
		}
		vec2 operator/(vec2 left, vec2& const right) {
			return left.divide(right);
		}
		vec2 operator*(vec2 left, vec2& const right) {
			return left.multply(right);
		}
		vec2 operator-(vec2 left, vec2& const right) {
			return left.distance(right);
		}
		std::ostream& operator<<(std::ostream& stream, const vec2& vect)
		{
			stream << "vec2(" << vect.x << "," << vect.y << ")";
			return stream;
		}
		bool vec2::operator==(const vec2& other) {
			return this->x == other.x && this->y == other.y;
		}
		bool vec2::operator!=(const vec2& other) {
			return !(*this == other);
		}
	}
}