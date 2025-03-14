
import vecmath;
import hitable;
import ray;

export class Sphere : public Hitable {

    public:
        Sphere() {};

        Sphere(Vec3 cen, float r) : center(cen), radius(r) {};

        virtual bool hit(const Ray& r, float t_min, float t_max, hitRecord& rec) const;

        Vec3 center;
        float radius;



};

