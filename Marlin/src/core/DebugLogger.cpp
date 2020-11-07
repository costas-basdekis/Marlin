#include "./DebugLogger.h"
#include "../feature/bedlevel/bedlevel.h"
#include "../libs/numtostr.h"
#include "../module/planner.h"
#include "../module/probe.h"
#include "../MarlinCore.h"

void DebugLogger::log_machine_info_() {
  serial->echoLnPgm("Machine Type: ", configuration.getMachineName());
  serial->echoLnPgm("Probe: ", configuration.getProbeName());

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
        serial->echoPgm(configuration.isScara ? PSTR("-Distal") : PSTR("-Back"));
      } else if (probe.offset_xy.y < 0) {
        serial->echoPgm(configuration.isScara ? PSTR("-Proximal") : PSTR("-Front"));
      } else if (probe.offset_xy.x != 0) {
        serial->echoPgm("-Center");
      }
      serial->echoPgm(" & ");
    }

    serial->echoPgm(probe.offset.z < 0 ? PSTR("Below") : probe.offset.z > 0 ? PSTR("Above") : PSTR("Same Z as"));
    serial->echoLnPgm(" Nozzle)");
  }

  if (configuration.hasAblOrUbl()) {
    serial->echoPgm("Auto Bed Leveling: ", configuration.getBedLevelingName());

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
          if (configuration.bedLevelingAutoUbl) {
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
