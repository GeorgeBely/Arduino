# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\beliy\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\171.4694.31\bin\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\beliy\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\171.4694.31\bin\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Workspace\Arduino\Projects\mobile\uno

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Workspace\Arduino\Projects\mobile\uno\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/uno.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/uno.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/uno.dir/flags.make

CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj: CMakeFiles/uno.dir/flags.make
CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj: CMakeFiles/uno.dir/includes_CXX.rsp
CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj: ../src/GSM/GSM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Workspace\Arduino\Projects\mobile\uno\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\uno.dir\src\GSM\GSM.cpp.obj -c C:\Workspace\Arduino\Projects\mobile\uno\src\GSM\GSM.cpp

CMakeFiles/uno.dir/src/GSM/GSM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uno.dir/src/GSM/GSM.cpp.i"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Workspace\Arduino\Projects\mobile\uno\src\GSM\GSM.cpp > CMakeFiles\uno.dir\src\GSM\GSM.cpp.i

CMakeFiles/uno.dir/src/GSM/GSM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uno.dir/src/GSM/GSM.cpp.s"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Workspace\Arduino\Projects\mobile\uno\src\GSM\GSM.cpp -o CMakeFiles\uno.dir\src\GSM\GSM.cpp.s

CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj.requires:

.PHONY : CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj.requires

CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj.provides: CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj.requires
	$(MAKE) -f CMakeFiles\uno.dir\build.make CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj.provides.build
.PHONY : CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj.provides

CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj.provides.build: CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj


CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj: CMakeFiles/uno.dir/flags.make
CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj: CMakeFiles/uno.dir/includes_CXX.rsp
CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj: ../src/Keypad/KeypadMobile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Workspace\Arduino\Projects\mobile\uno\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\uno.dir\src\Keypad\KeypadMobile.cpp.obj -c C:\Workspace\Arduino\Projects\mobile\uno\src\Keypad\KeypadMobile.cpp

CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.i"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Workspace\Arduino\Projects\mobile\uno\src\Keypad\KeypadMobile.cpp > CMakeFiles\uno.dir\src\Keypad\KeypadMobile.cpp.i

CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.s"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Workspace\Arduino\Projects\mobile\uno\src\Keypad\KeypadMobile.cpp -o CMakeFiles\uno.dir\src\Keypad\KeypadMobile.cpp.s

CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj.requires:

.PHONY : CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj.requires

CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj.provides: CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj.requires
	$(MAKE) -f CMakeFiles\uno.dir\build.make CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj.provides.build
.PHONY : CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj.provides

CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj.provides.build: CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj


CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj: CMakeFiles/uno.dir/flags.make
CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj: CMakeFiles/uno.dir/includes_CXX.rsp
CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj: ../src/LCD/LCDMobile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Workspace\Arduino\Projects\mobile\uno\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\uno.dir\src\LCD\LCDMobile.cpp.obj -c C:\Workspace\Arduino\Projects\mobile\uno\src\LCD\LCDMobile.cpp

CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.i"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Workspace\Arduino\Projects\mobile\uno\src\LCD\LCDMobile.cpp > CMakeFiles\uno.dir\src\LCD\LCDMobile.cpp.i

CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.s"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Workspace\Arduino\Projects\mobile\uno\src\LCD\LCDMobile.cpp -o CMakeFiles\uno.dir\src\LCD\LCDMobile.cpp.s

CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj.requires:

.PHONY : CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj.requires

CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj.provides: CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj.requires
	$(MAKE) -f CMakeFiles\uno.dir\build.make CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj.provides.build
.PHONY : CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj.provides

CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj.provides.build: CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj


CMakeFiles/uno.dir/src/main.cpp.obj: CMakeFiles/uno.dir/flags.make
CMakeFiles/uno.dir/src/main.cpp.obj: CMakeFiles/uno.dir/includes_CXX.rsp
CMakeFiles/uno.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Workspace\Arduino\Projects\mobile\uno\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/uno.dir/src/main.cpp.obj"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\uno.dir\src\main.cpp.obj -c C:\Workspace\Arduino\Projects\mobile\uno\src\main.cpp

CMakeFiles/uno.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uno.dir/src/main.cpp.i"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Workspace\Arduino\Projects\mobile\uno\src\main.cpp > CMakeFiles\uno.dir\src\main.cpp.i

CMakeFiles/uno.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uno.dir/src/main.cpp.s"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Workspace\Arduino\Projects\mobile\uno\src\main.cpp -o CMakeFiles\uno.dir\src\main.cpp.s

CMakeFiles/uno.dir/src/main.cpp.obj.requires:

