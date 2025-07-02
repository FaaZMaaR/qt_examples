cmake_minimum_required(VERSION 3.5)
project(qt_part_24)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport)

add_executable(list_1 listing_1.cpp printer.cpp)

target_link_libraries(list_1 PRIVATE Qt6::Widgets Qt6::PrintSupport)