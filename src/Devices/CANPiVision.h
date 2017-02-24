/*
 * CANPiVision.h
 */

#ifndef SRC_DEVICES_CANPIVISION_H_
#define SRC_DEVICES_CANPIVISION_H_

#include <stdint.h>
#include <memory>

#include "ctre/ctre.h"

class CANPiVisionIF;

class CANPiVision
{
public:
  explicit CANPiVision(uint8_t deviceNumber);
  virtual ~CANPiVision();

  /* Get the distance to the target
   *
   * @Return  - CTR_Code - Error code (if any) for getting the distance
   * @Param   - distance - distance to be filled in.
   *
   * Distance is less than 0 if there is no target lock
   *
   * The distance range is ??
   */
  CTR_Code GetDistance(int32_t* distance) const;

  /* Get the heading to the target
   *
   * @Return  - CTR_Code - Error code (if any) for getting heading
   * @Param   - heading - heading to be filled in.
   *
   * Heading is how far left and right in order to center the target.
   * 0 is centered.
   */
  CTR_Code GetHeading(int32_t* heading) const;

private:
  std::unique_ptr<CANPiVisionIF> visionInterface;
};

#endif /* SRC_DEVICES_CANPIVISION_H_ */
