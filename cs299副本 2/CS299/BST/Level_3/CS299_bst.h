#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class table
{
    public:
    	//These functions are supplied already
    	table();			//supplied
    	~table();			//supplied
        void build(); 		//supplied
        void display(); 	//supplied


/* ************** PLACE YOUR PROTOTYPE HERE ***************** */

        int remove_largest();
        int display_smaller();
        int count_larger();
        int remove_leaf();
        int copy_multiples(table &);
 
 	private:
 		node * root;
        int remove_largest(node *&root);
        int display_smaller(node *root, int data);
        int count_larger(node *root, int data);
        int get_smallest_data(node *root);
        int remove_leaf(node *&root);
        int copy_multiples(node *&, node *);
};
  

