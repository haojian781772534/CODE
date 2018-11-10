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
    cout << "the number of deleted: " << remove_every_other(head) << endl;
    display_all(head);

    cout << "the number of larger nodes: " << remove_larger(head) << endl;
    display_all(head);
    
    cout<< "--------------------------------------------------" <<endl;
    build(head);
    display_all(head);
    cout << "the number of duplicated: " << duplicate_2(head) << endl;


    display_all(head);
    destroy(head);    
    return 0;
}
