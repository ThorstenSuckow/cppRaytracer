#include <iostream>
#include <sstream>

import IOUtil;
import vecmath;
import ray;
import sphere;
import hitable;

using namespace std;


Vec3 color(const Ray &r, Hitable *world) {
    
    hitRecord rec;
    const float maxFloat = numeric_limits<float>::max();

    if (world->hit(r, 0.0f, maxFloat, rec)) {
        return 0.5f * Vec3(
            rec.normal.x() + 1.0f, 
            rec.normal.y() + 1.0f, 
            rec.normal.z() + 1.0f
        );
    }

    Vec3 unitDirection = Vec3::unitVector(r.direction());
    float t = 0.5f * (unitDirection.y() + 1.0f);
    return (1.0f - t) * Vec3(1.0f, 1.0f, 1.0f) + t * Vec3(0.5f, 0.7f, 1.0f);
}

int main() {

    int nx = 200;
    int ny = 100;

    stringstream buffer;

    buffer << "P3" << endl << nx << " " << ny << endl << 255 << endl;

    Vec3 lowerLeftCorner(-2.0f, -1.0f, -1.0f);
    Vec3 horizontal(4.0f, 0.0f, 0.0f);
    Vec3 vertical(0.0f, 2.0f, 0.0f);
    Vec3 origin(0.0f, 0.0f, 0.0f);

    Hitable* list[2];
    list[0] = new Sphere(Vec3(0.0f, 0.0f, -1.0f), 0.5f);
    list[1] = new Sphere(Vec3(0.0f, -100.5f, -1.0f), 100.0f);

    Hitable* world = new HitableList(list, 2);

    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {

            float u = float(i) / float(nx);
            float v = float(j) / float(ny);

            Ray r(origin, lowerLeftCorner + u * horizontal + v * vertical);

            Vec3 col = color(r, world);

            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            buffer << ir << " " << ig << " " << ib << endl;
        }
    }

    //cout << buffer.str();
    IOUtil::putContents("demo.ppm", buffer.str());
}