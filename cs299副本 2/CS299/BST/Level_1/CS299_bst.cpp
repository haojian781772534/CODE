#include "CS299_bst.h"

int count_biger(node *root){
    cout << "-------root data: " << root -> data;
    return count_biger(root, root -> data);
}
int count_biger(node *root, int root_data){
    if(!root)
        return 0;
    int count = 0;
    if(root -> data > root_data)
        count++;
    count += (count_biger(root -> left, root_data) + count_biger(root -> right, root_data));
    return count;
}

int calc_leaf(node *root){
    if(!root)
        return 0;
    if(!root -> left && !root -> right)
        return root -> data;
    return calc_leaf(root -> left) + calc_leaf(root -> right);
}

int height(node *root){
    if(!root)
        return 0;
    int left = height(root -> left);
    int right = height(root -> right);
    return (left > right) ? (left + 1) : (right + 1);
}

int root_succ(node *root){
    if(!root || !root -> right)
        return 0;
    node * temp = root -> right;
    while(temp -> left){
        temp = temp -> left;
    }
    return temp -> data;
}

void release(node *&root){
    if(!root)
        return;
    release(root -> left);
    release(root -> right);
    delete root;
    root = NULL;
}

void copy_bst(node *&new_root, node *source_root){
    if(!source_root){
        new_root = NULL;
        return;
    }
    new_root = new node;
    new_root -> data = source_root -> data;
    copy_bst(new_root -> left, source_root -> left);
    copy_bst(new_root -> right, source_root -> right);
}
