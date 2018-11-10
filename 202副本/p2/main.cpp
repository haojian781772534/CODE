//Jianqiang Hao
//CS202
//10/29/18
//Prog2
//design a program to support three transportatioa tools 
//using object oriented programming





#include<iostream>
#include<cctype>
#include<cstring>
#include"car.h"
#include"node.h"

using namespace std;

int main()
{
	control dll;
	int option=0;

	do{
		cout<<"*******Enter the choice you want************************************"<<endl;
		cout<<"*******1. Add node in the DLL***************************************"<<endl;
		cout<<"*******2. Repair and Back to the shop*******************************"<<endl;
		cout<<"*******3. Retrieve a vehicle in the List****************************"<<endl;
		cout<<"*******4. Remove all information in the DLL*************************"<<endl;
		cout<<"*******5. Display all information **********************************"<<endl;
		cout<<"*******6. Quit !!!**************************************************"<<endl;

		cin>>option;
		cin.ignore(100, '\n');

		if(option == 1)
		{
			int choice=0;
			cout<<" which kind of tools you want to use?"<<endl;
			cout<<"1.Scooter"<<endl;
			cout<<"2.Zip Car"<<endl;
			cout<<"3.bicycle"<<endl;

			cin>>choice;
			cin.ignore(100,'\n');

			dll.add_item(choice);

			cout<<"Add succeefully!"<<endl;
		}

		if(option ==2)
		{
			int match=0;
			cout<<"enter the id of the transportation"<<endl;
			cin>>match;
			cin.ignore(100, '\n');

			if(dll.remove(match)){
				cout<<"Remove succeelly"<<endl;}
			else
				cout<<" Wrong!"<<endl;
		}

		if(option == 3)
		{

			int match=0;
			cout<<"enter the id of the transportation you want to retrieve"<<endl;
			cin>>match;
			cin.ignore(100, '\n');

			if(dll.retrieve(match))
				cout<<"Find it"<<endl;
			else
				cout<<"Wrong !"<<endl;
		}
		if(option == 4)
		{
			if(dll.remove_all())
				cout<<"Remove succeelly"<<endl;
			else
				cout<<"Wrong !"<<endl;
		}
		
		if(option == 5)
		{
			dll.display();
		}
		else if(option == 6)
		{
			return 0;
		}
		else 
		{
			cout<<"Try again"<<endl;
		}

	}while(option !=6);

	return 0;

}
