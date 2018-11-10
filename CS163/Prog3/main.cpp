//Jianqiang Hao
//CS163
//Prog3
//08/1//2018
//to create a hash table using chaining 
//and use file operations
//


#include"table.h"
using namespace std;


int main()
{
	table h_table;
	int response1;
	char response2;
	if(h_table.create_information()==0)
		cout<<"Wrong in the base file"<<endl<<endl;

	else
	{
	   do
	   {
		   cout<<"Please Choose these Operation"<<endl;
		   cout<<"******* 1.Add a new item ****************************"<<endl;

		   cout<<"******* 2.Remove the elements in the item ***********"<<endl;

		   cout<<"******* 3.Display all information in the item *******"<<endl;

		   cout<<"******* 4.Display all items *************************"<<endl;

		   cout<<"******* 5.Retrieve about a item *********************"<<endl<<endl;

		   cin>>response1;
		   cin.ignore(100,'\n');
		   if(response1 == 1)
		   {
			if(h_table.insert_table())
				cout<<"Insert Succeedly"<<endl;
			else
				cout<<"Wrong !"<<endl;
		   }
		   else if(response1 == 2)
		   {
			char temp[SIZE];
			cout<<"Please enter the name of item you wanna delete"<<endl;
			cin.get(temp,SIZE,'\n');
			cin.ignore(100,'\n');
			if(h_table.remove(temp))
				cout<<" delete Succeedly"<<endl;
			else
				cout<<"Wrong !"<<endl;
		   }
		   else if(response1 == 3)
		   {
			   char temp2[SIZE];
			   cout<<"Please enter the name of item you wanna display"<<endl;
			   cin.get(temp2,SIZE,'\n');
			   cin.ignore(100,'\n');
			   if(h_table.display(temp2))
				   cout<<" display this item"<<endl;
			   else
				   cout<<"Wrong !"<<endl;
		   }
		   else if(response1 == 4)
		   {
			   if(h_table.display_all())
				   cout<<"display all information succeedly"<<endl;
			   else 
				   cout<<"Wrong !"<<endl;
		   }
		   else if(response1 == 5)
		   {
			   char temp3[SIZE];
			   cout<<"Please enter the name of item you wanna retrieve"<<endl;
			   cin.get(temp3, SIZE,'\n');
			   cin.ignore(100,'\n');
			   if(h_table.retrieve(temp3))
			   {
				   cout<<"this item was found"<<endl;
			   	   h_table.display(temp3);
				   
				   cout<<endl;
			   }
			   else 
				   cout<<"Wrong ! not found"<<endl;
		   }
		   else 
			{
				cout<<"Wrong !"<<endl;
			}

			   cout<<" Continue?  Y/N"<<endl;
			   cin>>response2;
			   cin.ignore(100,'\n');
		   
	   	}while(toupper(response2)=='Y');

	}
	  
	return 1;
}
