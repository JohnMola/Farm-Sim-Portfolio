cmake_minimum_required(VERSION 3.24)

project("Farming Simulator")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(farm_test tests/farm_test.cpp src/farm.cpp
        src/carrot.cpp
        src/carrot.hpp
        src/farm_printer.cpp
        src/farm_printer.hpp
        src/player.cpp
        src/player.hpp
        src/plot.hpp
        src/soil.cpp
        src/soil.hpp
        tests/carrot_test.cpp
        tests/farm_printer_test.cpp
        tests/player_test.cpp
        tests/soil_test.cpp)
add_executable(main main.cpp src/farm.cpp)

target_link_libraries(farm_test PRIVATE Catch2::Catch2WithMain)
