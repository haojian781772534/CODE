//Jianqiang Hao
//CS163
//Program3
//07/31/2018
//to create a hash table using chaining 
//and use file operations
//

#include"table.h"
using namespace std;


//constructor
table :: table(int size)
{
	hash_table_size=size;
	hash_table=new node*[hash_table_size+1];
	
	for(int i=0; i<size; i++)
		hash_table[i]=NULL;
}



//destructor
table :: ~table()
{
	for(int i=0; i<hash_table_size;i++)
	{
		node *current=hash_table[i];
		while(current)
		{
			node *temp=current->next;
			delete current;
			current=temp;
		}
	}
	delete []hash_table;

}



//input a data in the hash table
int table:: insert_table()
{

	node *curr=new node;
	curr->information.insert_data();
	int key=hash_function(curr->information.get_name());
	if(key<0 || key>hash_table_size-1)
		return 0;

	if(hash_table[key]==NULL)
	{
		curr->next=NULL;
	}
	else
		curr->next=hash_table[key];
	hash_table[key]=curr;

	return 1;
}



//hash function to look for key
int table::hash_function(char *key) const
{
	return *key *4  %hash_table_size;
}



//retrieve
int table :: retrieve(char *to_find)
{
	int key=hash_function(to_find);
	if(key<0 || key>hash_table_size-1)
		return 0;
	node *curr=hash_table[key];
	while(curr)
	{
		if(curr->information.retrieve_data(to_find))
			return 1;
		curr=curr->next;
	}
	return 0;
}



//remove an item in the hash table
int table:: remove(char *key_value)
{
	int key=hash_function(key_value);
	if(key<0 || key>hash_table_size-1)
		return 0;
	node *current=hash_table[key];
	node *temp=current->next;
	if(strcmp(current->information.name, key_value)==0)
	{
		delete current;
		hash_table[key]=temp;
		return 1;
	}
	
	while(temp)
	{
		if(strcmp(temp->information.name, key_value)==0)
		{
			if(temp->next==NULL)
			{
				delete temp;
				temp=NULL;
				current->next=NULL;
				return 1;
			}
			else{
				current->next=temp->next;
				delete temp;
				temp=NULL;
				return 1;
			}
		}
		current=temp;
		temp=temp->next;
	
	}
	return 1;
}



//display an item in the hash table
int table::display(char *key_value)
{

	int key=hash_function(key_value);
	if(key<0 || key>hash_table_size-1)
		return 0;
	node *current=hash_table[key];
	while(current)
	{
		current->information.display_data();
		current=current->next;
	}
	return 1;
}



//display all information in the hash table
int table:: display_all()
{
	for(int i=0;i<hash_table_size;i++)
	{
		if(hash_table[i])
		{
			node *curr=hash_table[i];
			while(curr)
				{
					curr->information.display_data();
					curr=curr->next;
				}
			cout<<endl;
		}
	}
	return 1;
}


//get data from the file
int table::create_information()
{
	ifstream fin;
	fin.open("shopping.txt");
	if(!fin)
	  return 0;
	else
	{
		node *current=new node;
		current->next=NULL;

		char temp1[SIZE];
		fin.get(temp1,SIZE,'|');
		fin.ignore(200,'|');
		current->information.name=new char[strlen(temp1)+1];
		strcpy(current->information.name,temp1);

		char temp2[SIZE];
		fin.get(temp2,SIZE,'|');
		fin.ignore(200,'|');
		current->information.description=new char[strlen(temp2)+1];
		strcpy(current->information.description,temp2);

		char temp3[SIZE];
		fin.get(temp3,SIZE,'|');
		fin.ignore(200,'|');
		current->information.color=new char[strlen(temp3)+1];
		strcpy(current->information.color, temp3);

		char temp4[SIZE];
		fin.get(temp4,SIZE,'|');
		fin.ignore(200,'|');
		current->information.item_size=new char[strlen(temp4)+1];
		strcpy(current->information.item_size, temp4);

		char temp5[SIZE];
		fin.get(temp5,SIZE,'\n');
		fin.ignore(200,'\n');
		current->information.website=new char[strlen(temp5)+1];
		strcpy(current->information.website,temp5);

		int key=hash_function(current->information.get_name());
		hash_table[key]=current;

		while(fin.peek()!=EOF)
		{
		node *current=new node;
		char temp1[SIZE];
		fin.get(temp1,SIZE,'|');
		fin.ignore(200,'|');
		current->information.name=new char[strlen(temp1)+1];
		strcpy(current->information.name,temp1);

		char temp2[SIZE];
		fin.get(temp2,SIZE,'|');
		fin.ignore(200,'|');
		current->information.description=new char[strlen(temp2)+1];
		strcpy(current->information.description,temp2);

		char temp3[SIZE];
		fin.get(temp3,SIZE,'|');
		fin.ignore(200,'|');
		current->information.color=new char[strlen(temp3)+1];
		strcpy(current->information.color, temp3);
	      
	        char temp4[SIZE];
		fin.get(temp4,SIZE,'|');	
		fin.ignore(200,'|');
	       	current->information.item_size=new char[strlen(temp4)+1];
		strcpy(current->information.item_size, temp4);

		char temp5[SIZE];
		fin.get(temp5,SIZE,'\n');
		fin.ignore(200,'\n');
		current->information.website=new char[strlen(temp5)+1];
		strcpy(current->information.website,temp5);
		
		int key=hash_function(current->information.get_name());
		node *temp=hash_table[key];
		if(temp==NULL)
			hash_table[key]=current;
		else
		{
			current->next=temp;
			hash_table[key]=current;
		}
		}
		fin.close();
		return 1;
	}
}


