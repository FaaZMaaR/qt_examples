cmake_minimum_required(VERSION 3.5)
project(qt_part_1)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(list_1 listing_1.cpp)
target_link_libraries(list_1 PRIVATE Qt6::Widgets)