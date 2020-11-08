#include <unity.h>
#include <src/core/Configuration.h>

void test_configuration_get_machine_type() {
  Configuration configuration;
  TEST_ASSERT_EQUAL(configuration.getMachineType(), CONF_MACHINE_TYPE_CARTESIAN);
}

void test_configuration_get_machine_type_core_xy() {
  Configuration configuration;
  configuration.isCartesian = false;
  configuration.isCore = true;
  TEST_ASSERT_EQUAL(configuration.getMachineType(), CONF_MACHINE_TYPE_CORE);
}

void test_configuration_multiple_machine_types_invalid() {
  Configuration configuration;
  configuration.isCartesian = true;
  configuration.isCore = true;
  TEST_ASSERT_FALSE(configuration.validate());
}

void test_configuration_machine_type() {
  RUN_TEST(test_configuration_get_machine_type);
  RUN_TEST(test_configuration_get_machine_type_core_xy);
  RUN_TEST(test_configuration_multiple_machine_types_invalid);
}
