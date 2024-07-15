#include "greathalt.h"
using namespace std;



FloorPlan::FloorPlan()
{
}

FloorPlan::FloorPlan(int fnum, string fName, int numSlots, int numDisabledSlots)
{
    floorNumber = fnum;
    floorName   = fName;
    numberOfNormalParkingSlots = numSlots;
    numberOfDisabledParkingSlots = numDisabledSlots;
}

int FloorPlan::getFloorNumber()
{
}

string FloorPlan::getFloorName()
{
}

int FloorPlan::getNumberOfNormalParkingSlots()
{
}

int FloorPlan::getNumberOfDisabledParkingSlots()
{
}

ParkingSlot * FloorPlan::getPtrToArrayOfNormalParkingSlots()
{
}
        	
ParkingSlot * FloorPlan::getPtrToArrayOfDisabledParkingSlots()
{
}