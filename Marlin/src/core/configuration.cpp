#include "./configuration.h"

#define _CHECK_AND_SET(VARIABLE, DEFAULT, ATTRIBUTE, VALUE) if (ATTRIBUTE) { \
  if (VARIABLE != DEFAULT) { \
    return DEFAULT; \
  } \
  VARIABLE = VALUE; \
}

#define _CHECK_AND_SET_NONE(VARIABLE, DEFAULT, VALUE) { \
  if (VARIABLE == DEFAULT) { \
    VARIABLE = VALUE; \
  } \
}

#define _MATCH_SWITCH(CASE, VALUE) case CASE: return VALUE;

bool Configuration::validate() {
  if (getMachineType() == CONF_MACHINE_TYPE_UNKNOWN) {
    return false;
  }

  if (getProbeType() == CONF_PROBE_TYPE_UNKNOWN) {
    return false;
  }

  if (getBedLevelingType() == CONF_BED_LEVELING_TYPE_UNKNOWN) {
    return false;
  }

  return true;
}

uint8_t Configuration::getMachineType() {
  uint8_t machineType = CONF_MACHINE_TYPE_UNKNOWN;

  #define CHECK_AND_SET_MACHINE_TYPE(ATTRIBUTE, VALUE) \
    _CHECK_AND_SET(machineType, CONF_MACHINE_TYPE_UNKNOWN, ATTRIBUTE, VALUE)

  CHECK_AND_SET_MACHINE_TYPE(isDelta, CONF_MACHINE_TYPE_DELTA);
  CHECK_AND_SET_MACHINE_TYPE(isScara, CONF_MACHINE_TYPE_SCARA);
  CHECK_AND_SET_MACHINE_TYPE(isCore, CONF_MACHINE_TYPE_CORE);
  CHECK_AND_SET_MACHINE_TYPE(isMarkForgedXy, CONF_MACHINE_TYPE_MARKFORGED_XY);
  CHECK_AND_SET_MACHINE_TYPE(isCartesian, CONF_MACHINE_TYPE_CARTESIAN);

  #undef CHECK_AND_SET_MACHINE_TYPE

  return machineType;
}

uint8_t Configuration::getProbeType() {
  uint8_t probeType = CONF_PROBE_TYPE_UNKNOWN;

  #define CHECK_AND_SET_MACHINE_TYPE(ATTRIBUTE, VALUE) \
    _CHECK_AND_SET(probeType, CONF_PROBE_TYPE_UNKNOWN, ATTRIBUTE, VALUE)

  CHECK_AND_SET_MACHINE_TYPE(probeNone, CONF_PROBE_TYPE_NONE);
  CHECK_AND_SET_MACHINE_TYPE(probeManually, CONF_PROBE_TYPE_MANUALLY);
  CHECK_AND_SET_MACHINE_TYPE(probeNozzleAsProbe, CONF_PROBE_TYPE_NOZZLE_AS_PROBE);
  CHECK_AND_SET_MACHINE_TYPE(probeFixMountedProbe, CONF_PROBE_TYPE_FIX_MOUNTED_PROBE);
  CHECK_AND_SET_MACHINE_TYPE(probeBltouch, CONF_PROBE_TYPE_BLTOUCH);
  CHECK_AND_SET_MACHINE_TYPE(probeZServoProbe, CONF_PROBE_TYPE_Z_SERVO_PROBE);
  CHECK_AND_SET_MACHINE_TYPE(probeTouchMiProbe, CONF_PROBE_TYPE_TOUCH_MI_PROBE);
  CHECK_AND_SET_MACHINE_TYPE(probeZProbeSled, CONF_PROBE_TYPE_Z_PROBE_SLED);
  CHECK_AND_SET_MACHINE_TYPE(probeZProbeAllenKey, CONF_PROBE_TYPE_Z_PROBE_ALLEN_KEY);
  CHECK_AND_SET_MACHINE_TYPE(probeSolenoidProbe, CONF_PROBE_TYPE_SOLENOID_PROBE);
  CHECK_AND_SET_MACHINE_TYPE(probeSensorlessProbing, CONF_PROBE_TYPE_SENSORLESS_PROBING);
  CHECK_AND_SET_MACHINE_TYPE(probeRackAndPinionProbe, CONF_PROBE_TYPE_RACK_AND_PINION_PROBE);
  CHECK_AND_SET_MACHINE_TYPE(probeManually, CONF_PROBE_TYPE_MANUALLY);

  #undef CHECK_AND_SET_PROBE_TYPE

  return probeType;
}

