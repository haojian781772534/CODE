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
    
    cout << "The longest lll's length is: " << find_longest(head, SIZE) << endl;
    
    cout << "The number of nodes that has been removed: " << remove_last(head, SIZE) << endl;
    display_all(head);

    cout << "The number of last lll(after add a node): " << add_last(head, SIZE) << endl;
    display_all(head);

    cout << "The number of whole table is: " << append_last(head, SIZE) << endl;

    build(head);
    display_all(head);
    cout<< "The number of whole table is: " << remove_ptr(head, SIZE) << endl;

    

    display_all(head);
    destroy(head);
    
    return 0;
}
