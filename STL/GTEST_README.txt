Repo
https://github.com/google/googletest

Installation on Ubuntu
https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/

IBM
https://www.ibm.com/developerworks/aix/library/au-googletestingframework.html

VS Code extension


sudo apt-get install cmake # install cmake
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
 cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
Compile and run the tests:
cmake CMakeLists.txt
make
./runTests
