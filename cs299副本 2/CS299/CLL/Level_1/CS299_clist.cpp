#include "CS299_clist.h"
int display_except(node *rear){
    if(!rear || rear -> next == rear)
        return 0;
    node *temp = rear -> next;
    int count = 0;
    while(temp != rear){
        count++;
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    return count;
}
bool remove_last(node *&rear){
    if(!rear)
        return false;
    if(rear -> next == rear){
        delete rear;
        if(!rear)
            return true;
        else
            return false;
    }
    node *temp = rear -> next;
    while(temp -> next != rear){
        temp = temp -> next;
    }
    temp -> next = rear -> next;
    delete rear;
    if(!rear)
        return false; 
    rear = temp;
    return true;
}
int copy_all(node *&new_rear, node *source_rear){
    if(!source_rear)
        return 0;
    else{
        int count = 0;
        node *temp2 = source_rear -> next;
        if(!new_rear){
            new_rear = new node;
            new_rear -> next = new_rear;
            new_rear -> data = source_rear -> data;
            count++;
        }
        while(temp2 != source_rear){
            node *temp1 = new node;
            temp1 -> next = new_rear -> next;
            new_rear -> next = temp1;
            temp1 -> data = temp2 -> data;
            temp2 = temp2 -> next;
            count++;
        }
        return count;
    }
}
