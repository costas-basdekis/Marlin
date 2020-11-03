#include <unity.h>
#include <src/feature/runout.h>
#include "./runout_any_extruders.cpp"

void test_get_runout_states(void) {
  FilamentSensorBase sensor;
  TEST_ASSERT_EQUAL(1, sensor.get_runout_states());
}

void test_runout() {
  RUN_TEST(test_get_runout_states);
  RUN_TEST(test_compare_runout_states);
}
