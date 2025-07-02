cmake_minimum_required(VERSION 3.5)
project(qt_part_52)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Qml)

add_executable(list_1 listing_1.cpp turtle.cpp turtle.h turtle_work_area.cpp turtle_work_area.h)
add_executable(list_2 listing_2.cpp)
add_executable(list_3 listing_3.cpp jstools.cpp jstools.h)

target_link_libraries(list_1 PRIVATE Qt6::Widgets Qt6::Qml)
target_link_libraries(list_2 PRIVATE Qt6::Widgets Qt6::Qml)
target_link_libraries(list_3 PRIVATE Qt6::Widgets Qt6::Qml)