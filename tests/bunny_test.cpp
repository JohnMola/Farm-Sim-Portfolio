#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/farm.hpp"
#include "../src/bunny.hpp"


TEST_CASE( "bunny can be created" ) {
  Bunny bunny(2, 3, 1, 0);
  REQUIRE( bunny.get_row() == 2 );
  REQUIRE( bunny.get_column() == 3 );
  REQUIRE( bunny.get_symbol() == "R" );
}

TEST_CASE( "bunny moves in its direction" ) {
  Bunny bunny(2, 3, 1, 0);
  bunny.move();
  REQUIRE( bunny.get_row() == 3 );
  REQUIRE( bunny.get_column() == 3 );
}

TEST_CASE( "bunny moves left" ) {
  Bunny bunny(2, 3, 0, -1);
  bunny.move();
  REQUIRE( bunny.get_row() == 2 );
  REQUIRE( bunny.get_column() == 2 );
}

TEST_CASE( "bunny moves right" ) {
  Bunny bunny(2, 3, 0, 1);
  bunny.move();
  REQUIRE( bunny.get_row() == 2 );
  REQUIRE( bunny.get_column() == 4 );
}

TEST_CASE( "bunny moves up" ) {
  Bunny bunny(2, 3, -1, 0);
  bunny.move();
  REQUIRE( bunny.get_row() == 1 );
  REQUIRE( bunny.get_column() == 3 );
}

TEST_CASE( "scared bunny moves 4 spaces" ) {
  Bunny bunny(5, 5, 0, 1);
  bunny.set_scared(5, 0);
  REQUIRE( bunny.is_scared() == true );
  bunny.move();
  REQUIRE( bunny.get_row() == 5 );
  REQUIRE( bunny.get_column() == 9 );
  REQUIRE( bunny.is_scared() == false );
}

TEST_CASE( "scared bunny moves away from player below" ) {
  Bunny bunny(5, 5, 0, 1);
  bunny.set_scared(6, 5);
  bunny.move();
  REQUIRE( bunny.get_row() == 1 );
  REQUIRE( bunny.get_column() == 5 );
}

TEST_CASE( "scared bunny moves away from player above" ) {
  Bunny bunny(5, 5, 0, 1);
  bunny.set_scared(4, 5);
  bunny.move();
  REQUIRE( bunny.get_row() == 9 );
  REQUIRE( bunny.get_column() == 5 );
}

TEST_CASE( "scared bunny moves away from player on left" ) {
  Bunny bunny(5, 5, 0, 1);
  bunny.set_scared(5, 4);
  bunny.move();
  REQUIRE( bunny.get_row() == 5 );
  REQUIRE( bunny.get_column() == 9 );
}

TEST_CASE( "scared bunny moves away from player on right" ) {
  Bunny bunny(5, 5, 0, 1);
  bunny.set_scared(5, 6);
  bunny.move();
  REQUIRE( bunny.get_row() == 5 );
  REQUIRE( bunny.get_column() == 1 );
}

TEST_CASE( "bunny position can be set" ) {
  Bunny bunny(2, 3, 0, 1);
  bunny.set_position(4, 5);
  REQUIRE( bunny.get_row() == 4 );
  REQUIRE( bunny.get_column() == 5 );
}

TEST_CASE( "bunny direction can be set" ) {
  Bunny bunny(2, 3, 0, 1);
  bunny.set_direction(-1, 0);
  bunny.move();
  REQUIRE( bunny.get_row() == 1 );
  REQUIRE( bunny.get_column() == 3 );
}

