/*
 * CANVision.cpp
 */

#include <Devices/CANVision.h>

namespace {
  const int32_t kLowMinimumConfidence = 10;
  const int32_t kMediumMinumumConfidence = 100;
  const int32_t kHighMinimumConfidence = 500;
}


CANVision::CANVision (int deviceNumber)
: vision(deviceNumber)
, m_deviceNumber(deviceNumber)
, m_tracking(false)
, m_table(nullptr)
{
}

CANVision::~CANVision ()
{
  if (m_table != nullptr) {
    m_table->RemoveTableListener(this);
  }
}

void CANVision::EnableTracking() {
  m_tracking = true;
}

void CANVision::DisableTracking() {
  m_tracking = false;
}

bool CANVision::IsTrackingEnabled() const {
  return m_tracking;
}



CANVision::Confidence CANVision::GetConfidence() const
{
  Confidence confidence = kConfidenceLow;

  int32_t deviation = abs(GetDeviationTicks());

  if (deviation < kMediumMinumumConfidence) {
    confidence = kConfidenceLow;
  } else if (deviation < kHighMinimumConfidence) {
    confidence = kConfidenceMedium;
  } else {
    confidence = kConfidenceHigh;
  }

  return confidence;
}

int CANVision::GetDistanceInches() const
{
  int32_t distance;

  CTR_Code code = vision.GetDistance(&distance);
  if (code) {
    wpi_setErrorWithContext(code, "vision.GetDistance failed.");
  }
  return distance;
}

int CANVision::GetDeviationTicks() const
{
  int32_t deviation;

  CTR_Code code = vision.GetHeading(&deviation);
  if (code) {
    wpi_setErrorWithContext(code, "vision.GetHeading failed.");
  }
  return deviation;
}


// LiveWindow Methods
void CANVision::InitTable(std::shared_ptr<ITable> subTable)
{
  m_table = subTable;
  UpdateTable();
}

std::shared_ptr<ITable> CANVision::GetTable() const
{
  return m_table;
}

void CANVision::StartLiveWindowMode()
{
  if (m_table != nullptr) {
    m_table->AddTableListener(this);
  }
}

void CANVision::StopLiveWindowMode()
{
  if (m_table != nullptr) {
    m_table->RemoveTableListener(this);
  }
}

void CANVision::UpdateTable()
{
  if (m_table != nullptr) {
    m_table->PutString("~TYPE~", "CANVision");
    m_table->PutBoolean("Tracking Enabled", IsTrackingEnabled());
    // todo: confidence as a string
    m_table->PutNumber("Distance", GetDistanceInches());
  }
}

void CANVision::ValueChanged(ITable* source, llvm::StringRef key,
                  std::shared_ptr<nt::Value> value, bool isNew)
{
  if (key == "Tracking Enabled" && value->IsBoolean()) {
    value->GetBoolean() ? EnableTracking() : DisableTracking();
  }
}

std::string CANVision::GetSmartDashboardType() const
{
  return "CANVision";
}

