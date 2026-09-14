#include <iostream>
#include "Satellite.h"

int main()
{
    Satellite satellite("TestSat", 400.0, 500.0);

    std::cout << "Satellite: " << satellite.getName() << '\n';
    std::cout << "Orbital velocity: "
        << satellite.calculateOrbitalVelocity()
        << " km/s\n";

    std::cout << "Orbital period: "
        << satellite.calculateOrbitalPeriod()
        << " seconds\n";

    return 0;
}