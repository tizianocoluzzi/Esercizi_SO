# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/tiziano/SO/esercitazioni_SO/exercise_2/bonus_mio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tiziano/SO/esercitazioni_SO/exercise_2/bonus_mio/build

# Include any dependencies generated for this target.
include CMakeFiles/linked_list_library.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/linked_list_library.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/linked_list_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linked_list_library.dir/flags.make

CMakeFiles/linked_list_library.dir/Auto.c.o: CMakeFiles/linked_list_library.dir/flags.make
CMakeFiles/linked_list_library.dir/Auto.c.o: /home/tiziano/SO/esercitazioni_SO/exercise_2/bonus_mio/Auto.c
CMakeFiles/linked_list_library.dir/Auto.c.o: CMakeFiles/linked_list_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tiziano/SO/esercitazioni_SO/exercise_2/bonus_mio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/linked_list_library.dir/Auto.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/linked_list_library.dir/Auto.c.o -MF CMakeFiles/linked_list_library.dir/Auto.c.o.d -o CMakeFiles/linked_list_library.dir/Auto.c.o -c /home/tiziano/SO/esercitazioni_SO/exercise_2/bonus_mio/Auto.c

CMakeFiles/linked_list_library.dir/Auto.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/linked_list_library.dir/Auto.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tiziano/SO/esercitazioni_SO/exercise_2/bonus_mio/Auto.c > CMakeFiles/linked_list_library.dir/Auto.c.i

CMakeFiles/linked_list_library.dir/Auto.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/linked_list_library.dir/Auto.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tiziano/SO/esercitazioni_SO/exercise_2/bonus_mio/Auto.c -o CMakeFiles/linked_list_library.dir/Auto.c.s

# Object files for target linked_list_library
linked_list_library_OBJECTS = \
"CMakeFiles/linked_list_library.dir/Auto.c.o"

# External object files for target linked_list_library
linked_list_library_EXTERNAL_OBJECTS =

liblinked_list_library.so: CMakeFiles/linked_list_library.dir/Auto.c.o
liblinked_list_library.so: CMakeFiles/linked_list_library.dir/build.make
liblinked_list_library.so: CMakeFiles/linked_list_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tiziano/SO/esercitazioni_SO/exercise_2/bonus_mio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library liblinked_list_library.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linked_list_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linked_list_library.dir/build: liblinked_list_library.so
.PHONY : CMakeFiles/linked_list_library.dir/build

CMakeFiles/linked_list_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linked_list_library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linked_list_library.dir/clean

CMakeFiles/linked_list_library.dir/depend:
	cd /home/tiziano/SO/esercitazioni_SO/exercise_2/bonus_mio/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tiziano/SO/esercitazioni_SO/exercise_2/bonus_mio /home/tiziano/SO/esercitazioni_SO/exercise_2/bonus_mio /home/tiziano/SO/esercitazioni_SO/exercise_2/bonus_mio/build /home/tiziano/SO/esercitazioni_SO/exercise_2/bonus_mio/build /home/tiziano/SO/esercitazioni_SO/exercise_2/bonus_mio/build/CMakeFiles/linked_list_library.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/linked_list_library.dir/depend

