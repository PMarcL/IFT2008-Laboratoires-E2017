#include "ContratException.h"

namespace labPileFile {

template<typename T>
Pile<T>::Pile() :
		m_sommet(NULL), m_cardinalite(0) {
}

template<typename T>
Pile<T>::Pile(const Pile<T>& p) :
		m_sommet(NULL), m_cardinalite(0) {
	_copier(p);
}

template<typename T>
Pile<T>::~Pile() {
	_detruire();
}

template<typename T>
void Pile<T>::empiler(const T & element) {
	auto nouveauNoeud = new Noeud(element, m_sommet);
	m_sommet = nouveauNoeud;
	m_cardinalite++;
}

template<typename T>
T Pile<T>::depiler() {
	auto valeur = m_sommet->m_el;
	auto tmp = m_sommet;
	m_sommet = m_sommet->m_suivant;
	m_cardinalite--;
	delete tmp;
	return valeur;
}

template<typename T>
bool Pile<T>::estVide() const {
	return m_cardinalite == 0;
}

template<typename T>
size_t Pile<T>::taille() const {
	return m_cardinalite;
}

template<typename T>
const T& Pile<T>::top() const {
	return m_sommet->m_el;
}

template<typename T>
const T & Pile<T>::operator[](const int & index) const {
	PRECONDITION(index < m_cardinalite);

	auto sentinelle = m_sommet;
	for (auto i = 0; i < index; i++) {
		sentinelle = sentinelle->m_suivant;
	}
	return sentinelle->m_el;
}

template<typename T>
const Pile<T> & Pile<T>::operator=(const Pile<T> & source) {
	if (this != &source) {
		_detruire();
		_copier(source);
	}

	return *this;
}

template<typename T>
std::ostream & operator <<(std::ostream & p_out, const Pile<T> & p_source) {
	typename Pile<T>::Noeud * tmp = p_source.m_sommet;
	p_out << "Pile: [";
	while (tmp != NULL) {
		p_out << tmp->m_el;
		if (tmp->m_suivant != NULL)
			p_out << ",";
		tmp = tmp->m_suivant;
	}
	p_out << "]";
	return p_out;
}

// Méthodes privées

template<typename T>
void Pile<T>::_detruire() {
	while (m_sommet != NULL) {
		auto tmp = m_sommet;
		m_sommet = m_sommet->m_suivant;
		delete tmp;
	}
	m_cardinalite = 0;
}

template<typename T>
void Pile<T>::_copier(const Pile<T>& source) {
	if (source.m_sommet == NULL) {
		return;
	}

	m_sommet = new Noeud(source.m_sommet->m_el);
	auto sentinelle = source.m_sommet->m_suivant;
	auto sentinelleCible = m_sommet;

	while (sentinelle != NULL) {
		sentinelleCible->m_suivant = new Noeud(sentinelle->m_el);
		sentinelleCible = sentinelleCible->m_suivant;
		sentinelle = sentinelle->m_suivant;
	}

	m_cardinalite = source.m_cardinalite;
}

} //Fin du namespace
