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
include CMakeFiles/tree.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tree.dir/flags.make

CMakeFiles/tree.dir/tree/Tree.cpp.obj: CMakeFiles/tree.dir/flags.make
CMakeFiles/tree.dir/tree/Tree.cpp.obj: ../tree/Tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\sjjg\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tree.dir/tree/Tree.cpp.obj"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tree.dir\tree\Tree.cpp.obj -c E:\sjjg\tree\Tree.cpp

CMakeFiles/tree.dir/tree/Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tree.dir/tree/Tree.cpp.i"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\sjjg\tree\Tree.cpp > CMakeFiles\tree.dir\tree\Tree.cpp.i

CMakeFiles/tree.dir/tree/Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tree.dir/tree/Tree.cpp.s"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\sjjg\tree\Tree.cpp -o CMakeFiles\tree.dir\tree\Tree.cpp.s

# Object files for target tree
tree_OBJECTS = \
"CMakeFiles/tree.dir/tree/Tree.cpp.obj"

# External object files for target tree
tree_EXTERNAL_OBJECTS =

tree.exe: CMakeFiles/tree.dir/tree/Tree.cpp.obj
tree.exe: CMakeFiles/tree.dir/build.make
tree.exe: CMakeFiles/tree.dir/linklibs.rsp
tree.exe: CMakeFiles/tree.dir/objects1.rsp
tree.exe: CMakeFiles/tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\sjjg\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tree.dir/build: tree.exe
.PHONY : CMakeFiles/tree.dir/build

CMakeFiles/tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tree.dir/clean

CMakeFiles/tree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\sjjg E:\sjjg E:\sjjg\cmake-build-debug E:\sjjg\cmake-build-debug E:\sjjg\cmake-build-debug\CMakeFiles\tree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tree.dir/depend

