#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "buckets.hpp"

TEST_CASE("TEST_CASE 2") {
  std::vector<int> samples{4,5,6};
  REQUIRE(detect_ranges(samples) == 1);
  auto objectofranges = GetRanges(samples);
  //REQUIRE(objectofranges.size() == 1);
  REQUIRE(objectofranges[0] == "4-6, 3");
}