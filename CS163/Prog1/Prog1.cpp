//Jianqiang Hao
//CS163
//Program1
//7/1/2018
//a program that help students understand all that is expected of 
// your time this summer to be succeed in CS163


#include"program1.h"
using namespace std;

//constructor
list::list()
{
	head=NULL;
}


//destructor
list::~list()
{
	while(head){
		while(head->down){
			item *current=head->down->item_next;
			delete []head->down->item_name;
			head->down->item_name=NULL;
			delete []head->down->ontime_due;
			head->down->ontime_due=NULL;
			delete []head->down->late_due;
			head->down->late_due=NULL;
			delete []head->down->due_time;
			head->down->due_time=NULL;
			head->down->item_next=NULL;
			head->down=current;
				}
	node *temp= head->next;
	delete []head->name;
	head->name=NULL;
	head->down=NULL;
	head->next=NULL;
	head=temp;
	}
}


//add a new node
/* int list:: add_node(char *add)
{ 
	return add_node(head, add);
}
*/
/*int list:: add_node( char *add)
{
	if(!head){
		head=new node;
		head->name=new char[strlen(add)+1];
		strcpy(head->name, add);
		head->next=NULL;
		head->down=NULL;
		return 1;                                   // add nodes by using loop
	}
	else{
	node *current =head;
	while(current->next!=NULL){
		current=current->next;
	}
	node *temp = new node;
	temp->name=new char[strlen(add)+1];
	strcpy(temp->name, add);
	temp->next=NULL;
	temp->down=NULL;
	current->next=temp;
	return 1;
	}
	return 0;
}
*/

int list:: add_node(char *add){ 			// add nodes by using recursion
	return add_node(head,add);			//wrapper function
	}
int list:: add_node(node* &head, char *add)
{
	if(!head){
		head=new node;
		head->name=new char[strlen(add)+1];
		strcpy(head->name,add);
		head->next=NULL;
		head->down=NULL;
		return 1;
		}
	else{
		if(head->next!=NULL)
			{
			add_node(head->next,add);
			}
		head->next=new node;
		head->next->name=new char[strlen(add)+1];
		strcpy(head->next->name,add);
		head->next->next=NULL;
		head->next->down=NULL;
		return 1;
	}
return 0;
}


//to find a node whether exists
bool list:: find_node(char *to_find)			//wrapper function
{
	return find_node(head,to_find);
}

bool list:: find_node(node *head, char *to_find)
{
	if(!head)
	  return false;
	if(strcmp(head->name, to_find)==0)
	  return true;
	find_node(head->next, to_find);
}


//display all node
/*int list:: display()
{
	if(!head)				//display all node by using loop
	  return 0;
	node *current=head;
	while(current){
		cout<<" name:"<<current->name<<endl;
		current=current->next;
	}
	return 1;
}*/
int list:: display()				//wrpper function
{
	return display(head);
}
int list:: display(node *head)
{
	if(!head)
		return 0;
	cout<<"name: "<<head->name<<endl;       //display all node by using recursion
	display(head->next);
	return 1;
}

// display items in only one node
int list:: display_item(char *need_item)
{
	if(!head)
	  return 0;
	node *current= head;
	while(current&&strcmp(current->name, need_item)!=0)
		{
			current=current->next;
		}
	while(current->down)
		{
			cout<<" item name:"<<current->down->item_name<<endl;
			cout<<" on time due data:"<<current->down->ontime_due<<endl;;
			cout<<" late time due data:"<<current->down->late_due<<endl;
			cout<<" due time: " <<current->down->due_time<<endl;
			current->down=current->down->item_next;
		}
	return 1;
}



