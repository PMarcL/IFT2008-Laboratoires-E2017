#include <iostream>
#include <algorithm>
#include "ContratException.h"

using namespace std;

namespace labGrapheListes {

template<typename T>
Graphe<T>::Graphe(size_t nbSommets) :
		m_nbSommets(nbSommets), m_noms(vector < T > (nbSommets)) {
	m_matriceAdj.resize(m_nbSommets);
	for (size_t i = 0; i < m_nbSommets; i++) {
		m_matriceAdj[i].resize(m_nbSommets, false);
	}
}

template<typename T>
Graphe<T>::~Graphe() {
}

template<typename T>
void Graphe<T>::nommer(unsigned int sommet, const T & nom) {
	PRECONDITION(sommet < m_nbSommets);
	m_noms[sommet] = nom;
}

template<typename T>
void Graphe<T>::ajouterArc(unsigned int source, unsigned int destination) {
	PRECONDITION(source < m_nbSommets);
	PRECONDITION(destination < m_nbSommets);
	PRECONDITION(m_matriceAdj[source][destination] != true);

	m_matriceAdj[source][destination] = true;
}

template<typename T>
void Graphe<T>::enleverArc(unsigned int source, unsigned int destination) {
	PRECONDITION(source < m_nbSommets);
	PRECONDITION(destination < m_nbSommets);
	PRECONDITION(m_matriceAdj[source][destination] != false);

	m_matriceAdj[source][destination] = false;
}

template<typename T>
bool Graphe<T>::arcExiste(unsigned int source, unsigned int destination) const {
	PRECONDITION(source < m_nbSommets);
	PRECONDITION(destination < m_nbSommets);
	return m_matriceAdj[source][destination];
}

template<typename T>
T Graphe<T>::reqNom(unsigned int sommet) const {
	PRECONDITION(sommet < m_nbSommets);
	return m_noms[sommet];
}

template<typename T>
size_t Graphe<T>::reqNbSommets() const {
	return m_nbSommets;
}

template<typename T>
void Graphe<T>::affiche() const {

	for (unsigned int i = 0; i < m_nbSommets; ++i) {
		std::cout << "Sommet " << i << ": ";

		for (unsigned int j = 0; j < m_nbSommets; ++j) {
			if (m_matriceAdj[i][j]) {
				std::cout << i << "->" << j << ", ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template<typename T>
vector<unsigned int> Graphe<T>::listerSommetsAdjacents(unsigned int sommet) const {
	PRECONDITION(sommet < m_nbSommets);
	vector<unsigned int> sommetsAdj;
	for (size_t i = 0; i < m_nbSommets; i++) {
		if (m_matriceAdj[sommet][i]) {
			sommetsAdj.push_back(i);
		}
	}
	return sommetsAdj;
}

template<typename T>
unsigned int Graphe<T>::degreEntreeSommet(unsigned int sommet) const {
	PRECONDITION(sommet < m_nbSommets);
	unsigned int degre = 0;
	for (size_t i = 0; i < m_nbSommets; i++) {
		if (m_matriceAdj[i][sommet]) {
			degre++;
		}
	}
	return degre;
}

template<typename T>
unsigned int Graphe<T>::degreSortieSommet(unsigned int sommet) const {
	PRECONDITION(sommet < m_nbSommets);
	unsigned int degre = 0;
	for (size_t i = 0; i < m_nbSommets; i++) {
		if (m_matriceAdj[sommet][i]) {
			degre++;
		}
	}
	return degre;
}

} //Fin du namespace
