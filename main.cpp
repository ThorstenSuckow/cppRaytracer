#include <iostream>
#include <sstream>

import IOUtil;
import vecmath;
import ray;
import sphere;
import hitable;
import camera;

using namespace std;

void init_srand() {
    srand(time(0));
}

/** 
 * Create arandom float.
 */
float random_f() {
    return static_cast<float>(rand()) / (RAND_MAX - 1);
}

Vec3 randomInUnitSphere() {
    Vec3 p;
    Vec3 sub(1, 1, 1);
    do {
        p = 2.0f * Vec3(random_f(), random_f(), random_f()) - sub;
    } while (p.squaredLength() >= 1.0f);

    return p;
}


Vec3 color(const Ray &r, Hitable *world) {
    
    hitRecord rec;
    const float maxFloat = numeric_limits<float>::max();

    if (world->hit(r, 0.0f, maxFloat, rec)) {
        Vec3 target = rec.p + rec.normal + randomInUnitSphere();
        return 0.5f * color(Ray(rec.p, target - rec.p), world);
    }
    else {
        Vec3 unitDirection = Vec3::unitVector(r.direction());
        float t = 0.5f * (unitDirection.y() + 1.0f);
        return (1.0f - t) * Vec3(1.0f, 1.0f, 1.0f) + t * Vec3(0.5f, 0.7f, 1.0f);
    }

}

int main() {

    init_srand();

    int nx = 200;
    int ny = 100;
    int ns = 100;

    stringstream buffer;

    buffer << "P3" << endl << nx << " " << ny << endl << 255 << endl;

    Hitable* list[2];
    list[0] = new Sphere(Vec3(0.0f, 0.0f, -1.0f), 0.5f);
    list[1] = new Sphere(Vec3(0.0f, -100.5f, -1.0f), 100.0f);

    Hitable* world = new HitableList(list, 2);

    Camera cam;

    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            
            Vec3 col(0, 0, 0);
            
            for (int s = 0; s < ns; s++) {
                float u = float(i + random_f()) / float(nx);
                float v = float(j + random_f()) / float(ny);
                Ray r = cam.getRay(u, v);
                Vec3 p = r.pointAtParameter(2.0);
                col += color(r, world);
            }
            col /= static_cast<float>(ns);
    
            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            buffer << ir << " " << ig << " " << ib << endl;
        }
    }

    //cout << buffer.str();
    IOUtil::putContents("demo.ppm", buffer.str());
}