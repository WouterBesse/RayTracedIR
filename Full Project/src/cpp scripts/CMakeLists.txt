cmake_minimum_required(VERSION 3.17)
project(RayTracedReverb)

include(FetchContent)

FetchContent_Declare(port_audio GIT_REPOSITORY "https://github.com/PortAudio/portaudio.git")
FetchContent_MakeAvailable(port_audio)

add_definitions(-DUNICODE -D_UNICODE)
add_executable(RayVerb main.cpp reverb.cpp ringbuffer.cpp camera.cpp ray.cpp rayTracer.cpp shape.cpp vectormath.cpp)

target_compile_features(RayVerb PRIVATE cxx_std_17)

target_link_libraries(RayVerb PRIVATE portaudio_static)