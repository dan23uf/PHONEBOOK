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
CMAKE_COMMAND = "C:\Users\claud\AppData\Local\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\claud\AppData\Local\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\claud\PHONEBOOK

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\claud\PHONEBOOK\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PHONEBOOK.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PHONEBOOK.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PHONEBOOK.dir/flags.make

CMakeFiles/PHONEBOOK.dir/main.cpp.obj: CMakeFiles/PHONEBOOK.dir/flags.make
CMakeFiles/PHONEBOOK.dir/main.cpp.obj: CMakeFiles/PHONEBOOK.dir/includes_CXX.rsp
CMakeFiles/PHONEBOOK.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\claud\PHONEBOOK\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PHONEBOOK.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PHONEBOOK.dir\main.cpp.obj -c C:\Users\claud\PHONEBOOK\main.cpp

CMakeFiles/PHONEBOOK.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PHONEBOOK.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\claud\PHONEBOOK\main.cpp > CMakeFiles\PHONEBOOK.dir\main.cpp.i

CMakeFiles/PHONEBOOK.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PHONEBOOK.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\claud\PHONEBOOK\main.cpp -o CMakeFiles\PHONEBOOK.dir\main.cpp.s

CMakeFiles/PHONEBOOK.dir/contact.cpp.obj: CMakeFiles/PHONEBOOK.dir/flags.make
CMakeFiles/PHONEBOOK.dir/contact.cpp.obj: CMakeFiles/PHONEBOOK.dir/includes_CXX.rsp
CMakeFiles/PHONEBOOK.dir/contact.cpp.obj: ../contact.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\claud\PHONEBOOK\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PHONEBOOK.dir/contact.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PHONEBOOK.dir\contact.cpp.obj -c C:\Users\claud\PHONEBOOK\contact.cpp

CMakeFiles/PHONEBOOK.dir/contact.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PHONEBOOK.dir/contact.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\claud\PHONEBOOK\contact.cpp > CMakeFiles\PHONEBOOK.dir\contact.cpp.i

CMakeFiles/PHONEBOOK.dir/contact.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PHONEBOOK.dir/contact.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\claud\PHONEBOOK\contact.cpp -o CMakeFiles\PHONEBOOK.dir\contact.cpp.s

CMakeFiles/PHONEBOOK.dir/phonebook.cpp.obj: CMakeFiles/PHONEBOOK.dir/flags.make
CMakeFiles/PHONEBOOK.dir/phonebook.cpp.obj: CMakeFiles/PHONEBOOK.dir/includes_CXX.rsp
CMakeFiles/PHONEBOOK.dir/phonebook.cpp.obj: ../phonebook.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\claud\PHONEBOOK\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PHONEBOOK.dir/phonebook.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PHONEBOOK.dir\phonebook.cpp.obj -c C:\Users\claud\PHONEBOOK\phonebook.cpp

CMakeFiles/PHONEBOOK.dir/phonebook.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PHONEBOOK.dir/phonebook.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\claud\PHONEBOOK\phonebook.cpp > CMakeFiles\PHONEBOOK.dir\phonebook.cpp.i

CMakeFiles/PHONEBOOK.dir/phonebook.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PHONEBOOK.dir/phonebook.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\claud\PHONEBOOK\phonebook.cpp -o CMakeFiles\PHONEBOOK.dir\phonebook.cpp.s

CMakeFiles/PHONEBOOK.dir/ImplementationMenu.cpp.obj: CMakeFiles/PHONEBOOK.dir/flags.make
CMakeFiles/PHONEBOOK.dir/ImplementationMenu.cpp.obj: CMakeFiles/PHONEBOOK.dir/includes_CXX.rsp
CMakeFiles/PHONEBOOK.dir/ImplementationMenu.cpp.obj: ../ImplementationMenu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\claud\PHONEBOOK\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PHONEBOOK.dir/ImplementationMenu.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PHONEBOOK.dir\ImplementationMenu.cpp.obj -c C:\Users\claud\PHONEBOOK\ImplementationMenu.cpp

CMakeFiles/PHONEBOOK.dir/ImplementationMenu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PHONEBOOK.dir/ImplementationMenu.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\claud\PHONEBOOK\ImplementationMenu.cpp > CMakeFiles\PHONEBOOK.dir\ImplementationMenu.cpp.i

CMakeFiles/PHONEBOOK.dir/ImplementationMenu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PHONEBOOK.dir/ImplementationMenu.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\claud\PHONEBOOK\ImplementationMenu.cpp -o CMakeFiles\PHONEBOOK.dir\ImplementationMenu.cpp.s

# Object files for target PHONEBOOK
PHONEBOOK_OBJECTS = \
"CMakeFiles/PHONEBOOK.dir/main.cpp.obj" \
"CMakeFiles/PHONEBOOK.dir/contact.cpp.obj" \
"CMakeFiles/PHONEBOOK.dir/phonebook.cpp.obj" \
"CMakeFiles/PHONEBOOK.dir/ImplementationMenu.cpp.obj"

# External object files for target PHONEBOOK
PHONEBOOK_EXTERNAL_OBJECTS =

PHONEBOOK.exe: CMakeFiles/PHONEBOOK.dir/main.cpp.obj
PHONEBOOK.exe: CMakeFiles/PHONEBOOK.dir/contact.cpp.obj
PHONEBOOK.exe: CMakeFiles/PHONEBOOK.dir/phonebook.cpp.obj
PHONEBOOK.exe: CMakeFiles/PHONEBOOK.dir/ImplementationMenu.cpp.obj
PHONEBOOK.exe: CMakeFiles/PHONEBOOK.dir/build.make
PHONEBOOK.exe: C:/SFML/lib/libsfml-system-d.a
PHONEBOOK.exe: C:/SFML/lib/libsfml-window-d.a
PHONEBOOK.exe: C:/SFML/lib/libsfml-graphics-d.a
PHONEBOOK.exe: CMakeFiles/PHONEBOOK.dir/linklibs.rsp
PHONEBOOK.exe: CMakeFiles/PHONEBOOK.dir/objects1.rsp
PHONEBOOK.exe: CMakeFiles/PHONEBOOK.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\claud\PHONEBOOK\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable PHONEBOOK.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PHONEBOOK.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PHONEBOOK.dir/build: PHONEBOOK.exe

.PHONY : CMakeFiles/PHONEBOOK.dir/build

CMakeFiles/PHONEBOOK.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PHONEBOOK.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PHONEBOOK.dir/clean

CMakeFiles/PHONEBOOK.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\claud\PHONEBOOK C:\Users\claud\PHONEBOOK C:\Users\claud\PHONEBOOK\cmake-build-debug C:\Users\claud\PHONEBOOK\cmake-build-debug C:\Users\claud\PHONEBOOK\cmake-build-debug\CMakeFiles\PHONEBOOK.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PHONEBOOK.dir/depend

