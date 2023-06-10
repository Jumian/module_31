# CMakeList.txt: проект CMake для Skillbox_cpp_30_2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
project ("Skillbox_cpp_30_2")

set(CMAKE_CXX_STANDARD 20)

if(POLICY CMP0079 )
  cmake_policy(SET CMP0079 NEW)
endif()

add_subdirectory(src)