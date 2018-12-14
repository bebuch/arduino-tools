#include "gtest/gtest.h"

#include <rotate.hpp>


namespace{


	TEST(rotate, left){
		unsigned char v = 0b00000001;

		v = tools::rotate(v, 1);
		ASSERT_EQ(int(v), 0b00000010);

		v = tools::rotate(v, 1);
		ASSERT_EQ(int(v), 0b00000100);

		v = tools::rotate(v, 1);
		ASSERT_EQ(int(v), 0b00001000);

		v = tools::rotate(v, 1);
		ASSERT_EQ(int(v), 0b00010000);

		v = tools::rotate(v, 1);
		ASSERT_EQ(int(v), 0b00100000);

		v = tools::rotate(v, 1);
		ASSERT_EQ(int(v), 0b01000000);

		v = tools::rotate(v, 1);
		ASSERT_EQ(int(v), 0b10000000);

		v = tools::rotate(v, 1);
		ASSERT_EQ(int(v), 0b00000001);
	}

	TEST(rotate, right){
		unsigned char v = 0b00000001;

		v = tools::rotate(v, -1);
		ASSERT_EQ(int(v), 0b10000000);

		v = tools::rotate(v, -1);
		ASSERT_EQ(int(v), 0b01000000);

		v = tools::rotate(v, -1);
		ASSERT_EQ(int(v), 0b00100000);

		v = tools::rotate(v, -1);
		ASSERT_EQ(int(v), 0b00010000);

		v = tools::rotate(v, -1);
		ASSERT_EQ(int(v), 0b00001000);

		v = tools::rotate(v, -1);
		ASSERT_EQ(int(v), 0b00000100);

		v = tools::rotate(v, -1);
		ASSERT_EQ(int(v), 0b00000010);

		v = tools::rotate(v, -1);
		ASSERT_EQ(int(v), 0b00000001);
	}


	TEST(rotate, multi){
		unsigned char v = 0b00100001;

		v = tools::rotate(v, 2);
		ASSERT_EQ(int(v), 0b10000100);

		v = tools::rotate(v, 3);
		ASSERT_EQ(int(v), 0b00100100);

		v = tools::rotate(v, -4);
		ASSERT_EQ(int(v), 0b01000010);
	}


}
