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
include DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/depend.make

# Include the progress variables for this target.
include DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/progress.make

# Include the compile flags for this target's objects.
include DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/flags.make

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o: ../3rd/curl/lib/mprintf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o   -c /home/yan/code/project/3rd/curl/lib/mprintf.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/resolve.dir/__/__/lib/mprintf.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/lib/mprintf.c > CMakeFiles/resolve.dir/__/__/lib/mprintf.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/resolve.dir/__/__/lib/mprintf.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/lib/mprintf.c -o CMakeFiles/resolve.dir/__/__/lib/mprintf.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o: ../3rd/curl/lib/nonblock.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o   -c /home/yan/code/project/3rd/curl/lib/nonblock.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/resolve.dir/__/__/lib/nonblock.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/lib/nonblock.c > CMakeFiles/resolve.dir/__/__/lib/nonblock.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/resolve.dir/__/__/lib/nonblock.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/lib/nonblock.c -o CMakeFiles/resolve.dir/__/__/lib/nonblock.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o: ../3rd/curl/lib/strtoofft.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o   -c /home/yan/code/project/3rd/curl/lib/strtoofft.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/lib/strtoofft.c > CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/lib/strtoofft.c -o CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.o: ../3rd/curl/lib/warnless.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/resolve.dir/__/__/lib/warnless.c.o   -c /home/yan/code/project/3rd/curl/lib/warnless.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/resolve.dir/__/__/lib/warnless.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/lib/warnless.c > CMakeFiles/resolve.dir/__/__/lib/warnless.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/resolve.dir/__/__/lib/warnless.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/lib/warnless.c -o CMakeFiles/resolve.dir/__/__/lib/warnless.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o: ../3rd/curl/lib/curl_ctype.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o   -c /home/yan/code/project/3rd/curl/lib/curl_ctype.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/lib/curl_ctype.c > CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/lib/curl_ctype.c -o CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.o: ../3rd/curl/tests/server/getpart.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/resolve.dir/getpart.c.o   -c /home/yan/code/project/3rd/curl/tests/server/getpart.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/resolve.dir/getpart.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/tests/server/getpart.c > CMakeFiles/resolve.dir/getpart.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/resolve.dir/getpart.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/tests/server/getpart.c -o CMakeFiles/resolve.dir/getpart.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.o: ../3rd/curl/lib/base64.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/resolve.dir/__/__/lib/base64.c.o   -c /home/yan/code/project/3rd/curl/lib/base64.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/resolve.dir/__/__/lib/base64.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/lib/base64.c > CMakeFiles/resolve.dir/__/__/lib/base64.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/resolve.dir/__/__/lib/base64.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/lib/base64.c -o CMakeFiles/resolve.dir/__/__/lib/base64.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o: ../3rd/curl/lib/memdebug.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o   -c /home/yan/code/project/3rd/curl/lib/memdebug.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/resolve.dir/__/__/lib/memdebug.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/lib/memdebug.c > CMakeFiles/resolve.dir/__/__/lib/memdebug.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/resolve.dir/__/__/lib/memdebug.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/lib/memdebug.c -o CMakeFiles/resolve.dir/__/__/lib/memdebug.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.o: ../3rd/curl/tests/server/util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/resolve.dir/util.c.o   -c /home/yan/code/project/3rd/curl/tests/server/util.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/resolve.dir/util.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/tests/server/util.c > CMakeFiles/resolve.dir/util.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/resolve.dir/util.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/tests/server/util.c -o CMakeFiles/resolve.dir/util.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.o: ../3rd/curl/tests/server/resolve.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/resolve.dir/resolve.c.o   -c /home/yan/code/project/3rd/curl/tests/server/resolve.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/resolve.dir/resolve.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/tests/server/resolve.c > CMakeFiles/resolve.dir/resolve.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/resolve.dir/resolve.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/tests/server/resolve.c -o CMakeFiles/resolve.dir/resolve.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.o


# Object files for target resolve
resolve_OBJECTS = \
"CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o" \
"CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o" \
"CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o" \
"CMakeFiles/resolve.dir/__/__/lib/warnless.c.o" \
"CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o" \
"CMakeFiles/resolve.dir/getpart.c.o" \
"CMakeFiles/resolve.dir/__/__/lib/base64.c.o" \
"CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o" \
"CMakeFiles/resolve.dir/util.c.o" \
"CMakeFiles/resolve.dir/resolve.c.o"

# External object files for target resolve
resolve_EXTERNAL_OBJECTS =

DBServer/ServerEngine/curl/tests/server/resolve: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o
DBServer/ServerEngine/curl/tests/server/resolve: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o
DBServer/ServerEngine/curl/tests/server/resolve: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o
DBServer/ServerEngine/curl/tests/server/resolve: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.o
DBServer/ServerEngine/curl/tests/server/resolve: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o
DBServer/ServerEngine/curl/tests/server/resolve: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.o
DBServer/ServerEngine/curl/tests/server/resolve: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.o
DBServer/ServerEngine/curl/tests/server/resolve: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o
DBServer/ServerEngine/curl/tests/server/resolve: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.o
DBServer/ServerEngine/curl/tests/server/resolve: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.o
DBServer/ServerEngine/curl/tests/server/resolve: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/build.make
DBServer/ServerEngine/curl/tests/server/resolve: /usr/lib/x86_64-linux-gnu/libssl.so
DBServer/ServerEngine/curl/tests/server/resolve: /usr/lib/x86_64-linux-gnu/libcrypto.so
DBServer/ServerEngine/curl/tests/server/resolve: /usr/lib/x86_64-linux-gnu/libz.so
DBServer/ServerEngine/curl/tests/server/resolve: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable resolve"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/resolve.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/build: DBServer/ServerEngine/curl/tests/server/resolve

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/build

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/mprintf.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/nonblock.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/strtoofft.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/warnless.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/curl_ctype.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/getpart.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/base64.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/__/__/lib/memdebug.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/util.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/resolve.c.o.requires

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/clean:
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && $(CMAKE_COMMAND) -P CMakeFiles/resolve.dir/cmake_clean.cmake
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/clean

DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/depend:
	cd /home/yan/code/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yan/code/project /home/yan/code/project/3rd/curl/tests/server /home/yan/code/project/build /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/resolve.dir/depend