.PHONY : CMakeFiles/uno.dir/src/main.cpp.obj.requires

CMakeFiles/uno.dir/src/main.cpp.obj.provides: CMakeFiles/uno.dir/src/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\uno.dir\build.make CMakeFiles/uno.dir/src/main.cpp.obj.provides.build
.PHONY : CMakeFiles/uno.dir/src/main.cpp.obj.provides

CMakeFiles/uno.dir/src/main.cpp.obj.provides.build: CMakeFiles/uno.dir/src/main.cpp.obj


CMakeFiles/uno.dir/src/test/test.cpp.obj: CMakeFiles/uno.dir/flags.make
CMakeFiles/uno.dir/src/test/test.cpp.obj: CMakeFiles/uno.dir/includes_CXX.rsp
CMakeFiles/uno.dir/src/test/test.cpp.obj: ../src/test/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Workspace\Arduino\Projects\mobile\uno\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/uno.dir/src/test/test.cpp.obj"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\uno.dir\src\test\test.cpp.obj -c C:\Workspace\Arduino\Projects\mobile\uno\src\test\test.cpp

CMakeFiles/uno.dir/src/test/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uno.dir/src/test/test.cpp.i"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Workspace\Arduino\Projects\mobile\uno\src\test\test.cpp > CMakeFiles\uno.dir\src\test\test.cpp.i

CMakeFiles/uno.dir/src/test/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uno.dir/src/test/test.cpp.s"
	C:\Users\beliy\.platformio\packages\toolchain-atmelavr\bin\avr-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Workspace\Arduino\Projects\mobile\uno\src\test\test.cpp -o CMakeFiles\uno.dir\src\test\test.cpp.s

CMakeFiles/uno.dir/src/test/test.cpp.obj.requires:

.PHONY : CMakeFiles/uno.dir/src/test/test.cpp.obj.requires

CMakeFiles/uno.dir/src/test/test.cpp.obj.provides: CMakeFiles/uno.dir/src/test/test.cpp.obj.requires
	$(MAKE) -f CMakeFiles\uno.dir\build.make CMakeFiles/uno.dir/src/test/test.cpp.obj.provides.build
.PHONY : CMakeFiles/uno.dir/src/test/test.cpp.obj.provides

CMakeFiles/uno.dir/src/test/test.cpp.obj.provides.build: CMakeFiles/uno.dir/src/test/test.cpp.obj


# Object files for target uno
uno_OBJECTS = \
"CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj" \
"CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj" \
"CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj" \
"CMakeFiles/uno.dir/src/main.cpp.obj" \
"CMakeFiles/uno.dir/src/test/test.cpp.obj"

# External object files for target uno
uno_EXTERNAL_OBJECTS =

uno.exe: CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj
uno.exe: CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj
uno.exe: CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj
uno.exe: CMakeFiles/uno.dir/src/main.cpp.obj
uno.exe: CMakeFiles/uno.dir/src/test/test.cpp.obj
uno.exe: CMakeFiles/uno.dir/build.make
uno.exe: CMakeFiles/uno.dir/linklibs.rsp
uno.exe: CMakeFiles/uno.dir/objects1.rsp
uno.exe: CMakeFiles/uno.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Workspace\Arduino\Projects\mobile\uno\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable uno.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\uno.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/uno.dir/build: uno.exe

.PHONY : CMakeFiles/uno.dir/build

CMakeFiles/uno.dir/requires: CMakeFiles/uno.dir/src/GSM/GSM.cpp.obj.requires
CMakeFiles/uno.dir/requires: CMakeFiles/uno.dir/src/Keypad/KeypadMobile.cpp.obj.requires
CMakeFiles/uno.dir/requires: CMakeFiles/uno.dir/src/LCD/LCDMobile.cpp.obj.requires
CMakeFiles/uno.dir/requires: CMakeFiles/uno.dir/src/main.cpp.obj.requires
CMakeFiles/uno.dir/requires: CMakeFiles/uno.dir/src/test/test.cpp.obj.requires

.PHONY : CMakeFiles/uno.dir/requires

CMakeFiles/uno.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\uno.dir\cmake_clean.cmake
.PHONY : CMakeFiles/uno.dir/clean

CMakeFiles/uno.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Workspace\Arduino\Projects\mobile\uno C:\Workspace\Arduino\Projects\mobile\uno C:\Workspace\Arduino\Projects\mobile\uno\cmake-build-debug C:\Workspace\Arduino\Projects\mobile\uno\cmake-build-debug C:\Workspace\Arduino\Projects\mobile\uno\cmake-build-debug\CMakeFiles\uno.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/uno.dir/depend

