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
  PGM_P machineNameDelta = "Delta";
  #define CONF_MACHINE_TYPE_SCARA         2
  PGM_P machineNameScara = "SCARA";
  #define CONF_MACHINE_TYPE_CORE          3
  PGM_P machineNameCoreXy = "Core";
  #define CONF_MACHINE_TYPE_MARKFORGED_XY 4
  PGM_P machineNameMarkForgedXy = "MarkForged";
  #define CONF_MACHINE_TYPE_CARTESIAN     5
  PGM_P machineNameCartesian = "Cartesian";

  uint8_t getMachineType();
  PGM_P getMachineName();
  PGM_P getMachineName(uint8_t machineType);

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
  PGM_P probeTypeNameNone = "";
  #define CONF_PROBE_TYPE_MANUALLY              2
  PGM_P probeTypeNameProbeManually = "PROBE_MANUALLY";
  #define CONF_PROBE_TYPE_NOZZLE_AS_PROBE       3
  PGM_P probeTypeNameNozzleAsProbe = "NOZZLE_AS_PROBE";
  #define CONF_PROBE_TYPE_FIX_MOUNTED_PROBE     4
  PGM_P probeTypeNameFixMountedProbe = "FIX_MOUNTED_PROBE";
  #define CONF_PROBE_TYPE_BLTOUCH               5
  PGM_P probeTypeNameBltouch = "BLTOUCH";
  #define CONF_PROBE_TYPE_Z_SERVO_PROBE           6
  PGM_P probeTypeNameZServoProbe = "Z SERVO PROBE";
  #define CONF_PROBE_TYPE_TOUCH_MI_PROBE        7
  PGM_P probeTypeNameTouchMiProbe = "TOUCH_MI_PROBE";
  #define CONF_PROBE_TYPE_Z_PROBE_SLED          8
  PGM_P probeTypeNameZProbeSled = "Z_PROBE_SLED";
  #define CONF_PROBE_TYPE_Z_PROBE_ALLEN_KEY     9
  PGM_P probeTypeNameZProbeAllenKey = "Z_PROBE_ALLEN_KEY";
  #define CONF_PROBE_TYPE_SOLENOID_PROBE        10
  PGM_P probeTypeNameSolenoidProbe = "SOLENOID_PROBE";
  #define CONF_PROBE_TYPE_SENSORLESS_PROBING    11
  PGM_P probeTypeNameSensorlessProbing = "SENSORLESS_PROBING";
  #define CONF_PROBE_TYPE_RACK_AND_PINION_PROBE 12
  PGM_P probeTypeNameRackAndPinionProbe = "RACK_AND_PINION_PROBE";

  uint8_t getProbeType();
  bool probeUsesBed();
  bool probeUsesBed(uint8_t probeType);
  bool probeHasXYOffset();
  bool probeHasXYOffset(uint8_t probeType);
  PGM_P getProbeName();
  PGM_P getProbeName(uint8_t probeType);

  // Bed leveling
  bool bedLevelingAuto3Point = ENABLED(AUTO_BED_LEVELING_3POINT);
  bool bedLevelingAutoLinear = ENABLED(AUTO_BED_LEVELING_LINEAR);
  bool bedLevelingAutoBilinear = ENABLED(AUTO_BED_LEVELING_BILINEAR);
  bool bedLevelingAutoUbl = ENABLED(AUTO_BED_LEVELING_UBL);
  bool bedLevelingMesh = ENABLED(MESH_BED_LEVELING);
  #define CONF_BED_LEVELING_TYPE_UNKNOWN  0
  #define CONF_BED_LEVELING_TYPE_NONE     1
  PGM_P bedLevelingNameNone = "";
  #define CONF_BED_LEVELING_TYPE_3POINT   2
  PGM_P bedLevelingName3Point = "3POINT";
  #define CONF_BED_LEVELING_TYPE_LINEAR   3
  PGM_P bedLevelingNameLinear = "LINEAR";
  #define CONF_BED_LEVELING_TYPE_BILINEAR 4
  PGM_P bedLevelingNameBilinear = "BILINEAR";
  #define CONF_BED_LEVELING_TYPE_UBL      5
  PGM_P bedLevelingNameUbl = "UBL";
  #define CONF_BED_LEVELING_TYPE_MESH     6
  PGM_P bedLevelingNameMesh = "MESH";

  uint8_t getBedLevelingType();
  PGM_P getBedLevelingName();
  PGM_P getBedLevelingName(uint8_t bedLevelingType);

  bool hasAblButNotUbl();
  bool hasAblOrUbl();
  bool isAblPlanar();

  bool bedLevelingFadeHeight = ENABLED(ENABLE_LEVELING_FADE_HEIGHT);
};
