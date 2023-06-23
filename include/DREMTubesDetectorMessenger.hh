//**************************************************
// \file DREMTubesDetectorMessenger.hh
// \brief: Definition of DREMTubesDetectorMessenger class
// \author: Andreas Loeschcke Centeno (University of Sussex)
// \start date: 25 June 2023
//**************************************************

//Prevent including header multplie times
//
#ifndef DREMTubesDetectorMessenger_h
#define DREMTubesDetectorMessenger_h 1

//Includers from Geant4
#include "G4UImessenger.hh"

class DREMTubesDetectorConstruction;
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

class DREMTubesDetectorMessenger : public G4UImessenger
{
 public:
  DREMTubesDetectorMessenger(DREMTubesDetectorConstruction*);
  ~DREMTubesDetectorMessenger();

  /// Invokes appropriate methods based on the typed command
  virtual void SetNewValue(G4UIcommand*, G4String) final;
  /// Retrieves the current settings
  virtual G4String GetCurrentValue(G4UIcommand*) final;

 private:
  /// Detector construction to setup
  DREMTubesDetectorConstruction* fDetector = nullptr;
  /// Command to set the directory common to all messengers in this example
  /// /Par03
  G4UIdirectory* fExampleDir = nullptr;
  /// Command to set the directory for detector settings /Par03/detector
  G4UIdirectory* fDetectorDir = nullptr;
  /// Command to set the detector horizontal rotation
  G4UIcmdWithADoubleAndUnit* fDetectorHorizRotCmd = nullptr;
};

#endif
