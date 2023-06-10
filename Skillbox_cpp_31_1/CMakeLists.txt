# CMakeList.txt: проект CMake для Skillbox_cpp_29_1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)


set(CMAKE_CXX_STANDARD 20)

project ("Skillbox_cpp_31_1")


# Enable Hot Reload for MSVC compilers if supported.

add_subdirectory(src)