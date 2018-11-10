#include "CS299_clist.h"
//Please place your name here
//
//

int main()
{
    list object;
    object.build();	//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the functions

    cout << "the number of nodes that was added is : " << object.add_before() << endl;
    object.display();
    cout << "1 means some nodes have been deleted: " << object.remove_same() << endl;
    object.display();
    cout << "1 means switch the first and last nodes: " << object.switch_node() << endl;
    object.display();
    list copy;
    cout<< " the average of last two nodes is: " << object.copy_two(copy) << endl;
    copy.display();

    object.display(); //resulting list after your function call!
    
    return 0;
}
