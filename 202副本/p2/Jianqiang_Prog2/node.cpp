//Jianqiang Hao
//CS202
//10/29/18
//Prog2
//design a program to support three transportatioa tools 
//using object oriented programming




#include"node.h"
#include<iostream>
#include<cctype>
#include<cstring>
#include"bicycle.h"
#include"scooter.h"
#include"zipcar.h"

using namespace std;

// constructor
node:: node():next(NULL), previous(NULL)
{
	point=NULL;
}



//destructor
node:: ~node()
{
	next=NULL;
	previous=NULL;
}



//constructor
node:: node(int i): next(NULL),previous(NULL)
{
	if(i== 1)
	{
		point =new scooter;
		point->read();
	}
	else if(i == 2)
	{
		point =new zip_car;
		point->read();
	}
	else if(i == 3)
	{
		point =new bicycle;
		point->read();
	}
	else
		point=NULL;
}



//get the pointer of next
node*& node::get_next()
{
	return next;
}



//get the pointer of previous
node*& node:: get_previous()
{
	return previous;
}



//set the pointer next 
void node :: set_next(node *ptr)
{
	next=ptr;
}


//set the pointer of previous
void node :: set_previous(node *ptr)
{
	previous =ptr;
}



//let the the type of car point to call display function 
void node:: display()
{
	point->display();
}



//get the id number 
int node:: return_id()
{
	return point->return_id();
}


//constructor
control :: control(): head(NULL), tail(NULL)
{
}



//destructor
control:: ~control()
{
	remove_all();
}


//add the node in the DLL
int control :: add_item(int choice)
{
    if(choice==1)					//choice is 1: scooter
    {
	if(!head)
	{
		head=new node(1);
		head->get_next()=NULL;
		head->get_previous()=NULL;
		tail=head;
		return 0;
	}
	else
	{
		node *current=new node(1);
		current->get_next()=NULL;
		current->get_previous()=tail;
		tail->get_next()=current;
		tail=current;
		return 1;
	}
    }
    if(choice == 2)					//choice is 2: zip car
    {	
	if(!head)
	{
		head=new node(2);
		head->get_next()=NULL;
		head->get_previous()=NULL;
		tail=head;
		return 0;
	}
	else
	{
		node *current=new node(2);
		current->get_next()=NULL;
		current->get_previous()=tail;
		tail->get_next()=current;
		tail=current;
		return 1;
	}
    }
    if(choice == 3)					// choice is 3: bicycle
    {
	if(!head)
	{
		head=new node(3);
	       	head->get_next()=NULL;
	       	head->get_previous()=NULL;
		tail=head;
		return 0;
	}
	else
	{
		node *current=new node(3);
		current->get_next()=NULL;
		current->get_previous()=tail;
		tail->get_next()=current;
		tail=current;
		return 1;
	}

    }
    else
	    return 0;
}



// display all information 
int control :: display()		//wrapper function
{
	return display(head);
}


int control :: display(node *head)
{
	if(!head)
		return 0;
	head->display();
	return display(head->get_next());
}



//remove the node by offering id number
int control::remove(int match)			//wrapper function
{
	return remove(head, match);
}


int control:: remove(node * head, int match)
{
	if(!head)
		return 0;
	/*if(match==head->return_id())
	{
		node *current=head;
		current->get_next()->get_previous()=current->get_previous();
		head->get_previous()->get_next()=head->get_next();
		
		head=head->get_next();
		delete current;
		current=NULL;

		return remove(head, match);
	}
	else 
		head=head->get_next();
		return remove(head, match);
		*/

	if(head->return_id()== match)
	{
		node *temp =head->get_next();
		if(head->get_previous())
		{
			head->get_previous()->get_next()=head->get_next();
		}
		else
		{
			this->head=this->head->get_next();
		}
		if(head->get_next())
		{
			head->get_next()->get_previous()=head->get_previous();
		}
		else
		{
			this->tail=this->tail->get_previous();
		}
		delete head;
		head=temp;
		return remove(head, match)+1;
	}
	
	return remove(head->get_next(), match);
}


// remove all information in the DLL
int control:: remove_all()			//wrapper function
{
	return remove_all(head);
}

int control:: remove_all(node *&head)
{
	if(!head)
		return 0;
	if(head== tail)
	{
		delete head;
		head= tail=NULL;
		return 1;
	}
	node *current=head;
	head=head->get_next();
	current->get_next()->get_previous()=NULL;
	current->get_next()=NULL;
	delete current;
	current= NULL;
	return remove_all(head);
}



//check one node to retrieve
int control :: retrieve(int match)		//wrapper function
{
	return retrieve(head, match);
}


int control :: retrieve(node *head, int match)
{
	if(!head)
		return 0;
	if(head->return_id()==match)
		return 1;
	else
		return retrieve(head->get_next(), match);
}


























