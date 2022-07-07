
#include "pch.h"

#include "../Crossing/typedef.cpp"
#include "../Crossing/func.cpp"
#include "../Crossing/checkcrossing.cpp"

TEST(CheckCrossingTest, Yes)
{
	float A[2], B[2], pry[2], res;
	A[0] = 3;
	A[1] = 4;
	B[0] = 1;
	B[1] = 0;
	pry[0] = 0;
	pry[1] = 1;
	res = checkcrossing(A, B, pry);
	ASSERT_EQ(1, res);
}

TEST(CheckCrossingTest, No)
{
	float A[2], B[2], pry[2], res;
	A[0] = 3;
	A[1] = 4;
	B[0] = 1;
	B[1] = 0;
	pry[0] = 0;
	pry[1] = 10;
	res = checkcrossing(A, B, pry);
	ASSERT_EQ(0, res);
}

TEST(CheckCrossingTest, OneLine)
{
	float A[2], B[2], pry[2], res;
	A[0] = 1;
	A[1] = 1;
	B[0] = 5;
	B[1] = 1;
	pry[0] = 0;
	pry[1] = 1;
	res = checkcrossing(A, B, pry);
	ASSERT_EQ(2, res);
}

TEST(CheckCrossingTest, Paralel)
{
	float A[2], B[2], pry[2], res;
	A[0] = 1;
	A[1] = 1;
	B[0] = 5;
	B[1] = 1;
	pry[0] = 0;
	pry[1] = 10;
	res = checkcrossing(A, B, pry);
	ASSERT_EQ(3, res);
}

TEST(FuncTest, Transmutate)
{
	float A[2], B[2], cmp[2], *res, fin[2];
	A[0] = 3;
	A[1] = 4;
	B[0] = 1;
	B[1] = 0;
	cmp[0] = 2;
	cmp[1] = -2;
	res = transmutate(A, B);
	fin[0] = res[0];
	fin[1] = res[1];
	ASSERT_EQ(cmp[0], fin[0]);
	ASSERT_EQ(cmp[1], fin[1]);
}

TEST(FuncTest, Crossing)
{
	float A[2], B[2], cmp[2], *res, fin[2];
	A[0] = 2;
	A[1] = -2;
	B[0] = 0;
	B[1] = 1;
	cmp[0] = 1.5;
	cmp[1] = 1;
	res = crossing(A, B);
	fin[0] = res[0];
	fin[1] = res[1];
	ASSERT_EQ(cmp[0], fin[0]);
	ASSERT_EQ(cmp[1], fin[1]);
}

TEST(FuncTest, Len)
{
	float A[2], B[2], pry[2], res;
	A[0] = 4;
	A[1] = 4;
	B[0] = 1;
	B[1] = 0;
	res = len(A, B);
	ASSERT_EQ(5, res);
}

