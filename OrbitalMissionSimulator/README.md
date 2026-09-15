# Orbital Mission Simulator

A C++ console application that simulates basic satellite missions and calculates orbital parameters around Earth.

## Features

- Create a satellite with custom mission parameters
- Calculate orbital velocity
- Calculate orbital period
- Simulate multiple completed orbits
- Track elapsed mission time
- Dynamically change orbital altitude
- Recalculate orbital parameters after altitude changes
- Generate mission reports
- Export mission results to a text file
- Validate user input

## Technologies

- C++
- Object-Oriented Programming (OOP)
- Standard Library
- File I/O
- Mathematical calculations
- Visual Studio
- Git / GitHub

## Project Structure

- `Satellite` - stores satellite information and performs orbital calculations
- `MissionSimulator` - manages mission simulation, orbit changes, statistics, and reports
- `OrbitalMissionSimulator.cpp` - handles user input and application flow

## Orbital Calculations

The simulator calculates orbital velocity and orbital period using the satellite's altitude above Earth.

The calculations use:

- Earth radius: 6371 km
- Earth's gravitational parameter: 398600.4418 km³/s²

## Example

```text
Satellite: Explorer-1
Altitude: 600.00 km
Mass: 500.00 kg
Orbital velocity: 7.56 km/s
Orbital period: 5792.33 seconds
Completed orbits: 3
```

## Build

Open the Visual Studio solution and build the project using Visual Studio 2022.

## Future Improvements

- Elliptical orbit simulation
- Multiple satellites
- Fuel consumption modeling
- Mission event tracking
- Unit tests
- Graphical visualization of satellite orbits

## Author

Chingiz Dadashev