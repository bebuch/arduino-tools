#ifndef _arduino_tools__stepper_state_4__hpp_INCLUDED_
#define _arduino_tools__stepper_state_4__hpp_INCLUDED_


namespace tools{


	template < int Pin0, int Pin1, int Pin2, int Pin3 >
	class stepper_state_4{
	public:
		void set(){
			digitalWrite(Pin0, (pos_ & 0b0001) ? HIGH : LOW);
			digitalWrite(Pin1, (pos_ & 0b0010) ? HIGH : LOW);
			digitalWrite(Pin2, (pos_ & 0b0100) ? HIGH : LOW);
			digitalWrite(Pin3, (pos_ & 0b1000) ? HIGH : LOW);
		}

		constexpr void prev()noexcept{
			pos_ |= (pos_ & 0b00000001) << 4;
			pos_ >>= 1;
		}

		constexpr void next()noexcept{
			pos_ <<= 1;
			pos_ |= (pos_ & 0b00010000) >> 4;
		}

	private:
		unsigned char pos_ = 0b00000011;
	};


}


#endif
