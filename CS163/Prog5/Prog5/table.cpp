//Jianqiang Hao
//CS163
//Prog5
//08/12/2018
//build a graph by using adjacency list
//the adjacency list will be an array of vertex and head
//for each linear linked list represent the edge list


#include"table.h"
using namespace std;



//constructor
graph :: graph(int size)
{
	list_size=size;

	adjacency_list =new vertex[size];
	for(int i=0; i<size; i++)
	{
		adjacency_list[i].head=NULL;
		adjacency_list[i].city_name=NULL;
	}
}



//destructor
graph :: ~graph()
{
	for(int i=0; i<list_size; i++)
	{
		delete []adjacency_list[i].head;
		adjacency_list[i].head=NULL;
		delete []adjacency_list[i].city_name;
		adjacency_list[i].city_name=NULL;
		delete []adjacency_list;
	}
	adjacency_list=NULL;
}



// store the vertex at the location
int graph:: insert_vertex(char *current)
{
	int i=0;
	while(adjacency_list[i].city_name && i<list_size)
		i++;

	if(i==list_size)
		return 0;

	adjacency_list[i].city_name = new char;
	if(strcpy(adjacency_list[i].city_name, current))
		return 1;

	delete adjacency_list[i].city_name;
	adjacency_list[i].city_name=NULL;
	return 0;
}



// find the location in the graph
int graph:: find_location(char *key)
{
	if(!key)
	  return 0;
	int i=0;
	while(adjacency_list[i].city_name && strcmp(adjacency_list[i].city_name, key)!=0 && i<list_size)
		++i;
	if(i==list_size)
		return -1;
	return i;
}



//atach an edge to a vertex
int graph :: insert_edge( char * current_vertex, char * to_attach)
{
	int i=find_location(current_vertex);
	if(i<0)
	  return 0;
	int j =find_location(to_attach);
	if(j<0)
	  return 0;

	node *temp= new node;
	temp->next=adjacency_list[i].head;
	temp->adjacent= &adjacency_list[j];
	adjacency_list[i].head=temp;
	return 1;
}



//display all information
int graph:: display_all(char *key)
{
	int i =find_location(key);
	if(i<0)
	  return 0;
	node *head=adjacency_list[i].head;
	cout<<" the vertex city name is:"<<adjacency_list[i].city_name<<endl;
	while(head)
	{
		cout<<"The city name is:"<<head->adjacent->city_name<<endl;
		head=head->next;
	}
	return 1;
}
