# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/yan/code/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yan/code/project/build

# Include any dependencies generated for this target.
include DBServer/CMakeFiles/DBServer.dir/depend.make

# Include the progress variables for this target.
include DBServer/CMakeFiles/DBServer.dir/progress.make

# Include the compile flags for this target's objects.
include DBServer/CMakeFiles/DBServer.dir/flags.make

DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.o: DBServer/CMakeFiles/DBServer.dir/flags.make
DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.o: ../DBServer/DBServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.o"
	cd /home/yan/code/project/build/DBServer && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DBServer.dir/DBServer.cpp.o -c /home/yan/code/project/DBServer/DBServer.cpp

DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DBServer.dir/DBServer.cpp.i"
	cd /home/yan/code/project/build/DBServer && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/DBServer/DBServer.cpp > CMakeFiles/DBServer.dir/DBServer.cpp.i

DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DBServer.dir/DBServer.cpp.s"
	cd /home/yan/code/project/build/DBServer && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/DBServer/DBServer.cpp -o CMakeFiles/DBServer.dir/DBServer.cpp.s

DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.o.requires:

.PHONY : DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.o.requires

DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.o.provides: DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.o.requires
	$(MAKE) -f DBServer/CMakeFiles/DBServer.dir/build.make DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.o.provides.build
.PHONY : DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.o.provides

DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.o.provides.build: DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.o


DBServer/CMakeFiles/DBServer.dir/main.cpp.o: DBServer/CMakeFiles/DBServer.dir/flags.make
DBServer/CMakeFiles/DBServer.dir/main.cpp.o: ../DBServer/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object DBServer/CMakeFiles/DBServer.dir/main.cpp.o"
	cd /home/yan/code/project/build/DBServer && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DBServer.dir/main.cpp.o -c /home/yan/code/project/DBServer/main.cpp

DBServer/CMakeFiles/DBServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DBServer.dir/main.cpp.i"
	cd /home/yan/code/project/build/DBServer && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/DBServer/main.cpp > CMakeFiles/DBServer.dir/main.cpp.i

DBServer/CMakeFiles/DBServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DBServer.dir/main.cpp.s"
	cd /home/yan/code/project/build/DBServer && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/DBServer/main.cpp -o CMakeFiles/DBServer.dir/main.cpp.s

DBServer/CMakeFiles/DBServer.dir/main.cpp.o.requires:

.PHONY : DBServer/CMakeFiles/DBServer.dir/main.cpp.o.requires

DBServer/CMakeFiles/DBServer.dir/main.cpp.o.provides: DBServer/CMakeFiles/DBServer.dir/main.cpp.o.requires
	$(MAKE) -f DBServer/CMakeFiles/DBServer.dir/build.make DBServer/CMakeFiles/DBServer.dir/main.cpp.o.provides.build
.PHONY : DBServer/CMakeFiles/DBServer.dir/main.cpp.o.provides

DBServer/CMakeFiles/DBServer.dir/main.cpp.o.provides.build: DBServer/CMakeFiles/DBServer.dir/main.cpp.o


# Object files for target DBServer
DBServer_OBJECTS = \
"CMakeFiles/DBServer.dir/DBServer.cpp.o" \
"CMakeFiles/DBServer.dir/main.cpp.o"

# External object files for target DBServer
DBServer_EXTERNAL_OBJECTS =

../bin/DBServer: DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.o
../bin/DBServer: DBServer/CMakeFiles/DBServer.dir/main.cpp.o
../bin/DBServer: DBServer/CMakeFiles/DBServer.dir/build.make
../bin/DBServer: ServerEngine/libServerEngine.so
../bin/DBServer: DBServer/CMakeFiles/DBServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/DBServer"
	cd /home/yan/code/project/build/DBServer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DBServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
DBServer/CMakeFiles/DBServer.dir/build: ../bin/DBServer

.PHONY : DBServer/CMakeFiles/DBServer.dir/build

DBServer/CMakeFiles/DBServer.dir/requires: DBServer/CMakeFiles/DBServer.dir/DBServer.cpp.o.requires
DBServer/CMakeFiles/DBServer.dir/requires: DBServer/CMakeFiles/DBServer.dir/main.cpp.o.requires

.PHONY : DBServer/CMakeFiles/DBServer.dir/requires

DBServer/CMakeFiles/DBServer.dir/clean:
	cd /home/yan/code/project/build/DBServer && $(CMAKE_COMMAND) -P CMakeFiles/DBServer.dir/cmake_clean.cmake
.PHONY : DBServer/CMakeFiles/DBServer.dir/clean

DBServer/CMakeFiles/DBServer.dir/depend:
	cd /home/yan/code/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yan/code/project /home/yan/code/project/DBServer /home/yan/code/project/build /home/yan/code/project/build/DBServer /home/yan/code/project/build/DBServer/CMakeFiles/DBServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : DBServer/CMakeFiles/DBServer.dir/depend
