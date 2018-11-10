#include "CS299_list.h"

//Place your name here in comments:
//
//
//
int main()
{
    //The following code builds the linear linked list
    node * head = NULL;
    build(head);
    display_all(head);

    //PLEASE PUT YOUR CODE HERE to call the functions
    cout << "find 2 (1 means true, 0 means false):" << find(head, 2)<< "\n";
    cout << "find 99 (1 means true, 0 means false):" << find(head, 99) << "\n";
    cout << "number of display: " << display_every_other(head) << "\n";
    cout << "data of last node: " << insert_before_last(head, 99) << "\n"; 
    cout << "number of remove: " << remove_all(head) << "\n";
    build(head);
    display_all(head);
    cout << "sum of remove node: " << remove_special(head) << "\n";

    remove_all(head); 
    build(head);
    node *new_list ;
    cout << "number of copy: " << copy(new_list, head) << "\n";
    cout << "the new_list is : ";
    display_all(new_list);

    display_all(head);
    destroy(head);    

    return 0;
}
