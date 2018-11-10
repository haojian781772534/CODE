//Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented proggramming to
//simulate the car in the lanes



#ifndef map_h
#define map_h
#include "lane.h"
#include "car.h"
class Lane;
class map							//class map
{
        public:
                map(int size);					//constructor
                ~map();						//destructor
                void addCar(Car *my_car);			//add a car in the map;
                void display();					//display all information in the map
                void display_car(Car *head);			//display car's information in a lane
		void move_car(int location, Car *instance);	// move the car to other lanes
        private:
                int lane_size;					//the number of lanes in the map
                Lane **list;
};
#endif
