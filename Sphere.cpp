import vecmath;
import hitable;
import ray;

export class Sphere : public Hitable {

    public:
        Sphere() {};

        Sphere(Vec3 cen, float r) : center(cen), radius(r) {};

        virtual bool hit(const Ray& r, float tmin, float tmax, hitRecord& rec) const;

        Vec3 center;
        float radius;

};

bool Sphere::hit(const Ray& r, float tmin, float tmax, hitRecord& rec) const {

    Vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = /* 2* */dot(oc, r.direction());
    float c = dot(oc, oc) - radius*radius;

    float discriminant = b * b - /* 4* */ a * c;

    if (discriminant > 0.0f) {
        // discriminant > 0 and temp w/in interval: 
        // closer to ray origin
        float temp = (-b - sqrt(discriminant)) / a;

        if (temp < tmax && temp > tmin) {
            rec.t = temp;
            rec.p = r.pointAtParameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < tmax && temp > tmin) {
            rec.t = temp;
            rec.p = r.pointAtParameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
    }

    return false;
    

}
