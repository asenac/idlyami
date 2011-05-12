cmake_minimum_required(VERSION 2.6)

project(idlyami CXX)

include(cmake/pump.cmake)
include(cmake/generator.cmake)

###############################################################################
#
# Temporal
#
###############################################################################
set(yami_PATH /home/asenac/workspace/yami4-gpl-1.3.0)
set(yami_INCLUDE_DIR ${yami_PATH}/include)
set(yami_LIBRARIES_DIR ${yami_PATH}/lib)
add_definitions(-g -DIDLYAMI_DEBUG=100)

###############################################################################
#
# Configuration
#
###############################################################################

set(idlyami_VERSION 0.1.1)

set(idlyami_EXPORTED_HEADERS
  Skel.hpp
  adapted.hpp
  Operation.hpp
  Request.hpp
  mapping.hpp
  ServerRequest.hpp
  detail/mpl.hpp
  POA.hpp
  idlyami.hpp
  yami_forward.hpp
  Stub.hpp
  Arguments.hpp
  ORB.hpp
  Servant.hpp
  Parameters.hpp)
set(idlyami_HEADERS)
set(idlyami_SOURCES
  ORB.cpp
  Parameters.cpp
  POA.cpp
  Object.cpp
  Servant.cpp
  ServerRequest.cpp
  Request.cpp)
set(idlyami_PUMPS
  Operation.hpp.pump)
set(idlyami_LIBS pthread yamicore yamicpp)

if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE "Release")
endif()


###############################################################################
#
# Compilation
#
###############################################################################

pump_files(${idlyami_PUMPS})

set(CMAKE_CXX_FLAGS "-Wall")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)
include_directories(${yami_INCLUDE_DIR})
link_directories(${yami_LIBRARIES_DIR})

add_library(idlyami SHARED ${idlyami_EXPORTED_HEADERS} ${idlyami_HEADERS} ${idlyami_SOURCES})
target_link_libraries(idlyami ${idlyami_LIBS})
set_target_properties(idlyami PROPERTIES VERSION 0.1.1 SOVERSION 0)

###############################################################################
#
# Examples
#
###############################################################################
add_subdirectory(examples)

###############################################################################
#
# Installation
#
###############################################################################

install(TARGETS idlyami DESTINATION lib)

foreach(header ${idlyami_EXPORTED_HEADERS})
  get_filename_component(_header_path ${header} PATH)
  install(FILES ${header} DESTINATION include/${_header_path})
endforeach()

###############################################################################
#
# Packaging
#
###############################################################################

