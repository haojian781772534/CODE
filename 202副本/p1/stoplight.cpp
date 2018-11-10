//Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented proggramming to
//simulate the car in the lanes

#include "stoplight.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//constructor
stoplight::stoplight(bool flag)
{
	pass = flag;
}


//destructor
stoplight::~stoplight(){}
