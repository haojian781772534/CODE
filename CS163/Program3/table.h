//Hanyang Xiao
//CS163
//Prog3
//05/13/2018
//The goal of this program is to 
//create a hash table using chaining
#include"information.h"
#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>



#ifndef TABLE
#define TABLE
struct node
{
    information info;
    node * next;
};

class table
{
    public:
            table(int size = 5);
            ~table();
            int insert(/*char **/);          //add new item to the hash table
            int retrieve(char *);
            int remove_all(char *);      //remove all terms that were retrieved from a particular source
            int display(char *);         //display all information about a particular term passed in as an argument
            int display_all();     //display all information
            int hash_function(char * key)const;     //hash function
            int create_information();     //get information from external data file



    private:
            node ** hash_table;
            int hash_table_size;
           // friend class information;
};
#endif

