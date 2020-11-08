#pragma once

#include "./Configuration.h"
#include "./SerialLogger.h"

class DebugLogger {
public:
  Configuration configuration;
  // TODO: After removing macro rename this
  void log_machine_info_();
  SerialLogger *serial = new SerialLogger();

  PGM_P getMachineName();
  PGM_P getMachineName(ConfigurationMachineType machineType);

  PGM_P getProbeName();
  PGM_P getProbeName(ConfigurationProbeType probeType);

  PGM_P getBedLevelingName();
  PGM_P getBedLevelingName(ConfigurationBedLevelingType bedLevelingType);
};
