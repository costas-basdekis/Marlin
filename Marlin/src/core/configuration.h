#pragma once

#include "../inc/MarlinConfigPre.h"

#define PGM_P const char *

class Configuration {
public:
  bool debugLevelingFeature = ENABLED(DEBUG_LEVELING_FEATURE);

  // TODO: How do we check and return multiple failures at compile time?
  bool validate();

  // Machine type
  bool isDelta = ENABLED(DELTA);
  bool isScara = ENABLED(IS_SCARA);
  bool isCore = ENABLED(IS_CORE);
  bool isMarkForgedXy = ENABLED(MARKFORGED_XY);
  bool isCartesian = ENABLED(IS_CARTESIAN);
  #define CONF_MACHINE_TYPE_UNKNOWN       0
  #define CONF_MACHINE_TYPE_DELTA         1
  #define CONF_MACHINE_TYPE_SCARA         2
  #define CONF_MACHINE_TYPE_CORE          3
  #define CONF_MACHINE_TYPE_MARKFORGED_XY 4
  #define CONF_MACHINE_TYPE_CARTESIAN     5

  uint8_t getMachineType();

  // Probe type
  bool probeNone = !ENABLED(PROBE_SELECTED);
  bool probeManually = ENABLED(PROBE_MANUALLY);
  bool probeNozzleAsProbe = ENABLED(NOZZLE_AS_PROBE);
  bool probeFixMountedProbe = ENABLED(FIX_MOUNTED_PROBE);
  bool probeBltouch = ENABLED(HAS_Z_SERVO_PROBE) && ENABLED(BLTOUCH);
  bool probeZServoProbe = ENABLED(HAS_Z_SERVO_PROBE) && !ENABLED(BLTOUCH);
  bool probeTouchMiProbe = ENABLED(TOUCH_MI_PROBE);
  bool probeZProbeSled = ENABLED(Z_PROBE_SLED);
  bool probeZProbeAllenKey = ENABLED(Z_PROBE_ALLEN_KEY);
  bool probeSolenoidProbe = ENABLED(SOLENOID_PROBE);
  bool probeSensorlessProbing = ENABLED(SENSORLESS_PROBING);
  bool probeRackAndPinionProbe = ENABLED(RACK_AND_PINION_PROBE);
  #define CONF_PROBE_TYPE_UNKNOWN               0
  #define CONF_PROBE_TYPE_NONE                  1
  #define CONF_PROBE_TYPE_MANUALLY              2
  #define CONF_PROBE_TYPE_NOZZLE_AS_PROBE       3
  #define CONF_PROBE_TYPE_FIX_MOUNTED_PROBE     4
  #define CONF_PROBE_TYPE_BLTOUCH               5
  #define CONF_PROBE_TYPE_Z_SERVO_PROBE         6
  #define CONF_PROBE_TYPE_TOUCH_MI_PROBE        7
  #define CONF_PROBE_TYPE_Z_PROBE_SLED          8
  #define CONF_PROBE_TYPE_Z_PROBE_ALLEN_KEY     9
  #define CONF_PROBE_TYPE_SOLENOID_PROBE        10
  #define CONF_PROBE_TYPE_SENSORLESS_PROBING    11
  #define CONF_PROBE_TYPE_RACK_AND_PINION_PROBE 12

  uint8_t getProbeType();
  bool probeUsesBed();
  bool probeUsesBed(uint8_t probeType);
  bool probeHasXYOffset();
  bool probeHasXYOffset(uint8_t probeType);

  // Bed leveling
  bool bedLevelingAuto3Point = ENABLED(AUTO_BED_LEVELING_3POINT);
  bool bedLevelingAutoLinear = ENABLED(AUTO_BED_LEVELING_LINEAR);
  bool bedLevelingAutoBilinear = ENABLED(AUTO_BED_LEVELING_BILINEAR);
  bool bedLevelingAutoUbl = ENABLED(AUTO_BED_LEVELING_UBL);
  bool bedLevelingMesh = ENABLED(MESH_BED_LEVELING);
  #define CONF_BED_LEVELING_TYPE_UNKNOWN  0
  #define CONF_BED_LEVELING_TYPE_NONE     1
  #define CONF_BED_LEVELING_TYPE_3POINT   2
  #define CONF_BED_LEVELING_TYPE_LINEAR   3
  #define CONF_BED_LEVELING_TYPE_BILINEAR 4
  #define CONF_BED_LEVELING_TYPE_UBL      5
  #define CONF_BED_LEVELING_TYPE_MESH     6

  uint8_t getBedLevelingType();

  bool hasAblButNotUbl();
  bool hasAblOrUbl();
  bool isAblPlanar();

  bool bedLevelingFadeHeight = ENABLED(ENABLE_LEVELING_FADE_HEIGHT);
};
