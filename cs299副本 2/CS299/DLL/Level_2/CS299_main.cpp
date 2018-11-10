#include "CS299_dlist.h"
//Please place your name here
//
//
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display_all(head);

    //PLEASE PUT YOUR CODE HERE to call the functions


    cout << "the sum of last two: " << swap_last_two(head) << endl;

    cout << "display the nodes, and the last number is : " << display_reverse(head) <<endl;

    cout << "add a data if it doesn't exist in list : " << add_node(head, 99) << endl;

    cout << "add a data if it doesn't exist in list : " << add_node(head, 2) << endl;

    node *new_list;
    cout << "duplicate copy from head: " << duplicate(new_list, head) << endl;
    display_all(new_list);

    display_all(head);
    destroy(head);    
    return 0;
}
