# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task/build_lin

# Include any dependencies generated for this target.
include CMakeFiles/GeoPoints.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GeoPoints.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GeoPoints.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GeoPoints.dir/flags.make

CMakeFiles/GeoPoints.dir/main.cpp.o: CMakeFiles/GeoPoints.dir/flags.make
CMakeFiles/GeoPoints.dir/main.cpp.o: ../main.cpp
CMakeFiles/GeoPoints.dir/main.cpp.o: CMakeFiles/GeoPoints.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task/build_lin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GeoPoints.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GeoPoints.dir/main.cpp.o -MF CMakeFiles/GeoPoints.dir/main.cpp.o.d -o CMakeFiles/GeoPoints.dir/main.cpp.o -c /home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task/main.cpp

CMakeFiles/GeoPoints.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GeoPoints.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task/main.cpp > CMakeFiles/GeoPoints.dir/main.cpp.i

CMakeFiles/GeoPoints.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GeoPoints.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task/main.cpp -o CMakeFiles/GeoPoints.dir/main.cpp.s

CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.o: CMakeFiles/GeoPoints.dir/flags.make
CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.o: ../source/GeoPointProcessor.cpp
CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.o: CMakeFiles/GeoPoints.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task/build_lin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.o -MF CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.o.d -o CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.o -c /home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task/source/GeoPointProcessor.cpp

CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task/source/GeoPointProcessor.cpp > CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.i

CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task/source/GeoPointProcessor.cpp -o CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.s

# Object files for target GeoPoints
GeoPoints_OBJECTS = \
"CMakeFiles/GeoPoints.dir/main.cpp.o" \
"CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.o"

# External object files for target GeoPoints
GeoPoints_EXTERNAL_OBJECTS =

GeoPoints: CMakeFiles/GeoPoints.dir/main.cpp.o
GeoPoints: CMakeFiles/GeoPoints.dir/source/GeoPointProcessor.cpp.o
GeoPoints: CMakeFiles/GeoPoints.dir/build.make
GeoPoints: CMakeFiles/GeoPoints.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task/build_lin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable GeoPoints"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GeoPoints.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GeoPoints.dir/build: GeoPoints
.PHONY : CMakeFiles/GeoPoints.dir/build

CMakeFiles/GeoPoints.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GeoPoints.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GeoPoints.dir/clean

CMakeFiles/GeoPoints.dir/depend:
	cd /home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task/build_lin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task /home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task /home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task/build_lin /home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task/build_lin /home/dmitrii/disk/projeckts_cpp/test_tasks/ATOM/first_task/build_lin/CMakeFiles/GeoPoints.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GeoPoints.dir/depend

