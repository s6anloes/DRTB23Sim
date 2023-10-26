//Namespace for test-beam geometry constants
//

#ifndef DRTB23SimGeoPar_h
#define DRTB23SimGeoPar_h

//Includers from Geant4
//
#include "G4SystemOfUnits.hh"
#include <numeric>

namespace { 

    // module constants
    constexpr G4int NofmodulesX = 10;
    constexpr G4int NofmodulesY = 10;
    // const int modflag[120]={-1,-1,-1,-1,-1,-1,-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,-1,-1,-1,-1,-1,-1,-1,
    //                    -1,-1,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,-1,-1,
    //                    30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,
    //                    -1,-1,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,-1,-1,
    //                    -1,-1,-1,-1,-1,-1,-1,74,75,76,77,78,79,80,81,82,83,-1,-1,-1,-1,-1,-1,-1};
    constexpr G4int modflag[100]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
                       10,11,12,13,14,15,16,17,18,19,
                       20,21,22,23,24,25,26,27,28,29,
    //                 30,31,32,33,34,35,36,37,38,39,
                       40,41,42,43,44,45,46,47,48,49,
                       50,51,52,53,54,55,56,57,58,59,
                       60,61,62,63,64,65,66,67,68,69,
                       70,71,72,73,74,75,76,77,78,79,
                       80,81,82,83,84,85,86,87,88,89,
                       90,91,92,93,94,95,96,97,98,99};
    constexpr G4int NoModulesSiPM=100;
    constexpr G4int SiPMMod[100]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
                       10,11,12,13,14,15,16,17,18,19,
                       20,21,22,23,24,25,26,27,28,29,
    //                 30,31,32,33,34,35,36,37,38,39,
                       40,41,42,43,44,45,46,47,48,49,
                       50,51,52,53,54,55,56,57,58,59,
                       60,61,62,63,64,65,66,67,68,69,
                       70,71,72,73,74,75,76,77,78,79,
                       80,81,82,83,84,85,86,87,88,89,
                       90,91,92,93,94,95,96,97,98,99};
    constexpr G4int NofFiberscolumn = 32;
    constexpr G4int NofFibersrow = 40;
    constexpr G4int NoModulesActive=100;
    constexpr G4double moduleZ = (2500.)*mm;
    constexpr G4bool irot=false;
    constexpr G4int NoFibersTower=NofFiberscolumn*NofFibersrow/2;

    // preshower constants
    constexpr G4double preshower_pos_x = 0.0*cm;
    constexpr G4double preshower_pos_y = 0.0*cm;
    constexpr G4double preshower_pos_z = -553.0*cm;

    // Comment on naming convention for housing variables:
    // length = direction along local z
    // height = direction along local y
    // width  = direction along local x
    // thickness = from context

    // platform constants
    constexpr G4double platform_radius = 3000*mm;    // Radius guessed for now
    constexpr G4double platform_half_height = 25*mm;     // Height guessed for now
    
    // bar/feet constants
    constexpr G4double bar_half_length = 40.0*cm/2;
    constexpr G4double bar_half_width  = 4.5*cm/2;
    constexpr G4double bar_half_height = 9.0*cm/2;
    constexpr G4double bar_wall_thickness = 10.0*mm;
    constexpr G4double bar_pos_from_front = 16.0*cm;

    // housing constants
    constexpr G4double housing_half_length = 345.5*cm/2;
    constexpr G4double housing_half_width  = 118.0*cm/2;
    constexpr G4double housing_half_height = 115.0*cm/2;
    constexpr G4double side_wall_thickness = 1.5*mm;
    constexpr G4double top_wall_thickness  = 1.4*mm;
    constexpr G4double bot_wall_thickness  = 10.0*mm;

    // support constants (longitudinal support below housing)
    constexpr G4double support_half_length = 163.5*cm/2;
    constexpr G4double support_half_height = 10.0*cm/2;
    constexpr G4double support_wall_thickness = 7.0*mm;

    // plastic cover constants
    constexpr G4double plastic_cover_full_length = 20.0*mm;
    constexpr G4double cutout_thickness = 4.5*mm;

}

#endif // DRTB23SimGeoPar_h
