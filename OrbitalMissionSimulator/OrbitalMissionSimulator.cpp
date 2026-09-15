#include <iostream>
#include <string>
#include "Satellite.h"
#include "MissionSimulator.h"
#include <limits>

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

    while (!(std::cin >> altitudeKm) || altitudeKm <= 0)
    {
        std::cout << "Invalid altitude. Enter a positive number: ";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter satellite mass (kg): ";

    while (!(std::cin >> massKg) || massKg <= 0)
    {
        std::cout << "Invalid mass. Enter a positive number: ";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter number of orbits to simulate: ";

    while (!(std::cin >> numberOfOrbits) || numberOfOrbits <= 0)
    {
        std::cout << "Invalid number of orbits. Enter a positive integer: ";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (satelliteName.empty())
    {
        std::cout << "\nSatellite name cannot be empty.\n";
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

    simulator.saveMissionReport("mission_report.txt");

    return 0;
}