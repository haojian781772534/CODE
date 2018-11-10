//Jianqiang Hao
//CS163
//Program3
//7/30/2018
//to create a hash table using chaining 
//and use file operations
//

#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>
#include"data.h"


#ifndef TABLE
#define TABLE


struct node
{
	data information;
	node *next;
};

class table{
	public:
		table(int size=7);
		~table();
		int insert_table();			//add new item to the hash table
		int hash_function(char *)const ;	//to look for a key value
		int retrieve(char *);			
		int remove(char *);			//delete a item in the hash table
		int display(char *);			//display all information in the item
		int display_all();			//display all items
		int create_information();		//get a information from a data file


	private:
		node **hash_table;
		int hash_table_size;			//hash table array size
};


#endif

