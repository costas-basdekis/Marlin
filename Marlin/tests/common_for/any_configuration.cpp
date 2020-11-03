#include <unity.h>
#include "../gcode/basic_gcode.cpp"
#include "../queue/parse_line_no_paren_comments.cpp"

void test_common_for_any_configuration() {
  test_basic_gcode();
  parse_line_no_paren_comments();
}
