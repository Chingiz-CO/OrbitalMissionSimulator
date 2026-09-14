#include "Satellite.h"
#include <cmath>

Satellite::Satellite(
    const std::string& name,
    double altitudeKm,
    double massKg)
    : name_(name),
    altitudeKm_(altitudeKm),
    massKg_(massKg)
{
}

const std::string& Satellite::getName() const
{
    return name_;
}

double Satellite::getAltitudeKm() const
{
    return altitudeKm_;
}

double Satellite::getMassKg() const
{
    return massKg_;
}

void Satellite::setAltitudeKm(double altitudeKm)
{
    altitudeKm_ = altitudeKm;
}

double Satellite::calculateOrbitalVelocity() const
{
    const double earthRadiusKm = 6371.0;
    const double gravitationalParameter = 398600.4418;

    double orbitalRadius = earthRadiusKm + altitudeKm_;

    return std::sqrt(gravitationalParameter / orbitalRadius);
}

double Satellite::calculateOrbitalPeriod() const
{
    const double earthRadiusKm = 6371.0;
    const double gravitationalParameter = 398600.4418;
    const double pi = 3.141592653589793;

    double orbitalRadius = earthRadiusKm + altitudeKm_;

    return 2.0 * pi *
        std::sqrt(std::pow(orbitalRadius, 3) / gravitationalParameter);
}