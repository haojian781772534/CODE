//Jianqiang Hao
//CS163
//Program4
//8/5/2018
//to create a binary tree and finsih some operations 
//and use file operations

#include"data.h"
using namespace std;

//constructor
data :: data()
{
	name=NULL;
	description=NULL;
	color=NULL;
	item_size=NULL;
	website=NULL;
}



//destructor
data :: ~data()
{
	if(name)
	{
		delete name;
		name=NULL;
	}
	if(description)
	{
		delete description;
		description=NULL;
	}
	if(color)
	{
		delete color;
		color=NULL;
	}
	if(item_size)
	{
		delete item_size;
		item_size=NULL;
	}
	if(website)
	{
		delete website;
		website=NULL;
	}
}



//input a data in the item
int data::insert_data()
{
	char temp1[SIZE];
	cout<<"Please enter the name of item"<<endl;
	cin.get(temp1, SIZE, '\n');
	cin.ignore(100,'\n');
	this->name=new char[strlen(temp1)+1];
	strcpy(this->name, temp1);

	char temp2[SIZE];
	cout<<"Please enter the description of item"<<endl;
	cin.get(temp2, SIZE, '\n');
	cin.ignore(100,'\n');
	this->description=new char[strlen(temp2)+1];
	strcpy(this->description, temp2);

	char temp3[SIZE];
	cout<<"Please enter the color of item"<<endl;
	cin.get(temp3, SIZE, '\n');
	cin.ignore(100,'\n');
	this->color=new char[strlen(temp3)+1];
	strcpy(this->color, temp3);

	char temp4[SIZE];
	cout<<"Please enter the size of item"<<endl;
	cin.get(temp4, SIZE, '\n');
	cin.ignore(100,'\n');
	this->item_size=new char[strlen(temp4)+1];
	strcpy(this->item_size, temp4);

	char temp5[SIZE];
	cout<<"Please enter the website of item"<<endl;
	cin.get(temp5, SIZE, '\n');
	cin.ignore(100,'\n');
	this->website=new char[strlen(temp5)+1];
	strcpy(this->website, temp5);

	return 1;
}



//display data for client
int data:: display_data()
{
	cout<<"name:"<<this->name<<endl;
	cout<<"description:"<<this->description<<endl;
	cout<<"color:"<<this->color<<endl;
	cout<<"item size:"<<this->item_size<<endl;
	cout<<"website:"<<this->website<<endl;

	return 1;
}


// retrieve data
int data::retrieve_data(char *to_find)
{
	if(strcmp(to_find, this->name)==0)
		return 1;
	else 
		return 0;
}


//return the name you input
/*char* data:: get_name()
{
	return this->name;
}*/
