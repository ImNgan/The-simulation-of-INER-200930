# The-simulation-of-INER-200930
## Estimating the cross-section of Steel304 target from proton beam ##

1. Gate/Geant4 v9.0 application
2. ROOT

## Set-up ##

- Proton beams of energies 15 MeV, 30 MeV start at the beam pipe to the 5x5x0.1 mm^3 target at 45 degree.
- An ABS attenuator is between the beam pipe and the target to have many different energies entering the target for the simulation

## Physics ##

- Physics list: QGSP_BIC_HP_EMY.
- Phase Space Actor: The information of particles was obtained at the target.

## Output ##

- The particles entering the target and the secondary particles in the target is scored via Phase Space Actor to estimate the cross-section for the simulation. (main_target.mac)
- The Phase Space at the target using at a source (main_read_target.mac)
