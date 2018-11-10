#include "CS299_arr.h"

int table::display_reverse(){
    return display_reverse(this -> head, size - 1);
}

int table::display_reverse(node *head[], int index){
    if(index < 0)
        return 0;
    int line = display_reverse(head[index]);
    cout << endl;
    return line + display_reverse(head, index - 1);
}
int table::display_reverse(node *head){
    if(!head)
        return 0;
    int count = display_reverse(head -> next);
    cout << head -> data << " ";
    return count + 1;
}

float table::average_all(){
    int sum = 0;
    int items = average_all(head, size - 1, sum);
    return float(sum) / float(items);
}

int table::average_all(node *head[], int index, int &sum){
    if(index < 0)
        return 0;
    return average_all(head[index], sum) + average_all(head, index - 1, sum);
}
int table::average_all(node *head, int &sum){
    if(!head)
        return 0;
    sum = sum + head -> data;
    return 1 + average_all(head -> next, sum);
}
//--------------------------------------------------

int table::copy_arr(table &source){
    head = new node*[source.size];
    this->size = source.size;
    return copy_arr(head, source.head, source.size - 1);
}
int table::copy_arr(node *head[], node *source[], int index){
    if(index < 0)
        return 0;
    return copy_arr(head[index], source[index]) + copy_arr(head, source, index - 1);
}
int table::copy_arr(node *&head, node *source){
    if(!source)
        return 0;
    head = new node;
    head -> data = source -> data;
    head -> next = NULL;
    return 1 + copy_arr(head -> next, source -> next);
}
