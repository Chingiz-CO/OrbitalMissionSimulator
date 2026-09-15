#include "MissionSimulator.h"
#include <iostream>
#include <iomanip>
#include <fstream>

MissionSimulator::MissionSimulator(const Satellite& satellite)
    : satellite_(satellite),
    elapsedTimeSeconds_(0.0),
    completedOrbits_(0)
{
}

void MissionSimulator::runSimulation(int numberOfOrbits)
{
    if (numberOfOrbits <= 0)
    {
        std::cout << "Number of orbits must be greater than zero.\n";
        return;
    }

    double orbitalPeriod = satellite_.calculateOrbitalPeriod();

    std::cout << "\nStarting mission simulation...\n";

    for (int orbit = 1; orbit <= numberOfOrbits; orbit++)
    {
        elapsedTimeSeconds_ += orbitalPeriod;
        completedOrbits_++;

        std::cout << "Orbit " << orbit
            << " completed after "
            << std::fixed << std::setprecision(2)
            << elapsedTimeSeconds_
            << " seconds.\n";
    }

    std::cout << "Simulation completed.\n";
}

void MissionSimulator::printMissionReport() const
{
    std::cout << "\n===== Mission Report =====\n";
    std::cout << "Satellite: " << satellite_.getName() << '\n';
    std::cout << "Altitude: " << satellite_.getAltitudeKm() << " km\n";
    std::cout << "Mass: " << satellite_.getMassKg() << " kg\n";
    std::cout << "Orbital velocity: "
        << satellite_.calculateOrbitalVelocity() << " km/s\n";
    std::cout << "Orbital period: "
        << satellite_.calculateOrbitalPeriod() << " seconds\n";
    std::cout << "Completed orbits: " << completedOrbits_ << '\n';
    std::cout << "Mission elapsed time: "
        << elapsedTimeSeconds_ << " seconds\n";
}

double MissionSimulator::getElapsedTimeSeconds() const
{
    return elapsedTimeSeconds_;
}

int MissionSimulator::getCompletedOrbits() const
{
    return completedOrbits_;
}

void MissionSimulator::changeOrbitAltitude(double newAltitudeKm)
{
    if (newAltitudeKm <= 0)
    {
        std::cout << "Invalid altitude.\n";
        return;
    }

    satellite_.setAltitudeKm(newAltitudeKm);

    std::cout << "\nOrbit altitude changed to "
        << newAltitudeKm
        << " km.\n";

    std::cout << "New orbital velocity: "
        << satellite_.calculateOrbitalVelocity()
        << " km/s\n";

    std::cout << "New orbital period: "
        << satellite_.calculateOrbitalPeriod()
        << " seconds\n";
}

void MissionSimulator::saveMissionReport(const std::string& filename) const
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Unable to save mission report.\n";
        return;
    }

    file << "===== Mission Report =====\n";
    file << "Satellite: " << satellite_.getName() << '\n';
    file << "Altitude: " << satellite_.getAltitudeKm() << " km\n";
    file << "Mass: " << satellite_.getMassKg() << " kg\n";
    file << "Orbital velocity: "
        << satellite_.calculateOrbitalVelocity() << " km/s\n";
    file << "Orbital period: "
        << satellite_.calculateOrbitalPeriod() << " seconds\n";
    file << "Completed orbits: " << completedOrbits_ << '\n';
    file << "Mission elapsed time: "
        << elapsedTimeSeconds_ << " seconds\n";

    file.close();

    std::cout << "\nMission report saved to " << filename << '\n';
}