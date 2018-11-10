




#ifndef zipcar_h
#define zipcar_h

#include"car.h"

class zip_car : public car
{
	public:
		zip_car();
		zip_car(char *intersection, int id_num, float cost_hour, bool repair, int gas_level, char *licence_plate);
		~zip_car();
		zip_car(const zip_car &copy_from);
		
		int display();
		void read();
		int return_id();
		
	private:
		int gas_level;
		char *licence_plate;
};

#endif
