module math;

#include <iostream>

using namespace std;

Vec3::Vec3() {

    cout << "new Vec!";
}

Vec3::Vec3(float e0, float e1, float e2) {

    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
}