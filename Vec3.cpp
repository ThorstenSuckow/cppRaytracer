module vecmath;


using namespace std;

/* Constructor */
Vec3::Vec3() {
}

Vec3::Vec3(float e0, float e1, float e2) {

    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
}


/*stream*/
inline istream& operator>>(istream& is, Vec3& t) {
    float x, y, z;
    is >> x >> y >> z;
    t.x(x);
    t.y(y);
    t.z(z);

    return is;
}

inline ostream& operator<<(ostream& os, const Vec3& t) {
    os << t.x() << t.y() << t.z();
    return os;
}

void Vec3::makeUnitVector() {
    float len = 1 / length();
    e[0] *= len;
    e[1] *= len;
    e[2] *= len;
}

Vec3 operator+(const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}

Vec3 operator-(const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
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