# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /home/alexey/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/alexey/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexey/projects/MLP/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexey/projects/MLP/src/build

# Utility rule file for MLP_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/MLP_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MLP_autogen.dir/progress.make

CMakeFiles/MLP_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/alexey/projects/MLP/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target MLP"
	/home/alexey/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E cmake_autogen /home/alexey/projects/MLP/src/build/CMakeFiles/MLP_autogen.dir/AutogenInfo.json ""

MLP_autogen: CMakeFiles/MLP_autogen
MLP_autogen: CMakeFiles/MLP_autogen.dir/build.make
.PHONY : MLP_autogen

# Rule to build all files generated by this target.
CMakeFiles/MLP_autogen.dir/build: MLP_autogen
.PHONY : CMakeFiles/MLP_autogen.dir/build

CMakeFiles/MLP_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MLP_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MLP_autogen.dir/clean

CMakeFiles/MLP_autogen.dir/depend:
	cd /home/alexey/projects/MLP/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexey/projects/MLP/src /home/alexey/projects/MLP/src /home/alexey/projects/MLP/src/build /home/alexey/projects/MLP/src/build /home/alexey/projects/MLP/src/build/CMakeFiles/MLP_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MLP_autogen.dir/depend

