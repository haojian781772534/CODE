//Jianqiang Hao
//CS163
//08/05/2018
//Prog4
//to create a binary tree and finsih some operations 
//and use file operations


#include<iostream>
#include<cctype>
#include<cstring>
#include"data.h"

struct node
{
	data information;				//save data's members
	node *left;					//a right pointer of the node
	node *right;					//a left pointer of the node
};


class tree
{
	public:
		tree();
		~tree();
		int insert();				//wrapper function, insert the node in the binary
		int display_all();			//wrapper function, display all information in the binary
		int remove(char *);			//wrapper function, remove the node you want to
		int remove_all();			//wrapper function,  remove all inforamtion
		int retrieve(char *);			//warpper function, rertrieve
		int height();				//wrapper function, find the height of the tree
		int create_information();		//using some data of data file

	private:
		node *root;
		int insert(node *&, node *);		//insert the node in the binary
		int display_all(node *);		//display all information in the binary
		int remove(node *&, char *);		//remove the node you want to 
		int remove_all(node *);			//remove all information
		int retrieve(node *, char *);		//retrieve
		int height(node *);			//find the height of the tree
		node * min_value(node *);		//look for the minimum in the binary tree

};



