#include <cmath>
#include <list>
#include <iostream>
#include "ContratException.h"

namespace labArbreAVL {

template<typename E>
Arbre<E>::Arbre() :
		m_racine(nullptr), m_cardinalite(0) {
}

template<typename E>
Arbre<E>::Arbre(const Arbre & aCopier) {
	_auxCopier(aCopier.m_racine, m_racine);
	m_cardinalite = aCopier.m_cardinalite;
}

template<typename E>
void Arbre<E>::_auxCopier(Noeud* source, Noeud *& destination) {
	if (source != nullptr) {
		destination = new Noeud(source->m_data);
		_auxCopier(source->m_gauche, destination->m_gauche);
		_auxCopier(source->m_droite, destination->m_droite);
	} else {
		destination = nullptr;
	}
}

template<typename E>
const Arbre<E>& Arbre<E>::operator =(const Arbre<E> & aCopier) {
	Arbre < E > temp(aCopier);
	std::swap(m_racine, temp.m_racine);
	m_cardinalite = temp.m_cardinalite;
	return *this;
}

template<typename E>
Arbre<E>::~Arbre() {
	_auxDetruire (m_racine);
}

template<typename E>
void Arbre<E>::_auxDetruire(Noeud *& noeud) {
	if (noeud != nullptr) {
		_auxDetruire(noeud->m_gauche);
		_auxDetruire(noeud->m_droite);
		delete noeud;
		noeud = nullptr;
	}
}

template<typename E>
std::vector<E> Arbre<E>::listerEnOrdre() const {
	std::vector < E > parcoursEnOrdre;
	_listerEnOrdre(m_racine, parcoursEnOrdre);
	return parcoursEnOrdre;
}

template<typename E>
void Arbre<E>::_listerEnOrdre(Noeud* noeud, std::vector<E> & parcoursEnOrdre) const {
	if (noeud != nullptr) {
		_listerEnOrdre(noeud->m_gauche, parcoursEnOrdre);
		parcoursEnOrdre.push_back(noeud->m_data);
		_listerEnOrdre(noeud->m_droite, parcoursEnOrdre);
	}
}

template<typename E>
std::vector<E> Arbre<E>::listerPreOrdre() const {
	std::vector < E > parcoursPreOrdre;
	_listerPreOrdre(m_racine, parcoursPreOrdre);
	return parcoursPreOrdre;
}

template<typename E>
void Arbre<E>::_listerPreOrdre(Noeud* noeud, std::vector<E> & parcoursPreOrdre) const {
	if (noeud != nullptr) {
		parcoursPreOrdre.push_back(noeud->m_data);
		_listerPreOrdre(noeud->m_gauche, parcoursPreOrdre);
		_listerPreOrdre(noeud->m_droite, parcoursPreOrdre);
	}
}

template<typename E>
std::vector<E> Arbre<E>::listerPostOrdre() const {
	std::vector < E > parcoursPostOrdre;
	_listerPostOrdre(m_racine, parcoursPostOrdre);
	return parcoursPostOrdre;
}

template<typename E>
void Arbre<E>::_listerPostOrdre(Noeud* noeud, std::vector<E> & parcoursPostOrdre) const {
	if (noeud != nullptr) {
		_listerPostOrdre(noeud->m_gauche, parcoursPostOrdre);
		_listerPostOrdre(noeud->m_droite, parcoursPostOrdre);
		parcoursPostOrdre.push_back(noeud->m_data);
	}
}

template<typename E>
std::vector<E> Arbre<E>::listerParNiveau() const {
	std::vector < E > listeParNiveau;
	std::list<Noeud *> file;
	file.push_back(m_racine);

	while (!file.empty()) {
		auto noeud = file.front();
		file.pop_front();

		listeParNiveau.push_back(noeud->m_data);

		if (noeud->m_gauche != nullptr) {
			file.push_back(noeud->m_gauche);
		}
		if (noeud->m_droite != nullptr) {
			file.push_back(noeud->m_droite);
		}
	}

	return listeParNiveau;
}

} //Fin du namespace
