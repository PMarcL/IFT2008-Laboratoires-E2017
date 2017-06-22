/**
 * \file ArbreBinaireTesteur.cpp
 * \brief Test pour la classe ArbreBinaire.
 * \author Ludovic Trottier
 * \author Mathieu Dumoulin
 * \version 0.3
 * \date mai 2014
 *
 * Démontre l'utilisation de la classe Arbre 
 */

#include <iomanip>
#include "ArbreBinaire.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;
using namespace labParcoursArbre;

class ArbreTestTab: public ::testing::Test {
protected:
	virtual void SetUp() {

		// L'arbre ressemble à ceci
		//         15
		//    9         22
		// 5    10
		tabS = new int[5];
		tabP = new int[5];

		tabP[0] = 15;
		tabP[1] = 9;
		tabP[2] = 5;
		tabP[3] = 10;
		tabP[4] = 22;

		tabS[0] = 5;
		tabS[1] = 9;
		tabS[2] = 10;
		tabS[3] = 15;
		tabS[4] = 22;

		/*on marque l'origine de tabP*/
		ptrOriDeTabP = tabP;

		Arbre<int> ab(tabS, 0, 4, &tabP);
		arb1 = ab;
	}
	virtual void TearDown() {
		delete[] ptrOriDeTabP;
		delete[] tabS;
	}
	Arbre<int> arb1;
	int * tabS;
	int *tabP;
	int *ptrOriDeTabP;

};

TEST_F(ArbreTestTab, listerEnOrdreOk) {
	vector<int> sommets = arb1.listerEnOrdre();
	ASSERT_EQ(5, sommets.size());
	for (size_t i = 0; i < sommets.size(); i++) {
		EXPECT_EQ(tabS[i], sommets[i]);
	}
}

TEST_F(ArbreTestTab, listerPreOrdreOk) {
	vector<int> v = arb1.listerPreOrdre();

	ASSERT_EQ(5, v.size());
	EXPECT_EQ(15, v[0]);
	EXPECT_EQ(9, v[1]);
	EXPECT_EQ(5, v[2]);
	EXPECT_EQ(10, v[3]);
	EXPECT_EQ(22, v[4]);
}

TEST_F(ArbreTestTab, listerParNiveauOk) {
	vector<int> v = arb1.listerParNiveau();
	ASSERT_EQ(5, v.size());
	EXPECT_EQ(15, v[0]);
	EXPECT_EQ(9, v[1]);
	EXPECT_EQ(22, v[2]);
	EXPECT_EQ(5, v[3]);
	EXPECT_EQ(10, v[4]);
}

TEST_F(ArbreTestTab, listerPostOrdreOk) {
	vector<int> v = arb1.listerPostOrdre();
	ASSERT_EQ(5, v.size());
	EXPECT_EQ(5, v[0]);
	EXPECT_EQ(10, v[1]);
	EXPECT_EQ(9, v[2]);
	EXPECT_EQ(22, v[3]);
	EXPECT_EQ(15, v[4]);
}

class ArbreTestVec: public ::testing::Test {
protected:
	virtual void SetUp() {

		// L'arbre ressemble à ceci
		//         15
		//    9         22
		// 5    10

		tabP.push_back(15);
		tabP.push_back(9);
		tabP.push_back(5);
		tabP.push_back(10);
		tabP.push_back(22);

		tabS.push_back(5);
		tabS.push_back(9);
		tabS.push_back(10);
		tabS.push_back(15);
		tabS.push_back(22);

		Arbre<int> ab(tabS, tabP);
		arb1 = ab;
	}
	// virtual void TearDown() {}
	Arbre<int> arb1;
	vector<int> tabS;
	vector<int> tabP;
};

TEST_F(ArbreTestVec, listerEnOrdreOk) {
	vector<int> sommets = arb1.listerEnOrdre();
	ASSERT_EQ(5, sommets.size());
	for (size_t i = 0; i < sommets.size(); i++) {
		EXPECT_EQ(tabS[i], sommets[i]);
	}
}

TEST_F(ArbreTestVec, listerPreOrdreOk) {
	vector<int> v = arb1.listerPreOrdre();
	ASSERT_EQ(5, v.size());
	EXPECT_EQ(15, v[0]);
	EXPECT_EQ(9, v[1]);
	EXPECT_EQ(5, v[2]);
	EXPECT_EQ(10, v[3]);
	EXPECT_EQ(22, v[4]);
}

TEST_F(ArbreTestVec, listerParNiveauOk) {
	vector<int> v = arb1.listerParNiveau();
	ASSERT_EQ(5, v.size());
	EXPECT_EQ(15, v[0]);
	EXPECT_EQ(9, v[1]);
	EXPECT_EQ(22, v[2]);
	EXPECT_EQ(5, v[3]);
	EXPECT_EQ(10, v[4]);
}

TEST_F(ArbreTestVec, listerPostOrdreOk) {
	vector<int> v = arb1.listerPostOrdre();
	ASSERT_EQ(5, v.size());
	EXPECT_EQ(5, v[0]);
	EXPECT_EQ(10, v[1]);
	EXPECT_EQ(9, v[2]);
	EXPECT_EQ(22, v[3]);
	EXPECT_EQ(15, v[4]);
}
