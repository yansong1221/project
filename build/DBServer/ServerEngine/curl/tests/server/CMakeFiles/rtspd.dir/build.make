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
include DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/depend.make

# Include the progress variables for this target.
include DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/progress.make

# Include the compile flags for this target's objects.
include DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/flags.make

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o: ../3rd/curl/lib/mprintf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o   -c /home/yan/code/project/3rd/curl/lib/mprintf.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/lib/mprintf.c > CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/lib/mprintf.c -o CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o: ../3rd/curl/lib/nonblock.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o   -c /home/yan/code/project/3rd/curl/lib/nonblock.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/lib/nonblock.c > CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/lib/nonblock.c -o CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o: ../3rd/curl/lib/strtoofft.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o   -c /home/yan/code/project/3rd/curl/lib/strtoofft.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/lib/strtoofft.c > CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/lib/strtoofft.c -o CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o: ../3rd/curl/lib/warnless.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o   -c /home/yan/code/project/3rd/curl/lib/warnless.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/__/__/lib/warnless.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/lib/warnless.c > CMakeFiles/rtspd.dir/__/__/lib/warnless.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/__/__/lib/warnless.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/lib/warnless.c -o CMakeFiles/rtspd.dir/__/__/lib/warnless.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o: ../3rd/curl/lib/curl_ctype.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o   -c /home/yan/code/project/3rd/curl/lib/curl_ctype.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/lib/curl_ctype.c > CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/lib/curl_ctype.c -o CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.o: ../3rd/curl/tests/server/getpart.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/getpart.c.o   -c /home/yan/code/project/3rd/curl/tests/server/getpart.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/getpart.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/tests/server/getpart.c > CMakeFiles/rtspd.dir/getpart.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/getpart.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/tests/server/getpart.c -o CMakeFiles/rtspd.dir/getpart.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o: ../3rd/curl/lib/base64.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/__/__/lib/base64.c.o   -c /home/yan/code/project/3rd/curl/lib/base64.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/__/__/lib/base64.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/lib/base64.c > CMakeFiles/rtspd.dir/__/__/lib/base64.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/__/__/lib/base64.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/lib/base64.c -o CMakeFiles/rtspd.dir/__/__/lib/base64.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o: ../3rd/curl/lib/memdebug.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o   -c /home/yan/code/project/3rd/curl/lib/memdebug.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/lib/memdebug.c > CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/lib/memdebug.c -o CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.o: ../3rd/curl/tests/server/util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/util.c.o   -c /home/yan/code/project/3rd/curl/tests/server/util.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/util.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/tests/server/util.c > CMakeFiles/rtspd.dir/util.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/util.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/tests/server/util.c -o CMakeFiles/rtspd.dir/util.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.o


DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.o: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/flags.make
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.o: ../3rd/curl/tests/server/rtspd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.o"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rtspd.dir/rtspd.c.o   -c /home/yan/code/project/3rd/curl/tests/server/rtspd.c

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rtspd.dir/rtspd.c.i"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yan/code/project/3rd/curl/tests/server/rtspd.c > CMakeFiles/rtspd.dir/rtspd.c.i

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rtspd.dir/rtspd.c.s"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yan/code/project/3rd/curl/tests/server/rtspd.c -o CMakeFiles/rtspd.dir/rtspd.c.s

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.o.requires:

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.o.requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.o.provides: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.o.requires
	$(MAKE) -f DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/build.make DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.o.provides.build
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.o.provides

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.o.provides.build: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.o


# Object files for target rtspd
rtspd_OBJECTS = \
"CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o" \
"CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o" \
"CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o" \
"CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o" \
"CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o" \
"CMakeFiles/rtspd.dir/getpart.c.o" \
"CMakeFiles/rtspd.dir/__/__/lib/base64.c.o" \
"CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o" \
"CMakeFiles/rtspd.dir/util.c.o" \
"CMakeFiles/rtspd.dir/rtspd.c.o"

# External object files for target rtspd
rtspd_EXTERNAL_OBJECTS =

DBServer/ServerEngine/curl/tests/server/rtspd: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o
DBServer/ServerEngine/curl/tests/server/rtspd: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o
DBServer/ServerEngine/curl/tests/server/rtspd: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o
DBServer/ServerEngine/curl/tests/server/rtspd: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o
DBServer/ServerEngine/curl/tests/server/rtspd: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o
DBServer/ServerEngine/curl/tests/server/rtspd: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.o
DBServer/ServerEngine/curl/tests/server/rtspd: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o
DBServer/ServerEngine/curl/tests/server/rtspd: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o
DBServer/ServerEngine/curl/tests/server/rtspd: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.o
DBServer/ServerEngine/curl/tests/server/rtspd: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.o
DBServer/ServerEngine/curl/tests/server/rtspd: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/build.make
DBServer/ServerEngine/curl/tests/server/rtspd: /usr/lib/x86_64-linux-gnu/libssl.so
DBServer/ServerEngine/curl/tests/server/rtspd: /usr/lib/x86_64-linux-gnu/libcrypto.so
DBServer/ServerEngine/curl/tests/server/rtspd: /usr/lib/x86_64-linux-gnu/libz.so
DBServer/ServerEngine/curl/tests/server/rtspd: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yan/code/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable rtspd"
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rtspd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/build: DBServer/ServerEngine/curl/tests/server/rtspd

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/build

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/mprintf.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/nonblock.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/strtoofft.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/warnless.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/curl_ctype.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/getpart.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/base64.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/__/__/lib/memdebug.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/util.c.o.requires
DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/requires: DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/rtspd.c.o.requires

.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/requires

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/clean:
	cd /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server && $(CMAKE_COMMAND) -P CMakeFiles/rtspd.dir/cmake_clean.cmake
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/clean

DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/depend:
	cd /home/yan/code/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yan/code/project /home/yan/code/project/3rd/curl/tests/server /home/yan/code/project/build /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server /home/yan/code/project/build/DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : DBServer/ServerEngine/curl/tests/server/CMakeFiles/rtspd.dir/depend

