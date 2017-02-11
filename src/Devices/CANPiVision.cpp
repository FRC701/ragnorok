/*
 * CANPiVision.cpp
 */

#include "Devices/CANPiVision.h"

#include "ctre/CtreCanNode.h"
#include "FRC_NetworkCommunication/CANSessionMux.h"  //CAN Communication

static const uint32_t kCANPiVisionArbitrationID = 0x07011400;
// More IDs to use for other commands
// 0x07011440
// 0x07011480
// 0x070114C0
// 0x07011500

static const uint32_t kCANPiVisionControlArbitrationID = 0x07011C00;
// 0x07011C40
// 0x07011C80
// 0x07011CC0
// 0x07011D00

// default control update rate is 10ms.
static const int kDefaultControlPeriodMs = 10;
static const uint32_t kExpectedResponseTimeoutMillis = 50;

struct VisionData_t
{
  int32_t distance;
  int32_t heading;
};

struct VisionControl_t
{
  /* Byte 0 */
  unsigned start : 1;
  unsigned reserved: 7;
};

class CANPiVisionIF : public CtreCanNode
{
public:
  CANPiVisionIF(uint8_t deviceNumber)
  : CtreCanNode(deviceNumber)
  {
    RegisterRx(kCANPiVisionArbitrationID | deviceNumber );
    RegisterTx(kCANPiVisionControlArbitrationID | deviceNumber, kDefaultControlPeriodMs);
  }

  inline
  void GetVisionData(CtreCanNode::recMsg<VisionData_t>* visionData)
  {
    *visionData = GetRx<VisionData_t>(kCANPiVisionArbitrationID | GetDeviceNumber(), kExpectedResponseTimeoutMillis);
  }

  CTR_Code GetDistance(int32_t* distance)
  {
    CtreCanNode::recMsg<VisionData_t> visionData = {};
    GetVisionData(&visionData);
    *distance = visionData->distance;
    return visionData.err;
  }

  CTR_Code GetHeading(int32_t* heading)
  {
    CtreCanNode::recMsg<VisionData_t> visionData = {};
    GetVisionData(&visionData);
    *heading = visionData->heading;
    return visionData.err;
  }
};

CANPiVision::CANPiVision(uint8_t deviceNumber)
  : visionInterface(std::make_unique<CANPiVisionIF>(deviceNumber))
{
}

CANPiVision::~CANPiVision ()
{
}

CTR_Code CANPiVision::GetDistance(int32_t* distance) const
{
  return visionInterface->GetDistance(distance);
}

CTR_Code CANPiVision::GetHeading(int32_t* heading) const
{
  return visionInterface->GetHeading(heading);
}


