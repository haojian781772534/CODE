#include "CS299_clist.h"
//Please place your name here
//
//
//
using namespace std;

int main()
{
    node * rear = NULL;
    build(rear);
    display_all(rear);

    //PLEASE PUT YOUR CODE HERE to call the functions
    cout << "number of even nodes: " << count_all(rear) << endl;
    cout << "add a node 99, 0 means there isn't a same data in list: " << add_end(rear, 99) << endl;
    cout << "add a node 2, 0 means there isn't a same data in list: " << add_end(rear, 2) << endl;
    display_all(rear);
    node *new_rear = NULL;
    duplicate(new_rear, rear);
    display_all(new_rear);
    cout << "number of removed: " << removal_entire(rear) << endl;




    display_all(rear); //resulting list after your function call!
    destroy(rear);
    
    return 0;
}
