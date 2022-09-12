cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)

add_library ( exopedia_lib utils.cpp exopediaui.cpp usermanager.cpp user.cpp customer.cpp
            customermanager.cpp customerview.cpp reservation.cpp adminview.cpp )

target_include_directories(exopedia_lib PUBLIC "../include"  )

message("Library exopedia_lib created")
