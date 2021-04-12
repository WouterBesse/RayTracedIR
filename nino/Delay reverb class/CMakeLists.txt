cmake_minimum_required(VERSION 3.17)
project(NinoVerb)

include(FetchContent)

FetchContent_Declare(port_audio GIT_REPOSITORY "https://github.com/PortAudio/portaudio.git")
FetchContent_MakeAvailable(port_audio)

add_executable(example reverb.cpp ringbuffer.cpp main.cpp)

target_compile_features(example PRIVATE cxx_std_17)

target_link_libraries(example PRIVATE portaudio_static)