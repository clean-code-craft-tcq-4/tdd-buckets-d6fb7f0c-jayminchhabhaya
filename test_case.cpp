#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "buckets.hpp"

TEST_CASE("TEST_CASE 1") {
  std::vector<int> samples{3, 3, 4, 5, 10, 11, 12};
  auto objectofranges = GetRanges(samples);
  REQUIRE(objectofranges.size() == 2);
  REQUIRE(objectofranges[0] == "10-12, 3");
  REQUIRE(objectofranges[1] == "3-5, 4");
}

TEST_CASE("TEST_CASE 2") {
  std::vector<int> samples{1,2,4,3};
  auto objectofranges = GetRanges(samples);
  REQUIRE(objectofranges.size() == 1);
  REQUIRE(objectofranges[0] == "1-4, 4");
}

TEST_CASE("TEST_CASE 3") {
    vector<int> samples {1,3,4,2,6,7,9,8,12,11,13};
    auto objectofranges = GetRanges(samples);
    REQUIRE(objectofranges.size() == 3);
    REQUIRE(objectofranges[2] == "1-4, 4");
    REQUIRE(objectofranges[1] == "6-9, 4");
    REQUIRE(objectofranges[0] == "11-13, 3");
}