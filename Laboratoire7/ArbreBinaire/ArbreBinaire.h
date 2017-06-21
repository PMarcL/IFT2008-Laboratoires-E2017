/**
 * \file ArbreBinaire.h
 * \brief Classe générique d'un arbre binaire
 * \author Ludovic Trottier
 * \author Mathieu Dumoulin
 * \author Abder
 * \version 0.3
 * \date Mai 2014
 *
 * Definition de la classe Arbre et de ses méthodes de parcours 
 */

#ifndef _ARBREBINAIRE_H
#define _ARBREBINAIRE_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <queue>

namespace labParcoursArbre {

/**
 * \class Arbre
 *
 * \brief classe générique représentant un arbre binaire
 *
 *  La classe gère un arbre binaire générique. L'implémentation se fait par chaînage.
 */
template<typename E>
class Arbre {
public:
	Arbre();
	Arbre(E *, int, int, E **);
	Arbre(const std::vector<E> &, const std::vector<E> &);
	Arbre(const Arbre &);
	~Arbre();
	const Arbre& operator =(const Arbre &);

	std::vector<E> listerPreOrdre() const;
	std::vector<E> listerEnOrdre() const;
	std::vector<E> listerPostOrdre() const;
	std::vector<E> listerParNiveau() const;

	void verifieInvariant() const;
private:
	/**
	 * \class Noeud
	 *
	 * \brief classe interne représentant un noeud typique de l'arbre
	 *
	 *  La classe représente un noeud typique
	 *  pour implémenter un arbre par chaînage.
	 */
	class Noeud {
	public:
		E m_data; /*!< La donnée dans l'arbre*/
		Noeud * m_gauche; /*!< Pointeur vers le fils gauche*/
		Noeud * m_droite; /*!< Pointeur vers le fils droit*/
		/**
		 * \brief Constructeur de la classe Noeud
		 * \post Un noeud typique est intialisé
		 */
		Noeud(const E & p_element) :
				m_data(p_element), m_gauche(0), m_droite(0) {
		}
	};

	Noeud * m_racine; /*!< La racine de l'arbre*/

	// Méthodes privées

	typedef typename std::vector<E>::const_iterator vecItr;
	typedef const vecItr constVecItr;
	Noeud * _auxPereSym(constVecItr&, constVecItr&, constVecItr&, constVecItr&);

    // À titre indicatif, voici les méthodes privées de la solution
    /*
	Noeud * _auxPereSym(E *, int, int, E **);
	void _listerEnOrdre(Noeud *, std::vector<E> &) const;
	void _listerPreOrdre(Noeud *, std::vector<E> &) const;
	void _listerPostOrdre(Noeud *, std::vector<E> &) const;
	void _auxCopier(Noeud *, Noeud*&);
	void _auxDetruire(Noeud *&);
    */

};

}		//Fin du namespace

#include "ArbreBinaire.hpp"

#endif

