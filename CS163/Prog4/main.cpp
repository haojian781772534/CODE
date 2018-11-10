// Jianqiang Hao
// CS163
// Prog4
// 08/05/2018
//to create a binary tree and finsih some operations 
//and use file operations
//

#include"tree.h"
using namespace std;

int main()
{
	tree h_tree;
	int response1=0;
	char response2;
	
	if(h_tree.create_information()==0)
		cout<<"Wrong! not found file."<<endl<<endl;
	do{
		cout<<"Please Choose Your Choice(1-6)"<<endl;
		cout<<"*******1. Add a new node in the tree: "<<endl;
		cout<<"*******2. Retrieve a information from a tree: "<<endl;
		cout<<"*******3. Remove a particular node in the tree: "<<endl;
		cout<<"*******4. Display all information in the tree: "<<endl;
		cout<<"*******5. Dsiplay the Height of the tree: "<<endl;
		cout<<"*******6. Remove all information  in the tree: "<<endl<<endl;

		cin>>response1;
		cin.ignore(100,'\n');
		if(response1 == 1)
		{
			if(h_tree.insert())
				cout<<" Insert succeedly"<<endl;
			else 
				cout<<" Wrong !"<<endl;
		}
		else if(response1 ==2)
		{
			char temp[SIZE];
			cout<<"Please enter the name of the node you want to retrieve: "<<endl;
			cin.get(temp,SIZE,'\n');
			cin.ignore(200,'\n');
			if(h_tree.retrieve(temp))
			{
				cout<<"This is found node."<<endl;
				cout<<endl;
			}
			else
			{
				cout<<"Wrong !"<<endl<<endl;
			}
		}
		
		else if(response1 ==3)
		{
			char temp[SIZE];
			cout<<"Please enter the name of the node you want to remove: "<<endl;
			cin.get(temp,SIZE,'\n');
			cin.ignore(200,'\n');
			if(h_tree.remove(temp))
			{
				cout<<"Remove Succeedly."<<endl;
			}
			else
			{
				cout<<"Wrong !"<<endl<<endl;
			}
		}
		else if(response1 == 4){
			h_tree.display_all();
		}
		else if(response1 == 5)
		{
			cout<<"This height of the tree is: "<<h_tree.height()<<endl;
		}
		else if(response1 == 6)
		{
			if(h_tree.remove_all())
				cout<<" Remove all information "<<endl;
			else
				cout<<" Wrong !"<<endl;
		}
		cout<<" Again?  Y/N"<<endl;
		cin>>response2;
		cin.ignore(100, '\n');
	}while(toupper(response2)=='Y');
	return 0;


}

