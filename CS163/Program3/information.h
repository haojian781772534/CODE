//Hanyang Xiao
//CS163
//Prog3
//05/13/2018
//The goal of this program is to 
//create a hash table using chaining
#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>
#define SIZE 150


/*struct a_term
{
    char * term;
    char * definition;
    char * reference;
    char * citation;
};*/
#ifndef INFORMATION
#define INFORMATION

class information
{
    public:
            information();
            ~information();
            int display();
            int create_info();
            //int create_info1();
            //int create_info2();
            int insert_info();
            char * get_term();
            int retrieve(char *);
   
            char * term;
            char * definition;
            char * reference;
            char * citation;
            

};
#endif