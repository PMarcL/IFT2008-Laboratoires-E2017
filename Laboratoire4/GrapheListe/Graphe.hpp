#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include "ContratException.h"

namespace labGrapheListes {

template<typename T>
Graphe<T>::Graphe(size_t nbSommets) :
		m_nbSommets(nbSommets), m_noms(std::vector < T > (nbSommets)), m_listesAdj(nbSommets) {
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

	std::list<unsigned int> & liste = m_listesAdj[source];
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
std::vector<unsigned int> Graphe<T>::listerSommetsAdjacents(unsigned int sommet) const {
	PRECONDITION(sommet < m_nbSommets);
	return std::vector<unsigned int>(m_listesAdj[sommet].begin(), m_listesAdj[sommet].end());
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

template<typename T>
std::vector<unsigned int> Graphe<T>::parcoursProfondeur(unsigned int sommet) const {
	std::stack<unsigned int> pile;
	std::vector<bool> sommetsVisites(m_nbSommets, false);
	std::vector<unsigned int> resultat;

	sommetsVisites[sommet] = true;
	pile.push(sommet);

	while (!pile.empty()) {
		auto prochain = pile.top();
		pile.pop();
		resultat.push_back(prochain);

		auto voisins = listerSommetsAdjacents(prochain);
		for (auto voisin : voisins) {
			if (!sommetsVisites[voisin]) {
				pile.push(voisin);
				sommetsVisites[voisin] = true;
			}
		}
	}
	return resultat;
}

template<typename T>
std::vector<unsigned int> Graphe<T>::parcoursLargeur(unsigned int sommet) const {
	std::queue<unsigned int> file;
	std::vector<bool> sommetsVisites(m_nbSommets, false);
	std::vector<unsigned int> resultat;

	sommetsVisites[sommet] = true;
	file.push(sommet);

	while (!file.empty()) {
		auto prochain = file.front();
		file.pop();
		resultat.push_back(prochain);

		auto voisins = listerSommetsAdjacents(prochain);
		for (auto voisin : voisins) {
			if (!sommetsVisites[voisin]) {
				file.push(voisin);
				sommetsVisites[voisin] = true;
			}
		}
	}
	return resultat;
}

template<typename T>
bool Graphe<T>::estConnexe() const {
	Graphe < T > copie(*this);

	for (unsigned int i = 0; i < m_nbSommets; i++) {
		for (unsigned int j = 0; j < m_nbSommets; j++) {
			if (copie.arcExiste(i, j) && !copie.arcExiste(j, i)) {
				copie.ajouterArc(j, i);
			}
		}
	}

	auto sommetsConnexes = copie.parcoursLargeur(0);
	return sommetsConnexes.size() == m_nbSommets;
}

template<typename T>
std::vector<unsigned int> Graphe<T>::triTopologique() const {
	std::list<unsigned int> triTopo;
	std::vector < EtatSommet > sommetsVisites(m_nbSommets, EtatSommet::PasVisite);

	for (unsigned int i = 0; i < m_nbSommets; i++) {
		if (sommetsVisites[i] == EtatSommet::PasVisite) {
			visiterSommet(i, sommetsVisites, triTopo);
		}
	}

	return std::vector<unsigned int>(triTopo.begin(), triTopo.end());
}

template<typename T>
void Graphe<T>::visiterSommet(unsigned int sommet, std::vector<EtatSommet> &sommetsVisites,
		std::list<unsigned int> &triTopo) const {
	if (sommetsVisites[sommet] == EtatSommet::EnCoursDeVisite) {
		// le graphe a un cycle
		PRECONDITION(false);
	}
	if (sommetsVisites[sommet] == EtatSommet::PasVisite) {
		sommetsVisites[sommet] = EtatSommet::EnCoursDeVisite;

		auto voisins = listerSommetsAdjacents(sommet);
		for (auto voisin : voisins) {
			visiterSommet(voisin, sommetsVisites, triTopo);
		}

		sommetsVisites[sommet] = EtatSommet::Visite;
		triTopo.push_front(sommet);
	}
}

} //Fin du namespace
