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
include ServerEngine/CMakeFiles/ServerEngine.dir/depend.make

# Include the progress variables for this target.
include ServerEngine/CMakeFiles/ServerEngine.dir/progress.make

# Include the compile flags for this target's objects.
include ServerEngine/CMakeFiles/ServerEngine.dir/flags.make

ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.o: ServerEngine/CMakeFiles/ServerEngine.dir/flags.make
ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.o: ../ServerEngine/Connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.o"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerEngine.dir/Connection.cpp.o -c /home/yan/code/project/ServerEngine/Connection.cpp

ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerEngine.dir/Connection.cpp.i"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/ServerEngine/Connection.cpp > CMakeFiles/ServerEngine.dir/Connection.cpp.i

ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerEngine.dir/Connection.cpp.s"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/ServerEngine/Connection.cpp -o CMakeFiles/ServerEngine.dir/Connection.cpp.s

ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.o.requires:

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.o.requires

ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.o.provides: ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.o.requires
	$(MAKE) -f ServerEngine/CMakeFiles/ServerEngine.dir/build.make ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.o.provides.build
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.o.provides

ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.o.provides.build: ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.o


ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.o: ServerEngine/CMakeFiles/ServerEngine.dir/flags.make
ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.o: ../ServerEngine/CppMysql.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.o"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerEngine.dir/CppMysql.cpp.o -c /home/yan/code/project/ServerEngine/CppMysql.cpp

ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerEngine.dir/CppMysql.cpp.i"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/ServerEngine/CppMysql.cpp > CMakeFiles/ServerEngine.dir/CppMysql.cpp.i

ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerEngine.dir/CppMysql.cpp.s"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/ServerEngine/CppMysql.cpp -o CMakeFiles/ServerEngine.dir/CppMysql.cpp.s

ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.o.requires:

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.o.requires

ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.o.provides: ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.o.requires
	$(MAKE) -f ServerEngine/CMakeFiles/ServerEngine.dir/build.make ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.o.provides.build
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.o.provides

ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.o.provides.build: ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.o


ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o: ServerEngine/CMakeFiles/ServerEngine.dir/flags.make
ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o: ../ServerEngine/EventDispatcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o -c /home/yan/code/project/ServerEngine/EventDispatcher.cpp

ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.i"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/ServerEngine/EventDispatcher.cpp > CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.i

ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.s"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/ServerEngine/EventDispatcher.cpp -o CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.s

ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o.requires:

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o.requires

ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o.provides: ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o.requires
	$(MAKE) -f ServerEngine/CMakeFiles/ServerEngine.dir/build.make ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o.provides.build
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o.provides

ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o.provides.build: ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o


ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.o: ServerEngine/CMakeFiles/ServerEngine.dir/flags.make
ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.o: ../ServerEngine/HttpClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.o"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerEngine.dir/HttpClient.cpp.o -c /home/yan/code/project/ServerEngine/HttpClient.cpp

ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerEngine.dir/HttpClient.cpp.i"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/ServerEngine/HttpClient.cpp > CMakeFiles/ServerEngine.dir/HttpClient.cpp.i

ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerEngine.dir/HttpClient.cpp.s"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/ServerEngine/HttpClient.cpp -o CMakeFiles/ServerEngine.dir/HttpClient.cpp.s

ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.o.requires:

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.o.requires

ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.o.provides: ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.o.requires
	$(MAKE) -f ServerEngine/CMakeFiles/ServerEngine.dir/build.make ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.o.provides.build
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.o.provides

ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.o.provides.build: ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.o


ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.o: ServerEngine/CMakeFiles/ServerEngine.dir/flags.make
ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.o: ../ServerEngine/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.o"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerEngine.dir/Logger.cpp.o -c /home/yan/code/project/ServerEngine/Logger.cpp

ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerEngine.dir/Logger.cpp.i"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/ServerEngine/Logger.cpp > CMakeFiles/ServerEngine.dir/Logger.cpp.i

ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerEngine.dir/Logger.cpp.s"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/ServerEngine/Logger.cpp -o CMakeFiles/ServerEngine.dir/Logger.cpp.s

ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.o.requires:

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.o.requires

ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.o.provides: ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.o.requires
	$(MAKE) -f ServerEngine/CMakeFiles/ServerEngine.dir/build.make ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.o.provides.build
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.o.provides

ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.o.provides.build: ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.o


ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o: ServerEngine/CMakeFiles/ServerEngine.dir/flags.make
ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o: ../ServerEngine/MYSQLPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o -c /home/yan/code/project/ServerEngine/MYSQLPool.cpp

ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.i"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/ServerEngine/MYSQLPool.cpp > CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.i

ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.s"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/ServerEngine/MYSQLPool.cpp -o CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.s

ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o.requires:

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o.requires

ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o.provides: ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o.requires
	$(MAKE) -f ServerEngine/CMakeFiles/ServerEngine.dir/build.make ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o.provides.build
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o.provides

ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o.provides.build: ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o


ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o: ServerEngine/CMakeFiles/ServerEngine.dir/flags.make
ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o: ../ServerEngine/MemoryStream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o -c /home/yan/code/project/ServerEngine/MemoryStream.cpp

ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerEngine.dir/MemoryStream.cpp.i"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/ServerEngine/MemoryStream.cpp > CMakeFiles/ServerEngine.dir/MemoryStream.cpp.i

ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerEngine.dir/MemoryStream.cpp.s"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/ServerEngine/MemoryStream.cpp -o CMakeFiles/ServerEngine.dir/MemoryStream.cpp.s

ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o.requires:

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o.requires

ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o.provides: ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o.requires
	$(MAKE) -f ServerEngine/CMakeFiles/ServerEngine.dir/build.make ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o.provides.build
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o.provides

ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o.provides.build: ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o


ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o: ServerEngine/CMakeFiles/ServerEngine.dir/flags.make
ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o: ../ServerEngine/PacketHelper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o -c /home/yan/code/project/ServerEngine/PacketHelper.cpp

ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerEngine.dir/PacketHelper.cpp.i"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/ServerEngine/PacketHelper.cpp > CMakeFiles/ServerEngine.dir/PacketHelper.cpp.i

ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerEngine.dir/PacketHelper.cpp.s"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/ServerEngine/PacketHelper.cpp -o CMakeFiles/ServerEngine.dir/PacketHelper.cpp.s

ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o.requires:

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o.requires

ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o.provides: ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o.requires
	$(MAKE) -f ServerEngine/CMakeFiles/ServerEngine.dir/build.make ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o.provides.build
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o.provides

ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o.provides.build: ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o


ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.o: ServerEngine/CMakeFiles/ServerEngine.dir/flags.make
ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.o: ../ServerEngine/Signal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.o"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerEngine.dir/Signal.cpp.o -c /home/yan/code/project/ServerEngine/Signal.cpp

ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerEngine.dir/Signal.cpp.i"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/ServerEngine/Signal.cpp > CMakeFiles/ServerEngine.dir/Signal.cpp.i

ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerEngine.dir/Signal.cpp.s"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/ServerEngine/Signal.cpp -o CMakeFiles/ServerEngine.dir/Signal.cpp.s

ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.o.requires:

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.o.requires

ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.o.provides: ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.o.requires
	$(MAKE) -f ServerEngine/CMakeFiles/ServerEngine.dir/build.make ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.o.provides.build
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.o.provides

ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.o.provides.build: ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.o


ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.o: ServerEngine/CMakeFiles/ServerEngine.dir/flags.make
ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.o: ../ServerEngine/TCPClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.o"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerEngine.dir/TCPClient.cpp.o -c /home/yan/code/project/ServerEngine/TCPClient.cpp

ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerEngine.dir/TCPClient.cpp.i"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/ServerEngine/TCPClient.cpp > CMakeFiles/ServerEngine.dir/TCPClient.cpp.i

ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerEngine.dir/TCPClient.cpp.s"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/ServerEngine/TCPClient.cpp -o CMakeFiles/ServerEngine.dir/TCPClient.cpp.s

ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.o.requires:

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.o.requires

ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.o.provides: ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.o.requires
	$(MAKE) -f ServerEngine/CMakeFiles/ServerEngine.dir/build.make ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.o.provides.build
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.o.provides

ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.o.provides.build: ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.o


ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.o: ServerEngine/CMakeFiles/ServerEngine.dir/flags.make
ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.o: ../ServerEngine/TCPServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.o"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerEngine.dir/TCPServer.cpp.o -c /home/yan/code/project/ServerEngine/TCPServer.cpp

ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerEngine.dir/TCPServer.cpp.i"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/ServerEngine/TCPServer.cpp > CMakeFiles/ServerEngine.dir/TCPServer.cpp.i

ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerEngine.dir/TCPServer.cpp.s"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/ServerEngine/TCPServer.cpp -o CMakeFiles/ServerEngine.dir/TCPServer.cpp.s

ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.o.requires:

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.o.requires

ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.o.provides: ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.o.requires
	$(MAKE) -f ServerEngine/CMakeFiles/ServerEngine.dir/build.make ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.o.provides.build
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.o.provides

ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.o.provides.build: ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.o


ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o: ServerEngine/CMakeFiles/ServerEngine.dir/flags.make
ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o: ../ServerEngine/ThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o -c /home/yan/code/project/ServerEngine/ThreadPool.cpp

ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerEngine.dir/ThreadPool.cpp.i"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/ServerEngine/ThreadPool.cpp > CMakeFiles/ServerEngine.dir/ThreadPool.cpp.i

ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerEngine.dir/ThreadPool.cpp.s"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/ServerEngine/ThreadPool.cpp -o CMakeFiles/ServerEngine.dir/ThreadPool.cpp.s

ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o.requires:

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o.requires

ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o.provides: ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o.requires
	$(MAKE) -f ServerEngine/CMakeFiles/ServerEngine.dir/build.make ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o.provides.build
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o.provides

ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o.provides.build: ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o


ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.o: ServerEngine/CMakeFiles/ServerEngine.dir/flags.make
ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.o: ../ServerEngine/Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.o"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerEngine.dir/Timer.cpp.o -c /home/yan/code/project/ServerEngine/Timer.cpp

ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerEngine.dir/Timer.cpp.i"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/code/project/ServerEngine/Timer.cpp > CMakeFiles/ServerEngine.dir/Timer.cpp.i

ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerEngine.dir/Timer.cpp.s"
	cd /home/yan/code/project/build/ServerEngine && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/code/project/ServerEngine/Timer.cpp -o CMakeFiles/ServerEngine.dir/Timer.cpp.s

ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.o.requires:

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.o.requires

ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.o.provides: ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.o.requires
	$(MAKE) -f ServerEngine/CMakeFiles/ServerEngine.dir/build.make ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.o.provides.build
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.o.provides

ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.o.provides.build: ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.o