bool Configuration::probeUsesBed() {
  return probeUsesBed(getProbeType());
}

bool Configuration::probeUsesBed(uint8_t probeType) {
  switch (probeType) {
  _MATCH_SWITCH(CONF_PROBE_TYPE_Z_SERVO_PROBE, true)
  _MATCH_SWITCH(CONF_PROBE_TYPE_FIX_MOUNTED_PROBE, true)
  _MATCH_SWITCH(CONF_PROBE_TYPE_BLTOUCH, true)
  _MATCH_SWITCH(CONF_PROBE_TYPE_NOZZLE_AS_PROBE, true)
  _MATCH_SWITCH(CONF_PROBE_TYPE_TOUCH_MI_PROBE, true)
  _MATCH_SWITCH(CONF_PROBE_TYPE_Z_PROBE_ALLEN_KEY, true)
  _MATCH_SWITCH(CONF_PROBE_TYPE_Z_PROBE_SLED, true)
  _MATCH_SWITCH(CONF_PROBE_TYPE_SOLENOID_PROBE, true)
  _MATCH_SWITCH(CONF_PROBE_TYPE_SENSORLESS_PROBING, true)
  _MATCH_SWITCH(CONF_PROBE_TYPE_RACK_AND_PINION_PROBE, true)
  }

  return false;
}

bool Configuration::probeHasXYOffset() {
  return probeHasXYOffset(getProbeType());
}

bool Configuration::probeHasXYOffset(uint8_t probeType) {
  return probeUsesBed() && !probeNozzleAsProbe;
}

bool Configuration::hasAblButNotUbl() {
  return (
    bedLevelingAuto3Point
    || bedLevelingAutoLinear
    || bedLevelingAutoBilinear
  );
}

bool Configuration::hasAblOrUbl() {
  return (
    hasAblButNotUbl()
    || bedLevelingAutoUbl
  );
}

bool Configuration::isAblPlanar() {
  return (
    bedLevelingAuto3Point
    || bedLevelingAutoLinear
  );
}

uint8_t Configuration::getBedLevelingType() {
  uint8_t bedLevelingType = CONF_BED_LEVELING_TYPE_UNKNOWN;

  #define CHECK_AND_SET_BED_LEVELING_TYPE(ATTRIBUTE, VALUE) \
    _CHECK_AND_SET(bedLevelingType, CONF_BED_LEVELING_TYPE_UNKNOWN, ATTRIBUTE, VALUE)
  #define CHECK_AND_SET_BED_LEVELING_TYPE_NONE(VALUE) \
    _CHECK_AND_SET_NONE(bedLevelingType, CONF_BED_LEVELING_TYPE_UNKNOWN, VALUE)

  CHECK_AND_SET_BED_LEVELING_TYPE(bedLevelingAuto3Point, CONF_BED_LEVELING_TYPE_3POINT);
  CHECK_AND_SET_BED_LEVELING_TYPE(bedLevelingAutoLinear, CONF_BED_LEVELING_TYPE_LINEAR);
  CHECK_AND_SET_BED_LEVELING_TYPE(bedLevelingAutoBilinear, CONF_BED_LEVELING_TYPE_BILINEAR);
  CHECK_AND_SET_BED_LEVELING_TYPE(bedLevelingAutoUbl, CONF_BED_LEVELING_TYPE_UBL);
  CHECK_AND_SET_BED_LEVELING_TYPE(bedLevelingMesh, CONF_BED_LEVELING_TYPE_MESH);
  CHECK_AND_SET_BED_LEVELING_TYPE_NONE(CONF_BED_LEVELING_TYPE_NONE);

  #undef CHECK_AND_SET_BED_LEVELING_TYPE_NONE
  #undef CHECK_AND_SET_BED_LEVELING_TYPE

  return bedLevelingType;
}
