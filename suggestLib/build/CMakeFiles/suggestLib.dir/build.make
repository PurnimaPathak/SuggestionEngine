# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/purnima/CLionProjects/Stateless/suggestLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/purnima/CLionProjects/Stateless/suggestLib/build

# Include any dependencies generated for this target.
include CMakeFiles/suggestLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/suggestLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/suggestLib.dir/flags.make

CMakeFiles/suggestLib.dir/main.cpp.o: CMakeFiles/suggestLib.dir/flags.make
CMakeFiles/suggestLib.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/purnima/CLionProjects/Stateless/suggestLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/suggestLib.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/suggestLib.dir/main.cpp.o -c /Users/purnima/CLionProjects/Stateless/suggestLib/main.cpp

CMakeFiles/suggestLib.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/suggestLib.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/purnima/CLionProjects/Stateless/suggestLib/main.cpp > CMakeFiles/suggestLib.dir/main.cpp.i

CMakeFiles/suggestLib.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/suggestLib.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/purnima/CLionProjects/Stateless/suggestLib/main.cpp -o CMakeFiles/suggestLib.dir/main.cpp.s

CMakeFiles/suggestLib.dir/suggestLib.cpp.o: CMakeFiles/suggestLib.dir/flags.make
CMakeFiles/suggestLib.dir/suggestLib.cpp.o: ../suggestLib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/purnima/CLionProjects/Stateless/suggestLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/suggestLib.dir/suggestLib.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/suggestLib.dir/suggestLib.cpp.o -c /Users/purnima/CLionProjects/Stateless/suggestLib/suggestLib.cpp

CMakeFiles/suggestLib.dir/suggestLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/suggestLib.dir/suggestLib.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/purnima/CLionProjects/Stateless/suggestLib/suggestLib.cpp > CMakeFiles/suggestLib.dir/suggestLib.cpp.i

CMakeFiles/suggestLib.dir/suggestLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/suggestLib.dir/suggestLib.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/purnima/CLionProjects/Stateless/suggestLib/suggestLib.cpp -o CMakeFiles/suggestLib.dir/suggestLib.cpp.s

# Object files for target suggestLib
suggestLib_OBJECTS = \
"CMakeFiles/suggestLib.dir/main.cpp.o" \
"CMakeFiles/suggestLib.dir/suggestLib.cpp.o"

# External object files for target suggestLib
suggestLib_EXTERNAL_OBJECTS =

libsuggestLib.a: CMakeFiles/suggestLib.dir/main.cpp.o
libsuggestLib.a: CMakeFiles/suggestLib.dir/suggestLib.cpp.o
libsuggestLib.a: CMakeFiles/suggestLib.dir/build.make
libsuggestLib.a: CMakeFiles/suggestLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/purnima/CLionProjects/Stateless/suggestLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libsuggestLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/suggestLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/suggestLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/suggestLib.dir/build: libsuggestLib.a

.PHONY : CMakeFiles/suggestLib.dir/build

CMakeFiles/suggestLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/suggestLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/suggestLib.dir/clean

CMakeFiles/suggestLib.dir/depend:
	cd /Users/purnima/CLionProjects/Stateless/suggestLib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/purnima/CLionProjects/Stateless/suggestLib /Users/purnima/CLionProjects/Stateless/suggestLib /Users/purnima/CLionProjects/Stateless/suggestLib/build /Users/purnima/CLionProjects/Stateless/suggestLib/build /Users/purnima/CLionProjects/Stateless/suggestLib/build/CMakeFiles/suggestLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/suggestLib.dir/depend

