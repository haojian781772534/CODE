//arr.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;  //some questions are char * data;
    node * next;
};

class table
{
    public:
        /* These functions are already written */
        table();		//supplied
        ~table();	//supplied
        void build();    //supplied
        void display();  //supplied


        /* *****************YOUR TURN! ******************************** */
        //Write your function prototype here:

        int display_reverse();
        float average_all();
        int copy_arr(table &source_head);


    private:
        node ** head;     //dynamically allocated array
        int size;	 //the array size

        int display_reverse(node **head, int index);
        int display_reverse(node *head);

        int average_all(node *head[], int index, int &sum);
        int average_all(node *head, int &sum);

        int copy_arr(node *head[], node *source[], int index);
        int copy_arr(node *&head, node *source);
};
