#include "CS299_dlist.h"

int swap_last_two(node *&head){
    if(!head || !head -> next)
        return 0;
    if(head -> next -> next == NULL && head -> previous == NULL){
        head -> previous = head -> next;
        head -> next -> next = head;
        head -> next = NULL;
        head -> next -> previous = NULL;
        head = head -> previous;
    }
    if(head -> next -> next -> next != NULL){
        return swap_last_two(head -> next);
    }
    else{
        node *temp1 = head -> next;
        node *temp2 = head -> next -> next;
        int result = temp1 -> data + temp2 -> data;

        head -> next = temp2;

        temp2 -> next = temp1;
        temp2 -> previous = head;

        temp1 -> next = NULL;
        temp1 -> previous = temp2;
        return result;
    }
}

int display_reverse(node *head){
    if(!head)
        return 0;
    if(!head -> next){
        cout << head -> data << "=>";
        return head -> data;
    }
    int last_number = display_reverse(head -> next);
    cout << head -> data << "=>";
    return last_number;
}

bool add_node(node *&head, int to_add){
    if(!head){
        head = new node;
        head -> next = NULL;
        head -> previous = NULL;
        head -> data = to_add;
        return true;
    }
    if(head -> data != to_add){
        if(!head -> next){
            head -> next = new node;
            head -> next -> data = to_add;
            head -> next -> next = NULL;
            head -> next -> previous = head;
            return true;
        }
        return add_node(head -> next, to_add);
    }
    else
        return false;
}

bool duplicate(node *&new_copy, node *original){
    if(!original)
        return false;
    duplicate(new_copy, NULL, original);
    return true;
}
void duplicate(node *&new_copy, node *previous_node, node * original){
    if(!original)
        return;
    new_copy = new node;
    new_copy -> data = original -> data;
    new_copy -> next = NULL;
    new_copy -> previous = previous_node;
    new_copy -> next = new node;
    new_copy -> next -> data = original -> data;
    new_copy -> next -> next = NULL;
    new_copy -> next -> previous = new_copy;
    duplicate(new_copy -> next -> next, new_copy -> next, original -> next);
}

