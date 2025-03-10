#include <iostream>
#include <sstream>

import IOUtil;
import vecmath;
import ray;


using namespace std;

Vec3 color(const Ray &r) {
    Vec3 unitDirection = Vec3::unitVector(r.direction());
    float t = 0.5 * (unitDirection.y() + 1.0f);
    return (1.0 - t) * Vec3(1.0f, 1.0f, 1.0f) + t * Vec3(0.5f, 0.7f, 1.0f);
}

int main() {

    int nx = 200;
    int ny = 100;

    stringstream buffer;

    buffer << "P3" << endl << nx << " " << ny << endl << 255 << endl;

    Vec3 lowerLeftCorner(-2.0f, -1.0f, -1.0f);
    Vec3 horizontal(8.0f, 0.0f, 0.0f);
    Vec3 vertical(0.0f, 2.0f, 0.0f);
    Vec3 origin(0.0f, 0.0f, 0.0f);

    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {

            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            

            Ray r(origin, lowerLeftCorner + u * horizontal + v * vertical);

            Vec3 col = color(r);


            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            buffer << ir << " " << ig << " " << ib << endl;

        }
    }

    
    //cout << buffer.str();
    IOUtil::putContents("demo.ppm", buffer.str());

}