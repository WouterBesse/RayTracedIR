cmake_minimum_required(VERSION 3.17)
project(AudioRayTracer)

add_executable(RayTracer main.cpp ray.cpp shape.cpp vectormath.cpp imager.cpp camera.cpp)

target_compile_features(RayTracer PRIVATE cxx_std_17)