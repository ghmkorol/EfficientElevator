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
#include <iostream>

#include "Passenger.h"

using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;

Passenger::Passenger():from(-1),to(-1),elevator(0),startTime(-1),boardingTime(-1),endTime(-1),isOnBoard_(0),ID(-1),shifts(0),requestNr(0)
{
  
}

Passenger::Passenger(int f,int t,int req):from(f),to(t),elevator(0),startTime(-1),boardingTime(-1),endTime(-1),isOnBoard_(0),ID(-1),shifts(0),requestNr(req)
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

void Passenger::PrintSummary()
{
  printf("Request # %d, from %d to %d, elevator %d\n",requestNr,from,to,elevator);
  
}


#endif