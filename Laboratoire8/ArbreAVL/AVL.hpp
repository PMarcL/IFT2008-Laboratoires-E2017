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

template<typename E>
void Arbre<E>::insererAVL(const E & data) {
	PRECONDITION(!appartient(data));
	_insererAVL(m_racine, data);
}

template<typename E>
void Arbre<E>::_insererAVL(Noeud *& noeud, const E & data) {
	if (noeud == nullptr) {
		noeud = new Noeud(data);
		m_cardinalite++;
		return;
	} else if (noeud->m_data < data) {
		_insererAVL(noeud->m_droite, data);
	} else {
		_insererAVL(noeud->m_gauche, data);
	}

	_miseAJourHauteurNoeud(noeud);
	_balancerUnNoeud(noeud);
}

template<typename E>
void Arbre<E>::_miseAJourHauteurNoeud(Noeud *& noeud) {
	if (noeud != nullptr) {
		noeud->m_hauteur = 1 + std::max(_hauteur(noeud->m_gauche), _hauteur(noeud->m_droite));
	}
}

template<typename E>
int Arbre<E>::_hauteur(Noeud *& noeud) const {
	if (noeud == nullptr) {
		return -1;
	}
	return noeud->m_hauteur;
}

template<typename E>
bool Arbre<E>::appartient(const E & data) const {
	return _appartient(m_racine, data);
}

template<typename E>
void Arbre<E>::_balancerUnNoeud(Noeud *& noeud) {
	if (noeud == nullptr) {
		return;
	}
	if (_debalancementAGauche(noeud)) {
		if (_sousArbrePencheADroite(noeud->m_gauche)) {
			_zigZagGauche(noeud);
		} else {
			_zigZigGauche(noeud);
		}
	} else if (_debalancementADroite(noeud)) {
		if (_sousArbrePencheAGauche(noeud->m_droite)) {
			_zigZagDroite(noeud);
		} else {
			_zigZigDroite(noeud);
		}
	}
}

template<typename E>
bool Arbre<E>::_debalancementAGauche(Noeud *& noeud) const {
	if (noeud == nullptr) {
		return false;
	}
	return _hauteur(noeud->m_gauche) - _hauteur(noeud->m_droite) >= 2;
}

template<typename E>
bool Arbre<E>::_debalancementADroite(Noeud *& noeud) const {
	if (noeud == nullptr) {
		return false;
	}
	return _hauteur(noeud->m_droite) - _hauteur(noeud->m_gauche) >= 2;
}

template<typename E>
bool Arbre<E>::_sousArbrePencheADroite(Noeud *& noeud) const {
	if (noeud == nullptr) {
		return false;
	}
	return _hauteur(noeud->m_gauche) < _hauteur(noeud->m_droite);
}

template<typename E>
bool Arbre<E>::_sousArbrePencheAGauche(Noeud *& noeud) const {
	if (noeud == nullptr) {
		return false;
	}
	return _hauteur(noeud->m_gauche) > _hauteur(noeud->m_droite);
}

template<typename E>
void Arbre<E>::_zigZigGauche(Noeud *& noeudCritique) {
	Noeud * noeudSousCritique = noeudCritique->m_gauche;
	noeudCritique->m_gauche = noeudSousCritique->m_droite;
	noeudSousCritique->m_droite = noeudCritique;

	_miseAJourHauteurNoeud(noeudCritique);
	_miseAJourHauteurNoeud(noeudSousCritique);

	noeudCritique = noeudSousCritique;
}

template<typename E>
void Arbre<E>::_zigZigDroite(Noeud *& noeudCritique) {
	Noeud * noeudSousCritique = noeudCritique->m_droite;
	noeudCritique->m_droite = noeudSousCritique->m_gauche;
	noeudSousCritique->m_gauche = noeudCritique;

	_miseAJourHauteurNoeud(noeudCritique);
	_miseAJourHauteurNoeud(noeudSousCritique);

	noeudCritique = noeudSousCritique;
}

template<typename E>
void Arbre<E>::_zigZagGauche(Noeud *& noeud) {
	_zigZigDroite(noeud->m_gauche);
	_zigZigGauche(noeud);
}

template<typename E>
void Arbre<E>::_zigZagDroite(Noeud *& noeud) {
	_zigZigGauche(noeud->m_droite);
	_zigZigDroite(noeud);
}

template<typename E>
bool Arbre<E>::estAVL() const {
	if (estVide()) {
		return true;
	}
	std::list<Noeud*> file;
	file.push_back(m_racine);

	while (!file.empty()) {
		auto noeud = file.front();
		file.pop_front();

		if (_amplitudeDuDebalancement(noeud) > 1) {
			return false;
		}

		if (noeud->m_gauche != nullptr) {
			file.push_back(noeud->m_gauche);
		}
		if (noeud->m_droite != nullptr) {
			file.push_back(noeud->m_droite);
		}
	}
	return true;
}

template<typename E>
bool Arbre<E>::estVide() const {
	return m_cardinalite == 0;
}

template<typename E>
void Arbre<E>::enleverAVL(const E & data) {
	PRECONDITION(appartient(data));
	_enleverAVL(m_racine, data);
}

template<typename E>
void Arbre<E>::_enleverAVL(Noeud *& noeud, const E & data) {
	if (noeud == nullptr) {
		throw std::logic_error("Tu es caves!!!");
	}

	if (noeud->m_data > data) {
		_enleverAVL(noeud->m_gauche, data);
	} else if (noeud->m_data < data) {
		_enleverAVL(noeud->m_droite, data);
	} else {
		if (_hauteur(noeud) == 0) {
			delete noeud;
			noeud = nullptr;
			m_cardinalite--;
		} else if (!_aDeuxfils(noeud)) {
			if (noeud->m_gauche != nullptr) {
				std::swap(noeud->m_data, noeud->m_gauche->m_data);
				_enleverAVL(noeud->m_gauche, data);
			} else {
				std::swap(noeud->m_data, noeud->m_droite->m_data);
				_enleverAVL(noeud->m_droite, data);
			}
		} else {
			Noeud * minDroite = _min(noeud->m_droite);
			std::swap(noeud->m_data, minDroite->m_data);
			_enleverAVL(noeud->m_droite, data);
		}
	}

	_miseAJourHauteurNoeud(noeud);
	_balancerUnNoeud(noeud);
}

template<typename E>
bool Arbre<E>::_aDeuxfils(Noeud *& noeud) const {
	if (noeud == nullptr) {
		return false;
	}
	return noeud->m_gauche != nullptr && noeud->m_droite != nullptr;
}

template<typename E>
typename Arbre<E>::Noeud* Arbre<E>::_min(Noeud * noeud) const {
	if (noeud->m_gauche == nullptr) {
		return noeud;
	}
	return _min(noeud->m_gauche);
}

template<typename E>
int Arbre<E>::_amplitudeDuDebalancement(Noeud * noeud) const {
	if (noeud == nullptr) {
		return 0;
	}
	return std::abs(_hauteur(noeud->m_gauche) - _hauteur(noeud->m_droite));
}

template<typename E>
bool Arbre<E>::_appartient(Noeud * const & noeud, const E & data) const {
	if (noeud == nullptr) {
		return false;
	} else if (noeud->m_data == data) {
		return true;
	} else if (noeud->m_data > data) {
		return _appartient(noeud->m_gauche, data);
	} else {
		return _appartient(noeud->m_droite, data);
	}
}

} //Fin du namespace