# Object files for target ServerEngine
ServerEngine_OBJECTS = \
"CMakeFiles/ServerEngine.dir/Connection.cpp.o" \
"CMakeFiles/ServerEngine.dir/CppMysql.cpp.o" \
"CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o" \
"CMakeFiles/ServerEngine.dir/HttpClient.cpp.o" \
"CMakeFiles/ServerEngine.dir/Logger.cpp.o" \
"CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o" \
"CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o" \
"CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o" \
"CMakeFiles/ServerEngine.dir/Signal.cpp.o" \
"CMakeFiles/ServerEngine.dir/TCPClient.cpp.o" \
"CMakeFiles/ServerEngine.dir/TCPServer.cpp.o" \
"CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o" \
"CMakeFiles/ServerEngine.dir/Timer.cpp.o"

# External object files for target ServerEngine
ServerEngine_EXTERNAL_OBJECTS =

ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.o
ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.o
ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o
ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.o
ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.o
ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o
ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o
ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o
ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.o
ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.o
ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.o
ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o
ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.o
ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/build.make
ServerEngine/libServerEngine.so: ServerEngine/CMakeFiles/ServerEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX shared library libServerEngine.so"
	cd /home/yan/code/project/build/ServerEngine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ServerEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ServerEngine/CMakeFiles/ServerEngine.dir/build: ServerEngine/libServerEngine.so

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/build

