#include "test/catch.hpp"
#include<buckets.hpp>

TEST_CASE("TEST_CASE I") 
{
  REQUIRE(detect_ranges() == 1);
}