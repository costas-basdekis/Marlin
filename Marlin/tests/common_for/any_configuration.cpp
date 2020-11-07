#include <unity.h>
#include "../gcode/basic_gcode.cpp"
#include "../queue/parse_line_no_paren_comments.cpp"
#include "../configuration/configuration_bed_leveling.cpp"
#include "../configuration/configuration_machine_type.cpp"
#include "../configuration/configuration_probe_type.cpp"
#include "../debug/debug_logger.cpp"
#include "../debug/debug_logger_names.cpp"

void test_common_for_any_configuration() {
  test_basic_gcode();
  parse_line_no_paren_comments();
  test_configuration_bed_leveling();
  test_configuration_machine_type();
  test_configuration_probe_type();
  test_debug_logger();
  test_debug_logger_names();
}
