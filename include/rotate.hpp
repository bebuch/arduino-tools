#ifndef _arduino_tools__rotate__hpp_INCLUDED_
#define _arduino_tools__rotate__hpp_INCLUDED_


namespace tools{


	constexpr unsigned char rotate(unsigned char v, signed char n)noexcept{
		if(n < 0){
			n = -n;
			signed char const o = 8 - n;
			return (v << o) | (v >> n);
		}else{
			signed char const o = 8 - n;
			return (v << n) | (v >> o);
		}
	}


}


#endif
