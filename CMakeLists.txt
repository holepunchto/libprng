cmake_minimum_required(VERSION 3.22)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(WIN32)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

project(prng C)

add_library(prng OBJECT)

set_target_properties(
  prng
  PROPERTIES
  C_STANDARD 99
  POSITION_INDEPENDENT_CODE 1
)

target_sources(
  prng
  INTERFACE
    include/prng.h
  PRIVATE
    src/prng.c
    src/splitmix64.h
    src/xoshiro256pp.h
)

target_include_directories(
  prng
  PUBLIC
    include
)

add_library(prng_shared SHARED $<TARGET_OBJECTS:prng>)

set_target_properties(
  prng_shared
  PROPERTIES
  OUTPUT_NAME prng
)

add_library(prng_static STATIC $<TARGET_OBJECTS:prng>)

set_target_properties(
  prng_static
  PROPERTIES
  OUTPUT_NAME prng
)

install(TARGETS prng_shared prng_static)

install(FILES include/prng.h DESTINATION include)

if(PROJECT_IS_TOP_LEVEL)
  enable_testing()
  add_subdirectory(test)
endif()
