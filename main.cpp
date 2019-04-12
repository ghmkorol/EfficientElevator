/**
 * S19 CSCI 332 Design and Analysis of Algorithms
 * 
 * Project-2 Efficient Elevator Control
 * 
 * Simulation Driver
 * 
 * Phillip J. Curtiss, Assistant Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#include <cstdlib>
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <sstream>
#include <queue>

#include "Passenger.h"
#include "Elevator.h" // Elevator object class


using std::cout;
using std::cin; 
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::ifstream;
using std::vector;
using std::queue;

int main(int argc, char *argv[])
{
    // read from standard input as described in the project assignment
    // create the required number of Elevators and Passengers
    // populate queues and priority queues as needed
  
    int F = 0; //number of floors
    int eSize = 0; //number of elevators
    queue<Passenger> pickUpQueue;
    vector<Elevator> elist; // create a vector to hold elevators
  
  //start read data from file
    ifstream inFile;
    inFile.open("input.txt");
    std::string s;
    int lineNumber=0;
    while(getline(inFile, s))
    {
      lineNumber++;
      std::stringstream ss(s);
      vector<int> v;
      int val;
      while(ss >> val) v.push_back(val);
      
      if(lineNumber==1){
	F=v.at(0);
	eSize=v.at(1);
	if(F<2){
	  cout << "Input file contains ERROR: Number of foolrs is < 2" << endl;
	  return EXIT_FAILURE;
	}
	if(eSize<1){
	  cout << "Input file contains ERROR: Number of elevators is < 1" << endl;
	  return EXIT_FAILURE;
	}
	elist = vector<Elevator>(eSize);
      }
      else if(lineNumber==2){

	for(int i=0;i<(int)v.size();i++){
	  if(v.at(i)<1 || v.at(i)>F)
	    cout << "Input file contains ERROR: Starting positions of elevators out of range" << endl;
	  elist.at(i).setFloor(v.at(i));
	}
      }
      else if(lineNumber>2){
	for(int i=1;i<(int)v.size();i++){
	 Passenger p(v.at(0),v.at(i));
	 pickUpQueue.push(p);
	}
      }
      
    }
    inFile.close();
    //stop read data from file
/////////////////////////////////////////////////////////////////////////////////////////////    
    
    
    int time=0;
    while(true)
    {
      bool isBreak=1;
      if((int)pickUpQueue.size()>0)isBreak=0;
//       for(int i=0;i<eSize;i++){
// 	if(elist.at(i).getSize()>0)isBreak=0;
//       }
      if(isBreak)break;
      
     
     //....................start assign passangers to the elevators ....................
     for(int i=0;i<eSize;i++){
        if((int)pickUpQueue.size()==0) break; 
	Passenger p = pickUpQueue.front();
	pickUpQueue.pop();
	p.setStartTime(time);
	
	int elevatorIndex=0;
	int minPath=999;
	int minNStops=999;
	for(int j=0;j<eSize;j++){
	 Elevator temp_e = elist.at(j);
	 //temp_e.addPassenger(p);
	 int ePath=temp_e.getPathLength();
	 int eNstops=temp_e.getNStops();
	 if(minPath>ePath){
	    minPath=ePath;
	   elevatorIndex=j;
	  }
	 else if(minPath==temp_e.getPathLength()){
	   if(minNStops>eNstops)
	   {minPath=ePath;
	     elevatorIndex=j;}
	  }
         }
	 elist.at(elevatorIndex).addPassenger(p);
	
      } 
      //............................end assign passangers to the elevators......................
      
      
      
      for(int i=0;i<eSize;i++){
	cout << i <<" passangers in the elevator: " << elist.at(i).getSize() << endl;
      }
      
      
      time++;
	
      //............................start move the elevators................................
      //............................start move the elevators................................
	
      
    }
    
    

    // loop through the request queues - generated from input
    // and modify queues and priority queues as needed
    // make sure you move - at each iteration step - the 
    // elevators to their next destination floor in their priority queue
    // remember - it takes no time to travel in our building

    // each time an elevator stops at a floor
    // process those leaving, those getting on the elevator

    // continue loop until no more requests and all passenger are
    // free from the elevators
    
    
    
    
    
    return EXIT_SUCCESS;
}