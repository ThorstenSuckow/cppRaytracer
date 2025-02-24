module vecmath;

using namespace std;

Vec3::Vec3() {
}

Vec3::Vec3(float e0, float e1, float e2) {

    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
}

inline Vec3& Vec3::operator/=(const float t) {
    float k = 1.0 / t;
    e[0] *= k;
    e[1] *= k;
    e[2] *= k;

    return *this;
}