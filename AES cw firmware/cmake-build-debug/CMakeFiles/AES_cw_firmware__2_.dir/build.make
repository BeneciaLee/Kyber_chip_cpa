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
CMAKE_SOURCE_DIR = "/mnt/e/AES cw firmware (2)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/e/AES cw firmware (2)/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/AES_cw_firmware__2_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AES_cw_firmware__2_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AES_cw_firmware__2_.dir/flags.make

CMakeFiles/AES_cw_firmware__2_.dir/main.c.o: CMakeFiles/AES_cw_firmware__2_.dir/flags.make
CMakeFiles/AES_cw_firmware__2_.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/e/AES cw firmware (2)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AES_cw_firmware__2_.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/AES_cw_firmware__2_.dir/main.c.o   -c "/mnt/e/AES cw firmware (2)/main.c"

CMakeFiles/AES_cw_firmware__2_.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AES_cw_firmware__2_.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/e/AES cw firmware (2)/main.c" > CMakeFiles/AES_cw_firmware__2_.dir/main.c.i

CMakeFiles/AES_cw_firmware__2_.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AES_cw_firmware__2_.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/e/AES cw firmware (2)/main.c" -o CMakeFiles/AES_cw_firmware__2_.dir/main.c.s

# Object files for target AES_cw_firmware__2_
AES_cw_firmware__2__OBJECTS = \
"CMakeFiles/AES_cw_firmware__2_.dir/main.c.o"

# External object files for target AES_cw_firmware__2_
AES_cw_firmware__2__EXTERNAL_OBJECTS =

AES_cw_firmware__2_: CMakeFiles/AES_cw_firmware__2_.dir/main.c.o
AES_cw_firmware__2_: CMakeFiles/AES_cw_firmware__2_.dir/build.make
AES_cw_firmware__2_: CMakeFiles/AES_cw_firmware__2_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/e/AES cw firmware (2)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable AES_cw_firmware__2_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AES_cw_firmware__2_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AES_cw_firmware__2_.dir/build: AES_cw_firmware__2_

.PHONY : CMakeFiles/AES_cw_firmware__2_.dir/build

CMakeFiles/AES_cw_firmware__2_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AES_cw_firmware__2_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AES_cw_firmware__2_.dir/clean

CMakeFiles/AES_cw_firmware__2_.dir/depend:
	cd "/mnt/e/AES cw firmware (2)/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/e/AES cw firmware (2)" "/mnt/e/AES cw firmware (2)" "/mnt/e/AES cw firmware (2)/cmake-build-debug" "/mnt/e/AES cw firmware (2)/cmake-build-debug" "/mnt/e/AES cw firmware (2)/cmake-build-debug/CMakeFiles/AES_cw_firmware__2_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/AES_cw_firmware__2_.dir/depend

