#include "./DebugLogger.h"
#include "../feature/bedlevel/bedlevel.h"
#include "../libs/numtostr.h"
#include "../module/planner.h"
#include "../module/probe.h"
#include "../MarlinCore.h"

#define _MATCH_SWITCH(CASE, VALUE) case CASE: return VALUE;

PGM_P machineNameDelta = "Delta";
PGM_P machineNameScara = "SCARA";
PGM_P machineNameCoreXy = "Core";
PGM_P machineNameMarkForgedXy = "MarkForged";
PGM_P machineNameCartesian = "Cartesian";

PGM_P probeTypeNameNone = "";
PGM_P probeTypeNameProbeManually = "PROBE_MANUALLY";
PGM_P probeTypeNameNozzleAsProbe = "NOZZLE_AS_PROBE";
PGM_P probeTypeNameFixMountedProbe = "FIX_MOUNTED_PROBE";
PGM_P probeTypeNameBltouch = "BLTOUCH";
PGM_P probeTypeNameZServoProbe = "Z SERVO PROBE";
PGM_P probeTypeNameTouchMiProbe = "TOUCH_MI_PROBE";
PGM_P probeTypeNameZProbeSled = "Z_PROBE_SLED";
PGM_P probeTypeNameZProbeAllenKey = "Z_PROBE_ALLEN_KEY";
PGM_P probeTypeNameSolenoidProbe = "SOLENOID_PROBE";
PGM_P probeTypeNameSensorlessProbing = "SENSORLESS_PROBING";
PGM_P probeTypeNameRackAndPinionProbe = "RACK_AND_PINION_PROBE";

PGM_P bedLevelingNameNone = "";
PGM_P bedLevelingName3Point = "3POINT";
PGM_P bedLevelingNameLinear = "LINEAR";
PGM_P bedLevelingNameBilinear = "BILINEAR";
PGM_P bedLevelingNameUbl = "UBL";
PGM_P bedLevelingNameMesh = "MESH";

void DebugLogger::log_machine_info_() {
  serial->echoLnPgm("Machine Type: ", getMachineName());
  serial->echoLnPgm("Probe: ", getProbeName());

  if (configuration.probeUsesBed()) {
    if (!configuration.probeHasXYOffset()) {
      serial->echoPgm("Probe Offset X0 Y0 Z", probe.offset.z);
      serial->echoPgm(" (");
    } else {
      serial->echoPgm("Probe Offset X", probe.offset_xy.x);
      serial->echoPgm(SP_Y_STR, probe.offset_xy.y);
      serial->echoPgm(SP_Z_STR, probe.offset.z);
      if (probe.offset_xy.x > 0) {
        serial->echoPgm(" (Right");
      } else if (probe.offset_xy.x < 0) {
        serial->echoPgm(" (Left");
      } else if (probe.offset_xy.y != 0) {
        serial->echoPgm(" (Middle");
      } else {
        serial->echoPgm(" (Aligned With");
      }
      if (probe.offset_xy.y > 0) {
        serial->echoPgm(configuration.isScara() ? PSTR("-Distal") : PSTR("-Back"));
      } else if (probe.offset_xy.y < 0) {
        serial->echoPgm(configuration.isScara() ? PSTR("-Proximal") : PSTR("-Front"));
      } else if (probe.offset_xy.x != 0) {
        serial->echoPgm("-Center");
      }
      serial->echoPgm(" & ");
    }

    serial->echoPgm(probe.offset.z < 0 ? PSTR("Below") : probe.offset.z > 0 ? PSTR("Above") : PSTR("Same Z as"));
    serial->echoLnPgm(" Nozzle)");
  }

  if (configuration.hasAblOrUbl()) {
    serial->echoPgm("Auto Bed Leveling: ", getBedLevelingName());

    if (planner.leveling_active) {
      serial->echoLnPgm(" (enabled)");
      if (configuration.bedLevelingFadeHeight) {
        if (planner.z_fade_height) {
          serial->echoLnPgm("Z Fade: ", planner.z_fade_height);
        }
        if (configuration.isAblPlanar()) {
          serial->echoPgm("ABL Adjustment X");
          LOOP_XYZ(axis) {
            const float position = planner.get_axis_position_mm(AxisEnum(axis)) - current_position[axis];
            serial->echo(XYZ_CHAR(axis));
            if (position > 0) {
              serial->echo('+');
            }
            serial->echo(position);
          }
        } else {
          float z_correction;
          if (configuration.bedLevelingType == ConfigurationBedLevelingType::AutoUbl) {
            #if ENABLED(AUTO_BED_LEVELING_UBL)
            serial->echoPgm("UBL Adjustment Z");
            z_correction = ubl.get_z_correction(current_position);
            #endif
          } else{
            #if ENABLED(AUTO_BED_LEVELING_BILINEAR)
            serial->echoPgm("ABL Adjustment Z");
            z_correction = bilinear_z_offset(current_position);
            #endif
          }
          serial->echoPgm(ftostr43sign(z_correction, '+'));
          if (planner.z_fade_height) {
            serial->echoPgm(" (", ftostr43sign(z_correction * planner.fade_scaling_factor_for_z(current_position.z), '+'));
            serial->echo(')');
          }
        }
      }
    } else {
      serial->echoLnPgm(" (disabled)");
    }

    serial->echoLn();
  }
}

