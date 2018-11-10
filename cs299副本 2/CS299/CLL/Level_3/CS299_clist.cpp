#include "CS299_clist.h"

int list::add_before(){
    return add_before(rear);
}
int list::add_before(node *&current_rear){
    if(!rear)
        return 0;
    if(rear -> next == rear){
        if(rear -> data %2 == 0){
            node *temp = new node;
            temp -> next = rear;
            rear -> next = temp;
            return 1;
        }
        else
            return 0;
    }
    if(current_rear -> next == rear){
        if(rear -> data %2 == 0){
            node *temp = new node;
            temp -> next = current_rear -> next;
            current_rear -> next = temp;
            return 1;
        }
        else
            return 0;
    }
    if(current_rear -> next -> data %2 == 0){
        node *temp = new node;
        temp -> next = current_rear -> next;
        current_rear -> next = temp;
        return 1 + add_before(current_rear -> next -> next);
    }
    return add_before(current_rear -> next);
}
bool list::remove_same(){
    return remove_same(rear -> next);
}
bool list::remove_same(node *&rear){
    if(this -> rear -> next == this -> rear){
        return false;
    }
    if(rear == this -> rear){
        return false;
    }
    if(rear -> data == this -> rear -> data){
        node *temp = rear;
        rear = rear -> next;
        delete temp;
        return remove_same(rear -> next)||true;
    }
    return remove_same(rear -> next)||false;
}




bool list::switch_node(){
    if(!rear)
        return false;
    else if(rear -> next -> next == rear){
        rear = rear -> next;
        return true;
    }
    else{
        switch_node(rear -> next);
        return true;
    }
}
void list::switch_node(node *pre_rear){
    if(pre_rear -> next == rear){
        pre_rear -> next = rear -> next;
        rear -> next = rear -> next -> next;
        pre_rear -> next -> next = rear;
        rear = pre_rear -> next;
    }
    else
        switch_node(pre_rear -> next);
}






float list::copy_two(list &new_object){
    if(!rear)
        return 0;
    else
        return copy_two(new_object.rear, rear -> next) / 2;
}
int list::copy_two(node *&dest_rear, node *source_rear){
    if(source_rear == rear){
        dest_rear = new node;
        dest_rear -> data = source_rear -> data;
        dest_rear -> next = dest_rear;
        return source_rear -> data;
    }
    if(source_rear -> next == rear){
        dest_rear = new node;
        dest_rear -> data = source_rear -> data;
        dest_rear -> next = new node;
        dest_rear -> next -> data = source_rear -> next -> data;
        dest_rear -> next -> next = dest_rear;
        dest_rear = dest_rear -> next;
        return source_rear -> data + source_rear -> next -> data;
    }
    return copy_two(dest_rear, source_rear -> next);
}
