/**
 * \file PileTesteur.cpp
 * \brief Tests unitaires pour Pile
 * \author Ludovic Trottier
 * \author Mathieu Dumoulin
 * \version 0.3
 * \date Mai 2014
 *
 * Implémentation des tests unitaires pour Pile.
 */

#include "gtest/gtest.h"
#include "Pile.h"
#include "Comparable.h"

static const Comparable c1(1, "bleu");
static const Comparable c2(2, "rouge");
static const Comparable c3(3, "vert");
static const Comparable c4(4, "jaune");

using namespace labPileFile;

TEST(PileTestsSimples, NouvellePileEstVide) {
	Pile<Comparable> p;
	ASSERT_TRUE(p.estVide());
}

TEST(PileTestsSimples, NouvellePileAUneTailleDeZero) {
	Pile<Comparable> p;
	ASSERT_EQ(0, p.taille());
}

TEST(PileTestsSimples, PileAvecUnElementNestPasVide) {
	Pile<Comparable> p;
	p.empiler(c1);
	ASSERT_FALSE(p.estVide());
}

TEST(PileTestsSimples, PileAvecUnElementLeRenvoieLorsqueTop) {
	Pile<Comparable> p;
	p.empiler(c1);
	ASSERT_EQ(c1, p.top());
}

TEST(PileTestsSimples, PileAvecDeuxElementsAUneTailleDeDeux) {
	Pile<Comparable> p;
	p.empiler(c1);
	p.empiler(c2);
	ASSERT_EQ(2, p.taille());
}

TEST(PileTestsSimples, PileAvecDeuxElementsRenvoieLeDernierInsereLorsqueTop) {
	Pile<Comparable> p;
	p.empiler(c1);
	p.empiler(c2);
	ASSERT_EQ(c2, p.top());
}

TEST(PileTestsSimples, PileAvecUnElementSiDepilerAUneTailleDeZero) {
	Pile<Comparable> p;
	p.empiler(c1);
	p.depiler();
	ASSERT_EQ(0, p.taille());
}

TEST(PileTestsSimples, PileAvecUnElementSiDepilerRenvoieElement) {
	Pile<Comparable> p;
	p.empiler(c1);
	auto elRenvoye = p.depiler();
	ASSERT_EQ(c1, elRenvoye);
}

TEST(PileTestsSimples, PileAvecDeuxElementsRenvoieLesElementsAvecLesCrochets) {
	Pile<Comparable> p;
	p.empiler(c1);
	p.empiler(c2);
	ASSERT_EQ(c2, p[0]);
	ASSERT_EQ(c1, p[1]);
}

TEST(PileTestsSimples, PileAvecDeuxElementsCopieLesDeuxElementsAvecConstructeur) {
	Pile<Comparable> p;
	p.empiler(c1);
	p.empiler(c2);

	Pile<Comparable> p_copie(p);
	ASSERT_EQ(c1, p_copie[1]);
	ASSERT_EQ(c2, p_copie[0]);
}

TEST(PileTestsSimples, PileAvecDeuxElementsCopieTailleAvecConstructeur) {
	Pile<Comparable> p;
	p.empiler(c1);
	p.empiler(c2);

	Pile<Comparable> p_copie(p);
	ASSERT_EQ(p.taille(), p_copie.taille());
}

TEST(PileTestsSimples, PileAvecDeuxElementsCopieLesDeuxElementsAvecOperateurDeCopie) {
	Pile<Comparable> p;
	p.empiler(c1);
	p.empiler(c2);

	Pile<Comparable> p_copie;
	p_copie = p;
	ASSERT_EQ(c1, p_copie[1]);
	ASSERT_EQ(c2, p_copie[0]);
}

struct PileTest: public ::testing::Test {
	virtual void SetUp() {
		pile2.empiler(c1);
		pile2.empiler(c2);
		pile2.empiler(c3);
		pile2.empiler(c4);
	}
	// virtual void TearDown() {}
	Pile<Comparable> pile1;
	Pile<Comparable> pile2;
};

TEST_F(PileTest, ajoutUnElementOk) {
	pile1.empiler(c4);
	EXPECT_FALSE(pile1.estVide());
	EXPECT_EQ(1, pile1.taille());
}

