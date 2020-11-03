#include <unity.h>
#include <src/gcode/gcode.h>
#include <src/gcode/parser.h>

void test_can_process_parsed_command() {
  GcodeSuite suite;
  parser.command_letter = 'G';
  parser.codenum = 0;
  suite.process_parsed_command(false);
}

void test_parse_g1_xz() {
  char current_command[] = "G0 X10 Z30";
  parser.command_letter = -128;
  parser.codenum = -1;
  parser.parse(current_command);
  TEST_ASSERT_EQUAL('G', parser.command_letter);
  TEST_ASSERT_EQUAL(0, parser.codenum);
  TEST_ASSERT_TRUE(parser.seen('X'));
  TEST_ASSERT_FALSE(parser.seen('Y'));
  TEST_ASSERT_TRUE(parser.seen('Z'));
  TEST_ASSERT_FALSE(parser.seen('E'));
}

void test_parse_g1_nxz() {
  char current_command[] = "N123 G0 X10 Z30";
  parser.command_letter = -128;
  parser.codenum = -1;
  parser.parse(current_command);
  TEST_ASSERT_EQUAL('G', parser.command_letter);
  TEST_ASSERT_EQUAL(0, parser.codenum);
  TEST_ASSERT_TRUE(parser.seen('X'));
  TEST_ASSERT_FALSE(parser.seen('Y'));
  TEST_ASSERT_TRUE(parser.seen('Z'));
  TEST_ASSERT_FALSE(parser.seen('E'));
}

void test_basic_gcode() {
  RUN_TEST(test_can_process_parsed_command);
  RUN_TEST(test_parse_g1_xz);
  RUN_TEST(test_parse_g1_nxz);
}
