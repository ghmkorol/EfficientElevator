/**
 * S19 CSCI 332 Design and Analysis of Algorithms
 * 
 * Project-2 Efficient Elevator Control
 * 
 * Passenger Object Implementation
 * 
 * Phillip J. Curtiss, Assistant Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef PASSENGER_IMP
#define PASSENGER_IMP

#include <memory>
#include <functional>
#include <algorithm>

#include "Passenger.h"

using std::shared_ptr;
using std::make_shared;

Passenger::Passenger():from(-1),to(-1),startTime(-1),boardingTime(-1),endTime(-1),isOnBoard_(0),ID(-1),shifts(0)
{
  
}

Passenger::Passenger(int f,int t):from(f),to(t),startTime(-1),boardingTime(-1),endTime(-1),isOnBoard_(0),ID(-1),shifts(0)
{
  
}

int Passenger::getPickUpFloor() const
{
  return from;
}

int Passenger::getDestination() const
{
  return to;
}

int Passenger::getCurrentGoal() const
{
  if(isOnBoard_)
    return to;
  else
    return from;
}

int Passenger::getShifts() const
{
  return shifts;
}

int Passenger::getID() const
{
  return ID;
}

void Passenger::setID(const int id)
{
  ID=id;
}

bool Passenger::isOnBoard() const
{
  return isOnBoard_;
}

void Passenger::setStartTime(const int starttime)
{
  startTime=starttime;
}


void Passenger::takeOnBoard(const int boardingtime)
{
  isOnBoard_=true;
  boardingTime=boardingtime;
}


#endif