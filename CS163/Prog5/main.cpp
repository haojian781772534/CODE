//Jianqiang Hao
//CS163
//Prog5
//08/12/2018
//build a graph by using adjacency list
//the adjacency list will be an array of vertex and head
//for each linear linked list represent the edge list


#include"table.h"
#define SIZE 30
using namespace std;


int main()
{
	graph g_list;
	int  response1;
	char response2;

	do
	{
		cout<<" Welcome to use!"<<endl;
		cout<<"1. enter the vertex!"<<endl;
		cout<<"2. please enter the roads about two city"<<endl;
		cout<<"3. please enter which city you want to check:"<<endl<<endl;

		cin>>response1;
		cin.ignore(100,'\n');
		if(response1 == 1)
		{
			cout<<" Please enter the vertex in the graph"<<endl;
			char temp1[SIZE];
			cin.get(temp1,SIZE, '\n');
			cin.ignore(100, '\n');

			int i=0;
			i=g_list.insert_vertex(temp1);
			if(i==1)
			{
				cout<<" insert succeedly"<<endl;
			}
			else
				cout<<" Wrong, this list is full"<<endl;
		}
		else if(response1 ==2)
		{
			cout<<"please enter first city name that you want to related"<<endl;
			char temp2[SIZE];
			char temp3[SIZE];

			cin.get(temp2, SIZE,'\n');
			cin.ignore(100, '\n');

			cout<<" please enter second city name:"<<endl;
			cin.get(temp3,SIZE,'\n');
			cin.ignore(100,'\n');
			int j=0;
			j=g_list.insert_edge(temp2,temp3);
			if(j==1)
				cout<<"Insert successfully"<<endl;
			else
				cout<<"Wrong!"<<endl;
		}
		else if(response1 ==3)
		{
			char temp4[SIZE];
			cout<<"please enter which course you want to check:"<<endl;
			cin.get(temp4,SIZE,'\n');
			cin.ignore(100,'\n');

			g_list.display_all(temp4);
		}
		cout<<"Again Y/N"<<endl;
		cin>>response2;
		cin.ignore(100,'\n');
	}while(toupper(response2) == 'Y');

	return 0;
}





		

