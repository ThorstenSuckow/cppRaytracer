module;

import vecmath;
import ray;

export module camera;


export class Camera {

    public: 
        Camera() {
            lowerLeftCorner = Vec3(-2.0f, -1.0f, -1.0f);
            horizontal = Vec3(4.0f, 0.0f, 0.0f);
            vertical = Vec3(0.0f, 2.0f, 0.0f);
            origin = Vec3(0.0f, 0.0f, 0.0f);
        }

        Ray getRay(float u, float v) {
            return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
        }

    private:
        Vec3 origin;
        Vec3 lowerLeftCorner;
        Vec3 horizontal;
        Vec3 vertical;
};