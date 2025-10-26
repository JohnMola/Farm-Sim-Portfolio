#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.hpp"

TEST_CASE( "it starts the player in row zero, column zero" ) {
    Player player(2, 2);
    REQUIRE( player.row() == 0 );
    REQUIRE( player.column() == 0 );
}

TEST_CASE( "it moves the player to the right" ) {
    Player player(2, 2);
    player.move_right();
    REQUIRE( player.row() == 0 );
    REQUIRE( player.column() == 1 );
}

TEST_CASE( "it moves the player down" ) {
    Player player(2, 2);
    player.move_down();
    REQUIRE( player.row() == 1 );
    REQUIRE( player.column() == 0 );
}

TEST_CASE( "it moves the player to the left" ) {
    Player player(2, 2);
    player.move_right();
    player.move_left();
    REQUIRE( player.row() == 0 );
    REQUIRE( player.column() == 0 );
}

TEST_CASE( "it moves the player up" ) {
    Player player(2, 2);
    player.move_down();
    player.move_up();
    REQUIRE( player.row() == 0 );
    REQUIRE( player.column() == 0 );
}
