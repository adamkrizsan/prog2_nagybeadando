# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adam/Documents/prog2_nagybeadando

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adam/Documents/prog2_nagybeadando

# Include any dependencies generated for this target.
include CMakeFiles/helloworld.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/helloworld.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/helloworld.dir/flags.make

CMakeFiles/helloworld.dir/helloworld.cpp.o: CMakeFiles/helloworld.dir/flags.make
CMakeFiles/helloworld.dir/helloworld.cpp.o: helloworld.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/Documents/prog2_nagybeadando/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/helloworld.dir/helloworld.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/helloworld.dir/helloworld.cpp.o -c /home/adam/Documents/prog2_nagybeadando/helloworld.cpp

CMakeFiles/helloworld.dir/helloworld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloworld.dir/helloworld.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/Documents/prog2_nagybeadando/helloworld.cpp > CMakeFiles/helloworld.dir/helloworld.cpp.i

CMakeFiles/helloworld.dir/helloworld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloworld.dir/helloworld.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/Documents/prog2_nagybeadando/helloworld.cpp -o CMakeFiles/helloworld.dir/helloworld.cpp.s

CMakeFiles/helloworld.dir/Table.cpp.o: CMakeFiles/helloworld.dir/flags.make
CMakeFiles/helloworld.dir/Table.cpp.o: Table.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/Documents/prog2_nagybeadando/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/helloworld.dir/Table.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/helloworld.dir/Table.cpp.o -c /home/adam/Documents/prog2_nagybeadando/Table.cpp

CMakeFiles/helloworld.dir/Table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloworld.dir/Table.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/Documents/prog2_nagybeadando/Table.cpp > CMakeFiles/helloworld.dir/Table.cpp.i

CMakeFiles/helloworld.dir/Table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloworld.dir/Table.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/Documents/prog2_nagybeadando/Table.cpp -o CMakeFiles/helloworld.dir/Table.cpp.s

CMakeFiles/helloworld.dir/Tile.cpp.o: CMakeFiles/helloworld.dir/flags.make
CMakeFiles/helloworld.dir/Tile.cpp.o: Tile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/Documents/prog2_nagybeadando/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/helloworld.dir/Tile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/helloworld.dir/Tile.cpp.o -c /home/adam/Documents/prog2_nagybeadando/Tile.cpp

CMakeFiles/helloworld.dir/Tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloworld.dir/Tile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/Documents/prog2_nagybeadando/Tile.cpp > CMakeFiles/helloworld.dir/Tile.cpp.i

CMakeFiles/helloworld.dir/Tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloworld.dir/Tile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/Documents/prog2_nagybeadando/Tile.cpp -o CMakeFiles/helloworld.dir/Tile.cpp.s

# Object files for target helloworld
helloworld_OBJECTS = \
"CMakeFiles/helloworld.dir/helloworld.cpp.o" \
"CMakeFiles/helloworld.dir/Table.cpp.o" \
"CMakeFiles/helloworld.dir/Tile.cpp.o"

# External object files for target helloworld
helloworld_EXTERNAL_OBJECTS =

helloworld: CMakeFiles/helloworld.dir/helloworld.cpp.o
helloworld: CMakeFiles/helloworld.dir/Table.cpp.o
helloworld: CMakeFiles/helloworld.dir/Tile.cpp.o
helloworld: CMakeFiles/helloworld.dir/build.make
helloworld: libgraphics.a
helloworld: CMakeFiles/helloworld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adam/Documents/prog2_nagybeadando/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable helloworld"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/helloworld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/helloworld.dir/build: helloworld

.PHONY : CMakeFiles/helloworld.dir/build

CMakeFiles/helloworld.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/helloworld.dir/cmake_clean.cmake
.PHONY : CMakeFiles/helloworld.dir/clean

CMakeFiles/helloworld.dir/depend:
	cd /home/adam/Documents/prog2_nagybeadando && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adam/Documents/prog2_nagybeadando /home/adam/Documents/prog2_nagybeadando /home/adam/Documents/prog2_nagybeadando /home/adam/Documents/prog2_nagybeadando /home/adam/Documents/prog2_nagybeadando/CMakeFiles/helloworld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/helloworld.dir/depend

