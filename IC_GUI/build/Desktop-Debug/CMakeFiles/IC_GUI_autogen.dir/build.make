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
CMAKE_SOURCE_DIR = /home/yeongyoo/DES_Instrument-Cluster-Team7/IC_GUI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yeongyoo/DES_Instrument-Cluster-Team7/IC_GUI/build/Desktop-Debug

# Utility rule file for IC_GUI_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/IC_GUI_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/IC_GUI_autogen.dir/progress.make

CMakeFiles/IC_GUI_autogen: IC_GUI_autogen/timestamp

IC_GUI_autogen/timestamp: /usr/lib/qt5/bin/moc
IC_GUI_autogen/timestamp: CMakeFiles/IC_GUI_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/yeongyoo/DES_Instrument-Cluster-Team7/IC_GUI/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target IC_GUI"
	/usr/bin/cmake -E cmake_autogen /home/yeongyoo/DES_Instrument-Cluster-Team7/IC_GUI/build/Desktop-Debug/CMakeFiles/IC_GUI_autogen.dir/AutogenInfo.json Debug
	/usr/bin/cmake -E touch /home/yeongyoo/DES_Instrument-Cluster-Team7/IC_GUI/build/Desktop-Debug/IC_GUI_autogen/timestamp

IC_GUI_autogen: CMakeFiles/IC_GUI_autogen
IC_GUI_autogen: IC_GUI_autogen/timestamp
IC_GUI_autogen: CMakeFiles/IC_GUI_autogen.dir/build.make
.PHONY : IC_GUI_autogen

# Rule to build all files generated by this target.
CMakeFiles/IC_GUI_autogen.dir/build: IC_GUI_autogen
.PHONY : CMakeFiles/IC_GUI_autogen.dir/build

CMakeFiles/IC_GUI_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IC_GUI_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IC_GUI_autogen.dir/clean

CMakeFiles/IC_GUI_autogen.dir/depend:
	cd /home/yeongyoo/DES_Instrument-Cluster-Team7/IC_GUI/build/Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yeongyoo/DES_Instrument-Cluster-Team7/IC_GUI /home/yeongyoo/DES_Instrument-Cluster-Team7/IC_GUI /home/yeongyoo/DES_Instrument-Cluster-Team7/IC_GUI/build/Desktop-Debug /home/yeongyoo/DES_Instrument-Cluster-Team7/IC_GUI/build/Desktop-Debug /home/yeongyoo/DES_Instrument-Cluster-Team7/IC_GUI/build/Desktop-Debug/CMakeFiles/IC_GUI_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/IC_GUI_autogen.dir/depend

