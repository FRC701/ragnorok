# An Inventory of Motor Controllers and Sensors

## Chassis
* 4 Talons
* 2 Encoders (one for right and one for left)

The chassis subsystem has 4 motors; two right and two left. There is also an encoder left and right. Choose one of the Talons to apply the encoder.

These encoders use the Grayhill encoders. The Talons for these controllers use the Wobot Sentinel Interface board. Each board requires an encoder to be wired to the Grayhill encoder.

## Shooter
* 3 Talons
* 2 Encoders

The shooter is made of a two-motor transmission to a single drive shaft and a single motor connected to two wheels (go figure). Each transmission needs an encoder.

## Ball Intake
* 1 Talon
* 1 Encoder

## Conveyor
* Talon
* Encoder

## Climber
* 2 Talon

## Gear Intake
* 1 Talon
* 1 Encoder
* 3 Switches

## Turret
* 1 Talon
* 1 Encoder
* 4 Switches
 
## Summary

Disable limit switches, except where noted.

| Subsystem   | Talon       | Encoder | Switches | Comment  |
| ----------- | ----------- | ------- | -------- | -------- |
| Chassis     | Right 1     | Wobot   | Yes      | WCP Hall Effect Sensors for Turret |
| Chassis     | Right 2     | No      | No       | Follower |
| Chassis     | Left 1      | Wobot   | No       | |
| Chassis     | Left 2      | No      | No       | Follower |
| Shooter     | Top 1       | Versa   | No       | |
| Shooter     | Top 2       | No      | No       | Follower |
| Shooter     | Bottom      | Versa   | No       | |
| Ball Intake | Intake      | Versa   | No       | |
| Conveyor    | Conveyor    | Versa   | Yes      | Banner Sensor for Gear Intake |
| Climber     | Climber 1   | No      | No       | |
| Climber     | Climber 2   | No      | No       | |
| Gear Intake | Gear Intake | Versa   | Yes      | Banner Sensor |
| Turret      | Turret      | Versa   | Yes      | **Enable Limit Switches** |

* 13 Talons
* 6 Versa Planetary Encoder Modules
    * 3 with switches
* 2 Wobot Sentinel Interfaces
* 2 WCP Hall Effect Sensors

