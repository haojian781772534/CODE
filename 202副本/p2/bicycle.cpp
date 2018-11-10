//Jianqiang Hao
//CS202
//10/29/18
//Prog2
//design a program to support three transportatioa tools 
//using object oriented programming


#include<iostream>
#include<cctype>
#include<cstring>
#include"bicycle.h"

using namespace std;

//constructor
bicycle:: bicycle():password(0)
{
//	read();
}


//constructor
bicycle:: bicycle(char *intersection, int id_num, float cost_hour, bool repair, int password):car(intersection, id_num, cost_hour, repair),password(password)
{
}


//destructor
bicycle :: ~bicycle()
{
	password=0;
}



//display all information in the class bicycle
int bicycle:: display()
{
	car::display();

	cout<<"the password is:"<<password<<endl;
	return 1;
}



//user to input information
void bicycle:: read()
{
	cout<<"enter the password(int):";
	cin>>password;
	cin.ignore(100,'\n');

}



//get the ID information 
int bicycle :: return_id()
{
	return this->id_num;
}
