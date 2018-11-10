#include "CS299_arr.h"

int find_longest(node *head[], int size){
    if(!size)
        return 0;
    int largest = 0;
    for(int i = 0; i < size; i++){
        int length = 0;
        node *current = head[i];

        while(current){
            length++;
            current = current -> next;
        }

        if(length > largest)
            largest = length;
    }

    return largest;
}

int remove_last(node *head[], int size){
    if(!size)
        return 0;

    int count = 0;
    for(int i = 0; i < size; i++){
        node *current = head[i];

        if(current && !current -> next){
            delete current;
            head[i] = NULL;
            count++;
        }
        else{
            while(current -> next -> next){
                current = current -> next;
            }
            delete current -> next;
            current -> next = NULL;
            count++;
        }
    }

    return count;
}

int add_last(node *head[], int size){
    if(!(size-1))
        return 0;

    int count = 0;
    node *current = head[size - 1];
    if(!current){
        current = new node;
        current -> data = 99;
        current -> next = NULL;
        count++;
    }
    else{
        while(current -> next){
            count++;
            current = current -> next;
        }
        current -> next = new node;
        current -> next -> next = NULL;
        current -> next -> data = 99;
        count = count + 2;
    }

    return count;
}

int append_last(node *head[], int size){
    if(!size)
        return 0;

    int count = 0;
    for(int i = 0; i < size; i++){
        node *current = head[i];

        while(current){
            node *temp = current;
            current = current -> next;
            temp -> next = NULL;
            delete temp;
            count++;
        }
        head[i] = NULL;
    }

    return count;
}

int remove_ptr(node *head[], int size){
    if(!size)
        return 0;

    node *current[size];
    int count = 0;
    for(int i = 0; i < size; i++){
        current[i] = head[i];
        head[i] = NULL;
    }

    for(int i = 0; i < size; i++){
        while(current[i]){
            node *temp = current[i];
            current[i] = current[i] -> next;
            temp -> next = NULL;
            delete temp;
            count++;
        }
    }

    return count;
}




