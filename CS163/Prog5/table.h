//Jianqiang Hao
//8/12/2018
//CS163
//Prog5
//build a graph by using adjacency list
//the adjacency list will be an array of vertex and head
//for each linear linked list represent the edge list


#include<iostream>
#include<cctype>
#include<cstring>

struct vertex
{
	char *city_name;				//the name of city
	struct node *head;				//head pointer to node 
};

struct node
{
	vertex *adjacent;				//adjacent to use vertex's data
	node *next;					//next pointer
};


class graph
{
	public:
		graph(int size=7);			//constructor
		~graph();				//destructor
		int insert_vertex(char *);		//insert the vertex 
		int insert_edge(char *, char *);	//add a relationship with two nodes
		int find_location(char *);		//find the location of two city
		int display_all(char *);		//display the name of city and relationship

	private:
		vertex *adjacency_list;
		int list_size;
};
