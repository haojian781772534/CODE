//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;   //some questions are a char * data;
    node * next;
};

class list
{
   public:
   //These functions are already written for you
     list();			//supplied
     ~list();			//supplied
     void build();     		//supplied
     void display();  		//supplied
    
    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:
    bool remove_last_two();    
    float average();
    int add_99();
    int copy_even(list &new_list);

   private:		//notice there is both a head and a tail!
      node * head;
      node * tail;
      bool remove_last_two(node *&head);
      int average(node *head, int &count);
      bool rlt(node *&head, int head_data); 
      int add_99(node *head);
      int copy_even(node *&dest, node *source);
};
