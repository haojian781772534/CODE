//Hanyang Xiao
//CS163
//Prog3
//05/13/2018
//The goal of this program is to 
//create a hash table using chaining



#include "table.h"
using namespace std;

int main()
{   
    table a_table;
    int response1;
    char response2;
    //cout << "test" << endl;
    if(a_table.create_information() == 0)
        cout << "error in opening file" << endl << endl;
    else
    {  
      do
      {
        cout << "Please Choose " << endl;
        cout << "***** 1. Add a new term ******************************** \n"
             << "***** 2. Retrieve a information about a term *********** \n"
             << "***** 3. Remove all terms from a particular courses **** \n"
             << "***** 4. Display all information about a term ********** \n"
             << "***** 5. Display all ***********************************" << endl << endl;
        cin >> response1;
        cin.ignore(100, '\n');
        if(response1 == 1)
        {   
            if(a_table.insert())
                cout << "Insert successfully" << endl << endl;
            else
                cout << "Something wrong" << endl << endl;

        }
        else if(response1 == 2)
        {   
            char temp[SIZE];
            cout << "Please enter the name of the term you want to retrieve" << endl << endl;
            cin.get(temp, SIZE, '\n');
            cin.ignore(1000, '\n');
            if(a_table.retrieve(temp))
            {
                cout << "This is what was found " << endl;
                a_table.display(temp);
                cout << endl;
            }
            else
                cout << "Sorry we can't find the term " << endl << endl;
            
        }
        else if(response1 == 3)
        {
            char temp[SIZE];
            cout << "Please enter the name of term you want to remove " << endl << endl;
            cin.get(temp, SIZE, '\n');
            cin.ignore(1000, '\n');
            if(a_table.remove_all(temp))
                cout << "Remove successfully" << endl << endl;
            else
                cout << "Something wrong" << endl << endl;
        }
        else if(response1 == 4)
        {
            char temp[SIZE];
            cout << "Please enter the name of term you want to display " << endl << endl;
            cin.get(temp, SIZE, '\n');
            cin.ignore(1000, '\n');
            a_table.display(temp);

            
        }
        else if(response1 == 5)
        {
            a_table.display_all();
        }
        else   
        {
            cout << "Wrong" << endl;
        }
        cout << "Again?      Y/N" << endl;
        cin >> response2;
        cin.ignore(100,'\n');
      }while(toupper(response2) == 'Y');
    }




    return 0;
}