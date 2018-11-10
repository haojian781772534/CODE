#include "CS299_dlist.h"
//Please place your name here:
//
//
using namespace std;


int main()
{
    list object;
    object.build();
    object.display();

    /*PLEASE PUT YOUR CODE HERE to call the functions*/
    cout << "sum of last two nodes(display last two): " << object.display_last_two() << endl;

    cout << "sum of list(remove last two): " << object.remove_last_two() << endl;
    object.display();

    cout << "average of list(add a node on the end of list): " << object.add_average() << endl;
    object.display();

    cout << "sum of largest two(remove largest two): " << object.remove_largest_two() << endl;


    object.display();
    
    return 0;
}