/*struct item
{
	char *item_name;
	char *ontime_due;
	char *late_due;
	char *due_time;
	item *item_next;
};


struct node
{
	char *name;
	node *next;
	item *down;
};
*/
// add some items in the node;
int list:: add_item(char *node_name, char *add_item_name, char *add_ontime_due, char *add_late_due, char *add_due_time)
{
	if(!head)
	  return 0;
	node *current= head;
	while(strcmp(current->name, node_name)!=0)
		current=current->next;
	item *temp1 =new item;
	temp1->item_name=new char[strlen(add_item_name)+1];
	strcpy(temp1->item_name, add_item_name);

	
	temp1->ontime_due=new char[strlen(add_ontime_due)+1];
	strcpy(temp1->ontime_due, add_ontime_due);

	
	temp1->late_due=new char[strlen(add_late_due)+1];
	strcpy(temp1->late_due, add_late_due);

	
	temp1->due_time=new char[strlen(add_due_time)+1];
	strcpy(temp1->due_time, add_due_time);

	temp1->item_next=NULL;

	if(current->down==NULL)
	  {
		current->down=temp1;
	  }
	else{
	item *pot= current->down;
	while(pot->item_next)
	{
		pot=pot->item_next;
	}
	pot->item_next=temp1;
	}
	return 1;
}


//if you finish your a item, you can delete item.
int list::finish_item(char *node_name, char *finish_item_name)
{
	if(!head)
	  return 0;
	node *current= head;
	while(strcmp(current->name, node_name)!=0)
		{
			current=current->next;
		}
	item *temp=current->down;
	if(!temp)
	  return 0;
	item *ptr = temp;
	while(strcmp(temp->item_name, finish_item_name)!=0)
		{
			ptr=temp;
			temp=temp->item_next;
		}
	if(strcmp(temp->item_name, finish_item_name)!=0)
		return 0;
	if(temp->item_next==NULL)
	  {
		delete []temp->item_name;		//situation3: delete the item in the category, and it is last one
		temp->item_name=NULL;
		
		delete []temp->ontime_due;
		temp->ontime_due=NULL;
		
		delete []temp->late_due;
		temp->late_due=NULL;

		delete []temp->due_time;
		temp->due_time=NULL;

		temp->item_next=NULL;
		delete temp;
		ptr->item_next=NULL;

		return 1;
	  }
	else if(temp->item_next!=NULL&&temp!=ptr){		//situation2: delete the item in the middle, it isn't first and last
		ptr->item_next=temp->item_next;
		delete []temp->item_name;
		temp->item_name=NULL;
		
		delete []temp->ontime_due;
		temp->ontime_due=NULL;
		
		delete []temp->late_due;
		temp->late_due=NULL;

		delete []temp->due_time;
		temp->due_time=NULL;
		delete temp;
		return 1;
	    }
	else{
		current->down=temp->item_next;			//situation3: delete the item in the first.
		delete []temp->item_name;
		temp->item_name=NULL;
		
		delete []temp->ontime_due;
		temp->ontime_due=NULL;
		
		delete []temp->late_due;
		temp->late_due=NULL;

		delete []temp->due_time;
		temp->due_time=NULL;

		temp->item_next=NULL;
		delete temp;
		return 1;
	}
}


// remove a category of all work
int list::remove_category(char *node_name)
{	
	if(!head)
	  return 0;
	node *current=head;
	node *ptr=current;
	while(strcmp(current->name,node_name)!=0)
	{
		ptr=current;
		current=current->next;
	}
	item *temp=current->down;
	if(!temp)
	  return 0;
	while(current->down!=NULL)
	{
		current->down=temp->item_next;	
		delete []temp->item_name;
		temp->item_name=NULL;
		
		delete []temp->ontime_due;
		temp->ontime_due=NULL;
		
		delete []temp->late_due;
		temp->late_due=NULL;

		delete []temp->due_time;
		temp->due_time=NULL;

		temp->item_next=NULL;
		temp=current->down;
	}
	if(head==current)
	{
		head=current->next;
		delete []current->name;
		current->name=NULL;

		current->next=NULL;
		current->down=NULL;
		return 1;
	}
	else{
		ptr->next=current->next;
		if(current->next==NULL)
			ptr->next=NULL;
		delete []current->name;
		current->name=NULL;
		current->next=NULL;
		current->down=NULL;
		return 1;
	}
	return 0;
}
		
