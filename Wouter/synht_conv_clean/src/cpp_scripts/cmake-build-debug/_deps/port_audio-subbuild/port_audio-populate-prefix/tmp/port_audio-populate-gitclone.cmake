
if(NOT "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/synht_conv_clean/src/cpp_scripts/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-gitinfo.txt" IS_NEWER_THAN "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/synht_conv_clean/src/cpp_scripts/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: 'H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/synht_conv_clean/src/cpp_scripts/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/synht_conv_clean/src/cpp_scripts/cmake-build-debug/_deps/port_audio-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: 'H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/synht_conv_clean/src/cpp_scripts/cmake-build-debug/_deps/port_audio-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "C:/Program Files/Git/cmd/git.exe"  clone --no-checkout "https://github.com/PortAudio/portaudio.git" "port_audio-src"
    WORKING_DIRECTORY "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/synht_conv_clean/src/cpp_scripts/cmake-build-debug/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/PortAudio/portaudio.git'")
endif()

execute_process(
  COMMAND "C:/Program Files/Git/cmd/git.exe"  checkout master --
  WORKING_DIRECTORY "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/synht_conv_clean/src/cpp_scripts/cmake-build-debug/_deps/port_audio-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'master'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "C:/Program Files/Git/cmd/git.exe"  submodule update --recursive --init 
    WORKING_DIRECTORY "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/synht_conv_clean/src/cpp_scripts/cmake-build-debug/_deps/port_audio-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: 'H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/synht_conv_clean/src/cpp_scripts/cmake-build-debug/_deps/port_audio-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/synht_conv_clean/src/cpp_scripts/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-gitinfo.txt"
    "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/synht_conv_clean/src/cpp_scripts/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: 'H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/synht_conv_clean/src/cpp_scripts/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-gitclone-lastrun.txt'")
endif()

