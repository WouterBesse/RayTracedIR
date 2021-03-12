cmake_minimum_required(VERSION 3.17)
project(WoutersClassKaas CXX CUDA)

set(CMAKE_CUDA_STANDARD 14)

include(FetchContent)

FetchContent_Declare(port_audio GIT_REPOSITORY "https://github.com/PortAudio/portaudio.git")
FetchContent_MakeAvailable(port_audio)

FetchContent_Declare(fmtlib GIT_REPOSITORY https://github.com/fmtlib/fmt.git)
FetchContent_MakeAvailable(fmtlib)

add_executable(Appeltaart main.cpp synth.cpp convolution.cu oscillator.cpp sampleconv.cpp sine.cpp square.cpp triangle.cpp)

set_target_properties(Appeltaart PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
set_target_properties(Appeltaart PROPERTIES LINKER_LANGUAGE "CXX")

target_compile_features(Appeltaart PRIVATE cxx_std_17)

target_link_libraries(Appeltaart PRIVATE portaudio_static fmt::fmt)