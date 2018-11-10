#include "CS299_clist.h"
//Your name:
//
//

using namespace std;

int main()
{
    node * rear = NULL;
    build(rear);
    display_all(rear);

    //PLEASE PUT YOUR CODE HERE to call the functions
    cout << "the number of rear that will be displayed: " << display_except(rear) << endl;
    cout << "if it's successful to delete the last node: " << remove_last(rear) << endl;  
    node *new_rear = NULL;
    cout << "the number of items copied: " << copy_all(new_rear, rear) << endl;
    display_all(new_rear);




    display_all(rear); //resulting list after your function call!
    destroy(rear);
    
    return 0;
}
