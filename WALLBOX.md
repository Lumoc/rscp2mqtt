## Wallbox

This update implements functions to support an E3/DC wallbox.

Because I don't have a wallbox from E3/DC, I couldn't test the functionality.

Please give me feedback if something is not working properly or can be improved.

Configuration

Add this line to the .config file:
```
WALLBOX=true
```

The following topics are sent to the MQTT broker:

| Device / Tag | MQTT Topic | Values / [Unit] |
| --- | --- | --- |
| Wallbox battery | rscp2mqtt/wallbox/battery_to_car | |
| Wallbox battery | rscp2mqtt/wallbox/battery_before_car | |
| New: Wallbox battery | rscp2mqtt/wallbox/battery_discharge_until | % |
| New: Wallbox battery | rscp2mqtt/wallbox/disable_battery_at_mix_mode | (true/false) |
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

The new topics are based on additional tags introduced by https://github.com/nischram/E3dcGui

In addition, these topics can be published to control the wallbox:

Set solar or mix mode with the current in [A] (6..32 Ampere)
```
mosquitto_pub -h localhost -p 1883 -t "rscp2mqtt/set/wallbox/control" -m "solar:16"
mosquitto_pub -h localhost -p 1883 -t "rscp2mqtt/set/wallbox/control" -m "mix:8"
```

Stop charging
```
mosquitto_pub -h localhost -p 1883 -t "rscp2mqtt/set/wallbox/control" -m "stop"
```

Set battery to car mode (true/1/false/0)
```
mosquitto_pub -h localhost -p 1883 -t "rscp2mqtt/set/wallbox/battery_to_car" -m true
```

Set battery before car mode (true/1/false/0)
```
mosquitto_pub -h localhost -p 1883 -t "rscp2mqtt/set/wallbox/battery_before_car" -m true
```

Set battery discharge until (%)
```
mosquitto_pub -h localhost -p 1883 -t "rscp2mqtt/set/wallbox/battery_discharge_until" -m 80
```

Set disable charging battery at mix mode (true/1/false/0)
```
mosquitto_pub -h localhost -p 1883 -t "rscp2mqtt/set/wallbox/disable_battery_at_mix_mode" -m true
```
