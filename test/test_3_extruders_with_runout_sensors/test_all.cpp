/* START_CONFIGURATION

opt_set EXTRUDERS 3;
opt_set TEMP_SENSOR_1 1;
opt_set TEMP_SENSOR_2 1;
opt_set TEMP_2_PIN 4;
opt_set TEMP_3_PIN 4;
opt_set HEATER_1_PIN 4;
opt_set HEATER_2_PIN 4;
opt_set E2_STEP_PIN 4;
opt_set E2_DIR_PIN 4;
opt_set E2_ENABLE_PIN 4;
opt_set E3_STEP_PIN 4;
opt_set E3_DIR_PIN 4;
opt_set E3_ENABLE_PIN 4;
opt_set NUM_RUNOUT_SENSORS 3;
opt_enable FILAMENT_RUNOUT_SENSOR;
opt_set FIL_RUNOUT_PIN 4;
opt_set FIL_RUNOUT2_PIN 4;
opt_set FIL_RUNOUT3_PIN 4;
opt_enable ADVANCED_PAUSE_FEATURE;
opt_enable EMERGENCY_PARSER;
opt_enable NOZZLE_PARK_FEATURE;

END_CONFIGURATION */
#include <unity.h>
#include "tests/common_for/any_configuration.cpp"
#include "tests/runout/runout_3_extruders.cpp"

int main(int argc, char **argv) {
  UNITY_BEGIN();
  test_common_for_any_configuration();
  test_runout();
  UNITY_END();

  return 0;
}
