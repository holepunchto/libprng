cmake_minimum_required(VERSION 3.22)

project(prng C)

add_library(prng OBJECT)

set_target_properties(
  prng
  PROPERTIES
  C_STANDARD 99
  POSITION_INDEPENDENT_CODE ON
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

add_library(prng_shared SHARED)

set_target_properties(
  prng_shared
  PROPERTIES
  OUTPUT_NAME prng
  WINDOWS_EXPORT_ALL_SYMBOLS ON
)

target_link_libraries(
  prng_shared
  PUBLIC
    prng
)

add_library(prng_static STATIC)

set_target_properties(
  prng_static
  PROPERTIES
  OUTPUT_NAME prng
)

target_link_libraries(
  prng_static
  PUBLIC
    prng
)

install(TARGETS prng_shared prng_static)

install(FILES include/prng.h DESTINATION include)

if(PROJECT_IS_TOP_LEVEL)
  enable_testing()
  add_subdirectory(test)
endif()
