/**
 * \file Pile.h
 * \brief Classe définissant le type abstrait pile
 * \author Ludovic Trottier
 * \author Mathieu Dumoulin <mathieu.dumoulin@gmail.com> été 2013
 * \author Abder
 * \version 0.3
 * \date mai 2014
 *
 * Représentation dans une liste chaînée
 */

#ifndef PILE_H
#define PILE_H

#include <iostream>
#include <stdexcept>

namespace labPileFile {
/**
 * \class Pile
 *
 * \brief Classe générique représentant une Pile.
 *
 *  La classe gère une pile générique. L'implémentation
 *  se fait dans une liste chaînée.
 */
template<typename T>
class Pile {
public:
	Pile();
	Pile(const Pile &);
	~Pile();

	void empiler(const T &);
	T depiler();

	bool estVide() const;
	size_t taille() const;
	const T& top() const;

	const T & operator[](const int &) const;
	const Pile<T> & operator =(const Pile<T> &);

	template<typename U> friend std::ostream& operator <<(std::ostream &, const Pile<U> &);

private:
	/**
	 * \class Noeud
	 *
	 * \brief Classe interne représentant un noeud (une position) dans la pile.
	 */
	class Noeud {
	public:
		T m_el; /*!<L'élément de base de la pile*/
		Noeud * m_suivant; /*!<Un pointeur vers le noeud suivant*/

		/**
		 * \brief Constructeur de la classe Noeud.
		 *
		 * \post Un noeud typique est initialisé.
		 */
		Noeud(const T& data_item, Noeud * next_ptr = 0) :
				m_el(data_item), m_suivant(next_ptr) {
		}
	};

	/**
	 * \typedef typedef Noeud *elem
	 * \brief Définition d'un pointeur sur un Noeud
	 *
	 *  Pour abréger les écritures
	 */
	typedef Noeud * elem;

	elem m_sommet; /*!<Pointeur vers le premier noeud, le sommet de la pile*/
	int m_cardinalite; /*!<Cardinalité de la pile*/

	// Méthodes privées
	void _detruire();
	void _copier(const Pile<T> &);

};
} //Fin du namespace

#include "Pile.hpp"

#endif
