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
CMAKE_SOURCE_DIR = /home/julian/uni/visual/PS/Assignment_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/julian/uni/visual/PS/Assignment_3

# Utility rule file for assignment_01_copy_shader.

# Include any custom commands dependencies for this target.
include CMakeFiles/assignment_01_copy_shader.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/assignment_01_copy_shader.dir/progress.make

CMakeFiles/assignment_01_copy_shader:
	/usr/bin/cmake -E copy_directory /home/julian/uni/visual/PS/Assignment_3/src/shader /home/julian/uni/visual/PS/Assignment_3/bin/shader

assignment_01_copy_shader: CMakeFiles/assignment_01_copy_shader
assignment_01_copy_shader: CMakeFiles/assignment_01_copy_shader.dir/build.make
.PHONY : assignment_01_copy_shader

# Rule to build all files generated by this target.
CMakeFiles/assignment_01_copy_shader.dir/build: assignment_01_copy_shader
.PHONY : CMakeFiles/assignment_01_copy_shader.dir/build

CMakeFiles/assignment_01_copy_shader.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assignment_01_copy_shader.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assignment_01_copy_shader.dir/clean

CMakeFiles/assignment_01_copy_shader.dir/depend:
	cd /home/julian/uni/visual/PS/Assignment_3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julian/uni/visual/PS/Assignment_3 /home/julian/uni/visual/PS/Assignment_3 /home/julian/uni/visual/PS/Assignment_3 /home/julian/uni/visual/PS/Assignment_3 /home/julian/uni/visual/PS/Assignment_3/CMakeFiles/assignment_01_copy_shader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/assignment_01_copy_shader.dir/depend

