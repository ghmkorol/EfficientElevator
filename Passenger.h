/**
 * S19 CSCI 332 Design and Analysis of Algorithms
 * 
 * Project-2 Efficient Elevator Control
 * 
 * Passenger Object Definition
 * 
 * Phillip J. Curtiss, Assistant Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef PASSENGER_H
#define PASSENGER_H

#include <memory>
#include <functional>
#include <algorithm>

using std::shared_ptr;

class Passenger
{

private:   
  
   int from;
   int to;
   int startTime;
   int boardingTime;
   int endTime;
   bool isOnBoard_;
   int ID;//id in the elevator
   int shifts;
  
public:
      

   Passenger();
   Passenger(int f, int t);
   //Board time
   //floortime
   
   // Member functions in alphabetical order   
   int getBoardElevatorTime() const;
   int getPickUpFloor() const;
   int getDestination() const;
   int getEndFloorNumber() const;
   int getStartTime() const;
   int getCurrentGoal() const;
   int getShifts() const;
   void setStartTime(const int starttime);
   int getID() const;
   void setID(const int id);
   void takeOnBoard(const int boardingtime);
   bool isOnBoard() const;

}; // end class Passenger


#endif