ServerEngine/CMakeFiles/ServerEngine.dir/requires: ServerEngine/CMakeFiles/ServerEngine.dir/Connection.cpp.o.requires
ServerEngine/CMakeFiles/ServerEngine.dir/requires: ServerEngine/CMakeFiles/ServerEngine.dir/CppMysql.cpp.o.requires
ServerEngine/CMakeFiles/ServerEngine.dir/requires: ServerEngine/CMakeFiles/ServerEngine.dir/EventDispatcher.cpp.o.requires
ServerEngine/CMakeFiles/ServerEngine.dir/requires: ServerEngine/CMakeFiles/ServerEngine.dir/HttpClient.cpp.o.requires
ServerEngine/CMakeFiles/ServerEngine.dir/requires: ServerEngine/CMakeFiles/ServerEngine.dir/Logger.cpp.o.requires
ServerEngine/CMakeFiles/ServerEngine.dir/requires: ServerEngine/CMakeFiles/ServerEngine.dir/MYSQLPool.cpp.o.requires
ServerEngine/CMakeFiles/ServerEngine.dir/requires: ServerEngine/CMakeFiles/ServerEngine.dir/MemoryStream.cpp.o.requires
ServerEngine/CMakeFiles/ServerEngine.dir/requires: ServerEngine/CMakeFiles/ServerEngine.dir/PacketHelper.cpp.o.requires
ServerEngine/CMakeFiles/ServerEngine.dir/requires: ServerEngine/CMakeFiles/ServerEngine.dir/Signal.cpp.o.requires
ServerEngine/CMakeFiles/ServerEngine.dir/requires: ServerEngine/CMakeFiles/ServerEngine.dir/TCPClient.cpp.o.requires
ServerEngine/CMakeFiles/ServerEngine.dir/requires: ServerEngine/CMakeFiles/ServerEngine.dir/TCPServer.cpp.o.requires
ServerEngine/CMakeFiles/ServerEngine.dir/requires: ServerEngine/CMakeFiles/ServerEngine.dir/ThreadPool.cpp.o.requires
ServerEngine/CMakeFiles/ServerEngine.dir/requires: ServerEngine/CMakeFiles/ServerEngine.dir/Timer.cpp.o.requires

.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/requires

ServerEngine/CMakeFiles/ServerEngine.dir/clean:
	cd /home/yan/code/project/build/ServerEngine && $(CMAKE_COMMAND) -P CMakeFiles/ServerEngine.dir/cmake_clean.cmake
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/clean

ServerEngine/CMakeFiles/ServerEngine.dir/depend:
	cd /home/yan/code/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yan/code/project /home/yan/code/project/ServerEngine /home/yan/code/project/build /home/yan/code/project/build/ServerEngine /home/yan/code/project/build/ServerEngine/CMakeFiles/ServerEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ServerEngine/CMakeFiles/ServerEngine.dir/depend

