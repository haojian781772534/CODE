//Jianqiang Hao
//CS163
//Prog4
//08/05/2018
//to create a binary tree and finsih some operations 
//and use file operations
//


#include"tree.h"
using namespace std;

tree::tree()
{
	root=NULL;
}



tree::~tree()
{
	remove_all();
}



//insert a data in the tree
int tree:: insert()					//wrapper function
{

	node *current=new node;
	current->information.insert_data();
	return insert(root, current);
}


int tree:: insert(node *& root, node *current)
{
	if(!root)
	{
		current->left=NULL;
		current->right=NULL;
		root=current;
	}
	else if(strcmp(current->information.name, root->information.name)<0)
	{
		insert(root->left,current);
	}
	else if(strcmp(current->information.name, root->information.name)>=0)
	{
		insert(root->right, current);
	}
	return 1;
}



//display all information
int tree:: display_all()
{
	return display_all(root);				//wrapper function
}

int tree :: display_all(node *root)
{
	if(!root)
	  return 0;
	root->information.display_data();
	display_all(root->left);
	display_all(root->right);
	return 1;
}



//determine the height of the tree
int tree:: height()
{
	return height(root);				//wrapper function
}

int tree :: height(node *root)
{
	if(!root)
	  return 0;
	int left_tree=0;
	int right_tree=0;
	left_tree=height(root->left)+1;
	right_tree=height(root->right)+1;

	return left_tree>right_tree?left_tree: right_tree;
}



//retrieve
int tree :: retrieve(char *to_find)
{
	return retrieve(root, to_find);				//wrapper function
}

int tree :: retrieve(node *root, char *to_find)
{
	if(!root)
	  return 0;
	if(root->information.retrieve_data(to_find))
		return 1;
	if(strcmp(root->information.name, to_find)>0)
		return retrieve(root->left,to_find);
	if(strcmp(root->information.name, to_find)<0)
		return retrieve(root->right, to_find);
	/*else{
	return	retrieve(root->left,to_find) +retrieve(root->right, to_find);}*/
		
}



// remove all information
int tree :: remove_all()
{
	return remove_all(root);		//wrapper function
}

int tree :: remove_all(node *root)
{
	if(!root)
	  return 0;
	remove_all(root->left);
	remove_all(root->right);
	if(!root->left && !root->right)
	{
		delete root;
		root=NULL;
	}
	return 1;
}



//remove particular node
int tree :: remove(char *match)
{
	return remove(root, match);		//wrapper function
}

int tree :: remove(node *&root, char *match)
{
	if(!root)
	  return 0;
	if(strcmp(match, root->information.name)<0)
		return remove(root->left,match);
	else if(strcmp(match, root->information.name)>0)
		return remove(root->right,match);
	else{
		if(root->left==NULL)
		{
			node *temp=root;
			root=root->right;
			delete temp;
			return 1;
		}
		else if(root->right==NULL)
		{
			node *temp=root;
			root=root->left;
			delete temp;
			return 1;
		}
		else{
			node *temp=min_value(root->right);
			strcpy(root->information.name,temp->information.name);
			strcpy(root->information.description, temp->information.description);
			strcpy(root->information.color, temp->information.color);
			strcpy(root->information.item_size, temp->information.item_size);
			strcpy(root->information.website, temp->information.website);
			return remove(root->right, temp->information.name);
		}
	}
}



//find the minimum in the binary tree
node* tree :: min_value(node *root)
{
	if(!root)					
	  return 0;
	if(!root->left)
		return root;
	else
		return min_value(root->left);
}



//using data file.
int tree:: create_information()
{
	ifstream fin;
	fin.open("shopping.txt");
	if(!fin)
	  return 0;
	else
	{
		node *current=new node;
		current->left=NULL;
		current->right=NULL;

		char temp1[SIZE];
		fin.get(temp1,SIZE,'|');
		fin.ignore(200,'|');
		current->information.name=new char[strlen(temp1)+1];
		strcpy(current->information.name, temp1);

		char temp2[SIZE];
		fin.get(temp2,SIZE,'|');
		fin.ignore(200,'|');
		current->information.description= new char[strlen(temp2)+1];
		strcpy(current->information.description, temp2);

		char temp3[SIZE];
		fin.get(temp3,SIZE,'|');
		fin.ignore(200,'|');
		current->information.color=new char[strlen(temp3)+1];
		strcpy(current->information.color, temp3);

		char temp4[SIZE];
		fin.get(temp4, SIZE,'|');
		fin.ignore(200,'|');
		current->information.item_size=new char[strlen(temp4)+1];
		strcpy(current->information.item_size, temp4);

		char temp5[SIZE];
		fin.get(temp5,SIZE,'\n');
		fin.ignore(200,'\n');
		current->information.website=new char[strlen(temp5)+1];
		strcpy(current->information.website, temp5);
		
		root=current;

		while(fin.peek()!=EOF)
		{
		node *current=new node;	
		char temp1[SIZE];
		fin.get(temp1,SIZE,'|');
		fin.ignore(200,'|');
		current->information.name=new char[strlen(temp1)+1];
		strcpy(current->information.name, temp1);

		char temp2[SIZE];
		fin.get(temp2,SIZE,'|');
		fin.ignore(200,'|');
		current->information.description= new char[strlen(temp2)+1];
		strcpy(current->information.description, temp2);

		char temp3[SIZE];
		fin.get(temp3,SIZE,'|');
		fin.ignore(200,'|');
		current->information.color=new char[strlen(temp3)+1];
		strcpy(current->information.color, temp3);

		char temp4[SIZE];
		fin.get(temp4, SIZE,'|');
		fin.ignore(200,'|');
		current->information.item_size=new char[strlen(temp4)+1];
		strcpy(current->information.item_size, temp4);

		char temp5[SIZE];
		fin.get(temp5,SIZE,'\n');
		fin.ignore(200,'\n');
		current->information.website=new char[strlen(temp5)+1];
		strcpy(current->information.website, temp5);
		
		if(!root)
		    root=current;	
		if(strcmp(root->information.name, current->information.name)<=0)
			insert(root,current);
		else
			insert(root,current);
		}
		fin.close();
		return 1;
	}
}
			


