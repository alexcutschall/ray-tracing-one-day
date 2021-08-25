#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
    public:
        // initialize an empty vector
        vec3() : e{0,0,0} {}
        // initialize vector with values
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        // Vector Operations

        // Addition
        vec3& operator+=(const vec3 &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        // Multiplication
        vec3& operator*=(const double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        // Division
        vec3& operator/=(const double t) {
            // This is a clever solution. It reuses the multiplication code
            // in order to do the divison
            return *this *= 1/t;
        }
        
        // Negate values
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]);  }

        // Retrieve value from vec3 array
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        // Length Operators
        double length_squared() const {
            return (e[0] * e[0]) + (e[1] * e[1]) * (e[2] * e[2]) ;
        }

        double length() const {
            // Clever in reusing code. It seems a bit more confusing than
            // how the division operator is, but functionality is correct
            return sqrt(length_squared());
        }

    public:
        double e[3];
        void print() {
            std::cout << "\rMaking sure everything works properly\n";
        }
};

// vec3 Utility Functions

// Output Values
inline std::ostream& operator<<(std::ostream &out, const vec3 &vec) {
    return out << vec.e[0] << ' ' << vec.e[1] << ' ' << vec.e[2];
}

// Add two vectors
inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// Subtract two vectors
inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// Multiply two vectors
inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * u.e[0], u.e[1] * v.e[1], v.e[2] * v.e[2]);
}

// Scale vector values by multiplier (make larger)
inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

// I don't really see the difference in the difference
// ways that it scales the vector other than where you put the muliplier.

// Scale vector with division (make smaller)


// Dot product

// Shirley mentions that you should probably review linear algebra for things like the dot product
// I don't have a ton of experience with linear algebra and it was still quite easy to follow
// without having to go through an entire textbook.

// This is what I followed:
// https://betterexplained.com/articles/vector-calculus-understanding-the-dot-product/
inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2];
}

// Cross product

// Unit vector


// Type aliases for vec3
using point3 = vec3;   // 3D point
using color = vec3;    // RGB color

#endif
