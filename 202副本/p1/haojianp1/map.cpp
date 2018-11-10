//Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented proggramming to
//simulate the car in the lanes

#include "map.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

//constructor
map :: map(int size)
{
        lane_size= size;
        list = new Lane *[lane_size];
	srand(time(0));
	bool rand_0_1 = rand() % 2;
        for(int i=0; i<lane_size; i++)
        {
		rand_0_1 = rand() % 2;
                list[i]= new Lane(i, rand_0_1);
        }

}


//destructor
map :: ~map()
{
	for(int i=0; i<lane_size;i++){
		delete list[i];
	}
	delete []list;
}



//add the car in the map
void map :: addCar(Car *my_car)
{
	if(my_car->getterLocation() > lane_size || my_car->getterLocation() < 0){
		cout<<"The lane is not in this map"<<endl;
		return;
	}
	if(list[my_car->getterLocation()]->get_sl_pass() == 1){
		cout<<"The stoplight of this lane is red"<<endl;
		return;
	}
        list[my_car->getterLocation()]->addCar(my_car);
}


// display car's information in the map
void map::display_car(Car *head){
        if(!head){
                cout<<"^";
                return;
        }
        cout<<"Car:"<<head->get_name()<<":"<<head->getterLocation()<<"->";
        display_car(head->get_next());
}



//display all information in the map
void map :: display()
{
        for(int i=0;i<lane_size;i++){
                cout<<"Lane"<<list[i]->get_location()<<",sl:"<<list[i]->get_sl_pass()<<"->";
                display_car(list[i]->get_head());
                cout<<endl;
        }
}


//move the car to other lanes
//in the stoplight, 0 is Green light, 1 is Red light
//when stoplight is 1(Red), we can not move the car 
//when stoplight is 0(Green), we can can move the car
void map::move_car(int location, Car *instance){
	if(location > lane_size || location < 0){
		cout<<"The lane is not in this map"<<endl;
		return;
	}
	if(list[location]->get_sl_pass() == 1){
		cout<<"The stoplight of this lane is red"<<endl;
		return;
	}
	int now = instance->getterLocation();
	instance->setLocation(location);
	Car *temp = list[now]->get_head();
	if(list[now]->get_head() == NULL){
		cout<<"The car is not on this lane"<<endl;
		return;
	}
	if(strcmp(instance->get_name(),temp->get_name())==0){
		list[now]->set_head(temp->get_next());
		instance->set_next(list[location]->get_head());
		list[location]->set_head(instance);
		return;
	}
	char *iname = instance->get_name();
	char *tname = temp->get_next()->get_name();
	while( temp->get_next() && strcmp(iname,tname)!=0){
		temp = temp -> get_next();
	}
	if(strcmp(iname,tname) == 0){
		temp->set_next(temp->get_next()->get_next());
		instance->set_next(list[location]->get_head());
		list[location]->set_head(instance);
		return;
	}
	else{
		cout<<"The car is not on this Lane"<<endl;
		return;
	}
	
}
