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
include CMakeFiles/kuohao.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/kuohao.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kuohao.dir/flags.make

CMakeFiles/kuohao.dir/homework/kuohao.cpp.obj: CMakeFiles/kuohao.dir/flags.make
CMakeFiles/kuohao.dir/homework/kuohao.cpp.obj: ../homework/kuohao.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\sjjg\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kuohao.dir/homework/kuohao.cpp.obj"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\kuohao.dir\homework\kuohao.cpp.obj -c E:\sjjg\homework\kuohao.cpp

CMakeFiles/kuohao.dir/homework/kuohao.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kuohao.dir/homework/kuohao.cpp.i"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\sjjg\homework\kuohao.cpp > CMakeFiles\kuohao.dir\homework\kuohao.cpp.i

CMakeFiles/kuohao.dir/homework/kuohao.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kuohao.dir/homework/kuohao.cpp.s"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\sjjg\homework\kuohao.cpp -o CMakeFiles\kuohao.dir\homework\kuohao.cpp.s

CMakeFiles/kuohao.dir/tool/tools.cpp.obj: CMakeFiles/kuohao.dir/flags.make
CMakeFiles/kuohao.dir/tool/tools.cpp.obj: ../tool/tools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\sjjg\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/kuohao.dir/tool/tools.cpp.obj"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\kuohao.dir\tool\tools.cpp.obj -c E:\sjjg\tool\tools.cpp

CMakeFiles/kuohao.dir/tool/tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kuohao.dir/tool/tools.cpp.i"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\sjjg\tool\tools.cpp > CMakeFiles\kuohao.dir\tool\tools.cpp.i

CMakeFiles/kuohao.dir/tool/tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kuohao.dir/tool/tools.cpp.s"
	D:\programe\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\sjjg\tool\tools.cpp -o CMakeFiles\kuohao.dir\tool\tools.cpp.s

# Object files for target kuohao
kuohao_OBJECTS = \
"CMakeFiles/kuohao.dir/homework/kuohao.cpp.obj" \
"CMakeFiles/kuohao.dir/tool/tools.cpp.obj"

# External object files for target kuohao
kuohao_EXTERNAL_OBJECTS =

kuohao.exe: CMakeFiles/kuohao.dir/homework/kuohao.cpp.obj
kuohao.exe: CMakeFiles/kuohao.dir/tool/tools.cpp.obj
kuohao.exe: CMakeFiles/kuohao.dir/build.make
kuohao.exe: CMakeFiles/kuohao.dir/linklibs.rsp
kuohao.exe: CMakeFiles/kuohao.dir/objects1.rsp
kuohao.exe: CMakeFiles/kuohao.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\sjjg\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable kuohao.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\kuohao.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kuohao.dir/build: kuohao.exe
.PHONY : CMakeFiles/kuohao.dir/build

CMakeFiles/kuohao.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\kuohao.dir\cmake_clean.cmake
.PHONY : CMakeFiles/kuohao.dir/clean

CMakeFiles/kuohao.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\sjjg E:\sjjg E:\sjjg\cmake-build-debug E:\sjjg\cmake-build-debug E:\sjjg\cmake-build-debug\CMakeFiles\kuohao.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kuohao.dir/depend

