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

bool Configuration::isScara() const {
  return machineType == ConfigurationMachineType::Scara;
}

bool Configuration::probeUsesBed() const {
  return probeUsesBed(probeType);
}

bool Configuration::probeUsesBed(ConfigurationProbeType probeType) const {
  switch (probeType) {
  _MATCH_SWITCH(ConfigurationProbeType::ZServoProbe, true)
  _MATCH_SWITCH(ConfigurationProbeType::FixMountedProbe, true)
  _MATCH_SWITCH(ConfigurationProbeType::Bltouch, true)
  _MATCH_SWITCH(ConfigurationProbeType::NozzleAsProbe, true)
  _MATCH_SWITCH(ConfigurationProbeType::TouchMiProbe, true)
  _MATCH_SWITCH(ConfigurationProbeType::ZProbeAllenKey, true)
  _MATCH_SWITCH(ConfigurationProbeType::ZProbeSled, true)
  _MATCH_SWITCH(ConfigurationProbeType::SolenoidProbe, true)
  _MATCH_SWITCH(ConfigurationProbeType::SensorlessProbing, true)
  _MATCH_SWITCH(ConfigurationProbeType::RackAndPinionProbe, true)
  default: return false;
  }
}

bool Configuration::probeHasXYOffset() const {
  return probeHasXYOffset(probeType);
}

bool Configuration::probeHasXYOffset(ConfigurationProbeType probeType) const {
  return probeUsesBed() && probeType != ConfigurationProbeType::NozzleAsProbe;
}

bool Configuration::hasAblButNotUbl() const {
  switch (bedLevelingType) {
  _MATCH_SWITCH(ConfigurationBedLevelingType::Auto3Point, true)
  _MATCH_SWITCH(ConfigurationBedLevelingType::AutoLinear, true)
  _MATCH_SWITCH(ConfigurationBedLevelingType::AutoBilinear, true)
  default: return false;
  };
}

bool Configuration::hasAblOrUbl() const {
  return (
    bedLevelingType == ConfigurationBedLevelingType::AutoUbl
    || hasAblButNotUbl()
  );
}

bool Configuration::isAblPlanar() const {
  switch (bedLevelingType) {
  _MATCH_SWITCH(ConfigurationBedLevelingType::Auto3Point, true)
  _MATCH_SWITCH(ConfigurationBedLevelingType::AutoLinear, true)
  default: return false;
  }
}
