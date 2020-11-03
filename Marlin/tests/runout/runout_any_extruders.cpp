#include <unity.h>
#include <src/feature/runout.h>

void test_compare_runout_states(void) {
  FilamentSensorBase sensor;
  TEST_ASSERT_EQUAL(0, sensor.compare_runout_states(0, 0));
  TEST_ASSERT_EQUAL(1, sensor.compare_runout_states(0, 1));
  TEST_ASSERT_EQUAL(1, sensor.compare_runout_states(1, 0));
  TEST_ASSERT_EQUAL(0, sensor.compare_runout_states(1, 1));
  TEST_ASSERT_EQUAL(0, sensor.compare_runout_states(3, 3));
  TEST_ASSERT_EQUAL(6, sensor.compare_runout_states(5, 3));
}
