#include <unity.h>
#include "./base.cpp"

void test_parse_line_g1_xz() {
  test_parse_line("G0 X10 Z30", "G0 X10 Z30");
}

void test_parse_line_g1_x_and_comment() {
  test_parse_line("G0 X10 ; Z30", "G0 X10 ");
}

void parse_line_no_paren_comments() {
  RUN_TEST(test_parse_line_g1_xz);
  RUN_TEST(test_parse_line_g1_x_and_comment);
}
