# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = ${PWD}

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = ${PWD}

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start ${PWD}/CMakeFiles ${PWD}/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start ${PWD}/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named DataStructures

# Build rule for target.
DataStructures: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 DataStructures
.PHONY : DataStructures

# fast build rule for target.
DataStructures/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/build
.PHONY : DataStructures/fast

src/libs/List/List.o: src/libs/List/List.c.o
.PHONY : src/libs/List/List.o

# target to build an object file
src/libs/List/List.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/List/List.c.o
.PHONY : src/libs/List/List.c.o

src/libs/List/List.i: src/libs/List/List.c.i
.PHONY : src/libs/List/List.i

# target to preprocess a source file
src/libs/List/List.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/List/List.c.i
.PHONY : src/libs/List/List.c.i

src/libs/List/List.s: src/libs/List/List.c.s
.PHONY : src/libs/List/List.s

# target to generate assembly for a file
src/libs/List/List.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/List/List.c.s
.PHONY : src/libs/List/List.c.s

src/libs/Node/Node.o: src/libs/Node/Node.c.o
.PHONY : src/libs/Node/Node.o

# target to build an object file
src/libs/Node/Node.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/Node/Node.c.o
.PHONY : src/libs/Node/Node.c.o

src/libs/Node/Node.i: src/libs/Node/Node.c.i
.PHONY : src/libs/Node/Node.i

# target to preprocess a source file
src/libs/Node/Node.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/Node/Node.c.i
.PHONY : src/libs/Node/Node.c.i

src/libs/Node/Node.s: src/libs/Node/Node.c.s
.PHONY : src/libs/Node/Node.s

# target to generate assembly for a file
src/libs/Node/Node.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/Node/Node.c.s
.PHONY : src/libs/Node/Node.c.s

src/libs/Queue/Queue.o: src/libs/Queue/Queue.c.o
.PHONY : src/libs/Queue/Queue.o

# target to build an object file
src/libs/Queue/Queue.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/Queue/Queue.c.o
.PHONY : src/libs/Queue/Queue.c.o

src/libs/Queue/Queue.i: src/libs/Queue/Queue.c.i
.PHONY : src/libs/Queue/Queue.i

# target to preprocess a source file
src/libs/Queue/Queue.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/Queue/Queue.c.i
.PHONY : src/libs/Queue/Queue.c.i

src/libs/Queue/Queue.s: src/libs/Queue/Queue.c.s
.PHONY : src/libs/Queue/Queue.s

# target to generate assembly for a file
src/libs/Queue/Queue.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/Queue/Queue.c.s
.PHONY : src/libs/Queue/Queue.c.s

src/libs/Stack/Stack.o: src/libs/Stack/Stack.c.o
.PHONY : src/libs/Stack/Stack.o

# target to build an object file
src/libs/Stack/Stack.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/Stack/Stack.c.o
.PHONY : src/libs/Stack/Stack.c.o

src/libs/Stack/Stack.i: src/libs/Stack/Stack.c.i
.PHONY : src/libs/Stack/Stack.i

# target to preprocess a source file
src/libs/Stack/Stack.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/Stack/Stack.c.i
.PHONY : src/libs/Stack/Stack.c.i

src/libs/Stack/Stack.s: src/libs/Stack/Stack.c.s
.PHONY : src/libs/Stack/Stack.s

# target to generate assembly for a file
src/libs/Stack/Stack.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/Stack/Stack.c.s
.PHONY : src/libs/Stack/Stack.c.s

src/libs/gfx/gfx.o: src/libs/gfx/gfx.c.o
.PHONY : src/libs/gfx/gfx.o

# target to build an object file
src/libs/gfx/gfx.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/gfx/gfx.c.o
.PHONY : src/libs/gfx/gfx.c.o

src/libs/gfx/gfx.i: src/libs/gfx/gfx.c.i
.PHONY : src/libs/gfx/gfx.i

# target to preprocess a source file
src/libs/gfx/gfx.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/gfx/gfx.c.i
.PHONY : src/libs/gfx/gfx.c.i

src/libs/gfx/gfx.s: src/libs/gfx/gfx.c.s
.PHONY : src/libs/gfx/gfx.s

# target to generate assembly for a file
src/libs/gfx/gfx.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/libs/gfx/gfx.c.s
.PHONY : src/libs/gfx/gfx.c.s

src/main.o: src/main.c.o
.PHONY : src/main.o

# target to build an object file
src/main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/main.c.o
.PHONY : src/main.c.o

src/main.i: src/main.c.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DataStructures.dir/build.make CMakeFiles/DataStructures.dir/src/main.c.s
.PHONY : src/main.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... DataStructures"
	@echo "... src/libs/List/List.o"
	@echo "... src/libs/List/List.i"
	@echo "... src/libs/List/List.s"
	@echo "... src/libs/Node/Node.o"
	@echo "... src/libs/Node/Node.i"
	@echo "... src/libs/Node/Node.s"
	@echo "... src/libs/Queue/Queue.o"
	@echo "... src/libs/Queue/Queue.i"
	@echo "... src/libs/Queue/Queue.s"
	@echo "... src/libs/Stack/Stack.o"
	@echo "... src/libs/Stack/Stack.i"
	@echo "... src/libs/Stack/Stack.s"
	@echo "... src/libs/gfx/gfx.o"
	@echo "... src/libs/gfx/gfx.i"
	@echo "... src/libs/gfx/gfx.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
