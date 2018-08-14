#
# Copyright (C) 2016 Azetti Networks
#

cmake_minimum_required(VERSION 2.8.11)
project(AztTestCaseCpp)

enable_testing()

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Test REQUIRED)

add_definitions(
  # put any extra options for the compiler here
  )
set(SOURCES
  # file1.cc file2.cc ...
  )

add_executable(test_user test_user.cc ${SOURCES})
add_test(test_user test_user)
target_link_libraries(test_user Qt5::Test)

add_executable(test_group test_group.cc ${SOURCES})
add_test(test_group test_group)
target_link_libraries(test_group Qt5::Test)
