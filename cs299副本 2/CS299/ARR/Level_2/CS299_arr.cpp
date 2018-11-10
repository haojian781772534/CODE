#include "CS299_arr.h"
#include <iostream>
using std::cout;
using std::endl;

int display_except(node *head[], int size){
    if(size == 0){
        return 0;
    }
    return display_except(head[size - 1]) + display_except(head, size - 1);
}
int display_except(node *head){
    if(!head || !head -> next){
        cout << endl;
        return 0;
    }

    cout << head -> data << " ";
    return 1 + display_except(head -> next);
}

int remove_last_lll(node *head[], int size){
    if(size == 0)
        return 0;
    int result = remove_last_lll(head[size - 1]);
    head[size - 1] = NULL;
    return result;
}
int remove_last_lll(node *&head){
    if(!head)
        return 0;
    node *temp = head;
    head = head -> next;
    temp -> next = NULL;
    delete temp;
    return 1 + remove_last_lll(head);
}

int add_node_every(node *head[], int size){
    if(size == 0)
        return 0;
    if(head[size - 1])
        return add_node_every(head[size - 1], head[size - 1] -> data) + add_node_every(head, size - 1);
    else{
        head[size - 1] = new node;
        head[size - 1] -> data = 0;
        head[size - 1] -> next = NULL;
        return 1 + add_node_every(head, size - 1);
    }
}
int add_node_every(node *&head, int first_data){
    if(!head){
        head = new node;
        head -> data = first_data;
        head -> next = NULL;
        return 1;
    }
    return add_node_every(head -> next, first_data); 
}
