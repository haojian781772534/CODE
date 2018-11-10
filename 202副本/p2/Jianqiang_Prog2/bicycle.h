//Jianqiang Hao
//CS202
//10/29/18
//Prog2
//design a program to support three transportatioa tools 
//using object oriented programming


#ifndef bicycle_h
#define bicycle_h
#include"car.h"

class bicycle : public car
{
	public:
		bicycle();			//constructor
		~bicycle();			//destructor	
		bicycle(char *intersection, int id_num, float cost_hour, bool repair, int password);			//constructor
		int display();		//display all information 
		void read();		//users enter information
		int return_id();	//get the ID number

	protected:
		int password;		//the password of bicycle to use
};


#endif
