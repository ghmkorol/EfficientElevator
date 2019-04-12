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

#include <functional> // for function prototype
#include <vector> // for vector from STL
#include <queue> // for priority_queue from STL

#include "Passenger.h"

using std::priority_queue;
using std::vector;
using std::function;

// Create a custom type from the priority_queue STL
// - first parameter of template - type of items to be held in priority queue
// - second parameter the internal container for storing queue items
// - third parameter the custom comparator that will emit the priority causing 
//   the items to be ordered in the container
//typedef priority_queue<int, vector<int>, function<bool(int, int)> > CustomPQ;
typedef priority_queue<Passenger, vector<Passenger>, function<bool(Passenger, Passenger)> > CustomPQ;

/**
 * Represents an elevator containing a priority queue of its passangers
 * custom comparator for ordering the passengers in the queue
 */
class Elevator
{
    private:
        /********** Static Members **********/

        // Holds the floor a given instance elevator is on
        //static 
        vector<Passenger> passengers;
	static int deep;
	static int hight;
        
        // Custom comparator used to order the passengers 
        // in the elevator - has acces to the floor vector
        static bool Comp(const Passenger &, const Passenger &);

        /********** Non-Static Members **********/

        // Reference to the priority queue for this elevator instance
        CustomPQ Ele_pq;
	int floor;
	int IDcounter;
  
    public:
        /********** Static Members **********/

        // Returns the size of the floor vector 
        // should equal the number of elevator instances
        int getSize();

        /********** Non-Static Members **********/

        // Default constructor
        Elevator();

        // get the current floor of this instance
        int getFloor() const;
        // set the current floor of this instance
        void setFloor(const int floor);
	
	void addPassenger(Passenger p);
	void checkForExit();
	void checkForEnter();
	void move();
	
	void updateDeepHight();
	int getPathLength();
	int getNStops();
	
}; // end Elevator Class
