#pragma once

#include "../inc/MarlinConfigPre.h"

enum class ConfigurationMachineType : uint8_t {
  Delta,
  Scara,
  Core,
  MarkForgedXY,
  Cartesian,
};

enum class ConfigurationProbeType : uint8_t {
  None,
  Manually,
  NozzleAsProbe,
  FixMountedProbe,
  Bltouch,
  ZServoProbe,
  TouchMiProbe,
  ZProbeSled,
  ZProbeAllenKey,
  SolenoidProbe,
  SensorlessProbing,
  RackAndPinionProbe,
};

enum class ConfigurationBedLevelingType : uint8_t {
  None,
  Auto3Point,
  AutoLinear,
  AutoBilinear,
  AutoUbl,
  Mesh,
};

class Configuration {
public:
  bool debugLevelingFeature = false;

  ConfigurationMachineType machineType = ConfigurationMachineType::Cartesian;

  bool isScara() const;

  ConfigurationProbeType probeType = ConfigurationProbeType::None;

  bool probeUsesBed() const;
  bool probeUsesBed(ConfigurationProbeType probeType) const;
  bool probeHasXYOffset() const;
  bool probeHasXYOffset(ConfigurationProbeType probeType) const;

  ConfigurationBedLevelingType bedLevelingType = ConfigurationBedLevelingType::None;

  bool hasAblButNotUbl() const;
  bool hasAblOrUbl() const;
  bool isAblPlanar() const;

  bool bedLevelingFadeHeight = true;
};
