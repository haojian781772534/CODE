//Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented proggramming to
//simulate the car in the lanes




#ifndef car_h
#define car_h
#include "location.h"
class map;
class Car : public Location		//class car is derived by class Location
{
        public:
                Car(int spd, char *name, int location,bool mov);		//constructor
                ~Car();								//destructor
                void setLocation(int loca);					//set the  location 
                int getterLocation();						//get the location information
                Car* get_next();						// get the next pointer 
                void set_next(Car *car);					//set the next pointer 	
                char * get_name();						//get the car name 
		void move_car(int location, map &Map);				//move the car to other lanes
        protected:
                int speed;		//car speed
                char *name;		//car name
                bool status;		// car status
                Car *next;		//next pointer
};
#endif
