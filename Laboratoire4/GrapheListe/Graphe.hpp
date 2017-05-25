#include <iostream>
#include <algorithm>
#include "ContratException.h"

using namespace std;

namespace labGrapheListes {

template<typename T>
Graphe<T>::Graphe(size_t nbSommets) :
		m_nbSommets(nbSommets), m_noms(vector < T > (nbSommets)), m_listesAdj(nbSommets) {
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
	PRECONDITION(!arcExiste(source, destination));

	m_listesAdj[source].push_back(destination);
}

template<typename T>
void Graphe<T>::enleverArc(unsigned int source, unsigned int destination) {
	PRECONDITION(source < m_nbSommets);
	PRECONDITION(destination < m_nbSommets);
	PRECONDITION(arcExiste(source, destination));

	list<unsigned int> & liste = m_listesAdj[source];
	auto it = find(liste.begin(), liste.end(), destination);
	liste.erase(it);
}

template<typename T>
T Graphe<T>::reqNom(unsigned int sommet) const {
	PRECONDITION(sommet < m_nbSommets);
	return m_noms[sommet];
}

template<typename T>
bool Graphe<T>::arcExiste(unsigned int source, unsigned int destination) const {
	PRECONDITION(source < m_nbSommets);
	PRECONDITION(destination < m_nbSommets);
	auto liste = m_listesAdj[source];
	auto it = find(liste.begin(), liste.end(), destination);
	return it != liste.end();
}

template<typename T>
size_t Graphe<T>::reqNbSommets() const {
	return m_nbSommets;
}

template<typename T>
void Graphe<T>::affiche() const {

	for (unsigned int i = 0; i < m_nbSommets; ++i) {
		std::cout << "Sommet " << i << ": ";

		for (std::list<unsigned int>::const_iterator it = m_listesAdj[i].begin(); it != m_listesAdj[i].end(); ++it) {
			std::cout << i << "->" << *it << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template<typename T>
vector<unsigned int> Graphe<T>::listerSommetsAdjacents(unsigned int sommet) const {
	PRECONDITION(sommet < m_nbSommets);
	return vector<unsigned int>(m_listesAdj[sommet].begin(), m_listesAdj[sommet].end());
}

template<typename T>
unsigned int Graphe<T>::degreEntreeSommet(unsigned int sommet) const {
	PRECONDITION(sommet < m_nbSommets);
	unsigned int degre = 0;
	for (auto s : m_listesAdj) {
		for (auto arc : s) {
			if (arc == sommet) {
				degre++;
			}
		}
	}
	return degre;
}

template<typename T>
unsigned int Graphe<T>::degreSortieSommet(unsigned int sommet) const {
	PRECONDITION(sommet < m_nbSommets);
	return m_listesAdj[sommet].size();
}

} //Fin du namespace
