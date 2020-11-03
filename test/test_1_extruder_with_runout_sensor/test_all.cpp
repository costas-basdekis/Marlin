/* START_CONFIGURATION

opt_enable FILAMENT_RUNOUT_SENSOR;
opt_set FIL_RUNOUT_PIN 4;
opt_enable ADVANCED_PAUSE_FEATURE;
opt_enable EMERGENCY_PARSER;
opt_enable NOZZLE_PARK_FEATURE;

END_CONFIGURATION */
#include <unity.h>
#include "tests/common_for/any_configuration.cpp"
#include "tests/runout/runout_1_extruder.cpp"

int main(int argc, char **argv) {
  UNITY_BEGIN();
  test_common_for_any_configuration();
  test_runout();
  UNITY_END();

  return 0;
}
