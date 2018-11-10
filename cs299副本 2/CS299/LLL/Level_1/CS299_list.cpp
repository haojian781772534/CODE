#include "CS299_list.h"




int remove(node * & head)
{
    if(!head)
        return 0;
    if(head -> next == NULL)
    {
        delete head;
        head = NULL;
        return 1;
    }
    node *current = head;
    head = head -> next;
    delete current;
        return 1 + remove(head -> next);





}
