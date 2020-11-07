#pragma once

#include "./configuration.h"
#include "./SerialLogger.h"

class DebugLogger {
public:
  Configuration configuration;
  // TODO: After removing macro rename this
  void log_machine_info_();
  SerialLogger *serial = new SerialLogger();
};
