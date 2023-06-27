//**************************************************
// \file DREMTubesDetectorMessenger.cc
// \brief: Implementation of 
//         DREMTubesDetectorMessenger class
// \author: Andreas Loeschcke Centeno (University of Sussex)
// \start date: 23 June 2023
//**************************************************

#include "DREMTubesDetectorMessenger.hh"
#include "DREMTubesDetectorConstruction.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithAString.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DREMTubesDetectorMessenger::DREMTubesDetectorMessenger(
  DREMTubesDetectorConstruction* aDetector)
  : G4UImessenger()
  , fDetector(aDetector)
{
  fExampleDir = new G4UIdirectory("/DREMTubes/");
  fExampleDir->SetGuidance("UI commands specific to this example");

  fDetectorDir = new G4UIdirectory("/DREMTubes/detector/");
  fDetectorDir->SetGuidance("Detector construction UI commands");

  fDetectorHorizRotCmd =
    new G4UIcmdWithADoubleAndUnit("/DREMTubes/detector/setHorizontalRotation", this);
  fDetectorHorizRotCmd->SetGuidance(
    "Set horizontal rotation of platform and calorimeter");
  fDetectorHorizRotCmd->SetParameterName("HorizontalRotation", false);
  fDetectorHorizRotCmd->SetUnitCategory("Angle");
  fDetectorHorizRotCmd->AvailableForStates(G4State_PreInit);
  fDetectorHorizRotCmd->SetToBeBroadcasted(false);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DREMTubesDetectorMessenger::~DREMTubesDetectorMessenger()
{
  delete fDetectorHorizRotCmd;
  delete fDetectorDir;
  delete fExampleDir;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DREMTubesDetectorMessenger::SetNewValue(G4UIcommand* aCommand,
                                         G4String aNewValue)
{
  if(aCommand == fDetectorHorizRotCmd)
  {
    fDetector->SetHorizontalRotation(fDetectorHorizRotCmd->GetNewDoubleValue(aNewValue));
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4String DREMTubesDetectorMessenger::GetCurrentValue(G4UIcommand* aCommand)
{
  G4String cv;

  if(aCommand == fDetectorHorizRotCmd)
  {
    cv = fDetectorHorizRotCmd->ConvertToString(fDetector->GetHorizontalRotation(), "deg");
  }
  return cv;
}