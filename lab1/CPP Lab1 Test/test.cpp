#include "pch.h"
#include "CPP Lab1.hpp"

TEST(DiscriminantTest, answer_correct_no1) {
	quadEq eq = { 1, -1, -2 };
	double d = Discriminant(eq);
	EXPECT_EQ(d, 9);
}

TEST(SolutionTest, no_roots_root_count_no2) {
	quadEq eq = { 1, 1, 10 };
	eqSolution sol = Solution(eq);
	EXPECT_EQ(sol.rootCount, 0);
}

TEST(SolutionTest, no_roots_roots_is_nullptr_no3) {
	quadEq eq = { 1, 1, 10 };
	eqSolution sol = Solution(eq);
	EXPECT_EQ(sol.roots, nullptr);
}

TEST(SolutionTest, one_root_root_count_no4) {
	quadEq eq = { 1, 4, 4 };
	eqSolution sol = Solution(eq);
	EXPECT_EQ(sol.rootCount, 1);
}

TEST(SolutionTest, one_root_roots_no5) {
	quadEq eq = { 1, 4, 4 };
	eqSolution sol = Solution(eq);
	EXPECT_EQ(sol.roots[0], -2);
}

TEST(SolutionTest, two_roots_root_count_no6) {
	quadEq eq = { 1, -1, -2 };
	eqSolution sol = Solution(eq);
	EXPECT_EQ(sol.rootCount, 2);
}

TEST(SolutionTest, two_roots_roots_no6) {
	quadEq eq = { 1, -1, -2 };
	eqSolution sol = Solution(eq);
	EXPECT_EQ(sol.roots[0], -1);
	EXPECT_EQ(sol.roots[1], 2);
}