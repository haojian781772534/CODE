#include "CS299_bst.h"

int table::remove_largest(){
    return remove_largest(root);
}

int table::remove_largest(node *&root){
    if(!root)
        return 0;
    if(root -> right){
        return remove_largest(root -> right);
    }
    node *temp = root;
    root = root -> left;
    int result = temp -> data;
    delete temp;
    return result;
}

int table::display_smaller(){
    return display_smaller(root, root -> data);
}

int table::display_smaller(node *root, int data){
    if(!root)
        return 0;
    int count = 0;
    if(root -> data < data){
        cout << root -> data << " ";
        count++;
    }
    return count + display_smaller(root -> left, data) + display_smaller(root -> right, data);
}

int table::count_larger(){
    return count_larger(root, get_smallest_data(root));
}
int table::get_smallest_data(node *root){
    if(!root)
        return 0;
    if(root -> left)
        return get_smallest_data(root -> left);
    return root -> data;
}
int table::count_larger(node *root, int data){
    if(!root)
        return 0;
    int count = 0;
    if(root -> data > data)
        count++;
    return count + count_larger(root -> left, data) + count_larger(root -> right, data);

}

int table::remove_leaf(){
    return remove_leaf(root);
}
int table::remove_leaf(node *&root){
    if(!root)
        return 0;
    if(!root -> left && !root -> right && root -> data != this -> root -> data){
        delete root;
        root = NULL;
        return 1;
    }
    return remove_leaf(root -> left) + remove_leaf(root -> right);
    
}

int table::copy_multiples(table &new_copy){
    return copy_multiples(new_copy.root, root);
}

int table::copy_multiples(node *&new_root, node *source_root){
    if(!source_root)
        return 0;
    new_root = new node;
    new_root -> left = new_root -> right = NULL;
    new_root -> data = source_root -> data / 3;
    return 1+copy_multiples(new_root -> left, source_root -> left) + copy_multiples(new_root -> right, source_root -> right);
}
