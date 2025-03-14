module;

import vecmath;
import ray;

export module hitable;

export struct hitRecord {
    float t;
    Vec3 p;
    Vec3 normal;
};

export class Hitable {

    public:
        virtual bool hit(const Ray& r, float tmin, float tmax, hitRecord& rec) const = 0;
};