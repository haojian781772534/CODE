//Jianqiang Hao
//Prog2
//CS163
//7/22/2018
//to find some satisfactory features about computer,
//where you can find them in the store. Using data structure is queue and stack.


#include<iostream>
#include<cctype>
#include<cstring>
#define SIZE 100
const int MAX=2;

class product							//an class to help class stack achieve list of array
{
	public:
		int create_array();				//to create an array in the list of arry
		int copy_stack(const product &);		//to copy some information to stack 
		bool exist_element();				//examine the array if have elements
		int display();					//display elements that private aspects
	private:	
		char *computer_name;				// computer name 
		char *price;					//computer price
		char *location;					//store location
		char *store_name;				//store name
};

struct node
{
	product *save_message;					//to save product's information
	node *next;
};

class stack
{
	public:
		stack(void);					// constructor
		~stack(void);					//destructor
		int push();					//add a element in the stack 
		int pop();					//to delete an elemnet in stack
		int peek(product &)const;			//to return the top_index value to client
		int display_all();				//display all elements to stack
	private:
		
		node *head;
		int top_index;
};



