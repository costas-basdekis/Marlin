#include <unity.h>
#include <src/core/Configuration.h>

void test_configuration_get_probe_type() {
  Configuration configuration;
  TEST_ASSERT_EQUAL(configuration.getProbeType(), CONF_PROBE_TYPE_NONE);
}

void test_configuration_multiple_probe_types_invalid() {
  Configuration configuration;
  configuration.probeNozzleAsProbe = true;
  configuration.probeFixMountedProbe = true;
  TEST_ASSERT_FALSE(configuration.validate());
}

void test_configuration_has_bed_probe_manually() {
  Configuration configuration;
  configuration.probeNone = false;
  configuration.probeManually = true;
  TEST_ASSERT_FALSE(configuration.probeUsesBed());
}

void test_configuration_has_bed_probe_bltouch() {
  Configuration configuration;
  configuration.probeNone = false;
  configuration.probeBltouch = true;
  TEST_ASSERT_TRUE(configuration.probeUsesBed());
}

void test_configuration_probe_has_xy_offset_manually() {
  Configuration configuration;
  configuration.probeNone = false;
  configuration.probeManually = true;
  TEST_ASSERT_FALSE(configuration.probeHasXYOffset());
}

void test_configuration_probe_has_xy_offset_bltouch() {
  Configuration configuration;
  configuration.probeNone = false;
  configuration.probeBltouch = true;
  TEST_ASSERT_TRUE(configuration.probeHasXYOffset());
}

void test_configuration_probe_has_xy_offset_nozzle_as_probe() {
  Configuration configuration;
  configuration.probeNone = false;
  configuration.probeNozzleAsProbe = true;
  TEST_ASSERT_FALSE(configuration.probeHasXYOffset());
}

void test_configuration_probe_type() {
  RUN_TEST(test_configuration_get_probe_type);
  RUN_TEST(test_configuration_multiple_probe_types_invalid);
  RUN_TEST(test_configuration_has_bed_probe_manually);
  RUN_TEST(test_configuration_has_bed_probe_bltouch);
  RUN_TEST(test_configuration_probe_has_xy_offset_manually);
  RUN_TEST(test_configuration_probe_has_xy_offset_bltouch);
  RUN_TEST(test_configuration_probe_has_xy_offset_nozzle_as_probe);
}
