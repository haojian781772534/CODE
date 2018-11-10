//Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented proggramming to
//simulate the car in the lanes



#ifndef location_h
#define location_h
class Location					//Base class
{
        public:
                Location();			//constructor
                Location(int loca);		//constructor
                ~Location();    		//destructor
		/*map *get_map(){
			return Map;
		}*/
        protected:
                int location;	
		//map * Map;
};
#endif
