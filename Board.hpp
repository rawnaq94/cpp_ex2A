#include "Direction.hpp"
#include <iostream>
#include <string>

using std::string;



namespace ariel {
	// Defines a direction of a message on the board
	class Board {
		private:
			int t;
        public:
			Board(){
			}
		    void post(unsigned int,unsigned int, Direction,string const&);
            string read(unsigned int,unsigned int, Direction, int);
            string show();	
	};
}
;

