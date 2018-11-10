#include "CS299_list.h"
//Place your name here
int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the functions
    cout << "average :" << object.average();
    cout << "number of node(99): "<< object.add_99();
    

    object.display();  //displays the LLL again!
   
    
    return 0;
}
