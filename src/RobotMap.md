# An Inventory of Motor Controllers and Sensors

## Chassis
* 4 Talons (1, 2, 3, 4)
* 2 Encoders (one for right and one for left)

The chassis subsystem has 4 motors; two right and two left. There is also an encoder left and right. Choose one of the Talons to apply the encoder.

These encoders use the Grayhill encoders. The Talons for these controllers use the Wobot Sentinel Interface board. Each board requires an encoder to be wired to the Grayhill encoder.

## Shooter
* 3 Talons (5, 6, 7)
* 2 Encoders

The shooter is made of a two-motor transmission to a single drive shaft and a single motor connected to two wheels (go figure). Each transmission needs an encoder.

## Turret
* 1 Talon (8)
* 1 Encoder
* 4 Switches
 
## Ball Intake
* 1 Talon (9)
* 1 Encoder

## Gear Intake
* 1 Talon (10)
* 1 Encoder
* 5 Switches
    * 2 Banner sensors for identifying the reflective tape
    * 1 Banner sensor for detecting the gear in the slot
    * 2 Pneumatic switch sensors

## Climber
* 2 Talon (11, 12)

## Conveyor
* Talon (13)
* Encoder

## Pneumatics
* Shift
* Gear Intake
* Gear Squeeze

## Summary

Disable limit switches, except where noted.

| Subsystem   | Talon       | ID  | Encoder | Switches | ConfigNeutralMode | Comment |
| ----------- | ----------- | --- | ------- | -------- | ----------------- | ------- |
| Chassis     | Right 1     | 1   | Wobot   | Yes      | kNeutralMode_Coast  | WCP Hall Effect Sensors for Turret |
| Chassis     | Right 2     | 2   | No      | No       | kNeutralMode_Coast | Follower |
| Chassis     | Left 1      | 3   | Wobot   | Yes      | kNeutralMode_Coast | Gear Intake Pneumatic Switch Sensors |
| Chassis     | Left 2      | 4   | No      | No       | kNeutralMode_Coast | Follower |
| Shooter     | Top 1       | 5   | Versa   | No       | kNeutralMode_Coast | |
| Shooter     | Top 2       | 6   | No      | No       | kNeutralMode_Coast | Follower |
| Shooter     | Bottom      | 7   | Versa   | No       | kNeutralMode_Coast | |
| Turret      | Turret      | 8   | Versa   | Yes      | kNeutralMode_Brake | **Enable Limit Switches** |
| Ball Intake | Intake      | 9   | Versa   | No       | kNeutralMode_Coast | |
| Gear Intake | Gear Intake | 10  | Versa   | Yes      | kNeutralMode_Coast | 2 Banner Sensors |
| Climber     | Climber 1   | 11  | No      | No       | kNeutralMode_Brake | |
| Climber     | Climber 2   | 12  | No      | No       | kNeutralMode_Brake | |
| Conveyor    | Conveyor    | 13  | Versa   | Yes      | kNeutralMode_Coast | Banner Sensor for Gear Intake |


| Pneumatic    | Left | Right |
| ------------ | ---- | ----- |
| Shift        | 0    | 7     |
| Gear Intake  | 1    | 6     |
| Gear Squeeze | 2    | 5     |
| Unused       | 3    | 4     |

* 13 Talons
* 6 Versa Planetary Encoder Modules
    * 3 with switches
* 2 Wobot Sentinel Interfaces
    * 1 for Hall Effect Sensors
    * 1 for pneumatic switch sensors
* 2 WCP Hall Effect Sensors

