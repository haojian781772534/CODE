//Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented programming to 
//simulate the car in the lanes




#include "location.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//constructor
Location :: Location()
{
        location=0;
}


//constructor
Location :: Location(int loca) : location(loca)
{
}

//destructor
Location :: ~Location(){}

