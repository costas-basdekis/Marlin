#include <unity.h>
#include <src/core/Configuration.h>

void test_configuration_abl_but_not_ubl() {
  Configuration configuration;
  TEST_ASSERT_FALSE(configuration.hasAblButNotUbl());
}

void test_configuration_abl_but_not_ubl_3_point() {
  Configuration configuration;
  configuration.bedLevelingType = ConfigurationBedLevelingType::Auto3Point;
  TEST_ASSERT_TRUE(configuration.hasAblButNotUbl());
}

void test_configuration_abl_but_not_ubl_ubl() {
  Configuration configuration;
  configuration.bedLevelingType = ConfigurationBedLevelingType::AutoUbl;
  TEST_ASSERT_FALSE(configuration.hasAblButNotUbl());
}

void test_configuration_abl_or_ubl() {
  Configuration configuration;
  configuration.bedLevelingType = ConfigurationBedLevelingType::None;
  TEST_ASSERT_FALSE(configuration.hasAblOrUbl());
}

void test_configuration_abl_or_ubl_3_point() {
  Configuration configuration;
  configuration.bedLevelingType = ConfigurationBedLevelingType::Auto3Point;
  TEST_ASSERT_TRUE(configuration.hasAblOrUbl());
}

void test_configuration_abl_or_ubl_ubl() {
  Configuration configuration;
  configuration.bedLevelingType = ConfigurationBedLevelingType::AutoUbl;
  TEST_ASSERT_TRUE(configuration.hasAblOrUbl());
}

void test_configuration_is_abl_planar() {
  Configuration configuration;
  configuration.bedLevelingType = ConfigurationBedLevelingType::None;
  TEST_ASSERT_FALSE(configuration.isAblPlanar());
}

void test_configuration_is_abl_planar_3_point() {
  Configuration configuration;
  configuration.bedLevelingType = ConfigurationBedLevelingType::Auto3Point;
  TEST_ASSERT_TRUE(configuration.isAblPlanar());
}

void test_configuration_is_abl_planar_ubl() {
  Configuration configuration;
  configuration.bedLevelingType = ConfigurationBedLevelingType::AutoUbl;
  TEST_ASSERT_FALSE(configuration.isAblPlanar());
}

void test_configuration_bed_leveling() {
  RUN_TEST(test_configuration_abl_but_not_ubl);
  RUN_TEST(test_configuration_abl_but_not_ubl_3_point);
  RUN_TEST(test_configuration_abl_but_not_ubl_ubl);
  RUN_TEST(test_configuration_abl_or_ubl);
  RUN_TEST(test_configuration_abl_or_ubl_3_point);
  RUN_TEST(test_configuration_abl_or_ubl_ubl);
  RUN_TEST(test_configuration_is_abl_planar);
  RUN_TEST(test_configuration_is_abl_planar_3_point);
  RUN_TEST(test_configuration_is_abl_planar_ubl);
}
