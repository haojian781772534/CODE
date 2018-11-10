#include "CS299_arr.h"
//Please place your name here:
//
//


int main()
{
    table object; 
    object.build(); //creates an array of LLL
    object.display(); //displays the array

    //PLEASE PUT YOUR CODE HERE to call the functions

    cout << "number of item is : " << object.display_reverse() << endl;
    cout << "average of table is : " << object.average_all() << endl;

    table test;
    cout << "number of item is : " << test.copy_arr(object) << endl;
    
    test.display();
    

    object.display();  //display again afterward!
    
    
    return 0;
}
