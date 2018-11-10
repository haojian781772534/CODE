#include "CS299_bst.h"
#define MAX(x, y) ((x) > (y)) ? (x) : (y)
int largest_item(node *root){
    int result = largest(root);
    cout << "------- the largest item of BST is " << result << endl;
    return result;
}

int largest(node *root){
    if(!root)
        return 0;
    int left_largest = largest(root -> left);
    int right_largest = largest(root -> right);
    int largest = MAX(root -> data, MAX(left_largest, right_largest));

    return largest;
}
int root_data_time(node *root){
    return root_data_time(root, root -> data);
}
int root_data_time(node *root, int root_data){
    if(!root)
        return 0;
    int count = 0;
    if(root -> left && root -> left -> data == root_data)
        count++;
    if(root -> right && root -> right -> data == root_data)
        count++;
    count = count + root_data_time(root -> left, root_data) + root_data_time(root -> right, root_data);
    return count;
}

int del_succ(node *&root){
    if(!root || !root -> right)
        return 0;
    if(root -> right -> left == NULL){
        node * temp = root -> right;
        root -> right = temp -> right;
        int result = temp -> data;
        delete temp;
        return result;
    }
    else{
        return del_succ_going(root -> right);
    }
}
int del_succ_going(node *&root){
    if(!root)
        return 0;
    if(root -> left)
        return del_succ_going(root -> left);
    node * temp = root;
    root = root -> right;
    int a = temp -> data;
    delete temp;
    return a;
}

void copy_bst(node *&dest, node *source){
    if(!source)
        return;
    if(!dest){
        dest = new node;
        dest -> data = 99;
        dest -> left = dest -> right = NULL;
    }
    if(source -> left){
        dest -> left = new node;
        dest -> left -> left = dest -> left -> right = NULL;
        dest -> left -> data = source -> left -> data;
    }
    if(source -> right){
        dest -> right = new node;
        dest -> right -> left = dest -> right -> right = NULL;
        dest -> right -> data = source -> right -> data;
    }
    copy_bst(dest -> left, source -> left);
    copy_bst(dest -> right, source -> right);
}
