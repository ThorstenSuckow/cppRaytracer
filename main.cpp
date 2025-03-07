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

    cout << "Vector: " << v1 << endl;
    v1.makeUnitVector();
    cout << "Vector: " << v1 << endl;
    Vec3 v4 = v1 * v1;
    cout << "Vector: " << v4 << endl;
    
    Vec3 v5 = Vec3(1, 1, 1);
    
    v5 = 3.0f * v5;
    cout << "Vector: " << v5 << endl;

    v5 = v5 / 3.0f;
    cout << "Vector: " << v5 << endl;



    IOUtil::putContents("demo.ppm", buffer.str());

}