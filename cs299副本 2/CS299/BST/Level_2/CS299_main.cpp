#include "CS299_bst.h"
//Please place your name here:
//
//

int main()
{
    node * root = NULL;
    build(root);
    display_all(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
    largest_item(root);
    cout << "-------the times that root data appears in the BST " << root_data_time(root) << endl;

    cout << "-------the successor(was deleted) of root : " << del_succ(root);

    node *new_bst = NULL;
    copy_bst(new_bst, root);
    display_all(new_bst);


    display_all(root);
    destroy(root);

    return 0;
}
