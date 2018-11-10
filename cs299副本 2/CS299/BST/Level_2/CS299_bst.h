#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
};

void build(node * & root);   //supplied
void display_all(node *  root);  //supplied
void destroy(node * & root); //supplied
/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
 
  
int largest_item(node *root);
int largest(node *root);

int root_data_time(node *root);
int root_data_time(node *root, int root_data);

int del_succ(node *&root);
int del_succ_going(node *&root);

void copy_bst(node *&dest, node * source);
