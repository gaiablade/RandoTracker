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
CMAKE_SOURCE_DIR = /home/caleb/Programming/Tracker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/caleb/Programming/Tracker/build

# Utility rule file for Tracker_autogen.

# Include the progress variables for this target.
include CMakeFiles/Tracker_autogen.dir/progress.make

CMakeFiles/Tracker_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/caleb/Programming/Tracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target Tracker"
	/usr/bin/cmake -E cmake_autogen /home/caleb/Programming/Tracker/build/CMakeFiles/Tracker_autogen.dir/AutogenInfo.json ""

Tracker_autogen: CMakeFiles/Tracker_autogen
Tracker_autogen: CMakeFiles/Tracker_autogen.dir/build.make

.PHONY : Tracker_autogen

# Rule to build all files generated by this target.
CMakeFiles/Tracker_autogen.dir/build: Tracker_autogen

.PHONY : CMakeFiles/Tracker_autogen.dir/build

CMakeFiles/Tracker_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tracker_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tracker_autogen.dir/clean

CMakeFiles/Tracker_autogen.dir/depend:
	cd /home/caleb/Programming/Tracker/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caleb/Programming/Tracker /home/caleb/Programming/Tracker /home/caleb/Programming/Tracker/build /home/caleb/Programming/Tracker/build /home/caleb/Programming/Tracker/build/CMakeFiles/Tracker_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tracker_autogen.dir/depend
