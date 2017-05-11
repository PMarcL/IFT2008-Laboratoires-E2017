/**
 * \file VectorTesteurVector1.cpp
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

class Vector1: public ::testing::Test {
protected:
	virtual void SetUp() {
		v.push_back(11);
		v.push_back(22);
		v.push_back(33);
	}

	virtual void TearDown() {
	}
	// private variables
	Vector<int> v;
};

TEST_F(Vector1, popBackOk) {
	int capacity = v.capacity();
	int poped = v.pop_back();
	EXPECT_EQ(33, poped);
	EXPECT_EQ(2, v.size());
	EXPECT_EQ(capacity, v.capacity());

	poped = v.pop_back();
	EXPECT_EQ(22, poped);
	EXPECT_EQ(1, v.size());
	EXPECT_EQ(capacity, v.capacity());

	poped = v.pop_back();
	EXPECT_EQ(11, poped);
	EXPECT_EQ(0, v.size());
	EXPECT_EQ(capacity, v.capacity());
}

TEST_F(Vector1, resizeToSmallerOK) {
	v.push_back(44);
	v.push_back(55);
	int oldCapacity = v.capacity();

	v.resize(2);
	EXPECT_EQ(2, v.size());
	EXPECT_EQ(oldCapacity, v.capacity());
	EXPECT_EQ(11, v[0]);
	EXPECT_EQ(22, v[1]);
}

TEST_F(Vector1, resizeToBiggerOK) {
	v.resize(5);
	EXPECT_EQ(5, v.size());
	EXPECT_EQ(5, v.capacity());
	EXPECT_EQ(11, v[0]);
	EXPECT_EQ(22, v[1]);
	EXPECT_EQ(33, v[2]);
	EXPECT_EQ(0, v[3]);
	EXPECT_EQ(0, v[4]);
}

TEST_F(Vector1, copyConstructorOK) {
	Vector<int> v2(v);
	EXPECT_FALSE(v2.empty());
	EXPECT_EQ(3, v2.size());
	EXPECT_EQ(3, v2.capacity());
}

TEST_F(Vector1, assignmentOperatorOK) {
	Vector<int> v2 = v;
	EXPECT_FALSE(v2.empty());
	EXPECT_EQ(3, v2.size());
	EXPECT_EQ(3, v2.capacity());
	EXPECT_EQ(11, v[0]);
	EXPECT_EQ(22, v[1]);
	EXPECT_EQ(33, v[2]);
}

TEST_F(Vector1, bracketOperator) {
	EXPECT_EQ(11, v[0]);
	EXPECT_EQ(22, v[1]);
	EXPECT_EQ(33, v[2]);
}

TEST_F(Vector1, at) {
	EXPECT_EQ(11, v.at(0));
	EXPECT_EQ(22, v.at(1));
	EXPECT_EQ(33, v.at(2));
}

TEST_F(Vector1, iterators) {
	using namespace std;

	Vector<int>::const_iterator it = v.begin();
	EXPECT_EQ(11, *(it++));
	EXPECT_EQ(22, *(it++));
	EXPECT_EQ(33, *(it++));
	EXPECT_EQ(v.end(), it);
}

TEST_F(Vector1, outofboundsThrowsException) {
	EXPECT_THROW(v.at(5), std::out_of_range);
	EXPECT_THROW(v.at(-1), std::out_of_range);
}

TEST_F(Vector1, squareBracketDoesntThrowsExceptionWhenOutOfRange) {
	EXPECT_NO_THROW(v[10]);
}

TEST_F(Vector1, clearOk) {
	v.clear();
	EXPECT_TRUE(v.empty());
	EXPECT_EQ(0, v.size());
}

TEST_F(Vector1, insertOk) {
	v.insert(v.begin(), 124);
	EXPECT_EQ(124, v[0]);
	EXPECT_EQ(4, v.size());

	v.insert(v.end(), 126);
	EXPECT_EQ(126, v[v.size()-1]);
	EXPECT_EQ(5, v.size());
}
