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

# Include any dependencies generated for this target.
include external/glad/CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include external/glad/CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include external/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include external/glad/CMakeFiles/glad.dir/flags.make

external/glad/CMakeFiles/glad.dir/src/glad.cpp.o: external/glad/CMakeFiles/glad.dir/flags.make
external/glad/CMakeFiles/glad.dir/src/glad.cpp.o: external/glad/src/glad.cpp
external/glad/CMakeFiles/glad.dir/src/glad.cpp.o: external/glad/CMakeFiles/glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julian/uni/visual/PS/Assignment_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object external/glad/CMakeFiles/glad.dir/src/glad.cpp.o"
	cd /home/julian/uni/visual/PS/Assignment_3/external/glad && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT external/glad/CMakeFiles/glad.dir/src/glad.cpp.o -MF CMakeFiles/glad.dir/src/glad.cpp.o.d -o CMakeFiles/glad.dir/src/glad.cpp.o -c /home/julian/uni/visual/PS/Assignment_3/external/glad/src/glad.cpp

external/glad/CMakeFiles/glad.dir/src/glad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glad.dir/src/glad.cpp.i"
	cd /home/julian/uni/visual/PS/Assignment_3/external/glad && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julian/uni/visual/PS/Assignment_3/external/glad/src/glad.cpp > CMakeFiles/glad.dir/src/glad.cpp.i

external/glad/CMakeFiles/glad.dir/src/glad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glad.dir/src/glad.cpp.s"
	cd /home/julian/uni/visual/PS/Assignment_3/external/glad && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julian/uni/visual/PS/Assignment_3/external/glad/src/glad.cpp -o CMakeFiles/glad.dir/src/glad.cpp.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/src/glad.cpp.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

bin/libglad.a: external/glad/CMakeFiles/glad.dir/src/glad.cpp.o
bin/libglad.a: external/glad/CMakeFiles/glad.dir/build.make
bin/libglad.a: external/glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/julian/uni/visual/PS/Assignment_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../bin/libglad.a"
	cd /home/julian/uni/visual/PS/Assignment_3/external/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	cd /home/julian/uni/visual/PS/Assignment_3/external/glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glad/CMakeFiles/glad.dir/build: bin/libglad.a
.PHONY : external/glad/CMakeFiles/glad.dir/build

external/glad/CMakeFiles/glad.dir/clean:
	cd /home/julian/uni/visual/PS/Assignment_3/external/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : external/glad/CMakeFiles/glad.dir/clean

external/glad/CMakeFiles/glad.dir/depend:
	cd /home/julian/uni/visual/PS/Assignment_3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julian/uni/visual/PS/Assignment_3 /home/julian/uni/visual/PS/Assignment_3/external/glad /home/julian/uni/visual/PS/Assignment_3 /home/julian/uni/visual/PS/Assignment_3/external/glad /home/julian/uni/visual/PS/Assignment_3/external/glad/CMakeFiles/glad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glad/CMakeFiles/glad.dir/depend

