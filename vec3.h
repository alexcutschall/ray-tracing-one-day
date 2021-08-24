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
        }

        // Subtraction
        

        // Negate values
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]);  }

        // Retrieve value from vec3 array
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        public:
            void print() {
                std::cout << "\rMaking sure everything works properly\n";
            }

    public:
        double e[3];
};

// Type aliases for vec3
using point3 = vec3;   // 3D point
using color = vec3;    // RGB color

#endif
