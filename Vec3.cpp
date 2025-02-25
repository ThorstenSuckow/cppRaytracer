module vecmath;

using namespace std;

Vec3::Vec3() {
}

Vec3::Vec3(float e0, float e1, float e2) {

    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
}

Vec3& Vec3::operator/=(const float t) {
    float k = 1.0f / t;
    e[0] *= k;
    e[1] *= k;
    e[2] *= k;

    return *this;
}

Vec3& Vec3::operator*=(const float t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;

    return *this;
}

Vec3& Vec3::operator-=(const Vec3& v2) {
    e[0] -= v2.e[0];
    e[1] -= v2.e[1];
    e[2] -= v2.e[2];

    return *this;
}

Vec3& Vec3::operator/=(const Vec3& v2) {
    e[0] /= v2.e[0];
    e[1] /= v2.e[1];
    e[2] /= v2.e[2];

    return *this;
}

Vec3& Vec3::operator*=(const Vec3& v2) {
    e[0] *= v2.e[0];
    e[1] *= v2.e[1];
    e[2] *= v2.e[2];

    return *this;
}


Vec3& Vec3::operator+=(const Vec3& v2) {
    e[0] += v2.e[0];
    e[1] += v2.e[1];
    e[2] += v2.e[2];

    return *this;
}

Vec3 operator/(const Vec3& v1, const float t) {
    return Vec3(v1.x() / t, v1.y() / t, v1.z() / t);

};


Vec3 Vec3::unitVector(const Vec3& v2) {

    return v2 / v2.length();

}