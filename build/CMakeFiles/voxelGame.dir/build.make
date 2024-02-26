# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.24.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.24.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/maksimmaltsev/Desktop/myEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maksimmaltsev/Desktop/myEngine/build

# Include any dependencies generated for this target.
include CMakeFiles/voxelGame.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/voxelGame.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/voxelGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/voxelGame.dir/flags.make

CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/graphics/Mesh.cpp
CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.o -MF CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.o.d -o CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/graphics/Mesh.cpp

CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/graphics/Mesh.cpp > CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.i

CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/graphics/Mesh.cpp -o CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.s

CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/graphics/Sprite.cpp
CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.o -MF CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.o.d -o CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/graphics/Sprite.cpp

CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/graphics/Sprite.cpp > CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.i

CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/graphics/Sprite.cpp -o CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.s

CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/graphics/Texture.cpp
CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.o -MF CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.o.d -o CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/graphics/Texture.cpp

CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/graphics/Texture.cpp > CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.i

CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/graphics/Texture.cpp -o CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.s

CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/input/Mouse.cpp
CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.o -MF CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.o.d -o CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/input/Mouse.cpp

CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/input/Mouse.cpp > CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.i

CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/input/Mouse.cpp -o CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.s

CMakeFiles/voxelGame.dir/src/myEngine.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/myEngine.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/myEngine.cpp
CMakeFiles/voxelGame.dir/src/myEngine.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/voxelGame.dir/src/myEngine.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/myEngine.cpp.o -MF CMakeFiles/voxelGame.dir/src/myEngine.cpp.o.d -o CMakeFiles/voxelGame.dir/src/myEngine.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/myEngine.cpp

CMakeFiles/voxelGame.dir/src/myEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/myEngine.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/myEngine.cpp > CMakeFiles/voxelGame.dir/src/myEngine.cpp.i

CMakeFiles/voxelGame.dir/src/myEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/myEngine.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/myEngine.cpp -o CMakeFiles/voxelGame.dir/src/myEngine.cpp.s

CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/myutils/fileReader.cpp
CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.o -MF CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.o.d -o CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/myutils/fileReader.cpp

CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/myutils/fileReader.cpp > CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.i

CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/myutils/fileReader.cpp -o CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.s

CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/renderer/Camera.cpp
CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.o -MF CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.o.d -o CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/renderer/Camera.cpp

CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/renderer/Camera.cpp > CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.i

CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/renderer/Camera.cpp -o CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.s

CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/renderer/ShaderProgram.cpp
CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.o -MF CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.o.d -o CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/renderer/ShaderProgram.cpp

CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/renderer/ShaderProgram.cpp > CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.i

CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/renderer/ShaderProgram.cpp -o CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.s

CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/renderer/Window.cpp
CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.o -MF CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.o.d -o CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/renderer/Window.cpp

CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/renderer/Window.cpp > CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.i

CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/renderer/Window.cpp -o CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.s

CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/time/FPSCounter.cpp
CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.o -MF CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.o.d -o CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/time/FPSCounter.cpp

CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/time/FPSCounter.cpp > CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.i

CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/time/FPSCounter.cpp -o CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.s

CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/voxels/Block.cpp
CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.o -MF CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.o.d -o CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/voxels/Block.cpp

CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/voxels/Block.cpp > CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.i

CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/voxels/Block.cpp -o CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.s

CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/voxels/BlocksData.cpp
CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.o -MF CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.o.d -o CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/voxels/BlocksData.cpp

CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/voxels/BlocksData.cpp > CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.i

CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/voxels/BlocksData.cpp -o CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.s

CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/world/ChukStorage.cpp
CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.o -MF CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.o.d -o CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/world/ChukStorage.cpp

CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/world/ChukStorage.cpp > CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.i

CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/world/ChukStorage.cpp -o CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.s

CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/world/ChunckRenderer.cpp
CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.o -MF CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.o.d -o CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/world/ChunckRenderer.cpp

CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/world/ChunckRenderer.cpp > CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.i

CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/world/ChunckRenderer.cpp -o CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.s

CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/world/Chunk.cpp
CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.o -MF CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.o.d -o CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/world/Chunk.cpp

CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/world/Chunk.cpp > CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.i

CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/world/Chunk.cpp -o CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.s

CMakeFiles/voxelGame.dir/src/world/Generator.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/world/Generator.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/world/Generator.cpp
CMakeFiles/voxelGame.dir/src/world/Generator.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/voxelGame.dir/src/world/Generator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/world/Generator.cpp.o -MF CMakeFiles/voxelGame.dir/src/world/Generator.cpp.o.d -o CMakeFiles/voxelGame.dir/src/world/Generator.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/world/Generator.cpp

CMakeFiles/voxelGame.dir/src/world/Generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/world/Generator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/world/Generator.cpp > CMakeFiles/voxelGame.dir/src/world/Generator.cpp.i

CMakeFiles/voxelGame.dir/src/world/Generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/world/Generator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/world/Generator.cpp -o CMakeFiles/voxelGame.dir/src/world/Generator.cpp.s

CMakeFiles/voxelGame.dir/src/world/World.cpp.o: CMakeFiles/voxelGame.dir/flags.make
CMakeFiles/voxelGame.dir/src/world/World.cpp.o: /Users/maksimmaltsev/Desktop/myEngine/src/world/World.cpp
CMakeFiles/voxelGame.dir/src/world/World.cpp.o: CMakeFiles/voxelGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/voxelGame.dir/src/world/World.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/voxelGame.dir/src/world/World.cpp.o -MF CMakeFiles/voxelGame.dir/src/world/World.cpp.o.d -o CMakeFiles/voxelGame.dir/src/world/World.cpp.o -c /Users/maksimmaltsev/Desktop/myEngine/src/world/World.cpp

CMakeFiles/voxelGame.dir/src/world/World.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/voxelGame.dir/src/world/World.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksimmaltsev/Desktop/myEngine/src/world/World.cpp > CMakeFiles/voxelGame.dir/src/world/World.cpp.i

CMakeFiles/voxelGame.dir/src/world/World.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/voxelGame.dir/src/world/World.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksimmaltsev/Desktop/myEngine/src/world/World.cpp -o CMakeFiles/voxelGame.dir/src/world/World.cpp.s

# Object files for target voxelGame
voxelGame_OBJECTS = \
"CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.o" \
"CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.o" \
"CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.o" \
"CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.o" \
"CMakeFiles/voxelGame.dir/src/myEngine.cpp.o" \
"CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.o" \
"CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.o" \
"CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.o" \
"CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.o" \
"CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.o" \
"CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.o" \
"CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.o" \
"CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.o" \
"CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.o" \
"CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.o" \
"CMakeFiles/voxelGame.dir/src/world/Generator.cpp.o" \
"CMakeFiles/voxelGame.dir/src/world/World.cpp.o"

# External object files for target voxelGame
voxelGame_EXTERNAL_OBJECTS =

voxelGame: CMakeFiles/voxelGame.dir/src/graphics/Mesh.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/graphics/Sprite.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/graphics/Texture.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/input/Mouse.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/myEngine.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/myutils/fileReader.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/renderer/Camera.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/renderer/ShaderProgram.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/renderer/Window.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/time/FPSCounter.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/voxels/Block.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/voxels/BlocksData.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/world/ChukStorage.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/world/ChunckRenderer.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/world/Chunk.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/world/Generator.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/src/world/World.cpp.o
voxelGame: CMakeFiles/voxelGame.dir/build.make
voxelGame: /Library/Developer/CommandLineTools/SDKs/MacOSX14.0.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
voxelGame: /usr/local/lib/libGLEW.2.2.0.dylib
voxelGame: CMakeFiles/voxelGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable voxelGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/voxelGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/voxelGame.dir/build: voxelGame
.PHONY : CMakeFiles/voxelGame.dir/build

CMakeFiles/voxelGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/voxelGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/voxelGame.dir/clean

CMakeFiles/voxelGame.dir/depend:
	cd /Users/maksimmaltsev/Desktop/myEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maksimmaltsev/Desktop/myEngine /Users/maksimmaltsev/Desktop/myEngine /Users/maksimmaltsev/Desktop/myEngine/build /Users/maksimmaltsev/Desktop/myEngine/build /Users/maksimmaltsev/Desktop/myEngine/build/CMakeFiles/voxelGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/voxelGame.dir/depend
