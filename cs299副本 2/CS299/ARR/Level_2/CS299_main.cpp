#include "CS299_arr.h"
//Please place your name here:
//
//
using namespace std;

int main()
{
    node * head[SIZE] = {0,0,0,0,0};
    build(head);
    display_all(head);

    //PLEASE PUT YOUR CODE HERE to call the functions

    
    cout << "The number of nodes will be displayed is: " << display_except(head, SIZE) << endl;
    display_all(head);

    cout << "the number of last list(will be deleted) is: " << remove_last_lll(head, SIZE) << endl;
    display_all(head);

    cout << "the number of node that have been added is :" << add_node_every(head, SIZE) << endl;
    display_all(head);
    

    display_all(head);
    destroy(head);
    
    return 0;
}
