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
include CMakeFiles/arrayqueue.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/arrayqueue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arrayqueue.dir/flags.make

CMakeFiles/arrayqueue.dir/Queue/arayqueue.cpp.obj: CMakeFiles/arrayqueue.dir/flags.make
CMakeFiles/arrayqueue.dir/Queue/arayqueue.cpp.obj: ../Queue/arayqueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\sjjg\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/arrayqueue.dir/Queue/arayqueue.cpp.obj"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\arrayqueue.dir\Queue\arayqueue.cpp.obj -c E:\sjjg\Queue\arayqueue.cpp

CMakeFiles/arrayqueue.dir/Queue/arayqueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arrayqueue.dir/Queue/arayqueue.cpp.i"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\sjjg\Queue\arayqueue.cpp > CMakeFiles\arrayqueue.dir\Queue\arayqueue.cpp.i

CMakeFiles/arrayqueue.dir/Queue/arayqueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arrayqueue.dir/Queue/arayqueue.cpp.s"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\sjjg\Queue\arayqueue.cpp -o CMakeFiles\arrayqueue.dir\Queue\arayqueue.cpp.s

# Object files for target arrayqueue
arrayqueue_OBJECTS = \
"CMakeFiles/arrayqueue.dir/Queue/arayqueue.cpp.obj"

# External object files for target arrayqueue
arrayqueue_EXTERNAL_OBJECTS =

arrayqueue.exe: CMakeFiles/arrayqueue.dir/Queue/arayqueue.cpp.obj
arrayqueue.exe: CMakeFiles/arrayqueue.dir/build.make
arrayqueue.exe: CMakeFiles/arrayqueue.dir/linklibs.rsp
arrayqueue.exe: CMakeFiles/arrayqueue.dir/objects1.rsp
arrayqueue.exe: CMakeFiles/arrayqueue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\sjjg\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable arrayqueue.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\arrayqueue.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/arrayqueue.dir/build: arrayqueue.exe
.PHONY : CMakeFiles/arrayqueue.dir/build

CMakeFiles/arrayqueue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\arrayqueue.dir\cmake_clean.cmake
.PHONY : CMakeFiles/arrayqueue.dir/clean

CMakeFiles/arrayqueue.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\sjjg E:\sjjg E:\sjjg\cmake-build-debug E:\sjjg\cmake-build-debug E:\sjjg\cmake-build-debug\CMakeFiles\arrayqueue.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arrayqueue.dir/depend

