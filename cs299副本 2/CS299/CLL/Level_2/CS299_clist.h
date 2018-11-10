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

int removal_entire(node *&rear);
int count_all(node *rear, node *real_rear);
int count_all(node *rear);
bool add_end(node *&rear, int to_add);
bool add_end(node *&rear, node *real_rear, int to_add);
bool duplicate(node *&new_copy, node *original);
bool duplicate(node *&new_copy, node *orgnl_current, node *orgnl_rear);

