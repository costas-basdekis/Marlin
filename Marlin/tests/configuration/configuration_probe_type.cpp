#include <unity.h>
#include <src/core/Configuration.h>

void test_configuration_has_bed_probe_manually() {
  Configuration configuration;
  configuration.probeType = ConfigurationProbeType::Manually;
  TEST_ASSERT_FALSE(configuration.probeUsesBed());
}

void test_configuration_has_bed_probe_bltouch() {
  Configuration configuration;
  configuration.probeType = ConfigurationProbeType::Bltouch;
  TEST_ASSERT_TRUE(configuration.probeUsesBed());
}

void test_configuration_probe_has_xy_offset_manually() {
  Configuration configuration;
  configuration.probeType = ConfigurationProbeType::Manually;
  TEST_ASSERT_FALSE(configuration.probeHasXYOffset());
}

void test_configuration_probe_has_xy_offset_bltouch() {
  Configuration configuration;
  configuration.probeType = ConfigurationProbeType::Bltouch;
  TEST_ASSERT_TRUE(configuration.probeHasXYOffset());
}

void test_configuration_probe_has_xy_offset_nozzle_as_probe() {
  Configuration configuration;
  configuration.probeType = ConfigurationProbeType::NozzleAsProbe;
  TEST_ASSERT_FALSE(configuration.probeHasXYOffset());
}

void test_configuration_probe_type() {
  RUN_TEST(test_configuration_has_bed_probe_manually);
  RUN_TEST(test_configuration_has_bed_probe_bltouch);
  RUN_TEST(test_configuration_probe_has_xy_offset_manually);
  RUN_TEST(test_configuration_probe_has_xy_offset_bltouch);
  RUN_TEST(test_configuration_probe_has_xy_offset_nozzle_as_probe);
}
