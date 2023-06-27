//**************************************************
// \file DRTB23SimDetectorMessenger.hh
// \brief: Definition of DRTB23SimDetectorMessenger class
// \author: Andreas Loeschcke Centeno (University of Sussex)
// \start date: 25 June 2023
//**************************************************

//Prevent including header multplie times
//
#ifndef DRTB23SimDetectorMessenger_h
#define DRTB23SimDetectorMessenger_h 1

//Includers from Geant4
#include "G4UImessenger.hh"

class DRTB23SimDetectorConstruction;
class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;

/**
 * @brief Detector messenger.
 *
 * Provides UI commands to setup detector and readout geometry (prior to
 * initialization). Radius, length, and material of the detector, as well as
 * segmentation of the readout geometry can be changed.
 *
 */

class DRTB23SimDetectorMessenger : public G4UImessenger
{
 public:
  DRTB23SimDetectorMessenger(DRTB23SimDetectorConstruction*);
  ~DRTB23SimDetectorMessenger();

  /// Invokes appropriate methods based on the typed command
  virtual void SetNewValue(G4UIcommand*, G4String) final;
  /// Retrieves the current settings
  virtual G4String GetCurrentValue(G4UIcommand*) final;

 private:
  /// Detector construction to setup
  DRTB23SimDetectorConstruction* fDetector = nullptr;
  /// Command to set the directory common to all messengers in this example
  /// /Par03
  G4UIdirectory* fExampleDir = nullptr;
  /// Command to set the directory for detector settings /Par03/detector
  G4UIdirectory* fDetectorDir = nullptr;
  /// Command to set the detector horizontal rotation
  G4UIcmdWithADoubleAndUnit* fDetectorHorizRotCmd = nullptr;
};

#endif
