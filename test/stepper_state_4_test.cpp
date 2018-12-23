#include "gtest/gtest.h"

#include <array>


namespace{


	constexpr int LOW  = 0;
	constexpr int HIGH = 1;

	struct digitalWrite_t{
		digitalWrite_t(){
			reset();
		}

		void reset(){
			pins.fill(-1);
		}

		void operator()(int pin, int value){
			ASSERT_LE(pin, 4);
			ASSERT_TRUE(value == LOW || value == HIGH);

			pins[pin] = value;
		}

		std::array< int, 4 > pins;
	};

	digitalWrite_t digitalWrite;


}

#include <stepper_state_4.hpp>


namespace{


	TEST(stepper_state_4, start_forward){
		digitalWrite.reset();
		ASSERT_EQ(digitalWrite.pins, (std::array{-1, -1, -1, -1}));

		tools::stepper_state_4< 0, 1, 2, 3 > state;

		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{HIGH, HIGH, LOW, LOW}));
		digitalWrite.reset();

		state.next();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{LOW, HIGH, HIGH, LOW}));
		digitalWrite.reset();

		state.next();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{LOW, LOW, HIGH, HIGH}));
		digitalWrite.reset();

		state.next();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{HIGH, LOW, LOW, HIGH}));
		digitalWrite.reset();

		state.next();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{HIGH, HIGH, LOW, LOW}));
		digitalWrite.reset();

		state.prev();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{HIGH, LOW, LOW, HIGH}));
		digitalWrite.reset();

		state.prev();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{LOW, LOW, HIGH, HIGH}));
		digitalWrite.reset();

		state.prev();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{LOW, HIGH, HIGH, LOW}));
		digitalWrite.reset();

		state.prev();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{HIGH, HIGH, LOW, LOW}));
		digitalWrite.reset();
	}


	TEST(stepper_state_4, start_backward){
		digitalWrite.reset();
		ASSERT_EQ(digitalWrite.pins, (std::array{-1, -1, -1, -1}));

		tools::stepper_state_4< 0, 1, 2, 3 > state;
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{HIGH, HIGH, LOW, LOW}));
		digitalWrite.reset();

		state.prev();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{HIGH, LOW, LOW, HIGH}));
		digitalWrite.reset();

		state.prev();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{LOW, LOW, HIGH, HIGH}));
		digitalWrite.reset();

		state.prev();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{LOW, HIGH, HIGH, LOW}));
		digitalWrite.reset();

		state.prev();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{HIGH, HIGH, LOW, LOW}));
		digitalWrite.reset();

		state.next();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{LOW, HIGH, HIGH, LOW}));
		digitalWrite.reset();

		state.next();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{LOW, LOW, HIGH, HIGH}));
		digitalWrite.reset();

		state.next();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{HIGH, LOW, LOW, HIGH}));
		digitalWrite.reset();

		state.next();
		state.set();
		ASSERT_EQ(digitalWrite.pins, (std::array{HIGH, HIGH, LOW, LOW}));
		digitalWrite.reset();
	}


	TEST(stepper_state_4, unset){
		digitalWrite.reset();
		ASSERT_EQ(digitalWrite.pins, (std::array{-1, -1, -1, -1}));

		tools::stepper_state_4< 0, 1, 2, 3 > state;
		state.unset();
		ASSERT_EQ(digitalWrite.pins, (std::array{LOW, LOW, LOW, LOW}));
	}


}
