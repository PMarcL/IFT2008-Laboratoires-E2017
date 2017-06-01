/**
 * \file AlgorithmesTesteur.cpp
 * \brief Googletest pour tester l'implémentation des algorithmes
 * \author Jean-Francis Roy
 * \version 0.1
 * \date Août 2016
 *
 */

#include <string>
#include "gtest/gtest.h"
#include "Graphe.h"
using namespace std;
using namespace labGrapheListes;

class GrapheAlgorithmesTest: public ::testing::Test {
protected:
	GrapheAlgorithmesTest() :
			g(6) {
	}

	virtual void SetUp() {
		g.ajouterArc(0, 1);
		g.ajouterArc(1, 2);
		g.ajouterArc(2, 5);
		g.ajouterArc(3, 2);
		g.ajouterArc(3, 4);
		g.ajouterArc(4, 5);
	}
	// virtual void TearDown() {}
	Graphe<string> g;
};

TEST_F(GrapheAlgorithmesTest, parcoursProfondeurUneSolution) {
	std::vector<unsigned int> p = g.parcoursProfondeur(0);

	// Note: nécessite C++11
	std::vector<unsigned int> solution1 = {0, 1, 2, 5};

	EXPECT_EQ(solution1, p);
}

TEST_F(GrapheAlgorithmesTest, parcoursProfondeurDeuxSolutions) {
	std::vector<unsigned int> p = g.parcoursProfondeur(3);

	// Note: nécessite C++11
	std::vector<unsigned int> solution1 = {3, 4, 5, 2};
	std::vector<unsigned int> solution2 = {3, 2, 5, 4};
	EXPECT_TRUE(p == solution1 || p == solution2);
}

TEST_F(GrapheAlgorithmesTest, parcoursLargeurUneSolution) {
	std::vector<unsigned int> p = g.parcoursLargeur(0);

	// Note: nécessite C++11
	std::vector<unsigned int> solution1 = {0, 1, 2, 5};

	EXPECT_EQ(solution1, p);
}

TEST_F(GrapheAlgorithmesTest, parcoursLargeurDeuxSolutions) {
	std::vector<unsigned int> p = g.parcoursLargeur(3);

	// Note: nécessite C++11
	std::vector<unsigned int> solution1 = {3, 2, 4, 5};
	std::vector<unsigned int> solution2 = {3, 4, 2, 5};
	EXPECT_TRUE(p == solution1 || p == solution2);
}

TEST_F(GrapheAlgorithmesTest, estConnexeOk) {
	EXPECT_TRUE(g.estConnexe());
}

TEST_F(GrapheAlgorithmesTest, estPasConnexeOk1) {
	g.enleverArc(0, 1);
	EXPECT_FALSE(g.estConnexe());
}

TEST_F(GrapheAlgorithmesTest, estPasConnexeOk2) {
	g.enleverArc(2, 5);
	g.enleverArc(3, 2);
	g.ajouterArc(2, 0);
	g.ajouterArc(5, 3);
	EXPECT_FALSE(g.estConnexe());
}

TEST_F(GrapheAlgorithmesTest, estPasConnexeOk3) {
	g.enleverArc(1, 2);
	EXPECT_FALSE(g.estConnexe());
}

TEST_F(GrapheAlgorithmesTest, triTopologiqueOk) {
	std::vector<unsigned int> t = g.triTopologique();

	// Note: nécessite C++11
	std::vector<unsigned int> solution1 = {0, 1, 3, 2, 4, 5};
	std::vector<unsigned int> solution2 = {0, 1, 3, 4, 2, 5};
	std::vector<unsigned int> solution3 = {0, 3, 1, 2, 4, 5};
	std::vector<unsigned int> solution4 = {0, 3, 1, 4, 2, 5};
	std::vector<unsigned int> solution5 = {0, 3, 4, 1, 2, 5};
	std::vector<unsigned int> solution6 = {3, 0, 1, 2, 4, 5};
	std::vector<unsigned int> solution7 = {3, 0, 1, 4, 2, 5};
	std::vector<unsigned int> solution8 = {3, 0, 4, 1, 2, 5};
	std::vector<unsigned int> solution9 = {3, 4, 0, 1, 2, 5};

	EXPECT_TRUE(t == solution1 || t == solution2 || t == solution3 || t == solution4 || t == solution5 || t == solution6 ||
			t == solution7 || t == solution8 || t == solution9);
}
