#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/spinach.hpp"

TEST_CASE("Spinach matures after 3 days "){
    Spinach spinach;
    spinach.end_day();
    spinach.end_day();
    spinach.end_day();
    REQUIRE(spinach.symbol() == "U");
}

TEST_CASE("Can speed growth process by watering"){
    Spinach spinach;
    spinach.water();
    spinach.end_day();
    spinach.end_day();
    REQUIRE(spinach.symbol() == "U");
}

TEST_CASE("spinach naturally sprouts after 2 days"){
    Spinach spinach;
    spinach.end_day();
    spinach.end_day();
    REQUIRE(spinach.symbol() == "u");
}