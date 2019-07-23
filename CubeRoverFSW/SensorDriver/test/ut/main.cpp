#include "Tester.hpp"

//test for condition when tip limit is reached
TEST(Nominal, TipTest) {
  CubeRoverFSW::Tester tester;
  tester.testTipOver();
}

//test for condition when tip rate limit is reached
TEST(Nominal, TipRateTest) {
  CubeRoverFSW::Tester tester;
  tester.testTipRate();
}
//test for if bad data is sent to signal bit
TEST(Nominal, SignalTest) {
  CubeRoverFSW::Tester tester;
  tester.testSignal();
}

//test if bad data is sent to range bit
TEST(Nominal, RangeTest) {
  CubeRoverFSW::Tester tester;
  tester.testRange();
}

//test for accel init Error
TEST(Nominal, AccelInitTest) {
  CubeRoverFSW::Tester tester;
  tester.testAccelInit();
}

//test for gyro init error
TEST(Nominal, GyroInitTest) {
  CubeRoverFSW::Tester tester;
  tester.testGyroInit();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
