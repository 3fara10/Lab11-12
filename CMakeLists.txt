cmake_minimum_required(VERSION 3.28)
project(lab9_10)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab9_10 main.cpp
        Tests/tests.cpp
        Tests/tests.cpp
        Domain/product.cpp
        Domain/money.cpp
        Service/service.h
        Ui/ui.h
        Ui/ui.cpp
        Repository/file_repository.h
        Exceptions/not_found_exception.h
        Exceptions/invalid_value_exception.h
        Exceptions/Invalid_code_exception.h
        Validators/money_validator.h
        Validators/product_validator.h
)
