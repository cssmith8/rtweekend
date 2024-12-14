cmake_minimum_required(VERSION 3.22)
project(atl)

set(CMAKE_CXX_STANDARD 14)

add_executable(atl main.cpp vec3.h color.h ray.h hittable.h sphere.h hittable_list.h rtweekend.h interval.h camera.h material.h utils.h fractal.h)
