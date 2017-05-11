/**
 * \file Vector.h
 * \brief Classe définissant le type Vector
 * \author Ludovic Trottier
 * \author Mathieu Dumoulin
 * \version 0.3
 * \date Mai 2014
 */
#ifndef _VECTOR__H
#define _VECTOR__H

/**
 * \class Vector
 *
 * \brief Classe générique simulant le type vector de la STL du C++
 *
 *  L'implémentation se fait dans un tableau générique.
 */
template<typename T>
class Vector {
public:
	explicit Vector(int = 0);
	Vector(const Vector &);
	~Vector();
	Vector &operator=(const Vector &);

	void resize(int, T = T());
	void reserve(int);
	bool empty() const;
	int size() const;
	int capacity() const;

	T &operator[](const int &);
	const T &operator[](const int &) const;
	T &at(const int &);
	const T &at(const int &) const;

	void push_back(const T &);
	T pop_back();
	const T &back() const;

	void clear();

	/**
	 * \typedef typedef T * iterator
	 * \brief Définition d'un pointeur sur un T
	 *
	 *  Pour abréger les écritures
	 */
	typedef T * iterator;
	/**
	 * \typedef typedef Noeud *elem
	 * \brief Définition d'un pointeur sur un T const
	 *
	 *  Pour abréger les écritures
	 */
	typedef const T * const_iterator;

	iterator insert(iterator, const T &);
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;

private:
	int m_size; /*!<Taille d'un vector*/
	int m_capacity; /*!<Capacité d'un vector*/
	T *m_objects; /*!<Pointeur pour le début d'un tableau dynamique*/
};

#include "Vector.hpp"

#endif
