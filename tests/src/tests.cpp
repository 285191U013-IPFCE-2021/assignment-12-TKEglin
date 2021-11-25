#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "duration.h"


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up
TEST_CASE("Duration tests") {
    Duration clock;

    REQUIRE(clock.getDuration() == 0);
}
// Add your test cases. Dont forget to include header file. 