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

# Utility rule file for PLATFORMIO_CLEAN.

# Include the progress variables for this target.
include CMakeFiles/PLATFORMIO_CLEAN.dir/progress.make

CMakeFiles/PLATFORMIO_CLEAN:
	cd /d C:\Workspace\Arduino\Projects\mobile\uno && C:\Python27\Scripts\platformio.exe -f -c clion run --target clean

PLATFORMIO_CLEAN: CMakeFiles/PLATFORMIO_CLEAN
PLATFORMIO_CLEAN: CMakeFiles/PLATFORMIO_CLEAN.dir/build.make

.PHONY : PLATFORMIO_CLEAN

# Rule to build all files generated by this target.
CMakeFiles/PLATFORMIO_CLEAN.dir/build: PLATFORMIO_CLEAN

.PHONY : CMakeFiles/PLATFORMIO_CLEAN.dir/build

CMakeFiles/PLATFORMIO_CLEAN.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PLATFORMIO_CLEAN.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PLATFORMIO_CLEAN.dir/clean

CMakeFiles/PLATFORMIO_CLEAN.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Workspace\Arduino\Projects\mobile\uno C:\Workspace\Arduino\Projects\mobile\uno C:\Workspace\Arduino\Projects\mobile\uno\cmake-build-debug C:\Workspace\Arduino\Projects\mobile\uno\cmake-build-debug C:\Workspace\Arduino\Projects\mobile\uno\cmake-build-debug\CMakeFiles\PLATFORMIO_CLEAN.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PLATFORMIO_CLEAN.dir/depend

