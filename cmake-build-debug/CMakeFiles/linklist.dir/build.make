# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Clion\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Clion\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\sjjg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\sjjg\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/linklist.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/linklist.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linklist.dir/flags.make

CMakeFiles/linklist.dir/list/Linklist.cpp.obj: CMakeFiles/linklist.dir/flags.make
CMakeFiles/linklist.dir/list/Linklist.cpp.obj: ../list/Linklist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\sjjg\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linklist.dir/list/Linklist.cpp.obj"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\linklist.dir\list\Linklist.cpp.obj -c E:\sjjg\list\Linklist.cpp

CMakeFiles/linklist.dir/list/Linklist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linklist.dir/list/Linklist.cpp.i"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\sjjg\list\Linklist.cpp > CMakeFiles\linklist.dir\list\Linklist.cpp.i

CMakeFiles/linklist.dir/list/Linklist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linklist.dir/list/Linklist.cpp.s"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\sjjg\list\Linklist.cpp -o CMakeFiles\linklist.dir\list\Linklist.cpp.s

# Object files for target linklist
linklist_OBJECTS = \
"CMakeFiles/linklist.dir/list/Linklist.cpp.obj"

# External object files for target linklist
linklist_EXTERNAL_OBJECTS =

linklist.exe: CMakeFiles/linklist.dir/list/Linklist.cpp.obj
linklist.exe: CMakeFiles/linklist.dir/build.make
linklist.exe: CMakeFiles/linklist.dir/linklibs.rsp
linklist.exe: CMakeFiles/linklist.dir/objects1.rsp
linklist.exe: CMakeFiles/linklist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\sjjg\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable linklist.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\linklist.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linklist.dir/build: linklist.exe
.PHONY : CMakeFiles/linklist.dir/build

CMakeFiles/linklist.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\linklist.dir\cmake_clean.cmake
.PHONY : CMakeFiles/linklist.dir/clean

CMakeFiles/linklist.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\sjjg E:\sjjg E:\sjjg\cmake-build-debug E:\sjjg\cmake-build-debug E:\sjjg\cmake-build-debug\CMakeFiles\linklist.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linklist.dir/depend
