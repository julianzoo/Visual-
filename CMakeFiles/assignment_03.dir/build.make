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
include CMakeFiles/assignment_03.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/assignment_03.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/assignment_03.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assignment_03.dir/flags.make

CMakeFiles/assignment_03.dir/src/assignment_3.cpp.o: CMakeFiles/assignment_03.dir/flags.make
CMakeFiles/assignment_03.dir/src/assignment_3.cpp.o: src/assignment_3.cpp
CMakeFiles/assignment_03.dir/src/assignment_3.cpp.o: CMakeFiles/assignment_03.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julian/uni/visual/PS/Assignment_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/assignment_03.dir/src/assignment_3.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_03.dir/src/assignment_3.cpp.o -MF CMakeFiles/assignment_03.dir/src/assignment_3.cpp.o.d -o CMakeFiles/assignment_03.dir/src/assignment_3.cpp.o -c /home/julian/uni/visual/PS/Assignment_3/src/assignment_3.cpp

CMakeFiles/assignment_03.dir/src/assignment_3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment_03.dir/src/assignment_3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julian/uni/visual/PS/Assignment_3/src/assignment_3.cpp > CMakeFiles/assignment_03.dir/src/assignment_3.cpp.i

CMakeFiles/assignment_03.dir/src/assignment_3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment_03.dir/src/assignment_3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julian/uni/visual/PS/Assignment_3/src/assignment_3.cpp -o CMakeFiles/assignment_03.dir/src/assignment_3.cpp.s

CMakeFiles/assignment_03.dir/src/flag.cpp.o: CMakeFiles/assignment_03.dir/flags.make
CMakeFiles/assignment_03.dir/src/flag.cpp.o: src/flag.cpp
CMakeFiles/assignment_03.dir/src/flag.cpp.o: CMakeFiles/assignment_03.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julian/uni/visual/PS/Assignment_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/assignment_03.dir/src/flag.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_03.dir/src/flag.cpp.o -MF CMakeFiles/assignment_03.dir/src/flag.cpp.o.d -o CMakeFiles/assignment_03.dir/src/flag.cpp.o -c /home/julian/uni/visual/PS/Assignment_3/src/flag.cpp

CMakeFiles/assignment_03.dir/src/flag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment_03.dir/src/flag.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julian/uni/visual/PS/Assignment_3/src/flag.cpp > CMakeFiles/assignment_03.dir/src/flag.cpp.i

CMakeFiles/assignment_03.dir/src/flag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment_03.dir/src/flag.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julian/uni/visual/PS/Assignment_3/src/flag.cpp -o CMakeFiles/assignment_03.dir/src/flag.cpp.s

CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.o: CMakeFiles/assignment_03.dir/flags.make
CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.o: src/math/matrix3d.cpp
CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.o: CMakeFiles/assignment_03.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julian/uni/visual/PS/Assignment_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.o -MF CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.o.d -o CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.o -c /home/julian/uni/visual/PS/Assignment_3/src/math/matrix3d.cpp

CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julian/uni/visual/PS/Assignment_3/src/math/matrix3d.cpp > CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.i

CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julian/uni/visual/PS/Assignment_3/src/math/matrix3d.cpp -o CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.s

CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.o: CMakeFiles/assignment_03.dir/flags.make
CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.o: src/math/matrix4d.cpp
CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.o: CMakeFiles/assignment_03.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julian/uni/visual/PS/Assignment_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.o -MF CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.o.d -o CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.o -c /home/julian/uni/visual/PS/Assignment_3/src/math/matrix4d.cpp

CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julian/uni/visual/PS/Assignment_3/src/math/matrix4d.cpp > CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.i

CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julian/uni/visual/PS/Assignment_3/src/math/matrix4d.cpp -o CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.s

CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.o: CMakeFiles/assignment_03.dir/flags.make
CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.o: src/math/vector2d.cpp
CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.o: CMakeFiles/assignment_03.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julian/uni/visual/PS/Assignment_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.o -MF CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.o.d -o CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.o -c /home/julian/uni/visual/PS/Assignment_3/src/math/vector2d.cpp

CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julian/uni/visual/PS/Assignment_3/src/math/vector2d.cpp > CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.i

CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julian/uni/visual/PS/Assignment_3/src/math/vector2d.cpp -o CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.s

CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.o: CMakeFiles/assignment_03.dir/flags.make
CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.o: src/math/vector3d.cpp
CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.o: CMakeFiles/assignment_03.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julian/uni/visual/PS/Assignment_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.o -MF CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.o.d -o CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.o -c /home/julian/uni/visual/PS/Assignment_3/src/math/vector3d.cpp

CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julian/uni/visual/PS/Assignment_3/src/math/vector3d.cpp > CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.i

CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julian/uni/visual/PS/Assignment_3/src/math/vector3d.cpp -o CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.s

CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.o: CMakeFiles/assignment_03.dir/flags.make
CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.o: src/math/vector4d.cpp
CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.o: CMakeFiles/assignment_03.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julian/uni/visual/PS/Assignment_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.o -MF CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.o.d -o CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.o -c /home/julian/uni/visual/PS/Assignment_3/src/math/vector4d.cpp

CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julian/uni/visual/PS/Assignment_3/src/math/vector4d.cpp > CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.i

CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julian/uni/visual/PS/Assignment_3/src/math/vector4d.cpp -o CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.s

