#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "buckets.hpp"

TEST_CASE("TEST_CASE I") {
  std::vector<int> samples{3, 3, 4, 5, 10, 11, 12};
  REQUIRE(detect_ranges(samples) == 1);

}