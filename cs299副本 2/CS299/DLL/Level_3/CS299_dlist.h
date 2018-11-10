//doubly linked list
//Notice that there is a head and a tail pointer!!!
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;		//some questions use a char * data;
    node * previous;
    node * next;
};

class list
{
    public:
        //These functions are already written
        list();         //supplied
        ~list();        //supplied
        void build();   //supplied
        void display(); //supplied
        

     /* *****************YOUR TURN! ******************************** */
     /* place your prototype here */
        int display_last_two();
        int remove_last_two();
        float add_average();
        int remove_largest_two();
     
     private:
         node * head;   //notice there is both a head
         node * tail;   //and a tail, common for DLL
         int display_last_two(node *head);
         int remove_last_two(node *&head);
         float add_average(node *&head, int sum, int count);
         int remove_largest_two(node *&head, int &a, int &b);
};
