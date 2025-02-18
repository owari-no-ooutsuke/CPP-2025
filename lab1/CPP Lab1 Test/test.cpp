#include "pch.h"
#include "CPP Lab1.hpp"

TEST(DiscriminantTest, answer_correct_no1) {
	quadEq eq = { 1, -1, -2 };
	double d = Discriminant(eq);
	EXPECT_EQ(d, 9);
}