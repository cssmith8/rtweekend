#include "fractal.h"

#include "rtweekend.h"

#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"
#include "utils.h"

#include "camera.h"

int main() {
    srand(time(NULL));

    hittable_list world;

    fractal_sphere(world, 0.5, 4, "");

    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 1080;
    cam.samples_per_pixel = 50;
    cam.max_depth         = 5;

    cam.vfov     = 25;
    cam.lookfrom = point3(13,2,6);
    cam.lookat   = point3(0,0,0);
    cam.vup      = vec3(0,1,0);

    cam.defocus_angle = 0.6;
    cam.focus_dist    = 10.0;

    cam.render(world);
}