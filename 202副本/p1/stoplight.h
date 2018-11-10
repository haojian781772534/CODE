#ifndef stoplight_h
#define stoplight_h
class stoplight
{
        public :
                stoplight(bool flag);
                ~stoplight();
		bool get_pass(){
			return pass;
		}

        protected:
                bool pass;
};
#endif
