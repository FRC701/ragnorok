/*
 * CANVision.h
 */

#ifndef SRC_DEVICES_CANVISION_H_
#define SRC_DEVICES_CANVISION_H_

#include "ErrorBase.h"
#include "LiveWindow/LiveWindowSendable.h"
#include "tables/ITableListener.h"

#include "CANPiVision.h"

// todo: Is there an abstract class here? Not for now.

class CANVision
: public frc::ErrorBase
, public frc::LiveWindowSendable
, public ITableListener
{
public:
  explicit CANVision(int deviceNumber);
  virtual ~CANVision();

  void EnableTracking();
  void DisableTracking();
  bool IsTrackingEnabled() const;

  enum Confidence {
      kConfidenceLow = 0    // What target? I don't see a target.
    , kConfidenceMedium = 1 // Oh that target? I can see it but it's not centered well.
    , kConfidenceHigh = 2   // That's the target! Fire!
  };

  /*
   * Return the confidence that the distance can be used for shooting
   */
  Confidence GetConfidence() const;
  int GetDistanceInches() const;


  // Support LiveWindow.
  void ValueChanged(ITable* source, llvm::StringRef key,
                    std::shared_ptr<nt::Value> value, bool isNew) override;
  void UpdateTable() override;
  void StartLiveWindowMode() override;
  void StopLiveWindowMode() override;
  std::string GetSmartDashboardType() const override;
  void InitTable(std::shared_ptr<ITable> subTable) override;
  std::shared_ptr<ITable> GetTable() const override;

private:
  CANPiVision vision;
  int m_deviceNumber;
  bool m_tracking;
  std::shared_ptr<ITable> m_table;
};

#endif /* SRC_DEVICES_CANVISION_H_ */
