//Jianqiang Hao
//CS202
//10/29/18
//Prog2
//design a program to support three transportatioa tools 
//using object oriented programming





#ifndef node_h
#define node_h


#include"car.h"


class node
{
	public:
		node();						//constructor
		~node();					//destructor
		node(int i);					//constructor
		node *&get_next();				//get the pointer of next
		void set_next(node *ptr);			//set the next 
		node *&get_previous();				// get the pointer of previous
		void set_previous(node *ptr);			//set the pointer of previous
		void display();					//display all information
		int return_id();				//return the id number

	protected:
		node *next;			//next pointer
		node *previous;			//previous pointer
		car *point;			//class car pointer
};


class control
{
	public:
		control();					//constructor
		~control();					//destructor
		int add_item(int choice);			// add the node in the DLL

		int display();					//display all information
		int display(node *head);			

		int remove(int match);				//remove the node 
		int remove(node * head, int match);

		int retrieve(int match);			//retrieve the node if exit
		int retrieve(node *head, int match);

		int remove_all();				//remove all information
		int remove_all(node *&head);



	protected:
		node *head;		//head pointer
		node *tail;		//tail pointer
};


#endif // node_h
