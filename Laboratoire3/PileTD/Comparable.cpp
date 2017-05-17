/**
 * \file Comparable.hpp
 * \brief Le code des méthodes membres de la classe Comparable.
 * \author Abder
 * \version 0.1
 * \date mars 2011
 */

#include "Comparable.h"

/**
 *  \brief Constructeur par défaut.
 *
 *  \post Une instance de la classe non initialisée.
 */
Comparable::Comparable() :
		m_valeur(0), m_mot("") {
}

/**
 *  \brief Constructeur avec arguments.
 *
 *  \post Une instance de la classe initialisée.
 */
Comparable::Comparable(const int & V, const std::string & M) :
		m_valeur(V), m_mot(M) {
}

/**
 *  \brief Constructeur de copie.
 *
 *  \post Une copie profonde de l'objet source.
 */
Comparable::Comparable(const Comparable & Source) :
		m_valeur(Source.m_valeur), m_mot(Source.m_mot) {
}

/**
 *  \brief Destructeur.
 *
 *  \post L'instance de la classe est détruite.
 */
Comparable::~Comparable() {
}

/**
 *  \brief Retourner le membre Valeur.
 *
 *  \post Un entier est retourné.
 */
int Comparable::reqValeur() const {
	return m_valeur;
}

/**
 *  \brief Retourner le membre Mot.
 *
 *  \post Une chaîne de caractères est retournée.
 */
std::string Comparable::reqMot() const {
	return m_mot;
}

/**
 * \brief Surcharger l'opérateur <
 *
 * \post Un booléen est retournée.
 */
bool Comparable::operator<(const Comparable & Op2) const {
	return m_valeur < Op2.m_valeur;
}

/**
 * \brief Surcharger l'opérateur <=
 *
 * \post Un booléen est retournée
 */
bool Comparable::operator<=(const Comparable & Op2) const {
	return m_valeur <= Op2.m_valeur;
}

/**
 * \brief Surcharger l'opérateur >
 *
 * \post Un booléen est retournée
 */
bool Comparable::operator>(const Comparable & Op2) const {
	return m_valeur > Op2.m_valeur;
}

/**
 * \brief Surcharger l'opérateur >=
 *
 * \post Un booléen est retournée.
 */
bool Comparable::operator>=(const Comparable & Op2) const {
	return m_valeur >= Op2.m_valeur;
}

/**
 * \brief Surcharger l'opérateur !=
 *
 * \post Un booléen est retournée.
 */
bool Comparable::operator!=(const Comparable & Op2) const {
	return m_valeur != Op2.m_valeur;
}

/**
 * \brief Surcharger l'opérateur ==
 *
 * \post Un booléen est retournée.
 */
bool Comparable::operator==(const Comparable & Op2) const {
	return m_valeur == Op2.m_valeur;
}

/**
 * \brief Surcharger l'opérateur =
 *
 * Copie l'opérande de droite dans l'objet courant.
 *
 * \post Une copie profonde de la source est retournée.
 */
Comparable & Comparable::operator=(const Comparable & Op2) {
	m_valeur = Op2.m_valeur;
	m_mot = Op2.m_mot;
	return *this;
}

/**
 * \brief Surcharger l'opérateur +
 *
 * Additionne deux objets Comparable.
 *
 * \post Une instance de type Comparable somme de 2 objets Comparable.
 */
Comparable Comparable::operator+(const Comparable &Op2) const {
	Comparable Temp;
	Temp.m_valeur = m_valeur + Op2.m_valeur;
	Temp.m_mot = m_mot;
	Temp.m_mot = Temp.m_mot + Op2.m_mot;
	return (Temp);
}

/**
 * \brief Surcharge de l'opérateur <<
 *
 *	Affiche le contenu de l'objet à l'écran.
 * \post Un flot de sortie correspondant à l'objet de type Comparable est retournée.
 */
std::ostream & operator<<(std::ostream & sortie, const Comparable & source) {
	sortie << "Valeur->" << std::setw(5) << std::setiosflags(std::ios::left) << source.reqValeur() << " Mot->"
			<< source.reqValeur() << std::endl;
	return sortie;
}

