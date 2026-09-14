#pragma once
#include <string>

class Satellite
{
private:
    std::string name_;
    double altitudeKm_;
    double massKg_;

public:
    Satellite(const std::string& name, double altitudeKm, double massKg);

    const std::string& getName() const;
    double getAltitudeKm() const;
    double getMassKg() const;

    void setAltitudeKm(double altitudeKm);

    double calculateOrbitalVelocity() const;
    double calculateOrbitalPeriod() const;
};