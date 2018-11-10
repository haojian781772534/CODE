#include "CS299_dlist.h"


int list::display_last_two(){
    return display_last_two(head);
}
int list::display_last_two(node *head){
    if(!head)
        return 0;
    if(!head -> next){
        cout << "last node: " << head -> data << endl;
        return head -> data;
    }

    int result = display_last_two(head -> next);

    if(!head -> next -> next){
        cout << "penult node: " <<head -> data << endl;
        return result + head -> data;
    }
    return result;
}

int list::remove_last_two(){
    return remove_last_two(head);
}
int list::remove_last_two(node *&head){
    if(!head)
        return 0;
    if(!head -> next){
        int result = head -> data;
        delete head;
        head = NULL;
        return result;
    }
    if(!head -> next -> next){
        int result = head -> data + head -> next -> data;
        delete head -> next;
        delete head;
        head = NULL;
        return result;
    }

    return head -> data + remove_last_two(head -> next);
}

float list::add_average(){
    return add_average(head, 0, 0);
}
float list::add_average(node *&head, int sum, int count){
    if(!head)
        return 0;
    if(!head -> next){
        head -> next = new node;
        head -> next -> next = NULL;
        head -> next -> previous = head;
        head -> next -> data = int(sum + head -> data) / (count + 1);
        return (sum + head -> data) / (count + 1);
    }
    return add_average(head -> next, sum + head -> data, count + 1);
}

int list::remove_largest_two(){
    int largest1 = 0;
    int largest2 = -1;
    return remove_largest_two(head, largest1, largest2);
}
int list::remove_largest_two(node *&head, int &largest1, int &largest2){
    if(!head)
        return largest1 + largest2;
    if(head -> data > largest1){
        largest2 = largest1;
        largest1 = head -> data;
    }
    else if(head -> data > largest2){
        largest2 = head -> data;
    }

    int sum = remove_largest_two(head -> next, largest1, largest2);

    if(head -> data == largest1 || head -> data == largest2){
        node *temp = head;
        if(temp -> next)
            temp -> next -> previous = temp-> previous;
        if(temp -> previous)
            temp -> previous -> next = temp -> next;
        delete temp;
    }
    return sum;
}
