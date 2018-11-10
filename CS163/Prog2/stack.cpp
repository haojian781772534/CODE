//Jianqiang Hao
//Prog2
//CS163
//07/22/2018
//to find some satisfactory features about computer,
//where you can find them in the store. Using data structure is queue and stack.

#include"stack.h"
using namespace std;

//constructor
stack:: stack(void){
	head=NULL;
	top_index=0;
}



//destructor
stack :: ~stack(void)
{
	if(!head)
	  return ;
	while(head)
	{
		
		node *current=head;
		head=head->next;
		delete []current->save_message;
		current=NULL;
	}
}


//add a node into the stack
int product :: create_array()					//to create and input some data in the class product
{
	char temp1[SIZE];
	cout<<" please enter the caomputer name:"<<endl;
	cin.get(temp1, SIZE, '\n');
	cin.ignore(200,'\n');
	this->computer_name=new char[strlen(temp1)+1];
	strcpy(this->computer_name, temp1);
	
	char temp2[SIZE];
	cout<<" please enter the caomputer price:"<<endl;
	cin.get(temp2, SIZE, '\n');
	cin.ignore(200,'\n');
	this->price=new char[strlen(temp2)+1];
	strcpy(this->price,temp2);
	
	char temp3[SIZE];
	cout<<" please enter the caomputer location:"<<endl;
	cin.get(temp3, SIZE, '\n');
	cin.ignore(200,'\n');
	this->location=new char[strlen(temp3)+1];
	strcpy(this->location, temp3);
	
	char temp4[SIZE];
	cout<<" please enter the caomputer location:"<<endl;
	cin.get(temp4, SIZE, '\n');
	cin.ignore(200,'\n');
	this->store_name=new char[strlen(temp4)+1];
	strcpy(this->store_name, temp4);
	
	return 1;
}


int stack :: push()
{
	if(!head||top_index==MAX)
	{
		node *temp=new node;
		temp->next=head;
		head=temp;
		head->save_message= new product[MAX];
		top_index=0;
	}
	head->save_message[top_index].create_array();
	return ++top_index;
}
	


//to delete a node in the stack
int stack:: pop()
{
	if(!head)
	  return 0;
	if(top_index==0)
	{
		delete []head->save_message;
		node *temp=head;
		head=head->next;
		delete temp;
		temp=NULL;
		if(!head)
			top_index=0;
		else{
			top_index=MAX-1;
			return 0;
		}
	}
	else{
		top_index=top_index-1;
	}
	return 1;
}


//to choose a top node return
/*int product:: copy_stack( product &to_copy)
{
	to_copy.computer_name=new char[strlen(this->computer_name)+1];
	strcpy(to_copy.computer_name, this->computer_name);
	
	to_copy.price=new char[strlen(this->price)+1];
	strcpy(to_copy.price, this->price);
	
	to_copy.location=new char[strlen(this->location)+1];
	strcpy(to_copy.location, this->location);

	to_copy.store_name=new char[strlen(this->store_name)+1];
	strcpy(to_copy.store_name, this->store_name);

	return 1;
}*/

int product:: copy_stack(const product &to_copy)			//to copy data in the product
{
	if(computer_name!=NULL)
		delete []computer_name;
	if(!to_copy.computer_name)
		return 0;
	computer_name=new char[strlen(to_copy.computer_name)];
	strcpy(computer_name, to_copy.computer_name);

	if(price!=NULL)
		delete []price;
	if(!to_copy.price)
		return 0;
	price=new char[strlen(to_copy.price)];
	strcpy(price, to_copy.price);

	if(location!=NULL)
		delete []location;
	if(!to_copy.location)
		return 0;
	location=new char[strlen(to_copy.location)];
	strcpy(location, to_copy.location);

	if(store_name!=NULL)
		delete []store_name;
	if(!to_copy.store_name)
		return 0;
	store_name=new char[strlen(to_copy.store_name)];
	strcpy(store_name, to_copy.store_name);

	return 1;
}


int stack :: peek(product &found_top)const
{
	if(!head)
	  return 0;
	if(found_top.copy_stack(head->save_message[top_index-1]))
		return 1;
}


//display all node
int product :: display()
{
	cout<<" computer name :"<<this->computer_name<<endl;
	cout<<" price :"<<this->price<<endl;
	cout<<" location :"<<this->location<<endl;
	cout<<" store name:"<<this->store_name<<endl<<endl;

	return 1;
}


bool product :: exist_element()				//to judge if have element in the array
{
	if(this->computer_name)
		return true;
	else
		return false;
}

int stack :: display_all()
{
	if(!head)
	  return 0;
	node *current=head;
	while(current)
	{
		for(int i=0; i<MAX; i++)
		{
			if(current->save_message[i].exist_element())
				current->save_message[i].display();
		}
		current=current->next;
	}
	return 1;
}

			

