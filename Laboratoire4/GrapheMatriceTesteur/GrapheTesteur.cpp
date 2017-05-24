/**
 * \file GrapheTesteur.cpp
 * \brief Test unitaires pour la classe Graphe
 * \author Jean-Francis Roy
 * \version 0.1
 * \date Août 2016
 *
 * Tests unitaires de la classe Graphe
 */

#include "Graphe.h"
#include "gtest/gtest.h"
#include <string>
#include <algorithm>

using labGrapheListes::Graphe;
using std::vector;
using std::string;

TEST(Test, test) {
	ASSERT_TRUE(true);
}

//class GrapheVide: public ::testing::Test {
//protected:
//	GrapheVide() :
//			g(0) {
//	}
//
//	Graphe<string> g;
//};

//class GrapheTest : public ::testing::Test {
//protected:
//    GrapheTest() : g(5) {}
//    virtual void SetUp() {
//        g.nommer(0, 'a');
//        g.nommer(1, 'b');
//        g.nommer(2, 'c');
//        g.nommer(3, 'd');
//        g.nommer(4, 'e');
//
//        g.ajouterArc(0, 0);
//        g.ajouterArc(0, 1);
//        g.ajouterArc(1, 2);
//        g.ajouterArc(3, 4);
//    }
//    //virtual void TearDown() {}
//
//    Graphe<char> g;
//};

//TEST_F(GrapheVide, GrapheVideNommerInvalide) {
//	EXPECT_ANY_THROW(g.nommer(0, "Bonjour"));
//	EXPECT_ANY_THROW(g.nommer(1, "Bonjour"));
//}

