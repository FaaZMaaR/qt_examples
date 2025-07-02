cmake_minimum_required(VERSION 3.5)
project(qt_part_41)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Sql Widgets)

add_executable(list_1 listing_1.cpp)
add_executable(list_2 listing_2.cpp)
add_executable(list_3 listing_3.cpp)
add_executable(list_4 listing_4.cpp)

target_link_libraries(list_1 PRIVATE Qt6::Sql)
target_link_libraries(list_2 PRIVATE Qt6::Sql Qt6::Widgets)
target_link_libraries(list_3 PRIVATE Qt6::Sql Qt6::Widgets)
target_link_libraries(list_4 PRIVATE Qt6::Sql Qt6::Widgets)