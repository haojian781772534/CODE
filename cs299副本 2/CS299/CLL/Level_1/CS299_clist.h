//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & rear);  //supplied
void display_all(node * rear);  //supplied
void destroy(node * & rear); //supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:

int display_except(node *rear);
bool remove_last(node *&rear);
int copy_all(node *&new_rear, node *source_rear);
