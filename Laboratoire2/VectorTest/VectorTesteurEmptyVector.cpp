/**
 * \file VectorTesteurEmptyVector.cpp
 * \brief Tests unitaires pour Vector
 * \author Ludovic Trottier
 * \author Mathieu Dumoulin
 * \version 0.3
 * \date Mai 2014
 */
#include "gtest/gtest.h"
#include "Vector.h"
#include <iostream>

using namespace std;

class EmptyVector: public ::testing::Test {
protected:
	virtual void SetUp() {
		w = Vector<int>(5);
	}

	virtual void TearDown() {
	}
	// private variables
	Vector<int> v;
	Vector<int> w;
};

TEST_F(EmptyVector, defaultObjectOk) {
	EXPECT_TRUE(v.empty());
	EXPECT_EQ(0, v.size());
}

TEST_F(EmptyVector, defaultObjectCapacityOk) {
	EXPECT_TRUE(w.empty());
	EXPECT_EQ(0, w.size());
	EXPECT_EQ(5, w.capacity());
}

TEST_F(EmptyVector, push_backOneElementOK) {
	v.push_back(11);
	EXPECT_FALSE(v.empty());
	EXPECT_EQ(1, v.size());
	EXPECT_EQ(1, v.capacity());
}

TEST_F(EmptyVector, push_backThreeElementOK) {
	v.push_back(11);
	v.push_back(22);
	v.push_back(33);
	EXPECT_FALSE(v.empty());
	EXPECT_EQ(3, v.size());
	EXPECT_EQ(3, v.capacity());
}

TEST_F(EmptyVector, pushPopOk) {
	v.push_back(11);
	int poped = v.pop_back();
	EXPECT_EQ(poped, 11);
	EXPECT_EQ(0, v.size());
	EXPECT_TRUE(v.empty());
	EXPECT_EQ(1, v.capacity());
}

TEST_F(EmptyVector, backIsOK) {
	v.push_back(11);
	EXPECT_EQ(11, v.back());

	v.push_back(22);
	EXPECT_EQ(22, v.back());

	v.push_back(33);
	EXPECT_EQ(33, v.back());
}

TEST_F(EmptyVector, clearOk) {
	v.clear();
	EXPECT_TRUE(v.empty());
	EXPECT_EQ(0, v.size());
}

TEST_F(EmptyVector, reserveOk){
	v.reserve(12);
	EXPECT_EQ(12, v.capacity());
}

