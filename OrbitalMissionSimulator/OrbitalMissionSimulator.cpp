#include <iostream>
#include <string>
#include "Satellite.h"
#include "MissionSimulator.h"

int main()
{
    std::string satelliteName;
    double altitudeKm;
    double massKg;
    int numberOfOrbits;

    std::cout << "===== Orbital Mission Simulator =====\n\n";

    std::cout << "Enter satellite name: ";
    std::getline(std::cin, satelliteName);

    std::cout << "Enter altitude (km): ";
    std::cin >> altitudeKm;

    std::cout << "Enter satellite mass (kg): ";
    std::cin >> massKg;

    std::cout << "Enter number of orbits to simulate: ";
    std::cin >> numberOfOrbits;

    if (satelliteName.empty() ||
        altitudeKm <= 0 ||
        massKg <= 0 ||
        numberOfOrbits <= 0)
    {
        std::cout << "\nInvalid mission parameters.\n";
        return 1;
    }

    Satellite satellite(
        satelliteName,
        altitudeKm,
        massKg
    );

    MissionSimulator simulator(satellite);

    std::cout << "\n===== Satellite Information =====\n";
    std::cout << "Name: " << satellite.getName() << '\n';
    std::cout << "Altitude: " << satellite.getAltitudeKm() << " km\n";
    std::cout << "Mass: " << satellite.getMassKg() << " kg\n";
    std::cout << "Orbital velocity: "
        << satellite.calculateOrbitalVelocity()
        << " km/s\n";
    std::cout << "Orbital period: "
        << satellite.calculateOrbitalPeriod()
        << " seconds\n";

    simulator.runSimulation(numberOfOrbits);
    simulator.printMissionReport();

    double newAltitude;

    std::cout << "\nEnter new altitude to adjust orbit (km): ";
    std::cin >> newAltitude;

    simulator.changeOrbitAltitude(newAltitude);

    simulator.printMissionReport();

    return 0;
}