//Jianqiang Hao
//CS202
//10/29/18
//Prog2
//design a program to support three transportatioa tools 
//using object oriented programming


#ifndef car_h
#define car_h

class car
{
	public:
		car();								//constructor
		car(char *name, int id_num, float cost_hour, bool repair);	//constructor
		virtual int display();						//display all information
		virtual int return_id()=0;					//pure virtual function
		virtual  ~car();						//destructor
		car(const car&to_copy);						//copy constructor

		virtual void read();						//get the all information

	protected:
		char *intersection;						//the location of car 
		int id_num;							//car ID number
		float cost_hour;						//cost per hour
		bool repair;							// if need to repair
};

#endif


