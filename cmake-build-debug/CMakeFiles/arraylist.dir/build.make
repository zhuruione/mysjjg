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
include CMakeFiles/arraylist.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/arraylist.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arraylist.dir/flags.make

CMakeFiles/arraylist.dir/list/arraylist.cpp.obj: CMakeFiles/arraylist.dir/flags.make
CMakeFiles/arraylist.dir/list/arraylist.cpp.obj: ../list/arraylist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\sjjg\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/arraylist.dir/list/arraylist.cpp.obj"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\arraylist.dir\list\arraylist.cpp.obj -c E:\sjjg\list\arraylist.cpp

CMakeFiles/arraylist.dir/list/arraylist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arraylist.dir/list/arraylist.cpp.i"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\sjjg\list\arraylist.cpp > CMakeFiles\arraylist.dir\list\arraylist.cpp.i

CMakeFiles/arraylist.dir/list/arraylist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arraylist.dir/list/arraylist.cpp.s"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\sjjg\list\arraylist.cpp -o CMakeFiles\arraylist.dir\list\arraylist.cpp.s

# Object files for target arraylist
arraylist_OBJECTS = \
"CMakeFiles/arraylist.dir/list/arraylist.cpp.obj"

# External object files for target arraylist
arraylist_EXTERNAL_OBJECTS =

arraylist.exe: CMakeFiles/arraylist.dir/list/arraylist.cpp.obj
arraylist.exe: CMakeFiles/arraylist.dir/build.make
arraylist.exe: CMakeFiles/arraylist.dir/linklibs.rsp
arraylist.exe: CMakeFiles/arraylist.dir/objects1.rsp
arraylist.exe: CMakeFiles/arraylist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\sjjg\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable arraylist.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\arraylist.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/arraylist.dir/build: arraylist.exe
.PHONY : CMakeFiles/arraylist.dir/build

CMakeFiles/arraylist.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\arraylist.dir\cmake_clean.cmake
.PHONY : CMakeFiles/arraylist.dir/clean

CMakeFiles/arraylist.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\sjjg E:\sjjg E:\sjjg\cmake-build-debug E:\sjjg\cmake-build-debug E:\sjjg\cmake-build-debug\CMakeFiles\arraylist.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arraylist.dir/depend

