/**
 * \file TriTesteur.cpp
 * \brief Tests unitaires pour les tris
 * \author Ludovic Trottier
 * \version 0.3
 * \date mai 2014
 *
 */
#include <iostream>
#include "Tri.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;
using namespace labTris;

TEST(Test, test) {
	ASSERT_TRUE(true);
}

template<typename E>
bool estTrie(const vector<E> & p_v) {
	if (p_v.empty()) {
		return true;
	}
	for (unsigned int i = 0; i < p_v.size() - 1; ++i) {
		if (p_v[i] > p_v[i + 1]) {
			return false;
		}
	}
	return true;
}

// Afficher un vector : si nécessaire
//
template<typename E>
void afficher(const vector<E> & p_v) {
	cout << "(";
	for (size_t i = 0; i < p_v.size(); ++i) {
		cout << p_v[i] << ',';
	}
	cout << ")" << endl;
}

class TriTest: public ::testing::Test {
protected:
	virtual void SetUp() {
		v.push_back(1);
		v.push_back(7);
		v.push_back(3);
		v.push_back(12);
		v.push_back(5);
		v.push_back(3);
		v.push_back(7);
		v.push_back(18);
		v.push_back(-9);

		w.push_back(9);
	}
	// virtual void TearDown() {}
	vector<int> v;
	vector<int> w;
};

//TEST_F(TriTest, insertionOk) {
//	triInsertion(v);
//	EXPECT_TRUE(estTrie(v));
//}
//TEST_F(TriTest, shellOk) {
//	triShell(v);
//	afficher(v);
//	EXPECT_TRUE(estTrie(v));
//}
//TEST_F(TriTest, rapideOk) {
//	triRapide(v);
//	EXPECT_TRUE(estTrie(v));
//}
//TEST_F(TriTest, fusionOk) {
//	triFusion(v);
//	EXPECT_TRUE(estTrie(v));
//}
//TEST_F(TriTest, selectionOk) {
//	triSelection(v);
//	EXPECT_TRUE(estTrie(v));
//}
//TEST_F(TriTest, bulleOk) {
//	triBulle(v);
//	EXPECT_TRUE(estTrie(v));
//}
//
//TEST_F(TriTest, parTasOk) {
//	triParTas(v);
//	EXPECT_TRUE(estTrie(v));
//}
//
//TEST_F(TriTest, insertion1ElementOk) {
//	triInsertion(w);
//	EXPECT_TRUE(estTrie(w));
//}
//TEST_F(TriTest, shell1ElementOk) {
//	triShell(w);
//	EXPECT_TRUE(estTrie(w));
//}
//TEST_F(TriTest, rapide1ElementOk) {
//	triRapide(w);
//	EXPECT_TRUE(estTrie(w));
//}
//TEST_F(TriTest, fusion1ElementOk) {
//	triFusion(w);
//	EXPECT_TRUE(estTrie(w));
//}
//TEST_F(TriTest, selection1ElementOk) {
//	triSelection(w);
//	EXPECT_TRUE(estTrie(w));
//}
//TEST_F(TriTest, bulle1ElementOk) {
//	triBulle(w);
//	EXPECT_TRUE(estTrie(w));
//}
//
//TEST_F(TriTest, parTas1ElementOk) {
//	triParTas(w);
//	EXPECT_TRUE(estTrie(w));
//}
//
//
//TEST(TriTesteur, fluxTriInsertion) {
//	srand(time(NULL));
//	vector<int> v;
//	for (int i = 0; i < 1000; ++i) {
//		v.clear();
//		for (int j = 0; j < 50; ++j) {
//			v.push_back(rand() % 50);
//		}
//
//		triInsertion(v);
//		EXPECT_TRUE(estTrie(v));
//	}
//}
//
//TEST(TriTesteur, fluxTriBulle) {
//	srand(time(NULL));
//	vector<int> v;
//	for (int i = 0; i < 1000; ++i) {
//		v.clear();
//		for (int j = 0; j < 50; ++j) {
//			v.push_back(rand() % 50);
//		}
//
//		triBulle(v);
//		EXPECT_TRUE(estTrie(v));
//	}
//}
//
//TEST(TriTesteur, fluxTriFusion) {
//	srand(time(NULL));
//	vector<int> v;
//	for (int i = 0; i < 1000; ++i) {
//		v.clear();
//		for (int j = 0; j < 50; ++j) {
//			v.push_back(rand() % 50);
//		}
//
//		triFusion(v);
//		EXPECT_TRUE(estTrie(v));
//	}
//}
//
//TEST(TriTesteur, fluxTriParTas) {
//	srand(time(NULL));
//	vector<int> v;
//	for (int i = 0; i < 1000; ++i) {
//		v.clear();
//		for (int j = 0; j < 50; ++j) {
//			v.push_back(rand() % 50);
//		}
//
//		triParTas(v);
//		EXPECT_TRUE(estTrie(v));
//	}
//}
//
//TEST(TriTesteur, fluxTriRapide) {
//	srand(time(NULL));
//	vector<int> v;
//	for (int i = 0; i < 1000; ++i) {
//		v.clear();
//		for (int j = 0; j < 50; ++j) {
//			v.push_back(rand() % 50);
//		}
//
//		triRapide(v);
//		EXPECT_TRUE(estTrie(v));
//	}
//}
//
//TEST(TriTesteur, fluxTriSelection) {
//	srand(time(NULL));
//	vector<int> v;
//	for (int i = 0; i < 1000; ++i) {
//		v.clear();
//		for (int j = 0; j < 50; ++j) {
//			v.push_back(rand() % 50);
//		}
//
//		triSelection(v);
//		EXPECT_TRUE(estTrie(v));
//	}
//}
//
//TEST(TriTesteur, fluxTriShell) {
//	srand(time(NULL));
//	vector<int> v;
//	for (int i = 0; i < 1000; ++i) {
//		v.clear();
//		for (int j = 0; j < 50; ++j) {
//			v.push_back(rand() % 50);
//		}
//
//		triShell(v);
//		EXPECT_TRUE(estTrie(v));
//	}
//}
