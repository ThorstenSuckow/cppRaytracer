#include <iostream>
#include <sstream>

import IOUtil;
import math;

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



    IOUtil::putContents("demo.ppm", buffer.str());

}