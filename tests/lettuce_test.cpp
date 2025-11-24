#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/lettuce.hpp"

TEST_CASE("Lettuce matures after 2 days "){
    Lettuce lettuce;
    lettuce.end_day();
    lettuce.end_day();
    REQUIRE(lettuce.symbol() == "L");
}
TEST_CASE("Can speed growth process by watering"){
    Lettuce lettuce;
    lettuce.water();
    lettuce.end_day();
    REQUIRE(lettuce.symbol() == "L");
}