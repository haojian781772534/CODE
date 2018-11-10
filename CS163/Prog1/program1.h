//Jianqiang Hao
//CS163
//Program1
//7/1/2018
//a program that help students understand all that is expected of 
// your time this summer to be succeed in CS163


#include<iostream>
#include<cctype>
#include<cstring>


struct item
{
	char *item_name;		// the name of some items in the category	
	char *ontime_due;
	char *late_due;
	char *due_time;
	item *item_next;		//pointer to the next item node
};



struct node
{
	char *name;			// the name of this category
	node *next;			// pointer to the next node
	item *down;			//pointer to the item LLL
};


class list
{
   public:
	list();
	~list();
	int add_node( char *);			//wrapper function
	int add_node(node *&, char *);		//add a new category node in the LLL

	bool find_node(char *);			//wrapper function
	bool find_node(node *, char *);		//look for a category 

	int display(node *);			//wrapper function
	int display();				// display all category in the LLL

	int display_item(char *);		//display all items in a category 

	int add_item(char * , char *, char *, char *, char *);		// add the item  in a category

	int finish_item(char *, char *);		//delete finished item in a category	

	int remove_category(char *);		//remove a category of all work 
   private:
	node *head;
};



