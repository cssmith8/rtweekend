#ifndef FRACTAL_H
#define FRACTAL_H

#include "rtweekend.h"

#include "hittable_list.h"
#include "material.h"
#include "sphere.h"
#include "utils.h"

#include <string>
#include <cmath>
using std::string;

void fractal_sphere(hittable_list& world, const float dividend, const int maxDepth, string path) {
    char last = (path == "") ? ' ' : last_letter(path);
    int depth = path.size();

    float size = pow(dividend, depth);
    point3 position = point3(0, 0, 0);

    //for each letter in the path
    for (int i = 0; i < depth; i++) {
        char letter = path[i];

        float closeDistance = pow(dividend, i);
        float farDistance = pow(dividend, i + 1);
        float distance = closeDistance + farDistance;

        switch (letter) {
            case 'F':
                position += vec3(0, 0, distance);
                break;
            case 'B':
                position += vec3(0, 0, -distance);
                break;
            case 'L':
                position += vec3(distance, 0, 0);
                break;
            case 'R':
                position += vec3(-distance, 0, 0);
                break;
            case 'U':
                position += vec3(0, distance, 0);
                break;
            case 'D':
                position += vec3(0, -distance, 0);
                break;
        }
    }

    //draw the sphere
    shared_ptr<material> sphere_material;
    auto albedo = color(position.x() / 8 + 0.5, position.y() / 8 + 0.5, position.z() / 8 + 0.5);
    sphere_material = make_shared<lambertian>(albedo);
    world.add(make_shared<sphere>(position, size, sphere_material));

    if (depth >= maxDepth) return;

    if (last != 'F') fractal_sphere(world, dividend, maxDepth, path + 'B');
    if (last != 'B') fractal_sphere(world, dividend, maxDepth, path + 'F');
    if (last != 'L') fractal_sphere(world, dividend, maxDepth, path + 'R');
    if (last != 'R') fractal_sphere(world, dividend, maxDepth, path + 'L');
    if (last != 'U') fractal_sphere(world, dividend, maxDepth, path + 'D');
    if (last != 'D') fractal_sphere(world, dividend, maxDepth, path + 'U');
}

#endif //FRACTAL_H