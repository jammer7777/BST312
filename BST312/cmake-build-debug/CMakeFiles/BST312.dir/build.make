# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jakea\CLionProjects\BST312

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jakea\CLionProjects\BST312\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BST312.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BST312.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BST312.dir/flags.make

CMakeFiles/BST312.dir/main.cpp.obj: CMakeFiles/BST312.dir/flags.make
CMakeFiles/BST312.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jakea\CLionProjects\BST312\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BST312.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BST312.dir\main.cpp.obj -c C:\Users\jakea\CLionProjects\BST312\main.cpp

CMakeFiles/BST312.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BST312.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jakea\CLionProjects\BST312\main.cpp > CMakeFiles\BST312.dir\main.cpp.i

CMakeFiles/BST312.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BST312.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jakea\CLionProjects\BST312\main.cpp -o CMakeFiles\BST312.dir\main.cpp.s

CMakeFiles/BST312.dir/BST312.cpp.obj: CMakeFiles/BST312.dir/flags.make
CMakeFiles/BST312.dir/BST312.cpp.obj: ../BST312.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jakea\CLionProjects\BST312\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BST312.dir/BST312.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BST312.dir\BST312.cpp.obj -c C:\Users\jakea\CLionProjects\BST312\BST312.cpp

CMakeFiles/BST312.dir/BST312.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BST312.dir/BST312.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jakea\CLionProjects\BST312\BST312.cpp > CMakeFiles\BST312.dir\BST312.cpp.i

CMakeFiles/BST312.dir/BST312.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BST312.dir/BST312.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jakea\CLionProjects\BST312\BST312.cpp -o CMakeFiles\BST312.dir\BST312.cpp.s

# Object files for target BST312
BST312_OBJECTS = \
"CMakeFiles/BST312.dir/main.cpp.obj" \
"CMakeFiles/BST312.dir/BST312.cpp.obj"

# External object files for target BST312
BST312_EXTERNAL_OBJECTS =

BST312.exe: CMakeFiles/BST312.dir/main.cpp.obj
BST312.exe: CMakeFiles/BST312.dir/BST312.cpp.obj
BST312.exe: CMakeFiles/BST312.dir/build.make
BST312.exe: CMakeFiles/BST312.dir/linklibs.rsp
BST312.exe: CMakeFiles/BST312.dir/objects1.rsp
BST312.exe: CMakeFiles/BST312.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jakea\CLionProjects\BST312\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BST312.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BST312.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BST312.dir/build: BST312.exe

.PHONY : CMakeFiles/BST312.dir/build

CMakeFiles/BST312.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BST312.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BST312.dir/clean

CMakeFiles/BST312.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jakea\CLionProjects\BST312 C:\Users\jakea\CLionProjects\BST312 C:\Users\jakea\CLionProjects\BST312\cmake-build-debug C:\Users\jakea\CLionProjects\BST312\cmake-build-debug C:\Users\jakea\CLionProjects\BST312\cmake-build-debug\CMakeFiles\BST312.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BST312.dir/depend

