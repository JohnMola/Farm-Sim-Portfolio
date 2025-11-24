#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/beet.hpp"

TEST_CASE("Beets mature after 5 days "){
    Beet beet;
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    REQUIRE(beet.symbol() == "B");
}

TEST_CASE("Can speed growth process by watering"){
    Beet beet;
    beet.water();
    beet.end_day();
    beet.water();
    beet.end_day();
    beet.water();
    beet.end_day();
    REQUIRE(beet.symbol() == "B");
}

TEST_CASE("Beets sprouts after 2 days"){
    Beet beet;
    beet.end_day();
    beet.end_day();
    REQUIRE(beet.symbol() == "b");
}