CMakeFiles/assignment_03.dir/src/mygl/base.cpp.o: CMakeFiles/assignment_03.dir/flags.make
CMakeFiles/assignment_03.dir/src/mygl/base.cpp.o: src/mygl/base.cpp
CMakeFiles/assignment_03.dir/src/mygl/base.cpp.o: CMakeFiles/assignment_03.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julian/uni/visual/PS/Assignment_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/assignment_03.dir/src/mygl/base.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_03.dir/src/mygl/base.cpp.o -MF CMakeFiles/assignment_03.dir/src/mygl/base.cpp.o.d -o CMakeFiles/assignment_03.dir/src/mygl/base.cpp.o -c /home/julian/uni/visual/PS/Assignment_3/src/mygl/base.cpp

CMakeFiles/assignment_03.dir/src/mygl/base.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment_03.dir/src/mygl/base.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julian/uni/visual/PS/Assignment_3/src/mygl/base.cpp > CMakeFiles/assignment_03.dir/src/mygl/base.cpp.i

CMakeFiles/assignment_03.dir/src/mygl/base.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment_03.dir/src/mygl/base.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julian/uni/visual/PS/Assignment_3/src/mygl/base.cpp -o CMakeFiles/assignment_03.dir/src/mygl/base.cpp.s

CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.o: CMakeFiles/assignment_03.dir/flags.make
CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.o: src/mygl/camera.cpp
CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.o: CMakeFiles/assignment_03.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julian/uni/visual/PS/Assignment_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.o -MF CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.o.d -o CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.o -c /home/julian/uni/visual/PS/Assignment_3/src/mygl/camera.cpp

CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julian/uni/visual/PS/Assignment_3/src/mygl/camera.cpp > CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.i

CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julian/uni/visual/PS/Assignment_3/src/mygl/camera.cpp -o CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.s

CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.o: CMakeFiles/assignment_03.dir/flags.make
CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.o: src/mygl/mesh.cpp
CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.o: CMakeFiles/assignment_03.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julian/uni/visual/PS/Assignment_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.o -MF CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.o.d -o CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.o -c /home/julian/uni/visual/PS/Assignment_3/src/mygl/mesh.cpp

CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julian/uni/visual/PS/Assignment_3/src/mygl/mesh.cpp > CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.i

CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julian/uni/visual/PS/Assignment_3/src/mygl/mesh.cpp -o CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.s

CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.o: CMakeFiles/assignment_03.dir/flags.make
CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.o: src/mygl/shader.cpp
CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.o: CMakeFiles/assignment_03.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julian/uni/visual/PS/Assignment_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.o -MF CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.o.d -o CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.o -c /home/julian/uni/visual/PS/Assignment_3/src/mygl/shader.cpp

CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julian/uni/visual/PS/Assignment_3/src/mygl/shader.cpp > CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.i

CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julian/uni/visual/PS/Assignment_3/src/mygl/shader.cpp -o CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.s

# Object files for target assignment_03
assignment_03_OBJECTS = \
"CMakeFiles/assignment_03.dir/src/assignment_3.cpp.o" \
"CMakeFiles/assignment_03.dir/src/flag.cpp.o" \
"CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.o" \
"CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.o" \
"CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.o" \
"CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.o" \
"CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.o" \
"CMakeFiles/assignment_03.dir/src/mygl/base.cpp.o" \
"CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.o" \
"CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.o" \
"CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.o"

# External object files for target assignment_03
assignment_03_EXTERNAL_OBJECTS =

bin/assignment_03: CMakeFiles/assignment_03.dir/src/assignment_3.cpp.o
bin/assignment_03: CMakeFiles/assignment_03.dir/src/flag.cpp.o
bin/assignment_03: CMakeFiles/assignment_03.dir/src/math/matrix3d.cpp.o
bin/assignment_03: CMakeFiles/assignment_03.dir/src/math/matrix4d.cpp.o
bin/assignment_03: CMakeFiles/assignment_03.dir/src/math/vector2d.cpp.o
bin/assignment_03: CMakeFiles/assignment_03.dir/src/math/vector3d.cpp.o
bin/assignment_03: CMakeFiles/assignment_03.dir/src/math/vector4d.cpp.o
bin/assignment_03: CMakeFiles/assignment_03.dir/src/mygl/base.cpp.o
bin/assignment_03: CMakeFiles/assignment_03.dir/src/mygl/camera.cpp.o
bin/assignment_03: CMakeFiles/assignment_03.dir/src/mygl/mesh.cpp.o
bin/assignment_03: CMakeFiles/assignment_03.dir/src/mygl/shader.cpp.o
bin/assignment_03: CMakeFiles/assignment_03.dir/build.make
bin/assignment_03: bin/libglfw3.a
bin/assignment_03: bin/libglad.a
bin/assignment_03: bin/libstb_image.a
bin/assignment_03: /usr/lib/x86_64-linux-gnu/libGLX.so
bin/assignment_03: /usr/lib/x86_64-linux-gnu/libOpenGL.so
bin/assignment_03: /usr/lib/x86_64-linux-gnu/librt.a
bin/assignment_03: /usr/lib/x86_64-linux-gnu/libm.so
bin/assignment_03: CMakeFiles/assignment_03.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/julian/uni/visual/PS/Assignment_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable bin/assignment_03"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assignment_03.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assignment_03.dir/build: bin/assignment_03
.PHONY : CMakeFiles/assignment_03.dir/build

CMakeFiles/assignment_03.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assignment_03.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assignment_03.dir/clean

CMakeFiles/assignment_03.dir/depend:
	cd /home/julian/uni/visual/PS/Assignment_3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julian/uni/visual/PS/Assignment_3 /home/julian/uni/visual/PS/Assignment_3 /home/julian/uni/visual/PS/Assignment_3 /home/julian/uni/visual/PS/Assignment_3 /home/julian/uni/visual/PS/Assignment_3/CMakeFiles/assignment_03.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/assignment_03.dir/depend

