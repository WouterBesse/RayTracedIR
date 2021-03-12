# Install script for directory: H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/port_audio_test")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/portaudio" TYPE FILE FILES "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-src/README.md")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/portaudio" TYPE FILE FILES "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-src/LICENSE.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-build/portaudio-2.0.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-src/include/portaudio.h"
    "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-src/include/pa_win_ds.h"
    "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-src/include/pa_win_waveformat.h"
    "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-src/include/pa_win_wmme.h"
    "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-src/include/pa_win_waveformat.h"
    "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-src/include/pa_win_wasapi.h"
    "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-src/include/pa_win_waveformat.h"
    "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-src/include/pa_win_wdmks.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-build/libportaudio.dll.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-build/libportaudio.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libportaudio.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libportaudio.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libportaudio.dll")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-build/libportaudio.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/portaudio/portaudioTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/portaudio/portaudioTargets.cmake"
         "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-build/CMakeFiles/Export/lib/cmake/portaudio/portaudioTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/portaudio/portaudioTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/portaudio/portaudioTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/portaudio" TYPE FILE FILES "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-build/CMakeFiles/Export/lib/cmake/portaudio/portaudioTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/portaudio" TYPE FILE FILES "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-build/CMakeFiles/Export/lib/cmake/portaudio/portaudioTargets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/portaudio" TYPE FILE FILES
    "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/cmake/portaudio/portaudioConfig.cmake"
    "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/cmake/portaudio/portaudioConfigVersion.cmake"
    )
endif()

