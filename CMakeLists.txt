cmake_minimum_required (VERSION 3.8)

project ("LWCountdown" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++latest")
set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++latest")


include(FetchContent)

FetchContent_Declare(
	cli11
	GIT_REPOSITORY https://github.com/CLIUtils/CLI11
	GIT_TAG        v2.1.2
)

FetchContent_MakeAvailable(cli11)

FetchContent_Declare(
	json
	GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent.git
	GIT_TAG v3.10.4
)

FetchContent_MakeAvailable(json)


add_executable (LWCountdown "main.cpp" "timer_helpers.hpp")
target_link_libraries(
	LWCountdown
	PRIVATE
		CLI11::CLI11
		nlohmann_json::nlohmann_json
)
