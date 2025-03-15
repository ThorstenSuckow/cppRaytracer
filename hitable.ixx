module;

export module hitable;

import vecmath;
import ray;

export struct hitRecord {
    float t;
    Vec3 p;
    Vec3 normal;
};

export class Hitable {
    public:
        virtual bool hit(const Ray& r, float tmin, float tmax, hitRecord& rec) const = 0;
};

export class HitableList : public Hitable {
    public:
        HitableList() {}
        HitableList(Hitable** l, int n) { list = l; listSize = n; }

        virtual bool hit(const Ray& r, float tmin, float tmax, hitRecord& rec) const;

        Hitable** list;
        int listSize;
};

bool HitableList::hit(const Ray& r, float tmin, float tmax, hitRecord& rec) const {

    hitRecord tempRec;
    bool hitAnything = false;

    float closestSoFar = tmax;

    for (int i = 0; i < listSize; i++) {
        if (list[i]->hit(r, tmin, closestSoFar, tempRec)) {
            hitAnything = true;
            closestSoFar = tempRec.t;
            rec = tempRec;
        }
    }

    return hitAnything;
}


