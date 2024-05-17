cmake_minimum_required(VERSION 3.28)
project(lab9_10)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab9_10 main.cpp
        tests.cpp
        tests.cpp
        product.cpp
        money.cpp
        service.h
        ui.h
        ui.cpp
        file_repository.h
        Exceptii.h
)
