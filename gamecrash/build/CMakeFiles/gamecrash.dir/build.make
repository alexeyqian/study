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
CMAKE_SOURCE_DIR = /home/parallels/study/gamecrash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parallels/study/gamecrash/build

# Include any dependencies generated for this target.
include CMakeFiles/gamecrash.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gamecrash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gamecrash.dir/flags.make

CMakeFiles/gamecrash.dir/src/main.cpp.o: CMakeFiles/gamecrash.dir/flags.make
CMakeFiles/gamecrash.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/study/gamecrash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gamecrash.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gamecrash.dir/src/main.cpp.o -c /home/parallels/study/gamecrash/src/main.cpp

CMakeFiles/gamecrash.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gamecrash.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/study/gamecrash/src/main.cpp > CMakeFiles/gamecrash.dir/src/main.cpp.i

CMakeFiles/gamecrash.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gamecrash.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/study/gamecrash/src/main.cpp -o CMakeFiles/gamecrash.dir/src/main.cpp.s

# Object files for target gamecrash
gamecrash_OBJECTS = \
"CMakeFiles/gamecrash.dir/src/main.cpp.o"

# External object files for target gamecrash
gamecrash_EXTERNAL_OBJECTS =

gamecrash: CMakeFiles/gamecrash.dir/src/main.cpp.o
gamecrash: CMakeFiles/gamecrash.dir/build.make
gamecrash: CMakeFiles/gamecrash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parallels/study/gamecrash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gamecrash"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gamecrash.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gamecrash.dir/build: gamecrash

.PHONY : CMakeFiles/gamecrash.dir/build

CMakeFiles/gamecrash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gamecrash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gamecrash.dir/clean

CMakeFiles/gamecrash.dir/depend:
	cd /home/parallels/study/gamecrash/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/study/gamecrash /home/parallels/study/gamecrash /home/parallels/study/gamecrash/build /home/parallels/study/gamecrash/build /home/parallels/study/gamecrash/build/CMakeFiles/gamecrash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gamecrash.dir/depend
