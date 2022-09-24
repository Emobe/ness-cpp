cmake_minimum_required(VERSION 3.10)


project(Ness
  VERSION 0.0
  DESCRIPTION "Ness"
  LANGUAGES CXX
)

cmake_minimum_required(VERSION 3.10)

project(Ness)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

#Includes
aux_source_directory(src SRC)
aux_source_directory(includes HEADERS)
include_directories(src)

set(SOURCES
  ${SRC}
  ${HEADERS}
)

add_executable(Ness ${SOURCES})

target_link_libraries(Ness ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