PGM_P DebugLogger::getMachineName() {
  return getMachineName(configuration.machineType);
}

PGM_P DebugLogger::getMachineName(ConfigurationMachineType machineType) {
  switch (machineType) {
  _MATCH_SWITCH(ConfigurationMachineType::Delta, machineNameDelta);
  _MATCH_SWITCH(ConfigurationMachineType::Scara, machineNameScara);
  _MATCH_SWITCH(ConfigurationMachineType::Core, machineNameCoreXy);
  _MATCH_SWITCH(ConfigurationMachineType::MarkForgedXY, machineNameMarkForgedXy);
  _MATCH_SWITCH(ConfigurationMachineType::Cartesian, machineNameCartesian);
  }

  return nullptr;
}

PGM_P DebugLogger::getProbeName() {
  return getProbeName(configuration.probeType);
}

PGM_P DebugLogger::getProbeName(ConfigurationProbeType probeType) {
  switch (probeType) {
  _MATCH_SWITCH(ConfigurationProbeType::None, probeTypeNameNone);
  _MATCH_SWITCH(ConfigurationProbeType::Manually, probeTypeNameProbeManually);
  _MATCH_SWITCH(ConfigurationProbeType::NozzleAsProbe, probeTypeNameNozzleAsProbe);
  _MATCH_SWITCH(ConfigurationProbeType::FixMountedProbe, probeTypeNameFixMountedProbe);
  _MATCH_SWITCH(ConfigurationProbeType::Bltouch, probeTypeNameBltouch);
  _MATCH_SWITCH(ConfigurationProbeType::ZServoProbe, probeTypeNameZServoProbe);
  _MATCH_SWITCH(ConfigurationProbeType::TouchMiProbe, probeTypeNameTouchMiProbe);
  _MATCH_SWITCH(ConfigurationProbeType::ZProbeSled, probeTypeNameZProbeSled);
  _MATCH_SWITCH(ConfigurationProbeType::ZProbeAllenKey, probeTypeNameZProbeAllenKey);
  _MATCH_SWITCH(ConfigurationProbeType::SolenoidProbe, probeTypeNameSolenoidProbe);
  _MATCH_SWITCH(ConfigurationProbeType::SensorlessProbing, probeTypeNameSensorlessProbing);
  _MATCH_SWITCH(ConfigurationProbeType::RackAndPinionProbe, probeTypeNameRackAndPinionProbe);
  }

  return nullptr;
}

PGM_P DebugLogger::getBedLevelingName() {
  return getBedLevelingName(configuration.bedLevelingType);
}

PGM_P DebugLogger::getBedLevelingName(ConfigurationBedLevelingType bedLevelingType) {
  switch (bedLevelingType) {
  _MATCH_SWITCH(ConfigurationBedLevelingType::None, bedLevelingNameNone);
  _MATCH_SWITCH(ConfigurationBedLevelingType::Auto3Point, bedLevelingName3Point);
  _MATCH_SWITCH(ConfigurationBedLevelingType::AutoLinear, bedLevelingNameLinear);
  _MATCH_SWITCH(ConfigurationBedLevelingType::AutoBilinear, bedLevelingNameBilinear);
  _MATCH_SWITCH(ConfigurationBedLevelingType::AutoUbl, bedLevelingNameUbl);
  _MATCH_SWITCH(ConfigurationBedLevelingType::Mesh, bedLevelingNameMesh);
  }

  return nullptr;
}
