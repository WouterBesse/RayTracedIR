# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\example.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\example.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\example.dir\flags.make

CMakeFiles\example.dir\reverb.cpp.obj: CMakeFiles\example.dir\flags.make
CMakeFiles\example.dir\reverb.cpp.obj: ..\reverb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/example.dir/reverb.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\example.dir\reverb.cpp.obj /FdCMakeFiles\example.dir\ /FS -c "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\reverb.cpp"
<<

CMakeFiles\example.dir\reverb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/reverb.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\example.dir\reverb.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\reverb.cpp"
<<

CMakeFiles\example.dir\reverb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/reverb.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\example.dir\reverb.cpp.s /c "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\reverb.cpp"
<<

CMakeFiles\example.dir\ringbuffer.cpp.obj: CMakeFiles\example.dir\flags.make
CMakeFiles\example.dir\ringbuffer.cpp.obj: ..\ringbuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/example.dir/ringbuffer.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\example.dir\ringbuffer.cpp.obj /FdCMakeFiles\example.dir\ /FS -c "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\ringbuffer.cpp"
<<

CMakeFiles\example.dir\ringbuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/ringbuffer.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\example.dir\ringbuffer.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\ringbuffer.cpp"
<<

CMakeFiles\example.dir\ringbuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/ringbuffer.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\example.dir\ringbuffer.cpp.s /c "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\ringbuffer.cpp"
<<

CMakeFiles\example.dir\main.cpp.obj: CMakeFiles\example.dir\flags.make
CMakeFiles\example.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/example.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\example.dir\main.cpp.obj /FdCMakeFiles\example.dir\ /FS -c "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\main.cpp"
<<

CMakeFiles\example.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\example.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\main.cpp"
<<

CMakeFiles\example.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\example.dir\main.cpp.s /c "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\main.cpp"
<<

# Object files for target example
example_OBJECTS = \
"CMakeFiles\example.dir\reverb.cpp.obj" \
"CMakeFiles\example.dir\ringbuffer.cpp.obj" \
"CMakeFiles\example.dir\main.cpp.obj"

# External object files for target example
example_EXTERNAL_OBJECTS =

example.exe: CMakeFiles\example.dir\reverb.cpp.obj
example.exe: CMakeFiles\example.dir\ringbuffer.cpp.obj
example.exe: CMakeFiles\example.dir\main.cpp.obj
example.exe: CMakeFiles\example.dir\build.make
example.exe: _deps\port_audio-build\portaudio_static_x86.lib
example.exe: CMakeFiles\example.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable example.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\example.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\example.dir\objects1.rsp @<<
 /out:example.exe /implib:example.lib /pdb:"H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\cmake-build-debug\example.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  _deps\port_audio-build\portaudio_static_x86.lib winmm.lib dsound.lib ole32.lib uuid.lib setupapi.lib ole32.lib uuid.lib setupapi.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\example.dir\build: example.exe

.PHONY : CMakeFiles\example.dir\build

CMakeFiles\example.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\example.dir\cmake_clean.cmake
.PHONY : CMakeFiles\example.dir\clean

CMakeFiles\example.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class" "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class" "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\cmake-build-debug" "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\cmake-build-debug" "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\RayTracedIR\nino\Delay reverb class\cmake-build-debug\CMakeFiles\example.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\example.dir\depend

