# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /home/wallace/Projects/CPP-dojo/google_interview/q1_binary_tree_l3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wallace/Projects/CPP-dojo/google_interview/q1_binary_tree_l3/build

# Include any dependencies generated for this target.
include CMakeFiles/question.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/question.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/question.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/question.dir/flags.make

CMakeFiles/question.dir/codegen:
.PHONY : CMakeFiles/question.dir/codegen

CMakeFiles/question.dir/main.cpp.o: CMakeFiles/question.dir/flags.make
CMakeFiles/question.dir/main.cpp.o: /home/wallace/Projects/CPP-dojo/google_interview/q1_binary_tree_l3/main.cpp
CMakeFiles/question.dir/main.cpp.o: CMakeFiles/question.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wallace/Projects/CPP-dojo/google_interview/q1_binary_tree_l3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/question.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/question.dir/main.cpp.o -MF CMakeFiles/question.dir/main.cpp.o.d -o CMakeFiles/question.dir/main.cpp.o -c /home/wallace/Projects/CPP-dojo/google_interview/q1_binary_tree_l3/main.cpp

CMakeFiles/question.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/question.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wallace/Projects/CPP-dojo/google_interview/q1_binary_tree_l3/main.cpp > CMakeFiles/question.dir/main.cpp.i

CMakeFiles/question.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/question.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wallace/Projects/CPP-dojo/google_interview/q1_binary_tree_l3/main.cpp -o CMakeFiles/question.dir/main.cpp.s

# Object files for target question
question_OBJECTS = \
"CMakeFiles/question.dir/main.cpp.o"

# External object files for target question
question_EXTERNAL_OBJECTS =

question: CMakeFiles/question.dir/main.cpp.o
question: CMakeFiles/question.dir/build.make
question: CMakeFiles/question.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/wallace/Projects/CPP-dojo/google_interview/q1_binary_tree_l3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable question"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/question.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/question.dir/build: question
.PHONY : CMakeFiles/question.dir/build

CMakeFiles/question.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/question.dir/cmake_clean.cmake
.PHONY : CMakeFiles/question.dir/clean

CMakeFiles/question.dir/depend:
	cd /home/wallace/Projects/CPP-dojo/google_interview/q1_binary_tree_l3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wallace/Projects/CPP-dojo/google_interview/q1_binary_tree_l3 /home/wallace/Projects/CPP-dojo/google_interview/q1_binary_tree_l3 /home/wallace/Projects/CPP-dojo/google_interview/q1_binary_tree_l3/build /home/wallace/Projects/CPP-dojo/google_interview/q1_binary_tree_l3/build /home/wallace/Projects/CPP-dojo/google_interview/q1_binary_tree_l3/build/CMakeFiles/question.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/question.dir/depend

