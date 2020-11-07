#include <unity.h>
#include <src/core/DebugLogger.h>

void test_configuration_get_machine_name_core_xy() {
  DebugLogger debugLogger;
  Configuration &configuration = debugLogger.configuration;
  configuration.isCartesian = false;
  configuration.isCore = true;
  TEST_ASSERT_EQUAL_STRING("Core", debugLogger.getMachineName());
}

void test_configuration_get_machine_name_core_xy_explicit() {
  DebugLogger debugLogger;
  TEST_ASSERT_EQUAL_STRING("Core", debugLogger.getMachineName(CONF_MACHINE_TYPE_CORE));
}

void test_configuration_get_probe_name_fix_mounted_probe() {
  DebugLogger debugLogger;
  Configuration &configuration = debugLogger.configuration;
  configuration.probeNone = false;
  configuration.probeFixMountedProbe = true;
  TEST_ASSERT_EQUAL_STRING("FIX_MOUNTED_PROBE", debugLogger.getProbeName());
}

void test_configuration_get_probe_name_fix_mounted_probe_explicit() {
  DebugLogger debugLogger;
  TEST_ASSERT_EQUAL_STRING("FIX_MOUNTED_PROBE", debugLogger.getProbeName(CONF_PROBE_TYPE_FIX_MOUNTED_PROBE));
}

void test_configuration_get_bed_leveling_name() {
  DebugLogger debugLogger;
  TEST_ASSERT_EQUAL_STRING("", debugLogger.getBedLevelingName());
}

void test_configuration_get_bed_leveling_name_3_point() {
  DebugLogger debugLogger;
  Configuration &configuration = debugLogger.configuration;
  configuration.bedLevelingAuto3Point = true;
  TEST_ASSERT_EQUAL_STRING("3POINT", debugLogger.getBedLevelingName());
}

void test_configuration_get_bed_leveling_name_3_point_explicit() {
  DebugLogger debugLogger;
  TEST_ASSERT_EQUAL_STRING("3POINT", debugLogger.getBedLevelingName(CONF_BED_LEVELING_TYPE_3POINT));
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
