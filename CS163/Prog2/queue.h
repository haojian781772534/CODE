//Jianqiang Hao
//Prog2
//CS163
//07/22/2018
//to find some satisfactory features about computer,
//where you can find them in the store. Using data structure is queue and stack.


#include<iostream>
#include<cctype>
#include<cstring>
#define SIZE 100
struct q_node
{
	char *trademark;			//computer's trademark you want to choose
	char *memory;				//computer's memory you can choose
	char *computer_type;			//computer's type you like 
	char *other_feature;			//other features you care
	q_node *next;

};

class queue
{
	
    public:
	queue(void);				//constructor
	~queue(void);				//desturctor
	int enqueue(char *, char *, char *, char *);	//add a node in the queue
	int dequeue();					//delete first input node in the queue											
	int peek();					//return the new node
	int display();					//wrapper function to display
	void remove_out(q_node *&, char *);		//help destructor to delete node
	int display(q_node *, q_node *);		//display all elements
    private:
	q_node *rear;
};
