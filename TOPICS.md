## Topics

| Device / Tag | MQTT Topic | Values / [Unit] |
| --- | --- | --- |
| Autarky | rscp2mqtt/autarky | [%] |
| Battery Charge Cycles | rscp2mqtt/battery/cycles | |
| Battery Current | rscp2mqtt/battery/current | [A] |
| Battery Device Name | rscp2mqtt/battery/name | "BAT_XXX" |
| Battery Energy Charge | rscp2mqtt/battery/energy/charge | [kWh] |
| Battery Energy Discharge | rscp2mqtt/battery/energy/discharge | [kWh] |
| Battery Error Code | rscp2mqtt/battery/error | |
| Battery Modules Count | rscp2mqtt/battery/dcb_count | |
| Battery Module Voltage | rscp2mqtt/battery/voltage | [V] |
| Battery RSOC | rscp2mqtt/battery/rsoc | [%] |
| Battery SOC | rscp2mqtt/battery/soc | [%] |
| Battery Status Code | rscp2mqtt/battery/status | |
| Battery Temperature Max | rscp2mqtt/battery/temperature/max | [°C] |
| Battery Temperature Min | rscp2mqtt/battery/temperature/min | [°C] |
| Battery Training Mode | rscp2mqtt/battery/training | (0-2) |
| Consumed Production | rscp2mqtt/consumed | [%] |
| EMS Addon Power | rscp2mqtt/addon/power | [W] |
| EMS Balanced Phase | rscp2mqtt/ems/balanced_phases/L1 | (true/false) |
| EMS Balanced Phase | rscp2mqtt/ems/balanced_phases/L2 | (true/false) |
| EMS Balanced Phase | rscp2mqtt/ems/balanced_phases/L3 | (true/false) |
| EMS Battery Power | rscp2mqtt/battery/power | [W] |
| EMS Charging Lock | rscp2mqtt/ems/charging_lock | (true/false) |
| EMS Charging Throttled | rscp2mqtt/ems/charging_throttled | (true/false) |
| EMS Charging Time Lock | rscp2mqtt/ems/charging_time_lock | (true/false) |
| EMS Coupling Mode | rscp2mqtt/coupling/mode | (0-4) |
| EMS Derate at percent value | rscp2mqtt/system/derate_at_percent_value | 0.7 |
| EMS Derate at power value | rscp2mqtt/system/derate_at_power_value | [W] |
| EMS Discharge Start Power | rscp2mqtt/ems/discharge_start/power | [W] |
| EMS Discharge Start Power Status | rscp2mqtt/ems/discharge_start/status | |
| EMS Discharging Lock | rscp2mqtt/ems/discharging_lock | (true/false) |
| EMS Discharging Time Lock | rscp2mqtt/ems/discharging_time_lock | (true/false) |
| EMS Emergency Power Available | rscp2mqtt/ems/emergency_power_available | (true/false) |
| EMS Grid In Limit | rscp2mqtt/grid_in_limit | (true/false) |
| EMS Grid Power | rscp2mqtt/grid/power | [W] |
| EMS Home Power | rscp2mqtt/home/power | [W] |
| EMS Installed Peak Power | rscp2mqtt/system/installed_peak_power | [W] |
| EMS Max Charge Power | rscp2mqtt/ems/max_charge/power | [W] |
| EMS Max Charge Power Status | rscp2mqtt/ems/max_charge/status | |
| EMS Max Discharge Power | rscp2mqtt/ems/max_discharge/power | [W] |
| EMS Max Discharge Power Status | rscp2mqtt/ems/max_discharge/status | |
| EMS Mode | rscp2mqtt/mode | (0,1,...) |
| EMS Power Limits Used | rscp2mqtt/ems/power_limits | (true/false) |
| EMS Powersave Enabled | rscp2mqtt/ems/power_save | (true/false) |
| EMS Set Power | rscp2mqtt/ems/set_power/power | [W] |
| EMS Solar Power | rscp2mqtt/solar/power | [W] |
| EMS Weather Regulation Enable | rscp2mqtt/ems/weather_regulation | (true/false) |
| EP Reserve | rscp2mqtt/reserve/procent | [%] |
| EP Reserve Energy | rscp2mqtt/reserve/energy | [Wh] |
| EP Reserve Max Energy | rscp2mqtt/reserve/max | [Wh] |
| EP Reserve Last SOC | rscp2mqtt/reserve/last_soc | [%] |
| Grid In Energy | rscp2mqtt/grid/energy/in | [kWh] |
| Grid Out Energy | rscp2mqtt/grid/energy/out | [kWh] |
| Home Energy | rscp2mqtt/home/energy | [kWh] |
| Month Autarky | rscp2mqtt/month/autarky | [%] |
| Month Battery Energy Charge | rscp2mqtt/month/battery/energy/charge | [kWh] |
| Month Consumed Production | rscp2mqtt/month/consumed | [%] |
| Month Energy Discharge | rscp2mqtt/month/battery/energy/discharge | [kWh] |
| Month Grid In Energy | rscp2mqtt/month/grid/energy/in | [kWh] |
| Month Grid Out Energy | rscp2mqtt/month/grid/energy/out | [kWh] |
| Month Home Energy | rscp2mqtt/month/home/energy | [kWh] |
| Month Solar Energy | rscp2mqtt/month/solar/energy | [kWh] |
| PM Active Phase L1 | rscp2mqtt/pm/active_phases/L1 | (true/false) |
| PM Active Phase L2 | rscp2mqtt/pm/active_phases/L2 | (true/false) |
| PM Active Phase L3 | rscp2mqtt/pm/active_phases/L3 | (true/false) |
| PM Energy L1 | rscp2mqtt/pm/energy/L1 | [Wh] |
| PM Energy L2 | rscp2mqtt/pm/energy/L2 | [Wh] |
| PM Energy L3 | rscp2mqtt/pm/energy/L3 | [Wh] |
| PM Power L1 | rscp2mqtt/pm/power/L1 | [W] |
| PM Power L2 | rscp2mqtt/pm/power/L2 | [W] |
| PM Power L2 | rscp2mqtt/pm/power/L2 | [W] |
| PM Voltage L1 | rscp2mqtt/pm/voltage/L1 | [V] |
| PM Voltage L2 | rscp2mqtt/pm/voltage/L2 | [V] |
| PM Voltage L3 | rscp2mqtt/pm/voltage/L3 | [V] |
| Production Date | rscp2mqtt/system/production_date | "KWXX_XXXX" |
| PVI Current L1 | rscp2mqtt/pvi/current/L1 | [A] |
| PVI Current L2 | rscp2mqtt/pvi/current/L2 | [A] |
| PVI Current L3 | rscp2mqtt/pvi/current/L3 | [A] |
| PVI On Grid | rscp2mqtt/pvi/on_grid | (true/false) |
| PVI Power L1 | rscp2mqtt/pvi/power/L1 | [W] |
| PVI Power L2 | rscp2mqtt/pvi/power/L2 | [W] |
| PVI Power L3 | rscp2mqtt/pvi/power/L3 | [W] |
| PVI String1 Current | rscp2mqtt/pvi/current/string_1 | [A] |
| PVI String1 Power | rscp2mqtt/pvi/power/string_1 | [W] |
| PVI String1 Voltage | rscp2mqtt/pvi/voltage/string_1 | [V] |
| PVI String2 Current | rscp2mqtt/pvi/current/string_2 | [A] |
| PVI String2 Power | rscp2mqtt/pvi/power/string_2 | [W] |
| PVI String2 Voltage | rscp2mqtt/pvi/voltage/string_2 | [V] |
| PVI Temperature 1 | rscp2mqtt/pvi/temperature/1  | [°C] |
| PVI Temperature 2 | rscp2mqtt/pvi/temperature/2  | [°C] |
| PVI Temperature 3 | rscp2mqtt/pvi/temperature/3  | [°C] |
| PVI Temperature 4 | rscp2mqtt/pvi/temperature/4  | [°C] |
| PVI Voltage L1 | rscp2mqtt/pvi/voltage/L1 | [V] |
| PVI Voltage L2 | rscp2mqtt/pvi/voltage/L2 | [V] |
| PVI Voltage L3 | rscp2mqtt/pvi/voltage/L3 | [V] |
| Serial Number | rscp2mqtt/system/serial_number | "S10-XXXXXXXXXXXX" |
| Software Release | rscp2mqtt/system/software | S10_XXXX_XXX |
| Solar Energy | rscp2mqtt/solar/energy | [kWh] |
| Time Zone | rscp2mqtt/time/zone | "Europe/City" |
| Wallbox battery | rscp2mqtt/wallbox/battery_to_car | |
| Wallbox battery | rscp2mqtt/wallbox/battery_before_car | |
| Wallbox battery | rscp2mqtt/wallbox/battery_discharge_until | % |
| Wallbox battery | rscp2mqtt/wallbox/disable_battery_at_mix_mode | (true/false) |
| Wallbox canceled | rscp2mqtt/wallbox/canceled | (true/false) |
| Wallbox charging | rscp2mqtt/wallbox/charging | (true/false) |
| Wallbox current | rscp2mqtt/wallbox/max_current | (true/false) |
| Wallbox locked | rscp2mqtt/wallbox/locked | (true/false) |
| Wallbox mode | rscp2mqtt/wallbox/sun_mode | (true/false) |
| Wallbox phases | rscp2mqtt/wallbox/active_phases | |
| Wallbox phases | rscp2mqtt/wallbox/number_used_phases | |
| Wallbox plugged | rscp2mqtt/wallbox/plugged | (true/false) |
| Wallbox power | rscp2mqtt/wallbox/total/power | [W] |
| Wallbox power | rscp2mqtt/wallbox/solar/power | [W] |
| Wallbox status | rscp2mqtt/wallbox/status | |
| Week Autarky | rscp2mqtt/week/autarky | [%] |
| Week Battery Energy Charge | rscp2mqtt/week/battery/energy/charge | [kWh] |
| Week Consumed Production | rscp2mqtt/week/consumed | [%] |
| Week Energy Discharge | rscp2mqtt/week/battery/energy/discharge | [kWh] |
| Week Grid In Energy | rscp2mqtt/week/grid/energy/in | [kWh] |
| Week Grid Out Energy | rscp2mqtt/week/grid/energy/out | [kWh] |
| Week Home Energy | rscp2mqtt/week/home/energy | [kWh] |
| Week Solar Energy | rscp2mqtt/week/solar/energy | [kWh] |
| Year Autarky | rscp2mqtt/year/autarky | [%] |
| Year Battery Energy Charge | rscp2mqtt/year/battery/energy/charge | [kWh] |
| Year Consumed Production | rscp2mqtt/year/consumed | [%] |
| Year Energy Discharge | rscp2mqtt/year/battery/energy/discharge | [kWh] |
| Year Grid In Energy | rscp2mqtt/year/grid/energy/in | [kWh] |
| Year Grid Out Energy | rscp2mqtt/year/grid/energy/out | [kWh] |
| Year Home Energy | rscp2mqtt/year/home/energy | [kWh] |
| Year Solar Energy | rscp2mqtt/year/solar/energy | [kWh] |
| Yesterday Autarky | rscp2mqtt/yesterday/autarky | [%] |
| Yesterday Battery Energy Charge | rscp2mqtt/yesterday/battery/energy/charge | [kWh] |
| Yesterday Battery SOC | rscp2mqtt/yesterday/battery/rsoc | [%] |
| Yesterday Consumed Production | rscp2mqtt/yesterday/consumed | [%] |
| Yesterday Energy Discharge | rscp2mqtt/yesterday/battery/energy/discharge | [kWh] |
| Yesterday Grid In Energy | rscp2mqtt/yesterday/grid/energy/in | [kWh] |
| Yesterday Grid Out Energy | rscp2mqtt/yesterday/grid/energy/out | [kWh] |
| Yesterday Home Energy | rscp2mqtt/yesterday/home/energy | [kWh] |
| Yesterday Solar Energy | rscp2mqtt/yesterday/solar/energy | [kWh] |
