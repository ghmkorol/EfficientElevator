/**
 * S19 CSCI332 Design and Analysis of Algorithms
 * 
 * Project - Efficient Elevator 
 * Custom Comparator for STL Priority Queue
 * 
 * Phillip J. Curtiss, Assistant Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#include <vector> // for vector from STL

using std::vector;

#include "Elevator.h" // Elevator Object class
#include "Passenger.h" // Passenger Object class

// reference to the vector in the elevator class
//extern
// vector<Passenger> Elevator::passengers;
extern int Elevator::deep;
extern int Elevator::hight;

/********** Static Methods **********/

/**
 * Compares two passenger objects and emits a bool
 * indicating which goes comes before the other
 * This method may refer to the static members of the
 * Elevator class, such as the floor vector, to help
 * determine the correct ordering of the passenger 
 * objects - required in the project. 
 * Example code uses integers to represent passengers
 * You should store the elevator id (and int) to the 
 * passenger object and use that as the index into the
 * floor vector
 */
bool Elevator::Comp(const Passenger &a, const Passenger &b)
{
    int gA = a.getCurrentGoal(); //current goal of a
    int gB = b.getCurrentGoal(); //current goal of b
    int shiftsA = a.getShifts();
    int shiftsB = b.getShifts();
    
    if(shiftsA>3||shiftsB>3){
      if(shiftsA>shiftsB){
	return false;
      }
      else if(shiftsA<shiftsB){
	return true;
      }
      else{
	return true;
      }
    }
    else{
      if(hight>abs(deep)){
	if(gA<gB){
	  return false;
	}
	else{
	  return true;
	}
      }
      else{
	if(gA<gB){
	  return true;
	}
	else{
	  return false;
	}
      }
    }
    

   
} // end Comp

void Elevator::updateDeepHight()
{
  
  if((int)passengers.size()==0){
    deep=0;
    hight=0;
  }
  else{
    for(int i=0;i<(int)passengers.size();i++){
      int g = passengers.at(i).getCurrentGoal();
      if( g-floor > hight) hight = g-floor;
      if(g-floor<deep)deep = g-floor;
    }
  }
}


/**
 * Returns the number of elements in the floor
 * vector, which should equal the number of 
 * elevator instances
 */
int Elevator::getSize()
{
    return passengers.size();
} // end getSize

/********** Non-Static Methods **********/

/**
 * Default constructor
 */
Elevator::Elevator()
{
    deep=0;
    hight=0;
    
    IDcounter=0;

    // add an element to the floor vector
    // for this instance
    floor=-1;

    // create a Custom Priority_queue for this instance
    // passing in the custom comparator static method
    Ele_pq = CustomPQ(Comp);
} // end Constructor

/********** Accessor Methods **********/



void Elevator::addPassenger(Passenger p)
{
  p.setID(IDcounter);
  IDcounter++;
  passengers.push_back(p);
  updateDeepHight();
  Ele_pq.push(p);
}

void Elevator::checkForExit()
{
    for(int i=0;i<(int)passengers.size();i++){
    Passenger p = passengers.at(i);
    }
}


/**
 * Get the floor this instance is on from 
 * the instance id
 */
int Elevator::getFloor() const
{
    return floor;
} // end getFloor

/********** Mutator Methods **********/

/**
 * Set the floor this instance is on
 * using the instance id
 */
void Elevator::setFloor(const int fl)
{
    floor = fl;
} // end setFloor

int Elevator::getNStops()
{
  vector<int> uniqueFoolrs;
  for(int i=0;i<(int)passengers.size();i++){
    Passenger p = passengers.at(i);
    if (std::find(uniqueFoolrs.begin(), uniqueFoolrs.end(), p.getCurrentGoal()) == uniqueFoolrs.end()) 
      uniqueFoolrs.push_back(p.getCurrentGoal());
    if(!(p.isOnBoard())){
     if (std::find(uniqueFoolrs.begin(), uniqueFoolrs.end(), p.getDestination()) == uniqueFoolrs.end()) 
      uniqueFoolrs.push_back(p.getDestination());
    }
  }
  return (int)uniqueFoolrs.size();
}

int Elevator::getPathLength()
{
  int distance=0;
  int f=floor;
  CustomPQ temp_pq=Ele_pq;
  while(!temp_pq.empty()) {
    Passenger p = temp_pq.top();
    if(p.isOnBoard()){
      distance+=abs(f-p.getCurrentGoal());
      f=p.getCurrentGoal();
      temp_pq.pop();
    }
    else{
      distance+=abs(f-p.getPickUpFloor());
      f=p.getCurrentGoal();
      temp_pq.pop();
      p.takeOnBoard(-1);
      temp_pq.push(p);
    }
  }
  
  return distance;
}

