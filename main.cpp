#include <iostream>
#include <sstream>

import IOUtil;
import vecmath;

using namespace std;

int main() {

    int nx = 200;
    int ny = 100;

    stringstream buffer;

    buffer << "P3" << endl << nx << " " << ny << endl << 255 << endl;

    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {

            float r = float(i) / float(nx);
            float g = float(j) / float(ny);
            float b = 0.2;
            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);

            buffer << ir << " " << ig << " " << ib << endl;

        }

    }


    Vec3 v1 = Vec3(3, 3, 3);
    v1 *= 3.0f;

    cout << v1.x() << v1.y() << v1.z();


    IOUtil::putContents("demo.ppm", buffer.str());

}