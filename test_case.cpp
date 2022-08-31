#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "buckets.hpp"
#include "A2Dconverter.hpp"

TEST_CASE("TEST_CASE 1 :: Detects samples in two ranges") {
  std::vector<int> samples{3, 3, 4, 5, 10, 11, 12};
  auto objectofranges = GetRanges(samples);
  REQUIRE(objectofranges.size() == 2);
  REQUIRE(objectofranges[0] == "10-12, 3");
  REQUIRE(objectofranges[1] == "3-5, 4");
}

TEST_CASE("TEST_CASE 2 :: Detects samples in one ranges") {
  std::vector<int> samples{1,2,4,3};
  auto objectofranges = GetRanges(samples);
  REQUIRE(objectofranges.size() == 1);
  REQUIRE(objectofranges[0] == "1-4, 4");
}

TEST_CASE("TEST_CASE 3 :: Detects samples in three ranges") {
    std::vector<int> samples {1,3,4,2,6,7,9,8,12,11,13};
    auto objectofranges = GetRanges(samples);
    REQUIRE(objectofranges.size() == 3);
    REQUIRE(objectofranges[0] == "1-4, 4");
    REQUIRE(objectofranges[2] == "6-9, 4");
    REQUIRE(objectofranges[1] == "11-13, 3");
}

TEST_CASE("TEST_CASE 4 :: Detects samples in same elements") {
    std::vector<int> samples {1,1,1,1,1,1};
    auto objectofranges = GetRanges(samples);
    REQUIRE(objectofranges.size() == 1);
    REQUIRE(objectofranges[0] == "1-1, 6");
}

TEST_CASE("TEST_CASE 5 :: Get binary to number and Convert A2D") {
    int BinaryValues[] = {0,1,0,0,0, 1,1,1,1, 0,1,0};
    int numberValue = binary_to_number(BinaryValues,12);
	REQUIRE(numberValue == 1146);
	REQUIRE(A2DConvert(numberValue) == 3);
}

TEST_CASE("TEST_CASE 6 :: Get binary to number and Convert A2D") {
    int BinaryValues[] = {0,1,0,0,0, 0,0,0,0, 0,0,0};
    int numberValue = binary_to_number(BinaryValues,12);
	REQUIRE(numberValue == 1024);
	REQUIRE(A2DConvert(numberValue) == 3);
}

TEST_CASE("TEST_CASE 7 :: Get binary to number and Convert A2D") {
    int BinaryValues[] = {1,0,0,1,1, 1,0,1,1, 1,0,1};
    int numberValue = binary_to_number(BinaryValues,12);
	REQUIRE(numberValue == 2525);
	REQUIRE(A2DConvert(numberValue) == 6);
}

TEST_CASE("TEST_CASE 8 :: Get binary to number and Convert A2D") {
    int BinaryValues[] = {0,0,0,0,0, 0,0,0,0, 0,0,0};
    int numberValue = binary_to_number(BinaryValues,12);
	REQUIRE(numberValue == 0);
	REQUIRE(A2DConvert(numberValue) == 0);
}

TEST_CASE("TEST_CASE 9 :: Get binary to number and Convert A2D") {
    int BinaryValues[] = {1,1,1,1,1, 1,1,1,1, 1,1,1};
    int numberValue = binary_to_number(BinaryValues,12);
	REQUIRE(numberValue == 4095);
	REQUIRE(A2DConvert(numberValue) == 10);
}
TEST_CASE("TEST_CASE 10 :: Get ampere readings and then Detects ranges") {
	std::vector<int> BinaryValues{0, 2047, 4094};
    auto samples = Getamperereadings(BinaryValues);
	auto objectofranges = GetRanges(samples);
    REQUIRE(objectofranges.size() == 3);
    REQUIRE(objectofranges[0] == "0, 1");
    REQUIRE(objectofranges[1] == "10, 1");
    REQUIRE(objectofranges[2] == "5, 1");
}