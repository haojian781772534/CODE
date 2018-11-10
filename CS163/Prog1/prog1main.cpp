//Jianqiang Hao
//CS163
//Program1
//7/1/2018
//a program that help students understand all that is expected of 
// your time this summer to be succeed in CS163


#include"program1.h"
#define SIZE 30
using namespace std;

int main()
{
	int response1=0;
	char response2;
	list my_list;
/*
class list
{
   public:
	list();
	~list();
	int add_node( char *);

	bool find_node(char *);
	bool find_node(node *, char *);

	int display();
	int display_item(char *);
	int add_item(char * , char *, char *, char *, char *);
	int isfinish_item(char *, char *);	
   private:
	node *head;
};*/

	do{
		cout<< "	Welcome to Your Sedchule"<<endl;
		cout<< "        	please choose"<<endl;
		cout<< "******* 1.Add a project*******************************************\n";
		cout<< "******* 2.Find a project******************************************\n";		
		cout<< "******* 3.Display all project*************************************\n";
		cout<< "******* 4.Display all items in a project**************************\n";
		cout<< "******* 5.Add a item in the project*******************************\n";
		cout<< "******* 6.Remove a item form a project****************************\n";
		cout<< "******* 7.Remove a category of all work***************************\n";
		cout<< "******* 8.Quit,Thanks*********************************************"<<endl;

		cin>>response1;
		cin.ignore(200,'\n');
		if(response1==1)
		  {
			char temp[SIZE];
			cout<<"Please enter the name of category"<<endl;
			cin.get(temp,SIZE,'\n');
			cin.ignore(200,'\n');

			if(my_list.add_node(temp))
				cout<<"you already add a category"<<endl;
			else
				cout<<"WRONG, not found"<<endl;
		  }
		if(response1==2)
		  {
			cout<<"Please enter the name of category"<<endl;
			char temp1[SIZE];
			cin.get(temp1,SIZE,'\n');
			cin.ignore(200,'\n');
			if(my_list.find_node(temp1))
				cout<<"you found a category"<<endl;
			else
				cout<<"WRONG, not found"<<endl;
		  }
		if(response1==3)
		  {
			cout<<"Display all category"<<endl;
			my_list.display();
			cout<<endl;
		  }
		if(response1==4)
		  {
							
			cout<<"Please enter the name of category"<<endl;
			char temp2[SIZE];
			cin.get(temp2,SIZE,'\n');
			cin.ignore(200,'\n');
			if(my_list.find_node(temp2))
			  {
				cout<<"you found a category "<<endl;
				my_list.display_item(temp2);
				cout<<endl;
			  }
			else
				cout<<"WRONG, not found"<<endl;
		  }
		if(response1==5)
		  {
			
			cout<<"Please enter the name of category"<<endl;
			char temp3[SIZE];
			cin.get(temp3,SIZE,'\n');
			cin.ignore(200,'\n');
			if(my_list.find_node(temp3))
			  {
				cout<<"you found a category, you can enter the name of item "<<endl;
				char temp4[SIZE];
				cin.get(temp4,SIZE,'\n');
				cin.ignore(200,'\n');
				/*
				char *item_name;
	                        char *ontime_due;
			       	char *late_due;
				char *due_time;
				*/
				cout<<" Please enter the on time, you can submit your homework"<<endl;
				char temp5[SIZE];
				cin.get(temp5,SIZE,'\n');
				cin.ignore(200, '\n');
				
				cout<<" Please enter the late time, you can submit your homework"<<endl; 
				char temp6[SIZE];
				cin.get(temp6,SIZE,'\n');
				cin.ignore(200, '\n');
			
				cout<<"Please enter due time"<<endl;
				char temp7[SIZE];
				cin.get(temp7,SIZE,'\n');
				cin.ignore(200,'\n');

				if(my_list.add_item(temp3, temp4, temp5, temp6, temp7))
					cout<<" add item succeedly"<<endl;
				else 
					cout<<"WRONG"<<endl;
			}
			else
				cout<<" WRONG! not found"<<endl;
			}
		if (response1==6)
			{
				char temp8[SIZE];
				char temp9[SIZE];
				cout<<"Please enter the name of category"<<endl;	
				cin.get(temp8,SIZE,'\n');
				cin.ignore(200,'\n');	
				cout<<"Please enter the name of items"<<endl;
				cin.get(temp9,SIZE,'\n');
				cin.ignore(200,'\n');

				if(my_list.finish_item(temp8, temp9))
					cout<<"Remove succeedly"<<endl;
				else
					cout<<"WRONG, not found"<<endl;
			}
		if(response1==7)
			{
				char temp10[SIZE];
				cout<<"Please enter the name of category"<<endl;
				cin.get(temp10,SIZE,'\n');
				cin.ignore(200,'\n');
				if(my_list.remove_category(temp10))
					cout<<"Remove succeedly"<<endl;
				else
					cout<<"WRONG, not found"<<endl;

			}
		if(response1==8)
			{
				return 0;
			}
		cout<<"Do you want to Continue?  (y/n)"<<endl;
		cin>>response2;
		cin.ignore(200,'\n');

	}while(response2=='y');

		return 0;
}			
					

			

