//Jianqiang Hao
//CS202
//10/29/18
//Prog2
//design a program to support three transportatioa tools 
//using object oriented programming



#include"car.h"
#include<iostream>
#include<cctype>
#include<cstring>

#define max 50

using namespace std;


//constructor
car:: car() : intersection(NULL), id_num(0), cost_hour(0.0),repair(false)
{
	read();
}



//constructor
car:: car(char *name, int id_num, float cost_hour, bool repair):intersection(NULL), id_num(id_num),cost_hour(cost_hour),repair(repair)
{
	this->intersection=new char[strlen(intersection)+1];
	strcpy(this->intersection, intersection);
}



//copy constructor
car :: car(const car&to_copy):intersection(NULL),id_num(to_copy.id_num),cost_hour(to_copy.cost_hour),repair(to_copy.repair)
{
	if(!to_copy.intersection)
		return;
	intersection= new char[strlen(to_copy.intersection)+1];
	strcpy(intersection, to_copy.intersection);
}



//destructor
car :: ~car()
{
	if(intersection)
		delete []intersection;
	intersection=NULL;
	id_num=0;
	cost_hour=0.0;
	repair=false;

}



//display all information in the class car
int car:: display()
{
	cout<<"the intersection where it is the closest:"<<intersection<<endl;
	cout<<"ID number is:"<<id_num<<endl;
	cout<<"the cost per hour:"<<cost_hour<<endl;
	cout<<"the status of the vehicle is(0 is ok, 1 is not available):"<<repair<<endl;

	return 0;
}


// users enter the information
void car :: read()
{
	char temp[max];
	cout<<"enter the intersection(char*):";
	cin.get(temp, max,'\n');
	intersection=new char[strlen(temp)+1];
	strcpy(intersection,temp);

	cout<<"enter the ID number(int):";
	cin>>id_num;
	cin.ignore(100,'\n');

	cout<<"enter the cost per hour(float):";
	cin>>cost_hour;
	cin.ignore(100,'\n');

	char r='\0';
	cout<<"the status of the vehicle(y/n):";
	cin>>r;
	cin.ignore(100,'\n');
	r=tolower(r);
	r=='y'?repair=true:repair=false;
}



























