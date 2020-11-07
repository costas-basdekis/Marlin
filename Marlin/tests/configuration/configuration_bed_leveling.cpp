#include <unity.h>
#include <src/core/configuration.h>

void test_configuration_get_bed_leveling_type() {
  Configuration configuration;
  TEST_ASSERT_EQUAL(CONF_BED_LEVELING_TYPE_NONE, configuration.getBedLevelingType());
}

void test_configuration_get_bed_leveling_type_3_point() {
  Configuration configuration;
  configuration.bedLevelingAuto3Point = true;
  TEST_ASSERT_EQUAL(CONF_BED_LEVELING_TYPE_3POINT, configuration.getBedLevelingType());
}

void test_configuration_bed_leveling_type_valid() {
  Configuration configuration;
  TEST_ASSERT_TRUE(configuration.validate());
}

void test_configuration_multiple_bed_leveling_types_invalid() {
  Configuration configuration;
  configuration.bedLevelingAuto3Point = true;
  configuration.bedLevelingAutoBilinear = true;
  TEST_ASSERT_FALSE(configuration.validate());
}

void test_configuration_abl_but_not_ubl() {
  Configuration configuration;
  TEST_ASSERT_FALSE(configuration.hasAblButNotUbl());
}

void test_configuration_abl_but_not_ubl_3_point() {
  Configuration configuration;
  configuration.bedLevelingAuto3Point = true;
  TEST_ASSERT_TRUE(configuration.hasAblButNotUbl());
}

void test_configuration_abl_but_not_ubl_ubl() {
  Configuration configuration;
  configuration.bedLevelingAutoUbl = true;
  TEST_ASSERT_FALSE(configuration.hasAblButNotUbl());
}

void test_configuration_abl_or_ubl() {
  Configuration configuration;
  TEST_ASSERT_FALSE(configuration.hasAblOrUbl());
}

void test_configuration_abl_or_ubl_3_point() {
  Configuration configuration;
  configuration.bedLevelingAuto3Point = true;
  TEST_ASSERT_TRUE(configuration.hasAblOrUbl());
}

void test_configuration_abl_or_ubl_ubl() {
  Configuration configuration;
  configuration.bedLevelingAutoUbl = true;
  TEST_ASSERT_TRUE(configuration.hasAblOrUbl());
}

void test_configuration_is_abl_planar() {
  Configuration configuration;
  TEST_ASSERT_FALSE(configuration.isAblPlanar());
}

void test_configuration_is_abl_planar_3_point() {
  Configuration configuration;
  configuration.bedLevelingAuto3Point = true;
  TEST_ASSERT_TRUE(configuration.isAblPlanar());
}

void test_configuration_is_abl_planar_ubl() {
  Configuration configuration;
  configuration.bedLevelingAutoUbl = true;
  TEST_ASSERT_FALSE(configuration.isAblPlanar());
}

void test_configuration_bed_leveling() {
  RUN_TEST(test_configuration_get_bed_leveling_type);
  RUN_TEST(test_configuration_get_bed_leveling_type_3_point);
  RUN_TEST(test_configuration_bed_leveling_type_valid);
  RUN_TEST(test_configuration_multiple_bed_leveling_types_invalid);
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
