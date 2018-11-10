#include "CS299_clist.h"

int removal_entire(node *&rear){
    if(!rear)
        return 0;
    node *temp = rear -> next;
    if(temp -> next == rear -> next){
        delete rear;
        rear = NULL;
        return 1;
    }
    else{
        rear -> next = temp -> next;
        delete temp;
        return 1 + removal_entire(rear);
    }
}
int count_all(node *rear){
    return count_all(rear -> next, rear);
}
int count_all(node *rear, node *real_rear){
    if(!rear)
        return 0;
    if(rear == real_rear){
        if(rear -> data %2 == 0)
            return 1;
        else
            return 0;
    }
    if(rear -> data %2 == 0){
        return 1 + count_all(rear -> next, real_rear);
    }
    else
        return count_all(rear -> next, real_rear);
}
bool add_end(node *&rear, int to_add){
    return add_end(rear -> next, rear, to_add);
}
bool add_end(node *&rear, node *real_rear, int to_add){
    if(!rear){
        rear = new node;
        rear -> next = rear;
        rear -> data = to_add;
        return false; //if the data is inexistent in the list, a node will be add
    }
    if(rear == real_rear){
        if(rear -> data == to_add)
            return true;
        else{
            rear = new node;
            rear -> next = real_rear;
            rear -> data = to_add;
            return false;
        }
    }
    if(rear -> data == to_add){
        return true;
    }
    else{
        return add_end(rear -> next, real_rear, to_add);
    }
}

bool duplicate(node *&new_copy, node *original){
    return duplicate(new_copy, original, original);
}
bool duplicate(node *&new_copy, node *orgnl_current, node *orgnl_rear){
    if(!orgnl_current)
        return false;
    if(!new_copy){
        new_copy = new node;
        new_copy -> data = orgnl_current -> data;
        new_copy -> next = new node;
        new_copy -> next -> data = orgnl_current -> data;
        new_copy -> next -> next = new_copy;
        return duplicate(new_copy, orgnl_current -> next, orgnl_rear);
    }
    if(orgnl_current -> next != orgnl_rear){
        node *temp = new node;
        temp -> data = orgnl_current -> data;
        temp -> next = new node;
        temp -> next -> data = orgnl_current -> data;
        temp -> next -> next = new_copy -> next;
        new_copy -> next = temp;
        return duplicate(new_copy, orgnl_current -> next, orgnl_rear);
    }
    else{
        node *temp = new node;
        temp -> data = orgnl_current -> data;
        temp -> next = new node;
        temp -> next -> data = orgnl_current -> data;
        temp -> next -> next = new_copy -> next;
        new_copy -> next = temp;
        return true;
    }
}
