//Jianqiang Hao
//CS202
//prog1
//10/17/18
//using object oriented programming to
//simulate the car in the lanes



#include "lane.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


//constructor
Lane :: Lane(int location, bool flag):light(flag)
{
        this->location =location;
        head = NULL;
}


// add the car in the lane
void Lane::addCar(Car *my_car){
        if(head == NULL)
        {
                head = my_car;
		return;
        }
        else{
                my_car->set_next(head->get_next());
                head->set_next(my_car);
        }
}



// destructor
// data member: Car*head, stoplight light
Lane :: ~Lane()
{
}



// get the head pointer in the lane
Car* Lane :: get_head()
{
	return head;
}


//set the head in the lane
void Lane :: set_head(Car *car)
{
	head= car;
}


// get the location in the lane 
int Lane :: get_location()
{
	return location;
}



//get the information that if the car can pass 
bool Lane :: get_sl_pass()
{
	return light.get_pass();
}

