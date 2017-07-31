cmake_minimum_required(VERSION 2.8)
set(LOGGER_LIBRARY logger)

if (COVERAGE)
  message("-- Coverage Enabled")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  --coverage -fprofile-arcs -ftest-coverage")
endif ()

if(NOT DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type")
endif()

project(${LOGGER_LIBRARY} CXX C)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

#### UTILITY ####

set(LOGGER_DEFINITIONS "")
function(logger_add_exported_definition)
  add_definitions("-D${ARGV0}")
  list(APPEND LOGGER_DEFINITIONS "${ARGV0}")
  set(LOGGER_DEFINITIONS "${LOGGER_DEFINITIONS}" PARENT_SCOPE)
endfunction(logger_add_exported_definition)

#### ENGINE ####

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
  add_definitions("-Wall")
endif ()

set(LOGGER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
list(APPEND LOGGER_INCLUDE_DIRS "${LOGGER_INCLUDE_DIR}")

include_directories(${LOGGER_INCLUDE_DIRS})

add_subdirectory(source)

add_library(${LOGGER_LIBRARY} ${LOGGER_SOURCES})
set(LOGGER_LIBRARIES "")
target_link_libraries(${LOGGER_LIBRARY} ${LOGGER_LIBRARIES})

# Export
list(APPEND LOGGER_LIBRARIES ${LOGGER_LIBRARY})

if (LOGGER_EXPORT_CMAKE_PACKAGE_VARS)
  set(LOGGER_LIBRARY "${LOGGER_LIBRARY}" PARENT_SCOPE)
  set(LOGGER_LIBRARIES "${LOGGER_LIBRARIES}" PARENT_SCOPE)
  set(LOGGER_INCLUDE_DIR "${LOGGER_INCLUDE_DIR}" PARENT_SCOPE)
  set(LOGGER_INCLUDE_DIRS "${LOGGER_INCLUDE_DIRS}" PARENT_SCOPE)
  set(LOGGER_DEFINITIONS "${LOGGER_DEFINITIONS}" PARENT_SCOPE)
endif ()
