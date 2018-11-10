#include "CS299_list.h"

bool find(node *head, int match){
    if(!head)
        return false;
    if(head -> data == match)
        return true;
    else
        return find(head -> next, match);
}

int display_every_other(node *head){
    if(!head)
        return 0;
    cout << head -> data << " ";
    return 1 + display_every_other(head -> next);
}

int insert_before_last(node *&head, int to_add){
    if(!head){
        head = new node;
        head -> next = NULL;
        head -> data = to_add;
        return to_add;
    }
    if(!head -> next){
        node *current = new node;
        current -> next = head;
        current -> data = to_add;
        head = current;
        return head -> next -> data;
    }
    if(head -> next -> next){
        return insert_before_last(head -> next, to_add);
    }
    else{
        node * tail = head -> next;
        head -> next = new node;
        head -> next -> next = tail;
        head -> next -> data = to_add;
        return tail -> data;
    }
}
int remove_all(node *&head){
    if(!head)
        return 0;
    int number = remove_all(head -> next);
    delete head;
    head = NULL;
    return number + 1;
}



int remove_special(node *& head){
    if(!head || !head -> next || !head -> next -> next){
        return 0;
    }
    else{
        node *current = head -> next;
        head -> next = current -> next;
        int rest_of_number = remove_special(head);
        int current_number = current -> data;
        delete current;
        return rest_of_number + current_number;
    }
}


int copy(node *&head_dest, node *head_source){
    if(!head_source){
        return 0;
    }
    head_dest = new node;
    head_dest -> data = head_source -> data;
    head_dest -> next = NULL;
    return 1 + copy(head_dest -> next, head_source -> next);
}
