//Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented proggramming to
//simulate the car in the lanes



#ifndef lane_h
#define lane_h
#include "location.h"
#include "car.h"
#include "stoplight.h"
class Location;
class car;

class Lane: public Location				//class car is derived by class Location
{
        public:
                Lane(int location, bool flag);		// constructor
                ~Lane();				//destructor
                Car *get_head();			// get the head pointer
                void set_head(Car *car);		//set the head pointer
                int get_location();			// get the location information
		bool get_sl_pass();			//get the information if stoplight can allow the car pass

                void addCar(Car *car);			// add the car in the lane
        protected:
                Car *head;		//head pointer
                stoplight light;
};
#endif
