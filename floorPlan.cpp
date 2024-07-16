#include "greathalt.h"
using namespace std;

FloorPlan::FloorPlan()
{
    floorNumber = 0; 
    floorName = "";
    numberOfNormalParkingSlots = 0;
    numberOfDisabledParkingSlots = 0;
    ptrToArrayOfNormalParkingSlots = nullptr;
    ptrToArrayOfDisabledParkingSlots = nullptr;
}

FloorPlan::FloorPlan(int fnum, string fName, int numSlots, int numDisabledSlots)
{
    floorNumber = fnum; 
    floorName = fName;
    numberOfNormalParkingSlots = numSlots;
    numberOfDisabledParkingSlots = numDisabledSlots;
    ptrToArrayOfNormalParkingSlots = new ParkingSlot[numSlots];
    ptrToArrayOfDisabledParkingSlots = new ParkingSlot[numDisabledSlots];

}

int FloorPlan::getFloorNumber()
{
    return floorNumber;
}

string FloorPlan::getFloorName()
{
    return floorName;
}

int FloorPlan::getNumberOfNormalParkingSlots()
{
    return numberOfNormalParkingSlots;
}

int FloorPlan::getNumberOfDisabledParkingSlots()
{
    return numberOfDisabledParkingSlots;
}

ParkingSlot * FloorPlan::getPtrToArrayOfNormalParkingSlots()
{
    return ptrToArrayOfNormalParkingSlots;
}
        	
ParkingSlot * FloorPlan::getPtrToArrayOfDisabledParkingSlots()
{
    return ptrToArrayOfDisabledParkingSlots;
}