#ifndef RSCP_MQTT_MAPPING_H_
#define RSCP_MQTT_MAPPING_H_

#include "RscpTags.h"
#include "RscpTypes.h"

#define TOPIC_SIZE        128
#define PAYLOAD_SIZE      80
#define REGEX_SIZE        128

#define PAYLOAD_REGEX_2_DIGIT      "(^[0-9]{1,2}$)"
#define PAYLOAD_REGEX_5_DIGIT      "(^[0-9]{1,5}$)"

namespace RSCP_MQTT {

typedef struct _cache_t {
    uint32_t container;
    uint32_t tag;
    int index;
    char topic[TOPIC_SIZE];
    char fstring[PAYLOAD_SIZE];
    char payload[PAYLOAD_SIZE];
    int type;
    int divisor;
    int bit_to_bool;
    int publish;
} cache_t;

cache_t cache[] = {
    { 0, TAG_INFO_SW_RELEASE, 0, "rscp2mqtt/system/software", "%s", "", RSCP::eTypeString, 1, 0, 0 },
    { 0, TAG_INFO_PRODUCTION_DATE, 0, "rscp2mqtt/system/production_date", "%s", "", RSCP::eTypeString, 1, 0, 0 },
    { 0, TAG_INFO_SERIAL_NUMBER, 0, "rscp2mqtt/system/serial_number", "%s", "", RSCP::eTypeString, 1, 0, 0 },
    { 0, TAG_INFO_TIME_ZONE, 0, "rscp2mqtt/time/zone", "%s", "", RSCP::eTypeString, 1, 0, 0 },
    { 0, TAG_EMS_POWER_PV, 0, "rscp2mqtt/solar/power", "%i", "", RSCP::eTypeInt32, 1, 0, 0 },
    { 0, TAG_EMS_POWER_BAT, 0, "rscp2mqtt/battery/power", "%i", "", RSCP::eTypeInt32, 1, 0, 0 },
    { 0, TAG_EMS_POWER_HOME, 0, "rscp2mqtt/home/power", "%i", "", RSCP::eTypeInt32, 1, 0, 0 },
    { 0, TAG_EMS_POWER_GRID, 0, "rscp2mqtt/grid/power", "%i", "", RSCP::eTypeInt32, 1, 0, 0 },
    { 0, TAG_EMS_POWER_ADD, 0, "rscp2mqtt/addon/power", "%i", "", RSCP::eTypeInt32, 1, 0, 0 },
    { 0, TAG_EMS_BAT_SOC, 0, "rscp2mqtt/battery/soc", "%i", "", RSCP::eTypeUChar8, 1, 0, 0 },
    { 0, TAG_EMS_STATUS, 0, "rscp2mqtt/ems/charging_lock", "%s", "", RSCP::eTypeUInt32, 1, 1, 0 },
    { 0, TAG_EMS_STATUS, 0, "rscp2mqtt/ems/discharging_lock", "%s", "", RSCP::eTypeUInt32, 1, 2, 0 },
    { 0, TAG_EMS_STATUS, 0, "rscp2mqtt/ems/emergency_power_available", "%s", "", RSCP::eTypeUInt32, 1, 4, 0 },
    { 0, TAG_EMS_STATUS, 0, "rscp2mqtt/ems/charging_throttled", "%s", "", RSCP::eTypeUInt32, 1, 8, 0 },
    { 0, TAG_EMS_STATUS, 0, "rscp2mqtt/grid_in_limit", "%s", "", RSCP::eTypeUInt32, 1, 16, 0 },
    { 0, TAG_EMS_STATUS, 0, "rscp2mqtt/ems/charging_time_lock", "%s", "", RSCP::eTypeUInt32, 1, 32, 0 },
    { 0, TAG_EMS_STATUS, 0, "rscp2mqtt/ems/discharging_time_lock", "%s", "", RSCP::eTypeUInt32, 1, 64, 0 },
    { 0, TAG_EMS_BALANCED_PHASES, 0, "rscp2mqtt/ems/balanced_phases/L1", "%i", "", RSCP::eTypeUChar8, 1, 1, 0 },
    { 0, TAG_EMS_BALANCED_PHASES, 0, "rscp2mqtt/ems/balanced_phases/L2", "%i", "", RSCP::eTypeUChar8, 2, 1, 0 },
    { 0, TAG_EMS_BALANCED_PHASES, 0, "rscp2mqtt/ems/balanced_phases/L3", "%i", "", RSCP::eTypeUChar8, 4, 1, 0 },
    { 0, TAG_EMS_INSTALLED_PEAK_POWER, 0, "rscp2mqtt/system/installed_peak_power", "%u", "", RSCP::eTypeUInt32, 1, 0, 0 },
    { 0, TAG_EMS_DERATE_AT_PERCENT_VALUE, 0, "rscp2mqtt/system/derate_at_percent_value", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { 0, TAG_EMS_DERATE_AT_POWER_VALUE, 0, "rscp2mqtt/system/derate_at_power_value", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { 0, TAG_EMS_SET_POWER, 0, "rscp2mqtt/ems/set_power/power", "%i", "", RSCP::eTypeInt32, 1, 0, 0 },
    { 0, TAG_EMS_MODE, 0, "rscp2mqtt/mode", "%i", "", RSCP::eTypeUChar8, 1, 0, 0 },
    { 0, TAG_EMS_COUPLING_MODE, 0, "rscp2mqtt/coupling/mode", "%i", "", RSCP::eTypeUChar8, 1, 0, 0 },
    // CONTAINER TAG_BAT_DATA --------------------------------------------------------------------
    { TAG_BAT_DATA, TAG_BAT_RSOC, 0, "rscp2mqtt/battery/rsoc", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_BAT_DATA, TAG_BAT_MODULE_VOLTAGE, 0, "rscp2mqtt/battery/voltage", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_BAT_DATA, TAG_BAT_CURRENT, 0, "rscp2mqtt/battery/current", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_BAT_DATA, TAG_BAT_CHARGE_CYCLES, 0, "rscp2mqtt/battery/cycles", "%u", "", RSCP::eTypeUInt32, 1, 0, 0 },
    { TAG_BAT_DATA, TAG_BAT_STATUS_CODE, 0, "rscp2mqtt/battery/status", "%u", "", RSCP::eTypeUInt32, 1, 0, 0 },
    { TAG_BAT_DATA, TAG_BAT_ERROR_CODE, 0, "rscp2mqtt/battery/error", "%u", "", RSCP::eTypeUInt32, 1, 0, 0 },
    { TAG_BAT_DATA, TAG_BAT_DEVICE_NAME, 0, "rscp2mqtt/battery/name", "%s", "", RSCP::eTypeString, 1, 0, 0 },
    { TAG_BAT_DATA, TAG_BAT_DCB_COUNT, 0, "rscp2mqtt/battery/dcb_count", "%i", "", RSCP::eTypeUChar8, 1, 0, 0 },
    { TAG_BAT_DATA, TAG_BAT_TRAINING_MODE, 0, "rscp2mqtt/battery/training", "%i", "", RSCP::eTypeUChar8, 1, 0, 0 },
    { TAG_BAT_DATA, TAG_BAT_MAX_DCB_CELL_TEMPERATURE, 0, "rscp2mqtt/battery/temperature/max", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_BAT_DATA, TAG_BAT_MIN_DCB_CELL_TEMPERATURE, 0, "rscp2mqtt/battery/temperature/min", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    // CONTAINER TAG_EMS_GET_POWER_SETTINGS ------------------------------------------------------
    { TAG_EMS_GET_POWER_SETTINGS, TAG_EMS_MAX_CHARGE_POWER, 0, "rscp2mqtt/ems/max_charge/power", "%u", "", RSCP::eTypeUInt32, 1, 0, 0 },
    { TAG_EMS_GET_POWER_SETTINGS, TAG_EMS_MAX_DISCHARGE_POWER, 0, "rscp2mqtt/ems/max_discharge/power", "%u", "", RSCP::eTypeUInt32, 1, 0, 0 },
    { TAG_EMS_GET_POWER_SETTINGS, TAG_EMS_POWER_LIMITS_USED, 0, "rscp2mqtt/ems/power_limits", "%s", "", RSCP::eTypeBool, 1, 0, 0 },
    { TAG_EMS_GET_POWER_SETTINGS, TAG_EMS_DISCHARGE_START_POWER, 0, "rscp2mqtt/ems/discharge_start/power", "%u", "", RSCP::eTypeUInt32, 1, 0, 0 },
    { TAG_EMS_GET_POWER_SETTINGS, TAG_EMS_POWERSAVE_ENABLED, 0, "rscp2mqtt/ems/power_save", "%s", "", RSCP::eTypeBool, 1, 0, 0 },
    { TAG_EMS_GET_POWER_SETTINGS, TAG_EMS_WEATHER_REGULATED_CHARGE_ENABLED, 0, "rscp2mqtt/ems/weather_regulation", "%s", "", RSCP::eTypeBool, 1, 0, 0 },
    // CONTAINER TAG_EMS_SET_POWER_SETTINGS ------------------------------------------------------
    { TAG_EMS_SET_POWER_SETTINGS, TAG_EMS_RES_DISCHARGE_START_POWER, 0, "rscp2mqtt/ems/discharge_start/status", "%i", "", RSCP::eTypeChar8, 1, 0, 0 },
    { TAG_EMS_SET_POWER_SETTINGS, TAG_EMS_RES_MAX_CHARGE_POWER, 0, "rscp2mqtt/ems/max_charge/status", "%i", "", RSCP::eTypeChar8, 1, 0, 0 },
    { TAG_EMS_SET_POWER_SETTINGS, TAG_EMS_RES_MAX_DISCHARGE_POWER, 0, "rscp2mqtt/ems/max_discharge/status", "%i", "", RSCP::eTypeChar8, 1, 0, 0 },
    // CONTAINER TAG_PM_DATA ---------------------------------------------------------------------
    { TAG_PM_DATA, TAG_PM_POWER_L1, 0, "rscp2mqtt/pm/power/L1", "%.0lf", "", RSCP::eTypeDouble64, 1, 0, 0 },
    { TAG_PM_DATA, TAG_PM_POWER_L2, 0, "rscp2mqtt/pm/power/L2", "%.0lf", "", RSCP::eTypeDouble64, 1, 0, 0 },
    { TAG_PM_DATA, TAG_PM_POWER_L3, 0, "rscp2mqtt/pm/power/L3", "%.0lf", "", RSCP::eTypeDouble64, 1, 0, 0 },
    { TAG_PM_DATA, TAG_PM_ENERGY_L1, 0, "rscp2mqtt/pm/energy/L1", "%.0lf", "", RSCP::eTypeDouble64, 1000, 0, 0 },
    { TAG_PM_DATA, TAG_PM_ENERGY_L2, 0, "rscp2mqtt/pm/energy/L2", "%.0lf", "", RSCP::eTypeDouble64, 1000, 0, 0 },
    { TAG_PM_DATA, TAG_PM_ENERGY_L3, 0, "rscp2mqtt/pm/energy/L3", "%.0lf", "", RSCP::eTypeDouble64, 1000, 0, 0 },
    { TAG_PM_DATA, TAG_PM_VOLTAGE_L1, 0, "rscp2mqtt/pm/voltage/L1", "%0.2f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PM_DATA, TAG_PM_VOLTAGE_L2, 0, "rscp2mqtt/pm/voltage/L2", "%0.2f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PM_DATA, TAG_PM_VOLTAGE_L3, 0, "rscp2mqtt/pm/voltage/L3", "%0.2f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PM_DATA, TAG_PM_ACTIVE_PHASES, 0, "rscp2mqtt/pm/active_phases/L1", "%i", "", RSCP::eTypeUChar8, 1, 1, 0 },
    { TAG_PM_DATA, TAG_PM_ACTIVE_PHASES, 0, "rscp2mqtt/pm/active_phases/L2", "%i", "", RSCP::eTypeUChar8, 2, 1, 0 },
    { TAG_PM_DATA, TAG_PM_ACTIVE_PHASES, 0, "rscp2mqtt/pm/active_phases/L3", "%i", "", RSCP::eTypeUChar8, 4, 1, 0 },
    // CONTAINER TAG_PVI_DATA --------------------------------------------------------------------
    { TAG_PVI_DC_POWER, TAG_PVI_VALUE, 0, "rscp2mqtt/pvi/power/string_1", "%.0f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_DC_POWER, TAG_PVI_VALUE, 1, "rscp2mqtt/pvi/power/string_2", "%.0f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_DC_VOLTAGE, TAG_PVI_VALUE, 0, "rscp2mqtt/pvi/voltage/string_1", "%.0f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_DC_VOLTAGE, TAG_PVI_VALUE, 1, "rscp2mqtt/pvi/voltage/string_2", "%.0f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_DC_CURRENT, TAG_PVI_VALUE, 0, "rscp2mqtt/pvi/current/string_1", "%0.2f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_DC_CURRENT, TAG_PVI_VALUE, 1, "rscp2mqtt/pvi/current/string_2", "%0.2f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_AC_POWER, TAG_PVI_VALUE, 0, "rscp2mqtt/pvi/power/L1", "%.0f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_AC_POWER, TAG_PVI_VALUE, 1, "rscp2mqtt/pvi/power/L2", "%.0f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_AC_POWER, TAG_PVI_VALUE, 2, "rscp2mqtt/pvi/power/L3", "%.0f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_AC_VOLTAGE, TAG_PVI_VALUE, 0, "rscp2mqtt/pvi/voltage/L1", "%.0f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_AC_VOLTAGE, TAG_PVI_VALUE, 1, "rscp2mqtt/pvi/voltage/L2", "%.0f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_AC_VOLTAGE, TAG_PVI_VALUE, 2, "rscp2mqtt/pvi/voltage/L3", "%.0f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_AC_CURRENT, TAG_PVI_VALUE, 0, "rscp2mqtt/pvi/current/L1", "%0.2f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_AC_CURRENT, TAG_PVI_VALUE, 1, "rscp2mqtt/pvi/current/L2", "%0.2f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_AC_CURRENT, TAG_PVI_VALUE, 2, "rscp2mqtt/pvi/current/L3", "%0.2f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_PVI_DATA, TAG_PVI_TEMPERATURE_COUNT, 0, "rscp2mqtt/pvi/temperature/count", "%i", "", RSCP::eTypeUChar8, 1, 0, false },
    { TAG_PVI_DATA, TAG_PVI_ON_GRID, 0, "rscp2mqtt/pvi/on_grid", "%s", "", RSCP::eTypeBool, 1, 0, 0 },
    // CONTAINER TAG_SE_EP_RESERVE ---------------------------------------------------------------
    { TAG_SE_EP_RESERVE, TAG_SE_PARAM_EP_RESERVE, 0, "rscp2mqtt/reserve/percent", "%0.2f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_SE_EP_RESERVE, TAG_SE_PARAM_EP_RESERVE_W, 0, "rscp2mqtt/reserve/energy", "%0.2f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_SE_EP_RESERVE, TAG_SE_PARAM_EP_RESERVE_MAX_W, 0, "rscp2mqtt/reserve/max", "%0.2f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_SE_EP_RESERVE, TAG_SE_PARAM_LAST_SOC, 0, "rscp2mqtt/reserve/last_soc", "%0.2f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    // CONTAINER TAG_DB_HISTORY_DATA_... ---------------------------------------------------------
    // TODAY
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_BAT_POWER_IN, 0, "rscp2mqtt/battery/energy/charge", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_BAT_POWER_OUT, 0, "rscp2mqtt/battery/energy/discharge", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_DC_POWER, 0, "rscp2mqtt/solar/energy", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_GRID_POWER_IN, 0, "rscp2mqtt/grid/energy/in", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_GRID_POWER_OUT, 0, "rscp2mqtt/grid/energy/out", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_CONSUMPTION, 0, "rscp2mqtt/home/energy", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_PM_0_POWER, 0, "rscp2mqtt/pm_0/energy", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_PM_1_POWER, 0, "rscp2mqtt/pm_1/energy", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_CONSUMED_PRODUCTION, 0, "rscp2mqtt/consumed", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_AUTARKY, 0, "rscp2mqtt/autarky", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    // YESTERDAY
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_BAT_POWER_IN, 1, "rscp2mqtt/yesterday/battery/energy/charge", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_BAT_POWER_OUT, 1, "rscp2mqtt/yesterday/battery/energy/discharge", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_DC_POWER, 1, "rscp2mqtt/yesterday/solar/energy", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_GRID_POWER_IN, 1, "rscp2mqtt/yesterday/grid/energy/in", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_GRID_POWER_OUT, 1, "rscp2mqtt/yesterday/grid/energy/out", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_CONSUMPTION, 1, "rscp2mqtt/yesterday/home/energy", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_PM_0_POWER, 1, "rscp2mqtt/yesterday/pm_0/energy", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_PM_1_POWER, 1, "rscp2mqtt/yesterday/pm_1/energy", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_BAT_CHARGE_LEVEL, 1, "rscp2mqtt/yesterday/battery/rsoc", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_CONSUMED_PRODUCTION, 1, "rscp2mqtt/yesterday/consumed", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_DB_HISTORY_DATA_DAY, TAG_DB_AUTARKY, 1, "rscp2mqtt/yesterday/autarky", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    // WEEK
    { TAG_DB_HISTORY_DATA_WEEK, TAG_DB_BAT_POWER_IN, 0, "rscp2mqtt/week/battery/energy/charge", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_WEEK, TAG_DB_BAT_POWER_OUT, 0, "rscp2mqtt/week/battery/energy/discharge", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_WEEK, TAG_DB_DC_POWER, 0, "rscp2mqtt/week/solar/energy", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_WEEK, TAG_DB_GRID_POWER_IN, 0, "rscp2mqtt/week/grid/energy/in", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_WEEK, TAG_DB_GRID_POWER_OUT, 0, "rscp2mqtt/week/grid/energy/out", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_WEEK, TAG_DB_CONSUMPTION, 0, "rscp2mqtt/week/home/energy", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_WEEK, TAG_DB_CONSUMED_PRODUCTION, 0, "rscp2mqtt/week/consumed", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_DB_HISTORY_DATA_WEEK, TAG_DB_AUTARKY, 0, "rscp2mqtt/week/autarky", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    // MONTH
    { TAG_DB_HISTORY_DATA_MONTH, TAG_DB_BAT_POWER_IN, 0, "rscp2mqtt/month/battery/energy/charge", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_MONTH, TAG_DB_BAT_POWER_OUT, 0, "rscp2mqtt/month/battery/energy/discharge", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_MONTH, TAG_DB_DC_POWER, 0, "rscp2mqtt/month/solar/energy", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_MONTH, TAG_DB_GRID_POWER_IN, 0, "rscp2mqtt/month/grid/energy/in", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_MONTH, TAG_DB_GRID_POWER_OUT, 0, "rscp2mqtt/month/grid/energy/out", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_MONTH, TAG_DB_CONSUMPTION, 0, "rscp2mqtt/month/home/energy", "%0.2f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_MONTH, TAG_DB_CONSUMED_PRODUCTION, 0, "rscp2mqtt/month/consumed", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_DB_HISTORY_DATA_MONTH, TAG_DB_AUTARKY, 0, "rscp2mqtt/month/autarky", "%0.1f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    // YEAR
    { TAG_DB_HISTORY_DATA_YEAR, TAG_DB_BAT_POWER_IN, 0, "rscp2mqtt/year/battery/energy/charge", "%.0f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_YEAR, TAG_DB_BAT_POWER_OUT, 0, "rscp2mqtt/year/battery/energy/discharge", "%.0f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_YEAR, TAG_DB_DC_POWER, 0, "rscp2mqtt/year/solar/energy", "%.0f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_YEAR, TAG_DB_GRID_POWER_IN, 0, "rscp2mqtt/year/grid/energy/in", "%.0f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_YEAR, TAG_DB_GRID_POWER_OUT, 0, "rscp2mqtt/year/grid/energy/out", "%.0f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_YEAR, TAG_DB_CONSUMPTION, 0, "rscp2mqtt/year/home/energy", "%.0f", "", RSCP::eTypeFloat32, 1000, 0, 0 },
    { TAG_DB_HISTORY_DATA_YEAR, TAG_DB_CONSUMED_PRODUCTION, 0, "rscp2mqtt/year/consumed", "%.0f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    { TAG_DB_HISTORY_DATA_YEAR, TAG_DB_AUTARKY, 0, "rscp2mqtt/year/autarky", "%.0f", "", RSCP::eTypeFloat32, 1, 0, 0 },
    // WALLBOX
    { 0, TAG_EMS_POWER_WB_ALL, 0, "rscp2mqtt/wallbox/total/power", "%i", "", RSCP::eTypeInt32, 1, 0, 0 },
    { 0, TAG_EMS_POWER_WB_SOLAR, 0, "rscp2mqtt/wallbox/solar/power", "%i", "", RSCP::eTypeInt32, 1, 0, 0 },
    { 0, TAG_EMS_BATTERY_TO_CAR_MODE, 0, "rscp2mqtt/wallbox/battery_to_car", "%i", "", RSCP::eTypeUChar8, 1, 0, 0 },
    { 0, TAG_EMS_BATTERY_BEFORE_CAR_MODE, 0, "rscp2mqtt/wallbox/battery_before_car", "%i", "", RSCP::eTypeUChar8, 1, 0, 0 },
    { 0, TAG_EMS_GET_WB_DISCHARGE_BAT_UNTIL, 0, "rscp2mqtt/wallbox/battery_discharge_until", "%i", "", RSCP::eTypeUChar8, 1, 0, 0 },
    { 0, TAG_EMS_GET_WALLBOX_ENFORCE_POWER_ASSIGNMENT, 0, "rscp2mqtt/wallbox/disable_battery_at_mix_mode", "%s", "", RSCP::eTypeBool, 1, 0, 0 },
    { TAG_WB_DATA, TAG_WB_DEVICE_STATE, 0, "rscp2mqtt/wallbox/status", "%s", "", RSCP::eTypeBool, 1, 0, 0 },
    { TAG_WB_DATA, TAG_WB_PM_ACTIVE_PHASES, 0, "rscp2mqtt/wallbox/active_phases", "%i", "", RSCP::eTypeInt32, 1, 0, 0 },
    { TAG_WB_EXTERN_DATA_ALG, TAG_WB_EXTERN_DATA, 1, "rscp2mqtt/wallbox/number_used_phases", "%i", "", RSCP::eTypeInt32, 1, 0, 0 },
    { TAG_WB_EXTERN_DATA_ALG, TAG_WB_EXTERN_DATA, 3, "rscp2mqtt/wallbox/max_current", "%i", "", RSCP::eTypeInt32, 1, 0, 0 },
    { TAG_WB_EXTERN_DATA_ALG, TAG_WB_EXTERN_DATA, 2, "rscp2mqtt/wallbox/plugged", "%s", "", RSCP::eTypeBool, 1, 8, 0 },
    { TAG_WB_EXTERN_DATA_ALG, TAG_WB_EXTERN_DATA, 2, "rscp2mqtt/wallbox/locked", "%s", "", RSCP::eTypeBool, 1, 16, 0 },
    { TAG_WB_EXTERN_DATA_ALG, TAG_WB_EXTERN_DATA, 2, "rscp2mqtt/wallbox/charging", "%s", "", RSCP::eTypeBool, 1, 32, 0 },
    { TAG_WB_EXTERN_DATA_ALG, TAG_WB_EXTERN_DATA, 2, "rscp2mqtt/wallbox/canceled", "%s", "", RSCP::eTypeBool, 1, 64, 0 },
    { TAG_WB_EXTERN_DATA_ALG, TAG_WB_EXTERN_DATA, 2, "rscp2mqtt/wallbox/sun_mode", "%s", "", RSCP::eTypeBool, 1, 128, 0 }
};

std::vector<cache_t> RscpMqttCache(cache, cache + sizeof(cache) / sizeof(cache_t));

typedef struct _rec_cache_t {
    uint32_t container;
    uint32_t tag;
    char topic[TOPIC_SIZE];
    char regex_true[REGEX_SIZE];
    char value_true[PAYLOAD_SIZE];
    char regex_false[REGEX_SIZE];
    char value_false[PAYLOAD_SIZE];
    char payload[PAYLOAD_SIZE];
    int type;
    int refresh_count;
    bool done;
} rec_cache_t;

rec_cache_t rec_cache[] = {
    { 0, TAG_EMS_REQ_START_MANUAL_CHARGE, "rscp2mqtt/set/manual_charge", PAYLOAD_REGEX_5_DIGIT, "", "", "", "", RSCP::eTypeUInt32, -1, true },
    { TAG_EMS_REQ_SET_POWER_SETTINGS, TAG_EMS_WEATHER_REGULATED_CHARGE_ENABLED, "rscp2mqtt/set/weather_regulation", "^true|on|1$", "1", "^false|off|0$", "0", "", RSCP::eTypeUChar8, -1, true },
    { TAG_EMS_REQ_SET_POWER_SETTINGS, TAG_EMS_POWER_LIMITS_USED, "rscp2mqtt/set/power_limits", "^true|on|1$", "true", "^false|off|0$", "false", "", RSCP::eTypeBool, -1, true },
    { TAG_EMS_REQ_SET_POWER_SETTINGS, TAG_EMS_MAX_CHARGE_POWER, "rscp2mqtt/set/max_charge_power", PAYLOAD_REGEX_5_DIGIT, "", "", "", "", RSCP::eTypeUInt32, -1, true },
    { TAG_EMS_REQ_SET_POWER_SETTINGS, TAG_EMS_MAX_DISCHARGE_POWER, "rscp2mqtt/set/max_discharge_power", PAYLOAD_REGEX_5_DIGIT, "", "", "", "", RSCP::eTypeUInt32, -1, true },
    { TAG_EMS_REQ_SET_POWER, TAG_EMS_REQ_SET_POWER_MODE, "power_mode: mode", "", "", "", "", "", RSCP::eTypeUChar8, 0, true },
    { TAG_EMS_REQ_SET_POWER, TAG_EMS_REQ_SET_POWER_VALUE, "power_mode: value", "", "", "", "", "", RSCP::eTypeInt32, 0, true },
    { TAG_SE_REQ_SET_EP_RESERVE, TAG_SE_PARAM_EP_RESERVE, "rscp2mqtt/set/reserve/percent", PAYLOAD_REGEX_2_DIGIT, "", "", "", "", RSCP::eTypeFloat32, -1, true },
    { TAG_SE_REQ_SET_EP_RESERVE, TAG_SE_PARAM_EP_RESERVE_W, "rscp2mqtt/set/reserve/energy", PAYLOAD_REGEX_5_DIGIT, "", "", "", "", RSCP::eTypeFloat32, -1, true },
    { 0, 0, "rscp2mqtt/set/power_mode", "^auto$|^idle:[0-9]{1,4}$|^charge:[0-9]{1,5}:[0-9]{1,4}$|^discharge:[0-9]{1,5}:[0-9]{1,4}$|^grid_charge:[0-9]{1,5}:[0-9]{1,4}$", "", "", "", "", RSCP::eTypeBool, -1, true },
    { 0, TAG_EMS_REQ_SET_BATTERY_TO_CAR_MODE, "rscp2mqtt/set/wallbox/battery_to_car", "^true|on|1$", "1", "^false|off|0$", "0", "", RSCP::eTypeUChar8, -1, true },
    { 0, TAG_EMS_REQ_SET_BATTERY_BEFORE_CAR_MODE, "rscp2mqtt/set/wallbox/battery_before_car", "^true|on|1$", "1", "^false|off|0$", "0", "", RSCP::eTypeUChar8, -1, true },
    { 0, TAG_EMS_REQ_SET_WB_DISCHARGE_BAT_UNTIL, "rscp2mqtt/set/wallbox/battery_discharge_until", PAYLOAD_REGEX_2_DIGIT, "", "", "", "", RSCP::eTypeUChar8, -1, true },
    { 0, TAG_EMS_REQ_SET_WALLBOX_ENFORCE_POWER_ASSIGNMENT, "rscp2mqtt/set/wallbox/disable_battery_at_mix_mode", "^true|on|1$", "true", "^false|off|0$", "false", "", RSCP::eTypeBool, -1, true },
    { TAG_WB_REQ_DATA, TAG_WB_EXTERN_DATA, "rscp2mqtt/set/wallbox/control", "^solar:[0-9]{1,2}$|^mix:[0-9]{1,2}$|^stop$", "", "", "", "", RSCP::eTypeBool, -1, true },
    { 0, 0, "rscp2mqtt/set/requests/pm", "^true|1$", "true", "^false|0$", "false", "", RSCP::eTypeBool, -1, true },
    { 0, 0, "rscp2mqtt/set/requests/pvi", "^true|1$", "true", "^false|0$", "false", "", RSCP::eTypeBool, -1, true },
    { 0, 0, "rscp2mqtt/set/log", "^true|1$", "true", "", "", "", RSCP::eTypeBool, -1, true },
    { 0, 0, "rscp2mqtt/set/force", "^true|1$", "true", "", "", "", RSCP::eTypeBool, -1, true },
    { 0, 0, "rscp2mqtt/set/interval", "(^[1-9]|10$)", "", "", "", "", RSCP::eTypeUChar8, -1, true }
};

std::vector<rec_cache_t> RscpMqttReceiveCache(rec_cache, rec_cache + sizeof(rec_cache) / sizeof(rec_cache_t));

bool compareRecCache(RSCP_MQTT::rec_cache_t c1, RSCP_MQTT::rec_cache_t c2) {
    return (c1.container < c2.container);
}

}

#endif
