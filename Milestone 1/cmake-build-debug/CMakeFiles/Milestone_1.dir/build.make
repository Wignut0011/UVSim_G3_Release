# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Dan5h\School\New folder\Milestone 1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Dan5h\School\New folder\Milestone 1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Milestone_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Milestone_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Milestone_1.dir/flags.make

CMakeFiles/Milestone_1.dir/GUI.cpp.obj: CMakeFiles/Milestone_1.dir/flags.make
CMakeFiles/Milestone_1.dir/GUI.cpp.obj: ../GUI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Dan5h\School\New folder\Milestone 1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Milestone_1.dir/GUI.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Milestone_1.dir\GUI.cpp.obj -c "C:\Users\Dan5h\School\New folder\Milestone 1\GUI.cpp"

CMakeFiles/Milestone_1.dir/GUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Milestone_1.dir/GUI.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Dan5h\School\New folder\Milestone 1\GUI.cpp" > CMakeFiles\Milestone_1.dir\GUI.cpp.i

CMakeFiles/Milestone_1.dir/GUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Milestone_1.dir/GUI.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Dan5h\School\New folder\Milestone 1\GUI.cpp" -o CMakeFiles\Milestone_1.dir\GUI.cpp.s

# Object files for target Milestone_1
Milestone_1_OBJECTS = \
"CMakeFiles/Milestone_1.dir/GUI.cpp.obj"

# External object files for target Milestone_1
Milestone_1_EXTERNAL_OBJECTS =

Milestone_1.exe: CMakeFiles/Milestone_1.dir/GUI.cpp.obj
Milestone_1.exe: CMakeFiles/Milestone_1.dir/build.make
Milestone_1.exe: CMakeFiles/Milestone_1.dir/linklibs.rsp
Milestone_1.exe: CMakeFiles/Milestone_1.dir/objects1.rsp
Milestone_1.exe: CMakeFiles/Milestone_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Dan5h\School\New folder\Milestone 1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Milestone_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Milestone_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Milestone_1.dir/build: Milestone_1.exe

.PHONY : CMakeFiles/Milestone_1.dir/build

CMakeFiles/Milestone_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Milestone_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Milestone_1.dir/clean

CMakeFiles/Milestone_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Dan5h\School\New folder\Milestone 1" "C:\Users\Dan5h\School\New folder\Milestone 1" "C:\Users\Dan5h\School\New folder\Milestone 1\cmake-build-debug" "C:\Users\Dan5h\School\New folder\Milestone 1\cmake-build-debug" "C:\Users\Dan5h\School\New folder\Milestone 1\cmake-build-debug\CMakeFiles\Milestone_1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Milestone_1.dir/depend

