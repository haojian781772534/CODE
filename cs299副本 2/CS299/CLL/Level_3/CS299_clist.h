//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;	//some questions are a char * data;
    node * next;
};

class list
{
    public:
        //These functions are already written
        list();			//supplied
        ~list();		//supplied
        void build();	//supplied
        void display();	//supplied

        /* *****************YOUR TURN! ********************* */
        //Write your function prototype here:
        int add_before();
        bool remove_same();
        bool switch_node();
        float copy_two(list &new_object);
        
    private:
        node * rear;
        int add_before(node *&current_rear);
        bool remove_same(node *&rear);
        void switch_node(node *pre_rear);
        int copy_two(node *&dest_rear, node *source_rear);
};
