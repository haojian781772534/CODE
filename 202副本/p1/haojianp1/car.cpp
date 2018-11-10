//Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented programming to 
//simulate the car in the lanes





#include "car.h"
#include "map.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
class map;
//constructor
Car :: Car( int spd, char *car_name, int loca,bool mov): Location(loca),speed(spd),status(mov)
{
        name = new char[strlen(car_name)+1];
        strcpy(name, car_name);

}



//destructor
Car::~Car(){
        speed = 0;
        delete []name;
        name=NULL;
        status=false;
}



//transmit the location to other class
void Car :: setLocation(int loca)
{
        location= loca;
}


//get the information of Location in the class car
int Car :: getterLocation()
{
        return location;
}



//move the car to other lanes, first we need to observe the stoplight
//in the stoplight, 0 is Green light, 1 is Red light
//when stoplight is 1(Red), we can not move the car 
//when stoplight is 0(Green), we can can move the car
void Car::move_car(int location, map &Map){
	if(location == this->location)
	{
		cout<<"You are in this ane now."<<endl;
		return;
	}	
	else{
		Car *&&self = this;
		Map.move_car(location, self);	
	}
}



// get the next pointer 
Car* Car ::get_next()
{
	return next;
}



// set the next pointer
void Car :: set_next(Car *car)
{
	next=car;
}



// get the naem of the car
char* Car :: get_name()
{
	return name;
}
