# set minimum cmake version
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# project name and language
project(exopedia LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

add_executable(${PROJECT_NAME}  main.cpp)

target_link_libraries(${PROJECT_NAME}
	PRIVATE  exopedia_lib  )