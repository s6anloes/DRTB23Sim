//**************************************************
// \file DRTB23SimDetectorMessenger.cc
// \brief: Implementation of 
//         DRTB23SimDetectorMessenger class
// \author: Andreas Loeschcke Centeno (University of Sussex)
// \start date: 23 June 2023
//**************************************************

#include "DRTB23SimDetectorMessenger.hh"
#include "DRTB23SimDetectorConstruction.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithAString.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DRTB23SimDetectorMessenger::DRTB23SimDetectorMessenger(
  DRTB23SimDetectorConstruction* aDetector)
  : G4UImessenger()
  , fDetector(aDetector)
{
  fExampleDir = new G4UIdirectory("/DRTB23Sim/");
  fExampleDir->SetGuidance("UI commands specific to this example");

  fDetectorDir = new G4UIdirectory("/DRTB23Sim/detector/");
  fDetectorDir->SetGuidance("Detector construction UI commands");

  fDetectorHorizRotCmd =
    new G4UIcmdWithADoubleAndUnit("/DRTB23Sim/detector/setHorizontalRotation", this);
  fDetectorHorizRotCmd->SetGuidance(
    "Set horizontal rotation of platform and calorimeter");
  fDetectorHorizRotCmd->SetParameterName("HorizontalRotation", false);
  fDetectorHorizRotCmd->SetUnitCategory("Angle");
  fDetectorHorizRotCmd->AvailableForStates(G4State_PreInit);
  fDetectorHorizRotCmd->SetToBeBroadcasted(false);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DRTB23SimDetectorMessenger::~DRTB23SimDetectorMessenger()
{
  delete fDetectorHorizRotCmd;
  delete fDetectorDir;
  delete fExampleDir;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DRTB23SimDetectorMessenger::SetNewValue(G4UIcommand* aCommand,
                                         G4String aNewValue)
{
  if(aCommand == fDetectorHorizRotCmd)
  {
    fDetector->SetHorizontalRotation(fDetectorHorizRotCmd->GetNewDoubleValue(aNewValue));
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4String DRTB23SimDetectorMessenger::GetCurrentValue(G4UIcommand* aCommand)
{
  G4String cv;

  if(aCommand == fDetectorHorizRotCmd)
  {
    cv = fDetectorHorizRotCmd->ConvertToString(fDetector->GetHorizontalRotation(), "deg");
  }
  return cv;
}