#pragma once


#include "Satellite.h"

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

    double getElapsedTimeSeconds() const;
    int getCompletedOrbits() const;
};