TEST_F(PileTest, ajoutTroisElementOk) {
	pile1.empiler(c1);
	EXPECT_EQ(c1, pile1.top());
	EXPECT_EQ(1, pile1.taille());
	pile1.empiler(c2);
	EXPECT_EQ(c2, pile1.top());
	EXPECT_EQ(2, pile1.taille());
	pile1.empiler(c3);
	EXPECT_EQ(c3, pile1.top());
	EXPECT_EQ(3, pile1.taille());
}

TEST_F(PileTest, ajoutUnElementEnleveUnElements) {
	pile1.empiler(c1);
	EXPECT_EQ(c1, pile1.depiler());
	EXPECT_TRUE(pile1.estVide());
}

TEST_F(PileTest, ajoutTroisElementEnleveTroisElements) {
	pile1.empiler(c1);
	EXPECT_EQ(c1, pile1.top());
	pile1.empiler(c2);
	EXPECT_EQ(c2, pile1.top());
	pile1.empiler(c3);
	EXPECT_EQ(3, pile1.taille());
	EXPECT_EQ(c3, pile1.depiler());
	EXPECT_EQ(2, pile1.taille());
	EXPECT_EQ(c2, pile1.depiler());
	EXPECT_EQ(1, pile1.taille());
	EXPECT_EQ(c1, pile1.depiler());
	EXPECT_TRUE(pile1.estVide());
}

TEST_F(PileTest, TestCaseBracketOperator1elem) {
	pile1.empiler(c1);
	EXPECT_TRUE(c1 == pile1[0]);
}

TEST_F(PileTest, TestCaseBracketOperator3elem) {
	pile1.empiler(c1);
	pile1.empiler(c2);
	pile1.empiler(c3);
	EXPECT_TRUE(c3 == pile1[0]);
	EXPECT_TRUE(c2 == pile1[1]);
	EXPECT_TRUE(c1 == pile1[2]);
}

TEST_F(PileTest, TestCaseOperatorEqual1ElemEach) {
	pile1.empiler(c1);
	Pile<Comparable> autre;
	autre.empiler(c1);
	autre = pile1;
	EXPECT_TRUE(c1 == pile1.top());
	EXPECT_TRUE(c1 == autre.top());
}

TEST_F(PileTest, TestCaseOperatorEqual3) {
	pile1.empiler(c1);
	pile1.empiler(c2);
	pile1.empiler(c3);
	Pile<Comparable> autre;
	autre = pile1;
	EXPECT_EQ(3, autre.taille());
	EXPECT_TRUE(c3 == autre.top());
	EXPECT_TRUE(c3 == autre[0]);
	EXPECT_TRUE(c2 == autre[1]);
	EXPECT_TRUE(c1 == autre[2]);
}

TEST_F(PileTest, TestCaseCopyConst1ElemEach) {
	pile1.empiler(c1);
	Pile<Comparable> autre(pile1);
	EXPECT_EQ(1, autre.taille());
	EXPECT_TRUE(c1 == autre.top());
}

TEST_F(PileTest, TestCaseCopyConst3Elem) {
	pile1.empiler(c1);
	pile1.empiler(c2);
	pile1.empiler(c3);
	Pile<Comparable> autre(pile1);
	EXPECT_TRUE(c3 == autre.top());
	EXPECT_TRUE(c3 == autre[0]);
	EXPECT_TRUE(c2 == autre[1]);
	EXPECT_TRUE(c1 == autre[2]);
}

//TEST_F(PileTest, TestCaseOperatorOstream) {
//	std::ostringstream oss;
//
//	pile1.empiler(c1);
//	pile1.empiler(c2);
//	pile1.empiler(c3);
//	oss << pile1;
//
//	std::string expected =
//	"Pile: [Valeur->3     Mot->vert\n,Valeur->2     Mot->rouge\n,Valeur->1     Mot->bleu\n]";
//	EXPECT_EQ(expected, oss.str());
//}
//
//TEST_F(PileTest, depilerPileVideLanceLogicError) {
//	Pile<int> pileVide;
//	EXPECT_THROW(pileVide.depiler(), PreconditionException);
//}
//
//TEST_F(PileTest, topPileVideLanceLogicError) {
//	Pile<int> pileVide;
//	EXPECT_THROW(pileVide.top(), PreconditionException);
//}
//
//TEST_F(PileTest, operatorCrochetErreur) {
//	Pile<int> unePile;
//	unePile.empiler(5);
//	EXPECT_THROW(unePile[-1], PreconditionException);
//	EXPECT_THROW(unePile[2], PreconditionException);
//}

