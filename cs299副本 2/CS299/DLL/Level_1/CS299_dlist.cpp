#include "CS299_dlist.h"

int remove_larger(node *&head){
    if(!head || !head -> next)   return 0;

    int count = 0;
    node *current = head -> next;

    while(current){
        if(current -> data > head -> data){
            node *temp = current;
            current = current -> next;
            temp -> previous -> next = temp -> next;
            if(temp -> next)
                temp -> next -> previous = temp -> previous;
            count++;
            delete temp;
        }
        else
            current = current -> next;
    }

    return count;
}
int remove_every_other(node *&head){
    if(!head)   return 0;

    int count = 0;
    node *current = head -> next;

    while(current){
        node *temp = current;
        current = current -> next;
        temp -> previous -> next = temp -> next;
        if(temp -> next)
            temp -> next -> previous = temp -> previous;
        delete temp;
        count++;
        if(current)
            current = current -> next;
        else
            break;
    }

    return count;
}
int duplicate_2(node *&head){
    if(!head)   return 0;

    int count = 0;
    node *current = head;

    while(current){
        if(current -> data == 2){
            node *temp = new node;
            temp -> data = 2;
            temp -> previous = current;
            temp -> next = current -> next;
            if(temp -> next)
                temp -> next -> previous = temp;
            current -> next = temp;
            count++;
            if(temp -> next)
                current = temp -> next;
            else
                current = NULL;
        }
        current = current -> next;
    }

    return count;
}
