#include <unity.h>
#include "./base.cpp"

void test_parse_line_g1_x_and_parenthesis_comment() {
  test_parse_line("G0 X10 (Z30)", "G0 X10 ");
}

void test_parse_line_g1_x_and_parenthesis_inline_comment() {
  test_parse_line("G0 X10 (Y20) Z30", "G0 X10  Z30");
}

void parse_line_paren_comments() {
  RUN_TEST(test_parse_line_g1_x_and_parenthesis_comment);
  RUN_TEST(test_parse_line_g1_x_and_parenthesis_inline_comment);
}
