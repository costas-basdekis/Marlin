#pragma once

#include "./configuration.h"
#include "./SerialLogger.h"

class DebugLogger {
public:
  Configuration configuration;
  // TODO: After removing macro rename this
  void log_machine_info_();
  SerialLogger *serial = new SerialLogger();

  PGM_P getMachineName();
  PGM_P getMachineName(uint8_t machineType);

  PGM_P getProbeName();
  PGM_P getProbeName(uint8_t probeType);

  PGM_P getBedLevelingName();
  PGM_P getBedLevelingName(uint8_t bedLevelingType);
};
