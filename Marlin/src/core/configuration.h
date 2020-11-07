#pragma once

#include "../inc/MarlinConfigPre.h"

#define PGM_P const char *

#ifdef UNIT_TEST
  #define _CONST_
#else
  #define _CONST_ const
#endif

class Configuration {
public:
  _CONST_ bool debugLevelingFeature = ENABLED(DEBUG_LEVELING_FEATURE);

  // TODO: How do we check and return multiple failures at compile time?
  bool validate() const;

  // Machine type
  _CONST_ bool isDelta = ENABLED(DELTA);
  _CONST_ bool isScara = ENABLED(IS_SCARA);
  _CONST_ bool isCore = ENABLED(IS_CORE);
  _CONST_ bool isMarkForgedXy = ENABLED(MARKFORGED_XY);
  _CONST_ bool isCartesian = ENABLED(IS_CARTESIAN);
  #define CONF_MACHINE_TYPE_UNKNOWN       0
  #define CONF_MACHINE_TYPE_DELTA         1
  #define CONF_MACHINE_TYPE_SCARA         2
  #define CONF_MACHINE_TYPE_CORE          3
  #define CONF_MACHINE_TYPE_MARKFORGED_XY 4
  #define CONF_MACHINE_TYPE_CARTESIAN     5

  uint8_t getMachineType() const;

  // Probe type
  _CONST_ bool probeNone = !ENABLED(PROBE_SELECTED);
  _CONST_ bool probeManually = ENABLED(PROBE_MANUALLY);
  _CONST_ bool probeNozzleAsProbe = ENABLED(NOZZLE_AS_PROBE);
  _CONST_ bool probeFixMountedProbe = ENABLED(FIX_MOUNTED_PROBE);
  _CONST_ bool probeBltouch = ENABLED(HAS_Z_SERVO_PROBE) && ENABLED(BLTOUCH);
  _CONST_ bool probeZServoProbe = ENABLED(HAS_Z_SERVO_PROBE) && !ENABLED(BLTOUCH);
  _CONST_ bool probeTouchMiProbe = ENABLED(TOUCH_MI_PROBE);
  _CONST_ bool probeZProbeSled = ENABLED(Z_PROBE_SLED);
  _CONST_ bool probeZProbeAllenKey = ENABLED(Z_PROBE_ALLEN_KEY);
  _CONST_ bool probeSolenoidProbe = ENABLED(SOLENOID_PROBE);
  _CONST_ bool probeSensorlessProbing = ENABLED(SENSORLESS_PROBING);
  _CONST_ bool probeRackAndPinionProbe = ENABLED(RACK_AND_PINION_PROBE);
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

  uint8_t getProbeType() const;
  bool probeUsesBed() const;
  bool probeUsesBed(uint8_t probeType) const;
  bool probeHasXYOffset() const;
  bool probeHasXYOffset(uint8_t probeType) const;

  // Bed leveling
  _CONST_ bool bedLevelingAuto3Point = ENABLED(AUTO_BED_LEVELING_3POINT);
  _CONST_ bool bedLevelingAutoLinear = ENABLED(AUTO_BED_LEVELING_LINEAR);
  _CONST_ bool bedLevelingAutoBilinear = ENABLED(AUTO_BED_LEVELING_BILINEAR);
  _CONST_ bool bedLevelingAutoUbl = ENABLED(AUTO_BED_LEVELING_UBL);
  _CONST_ bool bedLevelingMesh = ENABLED(MESH_BED_LEVELING);
  #define CONF_BED_LEVELING_TYPE_UNKNOWN  0
  #define CONF_BED_LEVELING_TYPE_NONE     1
  #define CONF_BED_LEVELING_TYPE_3POINT   2
  #define CONF_BED_LEVELING_TYPE_LINEAR   3
  #define CONF_BED_LEVELING_TYPE_BILINEAR 4
  #define CONF_BED_LEVELING_TYPE_UBL      5
  #define CONF_BED_LEVELING_TYPE_MESH     6

  uint8_t getBedLevelingType() const;

  bool hasAblButNotUbl() const;
  bool hasAblOrUbl() const;
  bool isAblPlanar() const;

  _CONST_ bool bedLevelingFadeHeight = ENABLED(ENABLE_LEVELING_FADE_HEIGHT);
};
