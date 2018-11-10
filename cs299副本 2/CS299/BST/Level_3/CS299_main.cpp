#include "CS299_bst.h"
//Please place your name here:
//
//

int main()
{
    table object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */

    cout << "-------the largest item(was deleted) is: " << object.remove_largest() << endl;

    cout << "-------the number of nodes that smaller than root : " << object.display_smaller() << endl;
    cout << "-------the number that larger than the smallest node: " << object.count_larger() << endl;
    cout << "-------the number of leaves(was deleted) : " << object.remove_leaf();

    table new_a;
    cout << "------the number of node that copied: " << object.copy_multiples(new_a);
    new_a.display();

    object.display();	//displays again after!
   
    return 0;
}
