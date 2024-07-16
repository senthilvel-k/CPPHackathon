#include "greathalt.h"
using namespace std;

ParkingSlot::ParkingSlot()
{
}

ParkingSlot::ParkingSlot(string vNumber, string lNumber, time_t enTime, time_t exTime)
{
    // Initialize with provided values
    vehicleNumber = vNumber;
    licenseNumber = lNumber;
    entryTime = enTime;
    exitTime = exTime;
}

string ParkingSlot::getVehicleNumber()
{
    return vehicleNumber;
}

string ParkingSlot::getLicenseNumber()
{
    return licenseNumber;
}

time_t ParkingSlot::getEntryTime()
{
    return entryTime;
}

time_t ParkingSlot::getExitTime()
{
    return exitTime;
}

void ParkingSlot::setVehicleNumber(string vNumber)
{
    vehicleNumber = vNumber;
}

void ParkingSlot::setLicenseNumber(string lNumber)
{
    licenseNumber = lNumber;
}

void ParkingSlot::setEntryTime(time_t t)
{
    entryTime = t;
}

void ParkingSlot::setExitTime(time_t t)
{
    exitTime = t;
}