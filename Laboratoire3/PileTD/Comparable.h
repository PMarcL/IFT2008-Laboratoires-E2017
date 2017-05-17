/**
 * \file Comparable.h
 * \brief Définition de la classe Comparable.
 * \author Abder
 * \version 0.1
 * \date mars 2011
 *
 * Une classe pour tester les implantations génériques.
 */

#ifndef _COMPARABLE_H
#define _COMPARABLE_H

#include <iostream>
#include <string>
#include <iomanip>

/**
 * \class ClassTests
 *
 * \brief classe de testes avec des opérateurs surchargés
 *
 *  La classe nous servira tout le long de la session
 *  pour tester nos différentes implantations génériques.
 */
class Comparable {
public:
	// Constructeurs et destructeurs
	explicit Comparable();
	explicit Comparable(const int & V, const std::string & M);
	Comparable(const Comparable & A);
	~Comparable();

	// Sélecteurs
	int reqValeur() const;
	std::string reqMot() const;

	// Surcharge d'opérateurs
	bool operator<(const Comparable &Op2) const;
	bool operator<=(const Comparable &Op2) const;
	bool operator>(const Comparable &Op2) const;
	bool operator>=(const Comparable &Op2) const;
	bool operator!=(const Comparable &Op2) const;
	bool operator==(const Comparable &Op2) const;
	Comparable & operator=(const Comparable &);
	Comparable operator+(const Comparable &) const;
	friend std::ostream & operator<<(std::ostream &, const Comparable &);

private:
	int m_valeur; /*!<Un entier*/
	std::string m_mot; /*!<Une chaîne de caractères*/

};

#endif
// fin de Comparable.h
