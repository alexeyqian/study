cmake_minimum_required(VERSION 2.14)

project(gamecrash)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

file(GLOB_RECURSE SOURCES src/*.cpp src/include/*.h)

#configure_file(GameCrashConfig.h.in GameCrashConfig.h)
#target_include_directories(gamecrash PUBLIC "${PROJECT_BINARY_DIR}")

########## sfml ##########
add_executable(gamecrash ${SOURCES})
target_link_libraries(gamecrash sfml-graphics sfml-window sfml-system)

########## unit tests ##########
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests/sqrt_tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)