#include <unity.h>
#include <src/core/DebugLogger.h>

void test_configuration_get_machine_name_core_xy() {
  DebugLogger debugLogger;
  Configuration &configuration = debugLogger.configuration;
  configuration.machineType = ConfigurationMachineType::Core;
  TEST_ASSERT_EQUAL_STRING("Core", debugLogger.getMachineName());
}

void test_configuration_get_machine_name_core_xy_explicit() {
  DebugLogger debugLogger;
  TEST_ASSERT_EQUAL_STRING("Core", debugLogger.getMachineName(ConfigurationMachineType::Core));
}

void test_configuration_get_probe_name_fix_mounted_probe() {
  DebugLogger debugLogger;
  Configuration &configuration = debugLogger.configuration;
  configuration.probeType = ConfigurationProbeType::FixMountedProbe;
  TEST_ASSERT_EQUAL_STRING("FIX_MOUNTED_PROBE", debugLogger.getProbeName());
}

void test_configuration_get_probe_name_fix_mounted_probe_explicit() {
  DebugLogger debugLogger;
  TEST_ASSERT_EQUAL_STRING("FIX_MOUNTED_PROBE", debugLogger.getProbeName(ConfigurationProbeType::FixMountedProbe));
}

void test_configuration_get_bed_leveling_name() {
  DebugLogger debugLogger;
  Configuration &configuration = debugLogger.configuration;
  configuration.bedLevelingType = ConfigurationBedLevelingType::None;
  TEST_ASSERT_EQUAL_STRING("", debugLogger.getBedLevelingName());
}

void test_configuration_get_bed_leveling_name_3_point() {
  DebugLogger debugLogger;
  Configuration &configuration = debugLogger.configuration;
  configuration.bedLevelingType = ConfigurationBedLevelingType::Auto3Point;
  TEST_ASSERT_EQUAL_STRING("3POINT", debugLogger.getBedLevelingName());
}

void test_configuration_get_bed_leveling_name_3_point_explicit() {
  DebugLogger debugLogger;
  TEST_ASSERT_EQUAL_STRING("3POINT", debugLogger.getBedLevelingName(ConfigurationBedLevelingType::Auto3Point));
}

void test_debug_logger_names() {
  RUN_TEST(test_configuration_get_machine_name_core_xy);
  RUN_TEST(test_configuration_get_machine_name_core_xy_explicit);
  RUN_TEST(test_configuration_get_probe_name_fix_mounted_probe);
  RUN_TEST(test_configuration_get_probe_name_fix_mounted_probe_explicit);
  RUN_TEST(test_configuration_get_bed_leveling_name);
  RUN_TEST(test_configuration_get_bed_leveling_name_3_point);
  RUN_TEST(test_configuration_get_bed_leveling_name_3_point_explicit);
}
