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
 

int count_biger(node *root);
int count_biger(node *root, int root_data);

int calc_leaf(node *root);

int height(node *root);

int root_succ(node *root);

void release(node *&root);

void copy_bst(node *&, node *source);
