#include "greathalt.h"

Garage::Garage()
{
}

Garage::Garage(string parkingMapFile, string dbName)
{
}

Garage::~Garage()
{
}

bool Garage::allotParkingSlot(string vNumber, string lNumber, char norDis)
{
}

bool Garage::vacateParkingSlot(string vNumber)
{
}

bool Garage::searchVehicleHistory(string vNumber)
{
}

void Garage::specificFloorAvailability(int fNumber, int& normalCount, int& disabledCount)
{
}

void Garage::allFloorsAvailability(int& normalCount, int& disabledCount)
{
}

void Garage::specificFloorOccupancy(int fNumber, int& normalCount, int& disabledCount)
{
}

void Garage::allFloorsOccupancy(int& normalCount, int& disabledCount)
{
}

void Garage::parkingFeesCollection(string strStartDate, string strEndDate, int& parkingFeesAmount)
{
}

int Garage::calculateParkingFine(time_t enTime, time_t exTime)
{
}

void Garage::fineCollection(string strStartDate, string strEndDate, int& fineAmount)
{
}

void Garage::displayAllDatabaseEntries()
{
}