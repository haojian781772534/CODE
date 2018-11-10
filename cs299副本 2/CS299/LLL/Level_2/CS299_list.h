//list.h
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;


//The data structure is a linear linked list of integers
struct node
{
    int data;
    node * next;
};

//These functions are already written and used by main
void build(node * & head);      //supplied
void display_all(node * head);  //supplied
void destroy(node * &head);     //supplied


/* *****************YOUR TURN! ******************************** */
/* PLACE YOUR PROTOTYPE HERE */
bool find(node *head, int match);
int display_every_other(node *head);
int insert_before_last(node *& head, int to_add);
int remove_all(node *&head);
int remove_special(node *&head);
int copy(node *&head_dest, node *head_source);


