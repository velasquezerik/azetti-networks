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
   #
  )

include_directories("${CMAKE_SOURCE_DIR}/inc")
add_subdirectory(src)
add_subdirectory(tests)


