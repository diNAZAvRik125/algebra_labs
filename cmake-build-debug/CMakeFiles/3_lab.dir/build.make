# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Nazar\CLionProjects\algebra_labs\3_lab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Nazar\CLionProjects\algebra_labs\3_lab\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\3_lab.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\3_lab.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\3_lab.dir\flags.make

CMakeFiles\3_lab.dir\main.cpp.obj: CMakeFiles\3_lab.dir\flags.make
CMakeFiles\3_lab.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Nazar\CLionProjects\algebra_labs\3_lab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3_lab.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\3_lab.dir\main.cpp.obj /FdCMakeFiles\3_lab.dir\ /FS -c C:\Nazar\CLionProjects\algebra_labs\3_lab\main.cpp
<<

CMakeFiles\3_lab.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3_lab.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\3_lab.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Nazar\CLionProjects\algebra_labs\3_lab\main.cpp
<<

CMakeFiles\3_lab.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3_lab.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\3_lab.dir\main.cpp.s /c C:\Nazar\CLionProjects\algebra_labs\3_lab\main.cpp
<<

# Object files for target 3_lab
3_lab_OBJECTS = \
"CMakeFiles\3_lab.dir\main.cpp.obj"

# External object files for target 3_lab
3_lab_EXTERNAL_OBJECTS =

3_lab.exe: CMakeFiles\3_lab.dir\main.cpp.obj
3_lab.exe: CMakeFiles\3_lab.dir\build.make
3_lab.exe: CMakeFiles\3_lab.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Nazar\CLionProjects\algebra_labs\3_lab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 3_lab.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\3_lab.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\3_lab.dir\objects1.rsp @<<
 /out:3_lab.exe /implib:3_lab.lib /pdb:C:\Nazar\CLionProjects\algebra_labs\3_lab\cmake-build-debug\3_lab.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\3_lab.dir\build: 3_lab.exe
.PHONY : CMakeFiles\3_lab.dir\build

CMakeFiles\3_lab.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\3_lab.dir\cmake_clean.cmake
.PHONY : CMakeFiles\3_lab.dir\clean

CMakeFiles\3_lab.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Nazar\CLionProjects\algebra_labs\3_lab C:\Nazar\CLionProjects\algebra_labs\3_lab C:\Nazar\CLionProjects\algebra_labs\3_lab\cmake-build-debug C:\Nazar\CLionProjects\algebra_labs\3_lab\cmake-build-debug C:\Nazar\CLionProjects\algebra_labs\3_lab\cmake-build-debug\CMakeFiles\3_lab.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\3_lab.dir\depend

