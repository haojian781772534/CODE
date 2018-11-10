//Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented proggramming to
//simulate the car in the lanes




#include <iostream>
#include <cctype>
#include <cstring>
#include "map.h"
#include "stoplight.h"
#include "lane.h"
#include "location.h"
#include "car.h"
#define SIZE 30



using namespace std;

int main(){
	map Map(5);
	
	Car *my_car1 = new Car(100,"A",1,1);
	Car *my_car2 = new Car(90,"B",1,1);
	Car *my_car3 = new Car(60,"C",1,1);

	Car *my_car4 = new Car(100,"D",2,1);
	Car *my_car5 = new Car(100,"E",2,1);
	Car *my_car6 = new Car(90,"F",2,1);

	Car *my_car7 = new Car(60,"G",3,1);
	Car *my_car8 = new Car(100,"QQQ",3,1);
	Car *my_car9 = new Car(100,"Z",3,1);

	Car *my_car10 = new Car(90,"X",4,1);
	Car *my_car11 = new Car(60,"N",4,1);
	Car *my_car12 = new Car(100,"QQ",4,1);


	Car *my_car13= new Car(100,"ABC",0,1);
	Car *my_car14 = new Car(90,"T",0,1);
	Car *my_car15= new Car(60,"ZZ",0,1);
				

	Map.addCar(my_car1);			//Lane1 cars
	Map.addCar(my_car2);	
	Map.addCar(my_car3);

	Map.addCar(my_car4);			//Lane2 cars
	Map.addCar(my_car5);
	Map.addCar(my_car6);	

	Map.addCar(my_car7);			//Lane3 cars
	Map.addCar(my_car8);
	Map.addCar(my_car9);

	Map.addCar(my_car10);			//Lane4 cars
	Map.addCar(my_car11);
	Map.addCar(my_car12);	

	Map.addCar(my_car13);			//Lane0 cars
	Map.addCar(my_car14);	
	Map.addCar(my_car15);

	cout<<"*******Welcome to use!********************************************"<<endl;

	cout<<"*******sl is stoplight, 1 is Red light, 0 is Green light!*********"<<endl;
	cout<<"***When car meet the Red light(1), the car can not Move and Add!!!***"<<endl;

	Map.display();

	cout<<"Lane 1 car 1 move to Lane2:"<<endl;
	cout<<"Lane 2 car 5 move to Lane1"<<endl;
	cout<<"Lane 3 car 7 move to Lane4"<<endl;
	cout<<"******************************************"<<endl;
	my_car1->move_car(2,Map);
	my_car5->move_car(1,Map);
	my_car7->move_car(4,Map);
	cout<<endl;

	Map.display();
	return 0;



}
