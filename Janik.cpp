#include <iostream>

class Vector {
	double x, y, z;
public:
	Vector() : x(0), y(0), z(0) {}

	Vector(double x, double y, double z) : x(x), y(y), z(z) {}

	Vector operator-() const {
		return Vector(-x, -y, -z);
	}

	Vector operator*(double a) const {
		return Vector(x*a, y*a, z*a);
	}

	friend Vector operator+(const Vector& vec1, const Vector& vec2) {
		return Vector(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
	}

	friend Vector operator-(const Vector& vec1, const Vector& vec2) {
		return Vector(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
	}

	friend double operator*(const Vector& vec1, const Vector& vec2) {
		return vec1.x*vec2.x + vec1.y*vec2.y + vec1.z*vec2.z;
	}

	friend Vector operator*(double a, const Vector& vec) {
		return vec * a;
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
		os << "[ " << vec.x << ", " << vec.y << ", " << vec.z << " ]";
		return os;
	}
};

int main() {
	Vector w1(1,1,1), w2(2,2,2), w3(1,2,1);
	Vector v = -(w1 + w2 - w3);
	Vector w = 2*v + w1*2;
	std::cout << v << " " << w
			  << " " << v*w << std::endl;
}