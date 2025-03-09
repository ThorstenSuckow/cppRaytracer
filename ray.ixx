module;

import vecmath;


export module ray;

export class Ray {

    public: 
        Ray() {}
        Ray(const Vec3& a, const Vec3& b) {
            A = a; 
            B = b;
        }

        inline Vec3 origin() const { return A;}
        inline Vec3 direction() const { return B; }
        inline Vec3 point_at_parameter(const float t) {
            return A + t * B;
        }

    private:
        Vec3 A;
        Vec3 B;
};