//Jianqiang Hao
//CS202
//10/29/18
//Prog2
//design a program to support three transportatioa tools 
//using object oriented programming


#include<iostream>
#include<cctype>
#include<cstring>
#include"zipcar.h"
#define max 50

using namespace std;


//constructor
zip_car :: zip_car(): gas_level(0), licence_plate(NULL)
{
//	read();
}



//constructor
zip_car :: zip_car(char *intersection, int id_num, float cost_hour, bool repair, int gas_level, char *licence_plate): car(intersection, id_num, cost_hour, repair),gas_level(gas_level), licence_plate(NULL)
{
	licence_plate= new char[strlen(licence_plate)+1];
	strcpy(this->licence_plate, licence_plate);
}


//copy constructor
zip_car :: zip_car(const zip_car &copy_from):car(copy_from),gas_level(0),licence_plate(NULL)
{
	if(!copy_from.licence_plate)
		return ;
	gas_level = copy_from.gas_level;
	licence_plate=new char[strlen(copy_from.licence_plate)+1];
	strcpy(licence_plate, copy_from.licence_plate);
}



//destructor
zip_car :: ~zip_car()
{
	if(licence_plate)
		delete []licence_plate;
	licence_plate=NULL;

	gas_level=0;
}


//users enter the information about zip car
void zip_car:: read()
{
	char temp[max];
	cout<<"licence_plate is(char*):";
	cin.get(temp, max, '\n');
	cin.ignore(100,'\n');
	licence_plate=new char[strlen(temp)+1];
	strcpy(licence_plate, temp);

	cout<<"enter the level of gas(int):";
	cin>>gas_level;
	cin.ignore(100,'\n');
}



//display all information in the zipcar
int zip_car:: display()
{
	car ::display();
	cout<<"gas level is:"<<gas_level<<endl;

	cout<<"licence plate is:"<<licence_plate<<endl;
	return 0;
}



//get the id number form zip car
int zip_car :: return_id()
{
	return this->id_num;
}
















