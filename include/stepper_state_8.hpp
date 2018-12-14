#ifndef _arduino_tools__stepper_state_8__hpp_INCLUDED_
#define _arduino_tools__stepper_state_8__hpp_INCLUDED_

#include "rotate.hpp"


namespace tools{


	template < int Pin0, int Pin1, int Pin2, int Pin3 >
	class stepper_state_8{
	public:
		void set(){
			digitalWrite(Pin0, (pos_ & 0b00000001) ? HIGH : LOW);
			digitalWrite(Pin1, (pos_ & 0b00000100) ? HIGH : LOW);
			digitalWrite(Pin2, (pos_ & 0b00010000) ? HIGH : LOW);
			digitalWrite(Pin3, (pos_ & 0b01000000) ? HIGH : LOW);
		}

		constexpr void prev()noexcept{
			pos_ = rotate(pos_, -1);
		}

		constexpr void next()noexcept{
			pos_ = rotate(pos_, 1);
		}

	private:
		unsigned char pos_ = 0b00000111;
	};


}


#endif
