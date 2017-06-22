#include <vector>
#include <list>
#include "ContratException.h"

namespace labParcoursArbre {

template<typename E>
Arbre<E>::Arbre() :
		m_racine(nullptr) {
}

template<typename E>
Arbre<E>::Arbre(E* parcoursSym, int debut, int fin, E** parcoursPreOrdre) {
	m_racine = _auxPereSym(parcoursSym, debut, fin, parcoursPreOrdre);
}

template<typename E>
typename Arbre<E>::Noeud* Arbre<E>::_auxPereSym(E* parcoursSym, int debut, int fin, E** parcoursPreOrdre) {
	if (debut > fin) {
		return nullptr;
	}

	Noeud* noeud = new Noeud(*parcoursPreOrdre[0]);
	int positionRacine = 0;
	while (parcoursSym[positionRacine] != *parcoursPreOrdre[0]) {
		positionRacine++;
	}

	(*parcoursPreOrdre)++;
	noeud->m_gauche = _auxPereSym(parcoursSym, debut, positionRacine - 1, parcoursPreOrdre);
	noeud->m_droite = _auxPereSym(parcoursSym, positionRacine + 1, fin, parcoursPreOrdre);

	return noeud;
}

template<typename E>
Arbre<E>::Arbre(const std::vector<E> & p_visiteSymetrique, const std::vector<E>& p_visitePere) {
	m_racine = _auxPereSym(p_visiteSymetrique.begin(), p_visiteSymetrique.end(), p_visitePere.begin(),
			p_visitePere.end());
}

template<typename E>
typename Arbre<E>::Noeud*
Arbre<E>::_auxPereSym(constVecItr& p_debutS, constVecItr& p_finS, constVecItr& p_debutP, constVecItr& p_finP) {

	PRECONDITION(std::distance(p_debutS, p_finS) == std::distance(p_debutP, p_finP));

	// Condition d'arret
	if (p_debutS == p_finS)
		return NULL;

	// Le premier element de tabP est la racine de l'arbre
	Noeud* nouveau = new Noeud(*p_debutP);

	// Recherche de la racine de l'arbre dans tabS. Apres cette boucle:
	// - iterS pointe sur la racine de l'arbre dans tabS;
	// - iterP pointe sur la racine du fils droit dans tabP;
	vecItr iterS = p_debutS;
	vecItr iterP = p_debutP + 1;
	while (*iterS != *p_debutP && iterS != p_finS) {
		++iterS;
		++iterP;
	}

	// Construction recursives des sous-arbres gauche et droit
	nouveau->m_gauche = _auxPereSym(p_debutS, iterS, p_debutP + 1, iterP);
	nouveau->m_droite = _auxPereSym(iterS + 1, p_finS, iterP, p_finP);

	return nouveau;
}

template<typename E>
Arbre<E>::Arbre(const Arbre & aCopier) {
	_auxCopier(aCopier.m_racine, m_racine);
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

}            //Fin du namespace
