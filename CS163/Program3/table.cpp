//Hanyang Xiao
//CS163
//Prog3
//05/13/2018
//The goal of this program is to 
//create a hash table using chaining


#include "table.h"
using namespace std;

table::table(int size)
{
    hash_table_size = size;
    hash_table = new node * [hash_table_size];
    node ** current = hash_table;
    node ** end = (hash_table + size);
    while(current != end)
    {
        *current = NULL;
        ++ current;
    }

}

table::~table()
{
    for(int i = 0; i < hash_table_size; ++i)
    {
        node * current = hash_table[i];
        while(current)
        {
            node * temp = current->next;
            delete current;
            current = temp;
        }
    }
    delete [] hash_table;
}
//add an item
int table::insert(/*char * key_value*/)
{
    node * current = new node;
    current->info.insert_info();
    int index = hash_function(current->info.get_term());
    if(index > (hash_table_size - 1) || index < 0)
        return 0;
    //node * current = new node;
    //current->info.insert_info();
    if(hash_table[index] == NULL)
    {
        hash_table[index] = current;
        current->next = NULL;
    }
    else
    {
        current->next = hash_table[index];
        hash_table[index] = current;
    }
    return 1;
    
}
//retrieve
int table::retrieve(char * to_find)
{
    int index = hash_function(to_find);
    if(index > (hash_table_size - 1) || index < 0)
        return 0;
    node * current = hash_table[index];
    while(current)
    {
        if(current->info.retrieve(to_find))
            return 1;
        current = current->next;
    }
    return 0;
}
//display
int table::display(char * key_value)
{
    int index = hash_function(key_value);
    if(index > (hash_table_size - 1) || index < 0)
        return 0;
    node * current = hash_table[index];
    while(current)
    {
        current->info.display();
        current = current->next;
    }
    return 1;
}
//display all
int table::display_all()
{
    for(int i = 0; i < hash_table_size; ++i)
    {
        if(hash_table[i])
        {
            node * current = hash_table[i];
            while(current)
            {
                current->info.display();
                current = current->next;
            }
        }
    }
    return 1;
}
//remove all
int table::remove_all(char * key_value)
{
    int index = hash_function(key_value);
    if(index > (hash_table_size - 1) || index < 0)
        return 0;
    node * current = hash_table[index];
    while(current)
    {
        node * temp = current->next;
        delete current;
        current = temp;
    }
    return 1;
}

//hash function
int table::hash_function(char * key)const
{
    return (key[0] + key[2]) % hash_table_size;
}

int table::create_information()
{
    /*ifstream fin;
    fin.open("CS_Terms.txt");
    //cout << "test1" << endl;
    if(!fin)
        return 0;
    else
    {
        //cout << "test2" << endl;
        node * current = new node;
            current->info.create_info();
            
            //cout << "test" << endl;
            //current->info.display();
            int index = hash_function(current->info.get_term());
            node * temp = hash_table[index];

                hash_table[index] = current;


        //fin.seekg(1,ios::cur);
         
        while(fin.peek()!=EOF)
        {
            
            node * current = new node;
            current->info.create_info();
            int index = hash_function(current->info.get_term());
            node * temp = hash_table[index];
            if(temp == NULL)
            {
                hash_table[index] = current;
            }
            else
            {
                current->next = temp;
                hash_table[index] = current;
            }
        }  
        fin.close();
        return 1;   
    }
    //fin.close();//cout << "test3" << endl;
    //return 1;*/
    /*char temp1[SIZE];
    char temp2[SIZE];
    char temp3[SIZE];
    char temp4[SIZE];*/
    ifstream fin;
    fin.open("CS_Terms.txt");
    if(!fin)
        return 0;
    else
    {
    node * current = new node;
    current->next = NULL;

    char temp1[SIZE];
    fin.get(temp1,SIZE,'|');
	fin.ignore(500,'|');
    current->info.term = new char[strlen(temp1) + 1];
    strcpy(current->info.term, temp1);

    char temp2[SIZE];
    fin.get(temp2,SIZE,'|');
	fin.ignore(500,'|');
    current->info.definition = new char[strlen(temp2) + 1];
    strcpy(current->info.definition, temp2);

    char temp3[SIZE];
    fin.get(temp3,SIZE,'|');
	fin.ignore(500,'|');
    current->info.reference = new char[strlen(temp3) + 1];
    strcpy(current->info.reference, temp3);

    char temp4[SIZE];
    fin.get(temp4,SIZE,'\n');
	fin.ignore(500,'\n');
    current->info.citation = new char[strlen(temp4) + 1];
    strcpy(current->info.citation, temp4);
    
    int index = hash_function(current->info.get_term());
    hash_table[index] = current;

    while(fin.peek()!=EOF)
    {
         node * current = new node;
             char temp1[SIZE];
        fin.get(temp1,SIZE,'|');
	    fin.ignore(500,'|');
        current->info.term = new char[strlen(temp1) + 1];
        strcpy(current->info.term, temp1);

        char temp2[SIZE];
        fin.get(temp2,SIZE,'|');
	    fin.ignore(500,'|');
        current->info.definition = new char[strlen(temp2) + 1];
        strcpy(current->info.definition, temp2);

        char temp3[SIZE];
        fin.get(temp3,SIZE,'|');
	    fin.ignore(500,'|');
        current->info.reference = new char[strlen(temp3) + 1];
        strcpy(current->info.reference, temp3);

        char temp4[SIZE];
        fin.get(temp4,SIZE,'\n');
	    fin.ignore(500,'\n');
        current->info.citation = new char[strlen(temp4) + 1];
        strcpy(current->info.citation, temp4);

        int index = hash_function(current->info.get_term());
            node * temp = hash_table[index];
            if(temp == NULL)
            {
                hash_table[index] = current;
            }
            else
            {
                current->next = temp;
                hash_table[index] = current;
            }
     }
     fin.close();
        return 1;
    }

}