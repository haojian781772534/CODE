//Jianqiang Hao
//CS163
//Prog2
//07/22/2018
//to find some satisfactory features about computer,
//where you can find them in the store. Using data structure is queue and stack.


#include"queue.h"
#include"stack.h"
using namespace std;

int main()
{
	char response1;
	do
	{
		stack found_computer;
		queue found_feature;
		int response2=0;
		int response3=0;
		int response4=0;

		do
		{
			cout<<"*******Please choose option*******"<<endl;
			cout<<"       1.Look for your feature you like"<<endl;
			cout<<"       2.Find your computer"<<endl;
			cout<<"       3.Quit!"<<endl;
			cin>>response2;
			cin.ignore(100, '\n');

			if(response2==1)
			{
				cout<<"*** Welcome to the feature"<<endl;
				cout<<"****Please choose one function"<<endl;
				cout<<"*****1.Add a feature "<<endl;
				cout<<"*****2.Remove a feature "<<endl;
				cout<<"*****3.Display all feature"<<endl;
				cout<<"*****4.Peek!"<<endl<<endl;
				cin>>response3;
				cin.ignore(100,'\n');
				if(response3==1)
				{
					
					char temp1[SIZE];
					cout<<"Please enter the computer's trademark"<<endl;
					cin.get(temp1,SIZE,'\n');
					cin.ignore(200,'\n');
	
					char temp2[SIZE];
					cout<<"Please enter the computer'memory"<<endl;
					cin.get(temp2,SIZE,'\n');
					cin.ignore(200,'\n');
	
					char temp3[SIZE];
					cout<<"Please enter the computer's type"<<endl;
					cin.get(temp3,SIZE,'\n');
					cin.ignore(200,'\n');
	
					char temp4[SIZE];
					cout<<"Please enter the computer's other feature"<<endl;
					cin.get(temp4,SIZE,'\n');
					if(found_feature.enqueue(temp1,temp2, temp3, temp4)==1)
						cout<<"*******Add succeedly"<<endl;
					else
						cout<<"*******Wrong!"<<endl;
				}
				
				if(response3==2)
				{
					if(found_feature.dequeue()==1)
						cout<<"*******Delete succeedly"<<endl;
					else
						cout<<"*******Wrong!"<<endl;
				}
				
				if(response3==3)
				{
					found_feature.display();
				}
				if(response3==4)
				{
					if(found_feature.peek()!=1)
						return 0;
				}
			}
			else if(response2==2)
			{	
				cout<<"*** Welcome to the computer"<<endl;
				cout<<"****Please choose one function"<<endl;
				cout<<"*****1.Add a computer "<<endl;
				cout<<"*****2.Remove a computer "<<endl;
				cout<<"*****3.Display all computer"<<endl;
				cout<<"*****4.Peek(return the top data)"<<endl<<endl;	
				cin>>response4;
				cin.ignore(100,'\n');
				if(response4==1)
				{
					if(found_computer.push()==1)
						cout<<"*******Add succeedly"<<endl;
					else
						cout<<"*******Wrong!"<<endl;
				}
				
				if(response4==2)
				{
					if(found_computer.pop()==1)
						cout<<"*******Delete succeedly"<<endl;
					else
						cout<<"*******Wrong!"<<endl;
				}
					
				if(response4==3)
				{
					found_computer.display_all();
				}
				if(response4==4)
				{	
					cout<< "this is peek:"<<endl;
					product to_copy;
					if(found_computer.peek(to_copy))
					to_copy.display();
					else 
						cout<<"*******Wrong!"<<endl;
				}
			}
			else if(response2==3)
			{
				return 0;
			}
			else {
				cout<<"Please enter the number(1-3)"<<endl;
				cin>>response2;
				cin.ignore(100,'\n');
			}
				}while(response2!=1||response2!=2);
				cout<<"Again? Y/N"<<endl<<endl;
				cin>>response1;
				cin.ignore(100,'\n');
			
				}while(toupper(response1)=='Y');
			return 0;
}
