//Jianqiang Hao
//CS202
//10/29/18
//Prog2
//design a program to support three transportatioa tools 
//using object oriented programming





#include"car.h"

#ifndef scooter_h
#define scooter_h


class scooter : public car
{
	public:
		scooter();												//constructor
		scooter(char *intersection, int id_num, float cost_hour, bool repair, int battery_level);		//constructor
		~scooter();												//destructor
		int display();												//display all information
		void read();												//get the information 
		int return_id();											//get the id

	private:
		int battery_level;         //the level of the battery

};



#endif
