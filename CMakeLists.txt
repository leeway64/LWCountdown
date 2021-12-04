cmake_minimum_required (VERSION 3.8)

project ("LWCountdown")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++latest")
set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++latest")

add_executable (LWCountdown "main.cpp" "CLI11.hpp" "json.hpp" "timer_helpers.hpp")
