#include "CS299_bst.h"

int main()
{
    node * root = NULL;
    build(root);
    display_all(root);

    /*  PLACE YOUR FUNCTION CALL HERE */

    cout << "-------the number of nodes that biger than root: " << count_biger(root) << endl;
    cout << "-------the sum of leaf node data: " << calc_leaf(root) << endl;
    cout << "-------the height of tree: " << height(root) << endl;
    cout << "-------the successor of root is : " << root_succ(root) << endl;
    
    node *new_bst = NULL;
    copy_bst(new_bst, root);
    display_all(new_bst);

    cout << "-------destroy the BST" << endl;
    release(root); 
    display_all(root);


    destroy(root);
    return 0;
}