//TEST_F(GrapheVide, GrapheVideAjouterArcInvalide) {
//    EXPECT_ANY_THROW(g.ajouterArc(0, 0));
//    EXPECT_ANY_THROW(g.ajouterArc(0, 1));
//    EXPECT_ANY_THROW(g.ajouterArc(1, 0));
//    EXPECT_ANY_THROW(g.ajouterArc(1, 1));
//}
//
//
//TEST_F(GrapheVide, GrapheVideEnleverArcInvalide) {
//    EXPECT_ANY_THROW(g.enleverArc(0, 0));
//    EXPECT_ANY_THROW(g.enleverArc(0, 1));
//    EXPECT_ANY_THROW(g.enleverArc(1, 0));
//    EXPECT_ANY_THROW(g.enleverArc(1, 1));
//}
//
//
//TEST_F(GrapheVide, GrapheVideReqNomInvalide) {
//    ASSERT_ANY_THROW(g.reqNom(0));
//    ASSERT_ANY_THROW(g.reqNom(1));
//}
//
//
//TEST_F(GrapheVide, GrapheVideArcExisteInvalide) {
//    EXPECT_ANY_THROW(g.arcExiste(0, 0));
//    EXPECT_ANY_THROW(g.arcExiste(0, 1));
//    EXPECT_ANY_THROW(g.arcExiste(1, 0));
//    EXPECT_ANY_THROW(g.arcExiste(1, 1));
//}
//
//
//TEST_F(GrapheVide, GrapheVideReqNbSommetsOk) {
//    ASSERT_EQ(0, g.reqNbSommets());
//}
//
//
//TEST_F(GrapheVide, GrapheVideAfficheOk) {
//    g.affiche();
//}
//
//
//TEST_F(GrapheVide, GrapheVideListerSommetsAdjacentsInvalide) {
//    EXPECT_ANY_THROW(g.listerSommetsAdjacents(0));
//    EXPECT_ANY_THROW(g.listerSommetsAdjacents(1));
//}
//
//
//TEST_F(GrapheVide, GrapheVideOrdreEntreeInvalide) {
//    EXPECT_ANY_THROW(g.ordreEntreeSommet(0));
//    EXPECT_ANY_THROW(g.ordreEntreeSommet(0));
//}
//
//
//TEST_F(GrapheVide, GrapheVideOrdreSortieInvalide) {
//    EXPECT_ANY_THROW(g.ordreSortieSommet(0));
//    EXPECT_ANY_THROW(g.ordreSortieSommet(0));
//}
//
//
//TEST_F(GrapheTest, ConstructeurOK) {
//   EXPECT_EQ(5, g.reqNbSommets());
//}
//
//
//TEST_F(GrapheTest, EnleverArcAbsentLanceException) {
//   EXPECT_ANY_THROW(g.enleverArc(4, 3));
//}
//
//
//TEST_F(GrapheTest, EnleverArcSommetInvalideLanceException) {
//   EXPECT_ANY_THROW(g.enleverArc(5, 3));
//}
//
//
//TEST_F(GrapheTest, AjouterArcDejaPresentLanceException) {
//    EXPECT_ANY_THROW(g.ajouterArc(0, 0));
//}
//
//
//TEST_F(GrapheTest, AjouterArcSommetInvalideLanceException) {
//    EXPECT_ANY_THROW(g.ajouterArc(6, 0));
//}
//
//
//TEST_F(GrapheTest, ArcExisteOK) {
//    EXPECT_TRUE(g.arcExiste(0, 0));
//    EXPECT_TRUE(g.arcExiste(0, 1));
//    EXPECT_TRUE(g.arcExiste(3, 4));
//
//    EXPECT_FALSE(g.arcExiste(1, 0));
//    EXPECT_FALSE(g.arcExiste(3, 3));
//    EXPECT_FALSE(g.arcExiste(4, 4));
//}
//
//
//TEST_F(GrapheTest, AjouterArcOK) {
//    EXPECT_FALSE(g.arcExiste(2, 2));
//    g.ajouterArc(2, 2);
//    EXPECT_TRUE(g.arcExiste(2, 2));
//
//    EXPECT_FALSE(g.arcExiste(2, 4));
//    g.ajouterArc(2, 4);
//    EXPECT_TRUE(g.arcExiste(2, 4));
//
//    EXPECT_FALSE(g.arcExiste(4, 2));
//    g.ajouterArc(4, 2);
//    EXPECT_TRUE(g.arcExiste(4, 2));
//}
//
//
//TEST_F(GrapheTest, EnleverArcOK) {
//    EXPECT_TRUE(g.arcExiste(1, 2));
//    g.enleverArc(1, 2);
//    EXPECT_FALSE(g.arcExiste(1, 2));
//
//    EXPECT_TRUE(g.arcExiste(3, 4));
//    g.enleverArc(3, 4);
//    EXPECT_FALSE(g.arcExiste(3, 4));
//
//    EXPECT_TRUE(g.arcExiste(0, 0));
//    g.enleverArc(0, 0);
//    EXPECT_FALSE(g.arcExiste(0, 0));
//}
//
//
//TEST_F(GrapheTest, ReqNomOK) {
//    EXPECT_EQ(g.reqNom(0), 'a');
//    EXPECT_EQ(g.reqNom(1), 'b');
//    EXPECT_EQ(g.reqNom(2), 'c');
//    EXPECT_EQ(g.reqNom(3), 'd');
//    EXPECT_EQ(g.reqNom(4), 'e');
//}
//
//
//TEST_F(GrapheTest, ReqNomSommetInvalideLanceException) {
//    EXPECT_ANY_THROW(g.reqNom(5));
//    EXPECT_ANY_THROW(g.reqNom(6));
//}
//
//
//TEST_F(GrapheTest, NommerOK) {
//    g.nommer(0, 'x');
//    EXPECT_EQ('x', g.reqNom(0));
//}
//
//
//TEST_F(GrapheTest, NommerSommetInvalideLanceException) {
//    EXPECT_ANY_THROW(g.nommer(5, 'y'));
//    EXPECT_ANY_THROW(g.nommer(6, 'z'));
//}
//
//
//TEST_F(GrapheTest, AfficheOK) {
//    g.affiche();
//}
//
//
//TEST_F(GrapheTest, ListerSommetsAdjacentsOK) {
//    // Construction d'un vecteur en C++11. Si ça ne compile pas, veuillez
//    // activer le support de C++11.
//    std::vector<unsigned int> v0 = {0, 1};
//    std::vector<unsigned int> v1 = {2};
//    std::vector<unsigned int> v2 = {};
//
//    // Fonctionne car la classe std::vector surcharge l'opérateur ==.
//    EXPECT_EQ(v0, g.listerSommetsAdjacents(0));
//    EXPECT_EQ(v1, g.listerSommetsAdjacents(1));
//    EXPECT_EQ(v2, g.listerSommetsAdjacents(2));
//}
//
//
//TEST_F(GrapheTest, ListerSommetsAdjacentsSommetInvalideLanceException) {
//    EXPECT_ANY_THROW(g.listerSommetsAdjacents(5));
//    EXPECT_ANY_THROW(g.listerSommetsAdjacents(6));
//}
//
//
//TEST_F(GrapheTest, OrdreEntreeSommetOK) {
//    EXPECT_EQ(1, g.ordreEntreeSommet(1));
//
//    g.ajouterArc(2, 1);
//    g.ajouterArc(3, 1);
//    EXPECT_EQ(3, g.ordreEntreeSommet(1));
//
//    g.enleverArc(0, 1);
//    EXPECT_EQ(2, g.ordreEntreeSommet(1));
//}
//
//
//TEST_F(GrapheTest, OrdreEntreeSommetInvalideLanceException) {
//    EXPECT_ANY_THROW(g.ordreEntreeSommet(5));
//    EXPECT_ANY_THROW(g.ordreEntreeSommet(6));
//}
//
//
//TEST_F(GrapheTest, OrdreSortieSommetOK) {
//    EXPECT_EQ(2, g.ordreSortieSommet(0));
//
//    g.ajouterArc(0, 2);
//    g.ajouterArc(0, 3);
//    EXPECT_EQ(4, g.ordreSortieSommet(0));
//
//    g.enleverArc(0, 0);
//    EXPECT_EQ(3, g.ordreSortieSommet(0));
//}
//
//
//TEST_F(GrapheTest, OrdreSortieSommetInvalideLanceException) {
//    EXPECT_ANY_THROW(g.ordreSortieSommet(5));
//    EXPECT_ANY_THROW(g.ordreSortieSommet(6));
//}
