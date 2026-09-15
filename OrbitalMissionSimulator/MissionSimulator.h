#pragma once

#include "Satellite.h"
#include <string>

class MissionSimulator
{
private:
    Satellite satellite_;
    double elapsedTimeSeconds_;
    int completedOrbits_;

public:
    MissionSimulator(const Satellite& satellite);

    void runSimulation(int numberOfOrbits);
    void printMissionReport() const;
    void changeOrbitAltitude(double newAltitudeKm);
    void saveMissionReport(const std::string& filename) const;

    double getElapsedTimeSeconds() const;
    int getCompletedOrbits() const;
};