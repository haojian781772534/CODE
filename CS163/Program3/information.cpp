 //Hanyang Xiao
//CS163
//Prog3
//05/13/2018
//The goal of this program is to 
//create a hash table using chaining


#include"information.h"
using namespace std;


information::information()
{   
    term = NULL;
    definition = NULL;
    reference = NULL;
    citation = NULL;

}

information::~information()
{   
    if(term)
    {
        delete []term;
        term = NULL;
    }
    if(definition)
    {
        delete []definition;
        definition = NULL;
    }
    if(reference)
    {
        delete []reference;
        reference = NULL;
    }
    if(citation)
    {
        delete []citation;
        citation = NULL;
    }

}

//create information
/*int information::create_info()
{
    ifstream fin;


    char temp1[SIZE];
    char temp2[SIZE];
    char temp3[SIZE];
    char temp4[SIZE];

    fin.get(temp1,SIZE,'|');
	fin.ignore(500,'|');
    term = new char[strlen(temp1) + 1];
    strcpy(term, temp1);

    cout << "test" << endl;
    cout << term << endl;
    cout << temp1 << endl;  

    fin.get(temp2,SIZE,'|');
	fin.ignore(500,'|');
    definition = new char[strlen(temp2) + 1];
    strcpy(definition, temp2);

    fin.get(temp3,SIZE,'|');
	fin.ignore(500,'|');
    reference = new char[strlen(temp3) + 1];
    strcpy(reference, temp3);

    fin.get(temp4,SIZE,'|');
	fin.ignore(500,'|');
    citation = new char[strlen(temp4) + 1];
    strcpy(citation, temp4);
    
    return 1;
}*/
/*int information::create_info1()
{
    ifstream fin;
    char temp1[SIZE];


    fin.get(temp1,SIZE,'|');
	fin.ignore(500,'|');
    this->term = new char[strlen(temp1) + 1];
    strcpy(term, temp1);

    


    return 1;


}*/
/*int information::create_info2()
{
    ifstream fin;

    char temp2[SIZE];
    char temp3[SIZE];
    char temp4[SIZE];


    fin.get(temp2,SIZE,'|');
	fin.ignore(500,'|');
    this->definition = new char[strlen(temp2) + 1];
    strcpy(definition, temp2);

    fin.get(temp3,SIZE,'|');
	fin.ignore(500,'|');
    this->reference = new char[strlen(temp3) + 1];
    strcpy(reference, temp3);

    fin.get(temp4,SIZE,'|');
	fin.ignore(500,'|');
    this->citation = new char[strlen(temp4) + 1];
    strcpy(citation, temp4);
    
    return 1;
}*/

//add information
int information::insert_info()
{
    char temp1[SIZE];
    cout << "Please enter the term" << endl;
    cin.get(temp1, SIZE, '\n');
    cin.ignore(1000, '\n');
    term = new char[strlen(temp1) + 1];
    strcpy(term, temp1);

    char temp2[SIZE];
    cout << "Please enter the definition" << endl;
    cin.get(temp2, SIZE, '\n');
    cin.ignore(1000, '\n');
    definition = new char[strlen(temp2) + 1];
    strcpy(definition, temp2);

    char temp3[SIZE];
    cout << "Please enter the reference" << endl;
    cin.get(temp3, SIZE, '\n');
    cin.ignore(1000, '\n');
    reference = new char[strlen(temp3) + 1];
    strcpy(reference, temp3);

    char temp4[SIZE];
    cout << "Please enter the citation" << endl;
    cin.get(temp4, SIZE, '\n');
    cin.ignore(1000, '\n');
    citation = new char[strlen(temp4) + 1];
    strcpy(citation, temp4);

    return 1;
}

//display
int information::display()
{

    cout << "term : " << this->term << endl;
    cout << "definition : " << this->definition << endl;
    cout << "reference : " << this->reference << endl;
    cout << "citation : " << this->citation << endl;

    return 1;
}

int information::retrieve(char * to_find)
{
    if(strcmp(to_find, term) == 0)
        return 1;
    else
        return 0;
}

char * information::get_term()
{
    return term;
}