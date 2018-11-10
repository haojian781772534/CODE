//Jianqiang Hao
//Prog2
//CS163
//7/22/2018
//to find some satisfactory features about computer,
//where you can find them in the store. Using data structure is queue and stack.


#include"queue.h"
using namespace std;

//constructor
queue :: queue(void)
{
	rear=NULL;
}


//destructor
queue :: ~queue(void)
{
	q_node *current=rear;
	while(current){
		q_node *temp=current;
		current=current->next;
		remove_out(temp, temp->trademark);
	}
	rear=NULL;
}


//help destructor delete data
void queue::remove_out(q_node *&current, char *compare_name)	
{
	if(current==NULL)
		return;
	if(!strcmp(current->trademark,compare_name))
	{
		q_node *item=current;
		current=current->next;
		delete []item->trademark;
		item->trademark=NULL;
		delete []item->memory;
		item->memory=NULL;
		delete []item->computer_type;
		item->computer_type=NULL;
		delete []item->other_feature;
		item->other_feature=NULL;
		delete item;
		return ;
	}
	else remove_out(current->next, compare_name); 
}



//to add a node into queue
int queue:: enqueue(char *to_trademark, char *to_memory, char *to_computer_type, char *to_other_feature)
{ 
	if(!rear)
       	{
	          q_node *current=new q_node;
		  current->trademark=new char[strlen(to_trademark)];
		  strcpy(current->trademark, to_trademark);

		  current->memory=new char[strlen(to_memory)];
		  strcpy(current->memory, to_memory);

		  current->computer_type=new char[strlen(to_computer_type)];
		  strcpy(current->computer_type, to_computer_type);

		  current->other_feature=new char[strlen(to_other_feature)];
		  strcpy(current->other_feature, to_other_feature);

		  rear=current;
		  rear->next=rear;
		  return 1;
	  }
		  q_node *current=new q_node;	 
		  current->trademark=new char[strlen(to_trademark)];
		  strcpy(current->trademark, to_trademark);

		  current->memory=new char[strlen(to_memory)];
		  strcpy(current->memory, to_memory);

		  current->computer_type=new char[strlen(to_computer_type)];
		  strcpy(current->computer_type, to_computer_type);
		 
		  current->other_feature=new char[strlen(to_other_feature)];
		  strcpy(current->other_feature, to_other_feature);
		  current->next=rear->next;
		  rear->next=current;
		  rear=current;
		  return 1;
}



//to delete a node in the queue
int queue:: dequeue()
{
	if(!rear)
	   return 0;
	if(rear->next==rear)
	{
		delete rear;
		rear=NULL;
	}
	else{
		q_node *current=rear->next;
		rear->next=current->next;
		delete current;
		current=NULL;
	}
	return 1;
}


//to choose last position to return its value
int queue:: peek()
{
	if(!rear)
	  return 0;
	else{
		q_node *temp=rear->next;
				
		cout<<"trademark is:"<<temp->trademark<<endl;
		cout<<"computer memory is:"<<temp->memory<<endl;
		cout<<"computer type is:"<<temp->computer_type<<endl;
		cout<<"other feature is:"<<temp->other_feature<<endl;
	}
	return 1;
}



//display all computer's feature
int queue :: display()							//wrapper function
{
	q_node *temp=rear;
	return display(rear, temp);
}
int queue :: display(q_node *rear, q_node *current)
{
	if(!rear)
	  return 0;
	if(rear!=current->next)
	{
		cout<<"trademark is:"<<current->next->trademark<<endl;
		cout<<"computer memory is:"<<current->next->memory<<endl;
		cout<<"computer type is:"<<current->next->computer_type<<endl;
		cout<<"other feature is:"<<current->next->other_feature<<endl;

		return display(rear, current->next);
	}
	
		cout<<"trademark is:"<<rear->trademark<<endl;
		cout<<"computer memory is:"<<rear->memory<<endl;
		cout<<"computer type is:"<<rear->computer_type<<endl;
		cout<<"other feature is:"<<rear->other_feature<<endl;
}

