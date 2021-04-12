cmake_minimum_required(VERSION 3.17)
project(WoutersClassKaas)

include(FetchContent)

FetchContent_Declare(port_audio GIT_REPOSITORY "https://github.com/PortAudio/portaudio.git")
FetchContent_MakeAvailable(port_audio)

add_executable(Appeltaart main.cpp synth.cpp convolution.cpp oscillator.cpp sampleconv.cpp sine.cpp square.cpp triangle.cpp)

target_compile_features(Appeltaart PRIVATE cxx_std_17)

target_link_libraries(Appeltaart PRIVATE portaudio_static)