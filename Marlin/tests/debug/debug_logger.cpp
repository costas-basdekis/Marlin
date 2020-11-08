#include <unity.h>
#include <src/core/utility.h>
#include <src/core/DebugLogger.h>
#include <src/module/planner.h>
#include "TestLogger.cpp"

void test_debug_logger_output() {
  DebugLogger debugLogger;
  TestLogger testLogger;
  debugLogger.serial = &testLogger;

  debugLogger.log_machine_info_();
  TEST_ASSERT_EQUAL_STRING((
    "Machine Type: Cartesian\n"
    "Probe: \n"
  ), testLogger.getBuffer());
}

void test_debug_logger_output_core_xy_fix_mounted_probe() {
  DebugLogger debugLogger;
  Configuration &configuration = debugLogger.configuration;
  TestLogger testLogger;
  debugLogger.serial = &testLogger;

  configuration.machineType = ConfigurationMachineType::Core;
  configuration.probeType = ConfigurationProbeType::FixMountedProbe;
  debugLogger.log_machine_info_();
  TEST_ASSERT_EQUAL_STRING((
    "Machine Type: Core\n"
    "Probe: FIX_MOUNTED_PROBE\n"
    "Probe Offset X0.000000 Y0.000000 Z0.000000 (Aligned With & Same Z as Nozzle)\n"
  ), testLogger.getBuffer());
}

void test_debug_logger_output_core_xy_fix_mounted_probe_3_point() {
  DebugLogger debugLogger;
  Configuration &configuration = debugLogger.configuration;
  TestLogger testLogger;
  debugLogger.serial = &testLogger;

  configuration.machineType = ConfigurationMachineType::Core;
  configuration.probeType = ConfigurationProbeType::FixMountedProbe;
  configuration.bedLevelingType = ConfigurationBedLevelingType::Auto3Point;
  debugLogger.log_machine_info_();
  TEST_ASSERT_EQUAL_STRING((
    "Machine Type: Core\n"
    "Probe: FIX_MOUNTED_PROBE\n"
    "Probe Offset X0.000000 Y0.000000 Z0.000000 (Aligned With & Same Z as Nozzle)\n"
    "Auto Bed Leveling: 3POINT (disabled)\n"
    "\n"
  ), testLogger.getBuffer());
}
//
//void test_debug_logger_output_core_xy_fix_mounted_probe_3_point_leveling_active() {
//  DebugLogger debugLogger;
//  Configuration &configuration = debugLogger.configuration;
//  TestLogger testLogger;
//  debugLogger.serial = &testLogger;
//
//  configuration.isCartesian = false;
//  configuration.isCore = true;
//  configuration.probeNone = false;
//  configuration.probeFixMountedProbe = true;
//  configuration.bedLevelingAuto3Point = true;
//  planner.leveling_active = true;
//  debugLogger.log_machine_info_();
//  TEST_ASSERT_EQUAL_STRING((
//    "Machine Type: Core\n"
//    "Probe: FIX_MOUNTED_PROBE\n"
//    "Probe Offset X0.000000 Y0.000000 Z0.000000 (Aligned With & Same Z as Nozzle)\n"
//    "Auto Bed Leveling: 3POINT (enabled)"
//  ), testLogger.getBuffer());
//}

void test_debug_logger() {
  RUN_TEST(test_debug_logger_output);
  RUN_TEST(test_debug_logger_output_core_xy_fix_mounted_probe);
  RUN_TEST(test_debug_logger_output_core_xy_fix_mounted_probe_3_point);
//  RUN_TEST(test_debug_logger_output_core_xy_fix_mounted_probe_3_point_leveling_active);
}
