//arr.h
#include <iostream>
#include <cstring>
#include <cctype>

const int SIZE = 5;	//size of the array of head pointers

struct node
{
    int data;
    node * next;
};


/* These functions are already written and can be called to test out your code */
void build(node * head[]);  //supplied
void display_all(node * head[]);  //supplied
void destroy(node * head[]); //supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:


int find_longest(node *head[], int size);
int remove_last(node *head[], int size);
int add_last(node *head[], int size);
int append_last(node *head[], int size);
int remove_ptr(node *head[], int size);

