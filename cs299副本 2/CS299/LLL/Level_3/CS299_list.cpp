#include "CS299_list.h"

bool list::remove_last_two(){
    return remove_last_two(head);
}
bool list::rlt(node *&head, int head_data){
    if(head -> next -> next == tail){
        if((head -> next -> data + tail -> data) > head_data){
            delete tail;
            delete head -> next;
            tail = head;
            head -> next = NULL;
            return true;
        }
        else
            return false;
    }
    else{
        return rlt(head -> next, head_data);
    }
}

bool list::remove_last_two(node *&head){
    if(!head || !head -> next || !head -> next -> next)
        return false;
    else
        return rlt(head, head -> data);
}

float list::average(){
   int count = 0;
   return float(average(head, count)) / float(count);
}
int list::average(node *head, int &count){
    if(!head)
        return 0;
    else{
        return head -> data + average(head -> next, ++count);
    }
}

int list::add_99(){
    return add_99(head);
}
int list::add_99(node *head){
    if(!head || head == tail)
        return 0;
    if(head -> data > tail -> data){
        node *current = head -> next;
        head -> next = new node;
        head -> next -> data = 99;
        head -> next -> next = current;
        return 1 + add_99(current);
    }
    else
        return add_99(head -> next);
}
int copy_even(list &new_list){
    return copy_even(new_list.head, new_list.tail, head);
}
int copy_even(node *&dest, node *&tail, node *source){
    if(!source){
        dest = NULL;
        return 0;
    }
    if(source -> data %2 == 0){
        dest = new node;
        dest -> data = source -> data;
        dest -> next = NULL;
        tail = dest;
        return 1 + copy_even(dest -> next, tail, source -> next);
    }
    else{
        return copy_even(dest, tail, source -> next);
    }
}








