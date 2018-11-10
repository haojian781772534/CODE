//Jianqiang Hao
//CS163
//Program4
//8/5/2018
//to create a binary tree and finsih some operations 
//and use file operations


#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>
#define SIZE 150

#ifndef DATA
#define DATA

class data
{
	public:
		data();
		~data();
		int insert_data();		//insert a data in the item
		int display_data();		//display data element
		int retrieve_data(char *);	//retrieve a data
		//char *get_name();		//get a name data

		char *name;			//the name of item
		char *description;		//description of item
		char *color;			//the color of item
		char *item_size;		//item size
		char *website;			//the webiste of item
};


#endif
