/* START_CONFIGURATION

opt_enable PAREN_COMMENTS

END_CONFIGURATION */
#include <unity.h>
#include "tests/common_for/any_configuration.cpp"
#include "tests/queue/parse_line_paren_comments.cpp"

int main(int argc, char **argv) {
  UNITY_BEGIN();
  test_common_for_any_configuration();
  parse_line_paren_comments();
  UNITY_END();

  return 0;
}
