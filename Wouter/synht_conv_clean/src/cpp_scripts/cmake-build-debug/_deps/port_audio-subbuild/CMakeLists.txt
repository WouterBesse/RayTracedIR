# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.17.5)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(port_audio-populate NONE)

include(ExternalProject)
ExternalProject_Add(port_audio-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/PortAudio/portaudio.git"
                    SOURCE_DIR          "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/synht_conv_clean/src/cpp_scripts/cmake-build-debug/_deps/port_audio-src"
                    BINARY_DIR          "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/synht_conv_clean/src/cpp_scripts/cmake-build-debug/_deps/port_audio-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)
