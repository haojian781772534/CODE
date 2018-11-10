//Jianqiang Hao
//CS202
//10/29/18
//Prog2
//design a program to support three transportatioa tools 
//using object oriented programming



#include<iostream>
#include<cctype>
#include<cstring>
#include"scooter.h"

using namespace std;

//constructor
scooter:: scooter():battery_level(0)
{
//	read();
}



//constructor
scooter:: scooter(char *intersection, int id_num, float cost_hour, bool repair, int battery_level): car(intersection, id_num, cost_hour, repair),battery_level(battery_level)
{
}


//destructor
scooter:: ~scooter()
{
}


//users enter the information
void scooter :: read()
{
	cout<<" the car's battery level is(int):";
	cin>>battery_level;
	cin.ignore(100,'\n');
}


//display all information 
int scooter ::display()
{
	car:: display();
	cout<<"the battery level is: "<<battery_level<<endl;

	return 0;
}



//get the id number of the scooter 
int scooter :: return_id()
{
	return this->id_num;
}
