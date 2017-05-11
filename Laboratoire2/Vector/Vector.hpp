/**
 * \file Vector.hpp
 * \brief Implémentation de la classe Vector
 * \author Ludovic Trottier
 * \author Mathieu Dumoulin
 * \version 0.3
 * \date Mai 2014
 */

#include <algorithm>
#include <stdexcept>

/**!
 * std::vector est un conteneur séquentiel qui encapsule les tableaux de taille dynamique .
 Les éléments sont stockés de façon contigüe, ce qui signifie que les éléments sont accessibles non
 seulement via les itérateurs, mais aussi à partir des pointeurs classiques sur un élément.
 Cela signifie qu'un pointeur sur un élément d'un vector peut être passé à une fonction qui attend
 un pointeur sur un élément d'un tableau.

 Le stockage du vector est pris en charge automatiquement, pouvant être augmenté ou diminué au
 besoin. Les vector occupent généralement plus d'espace que les tableaux statiques, du fait que de
 la mémoire supplémentaire est allouée pour anticiper un accroissement future. Ainsi, un vector n'a
 pas besoin de ré-allouer la mémoire chaque fois qu'un élément est inséré, mais seulement lorsque
 la mémoire additionnelle est épuisée. La quantité totale de mémoire allouée peut être obtenue en
 utilisant la fonction capacity().
 */

/**
 * \brief Constructor with an initial capacity
 * \param[in] p_initSize initial capacity, multiples of the size of T
 */
template<typename T>
Vector<T>::Vector(int p_initSize) :
		m_size(0), m_capacity(0), m_objects(0) {
	reserve(p_initSize);
}

/**
 * \brief Destructor, all allocated memory (if any) is freed
 */
template<typename T>
Vector<T>::~Vector() {
	if (m_capacity > 0) {
		delete[] m_objects;
	}
}

/*
 * \brief Copy constructor - Deep copy
 * \param[in] Another vector to copy
 */
template<typename T>
Vector<T>::Vector(const Vector & p_rhs) :
		m_size(p_rhs.m_size), m_capacity(p_rhs.m_capacity), m_objects(0) {
	if (this != &p_rhs) {
		delete[] m_objects;
		m_objects = new T[p_rhs.m_capacity];
		std::copy(p_rhs.begin(), p_rhs.end(), m_objects);
	}
}

/*
 * \brief Assignment operator - Deep copy
 * \param[in] Another vector to copy
 */
template<typename T>
Vector<T> & Vector<T>::operator=(const Vector & p_rhs) {
	if (this != &p_rhs) {
		delete[] m_objects;
		T * m_objects = new T[p_rhs.m_capacity];
		std::copy(p_rhs.begin(), p_rhs.end(), m_objects);
		m_capacity = p_rhs.m_capacity;
		m_size = p_rhs.m_size;
	}
	return *this;
}

/**
 * \brief Test whether vector is empty
 * \return true if vector is empty, false if not empty
 */
template<typename T>
bool Vector<T>::empty() const {
	return m_size == 0;
}
/**
 * \brief Query the size of the vector
 * \return The number of elements currently in the vector
 */
template<typename T>
int Vector<T>::size() const {
	return m_size;
}
/**
 * \brief Return size of allocated storage capacity
 * \return The memory currently reserved by the vector
 */
template<typename T>
int Vector<T>::capacity() const {
	return m_capacity;
}

/*
 * \brief Add element at the end
 *
 * Adds a new element at the end of the vector, after its current last element. The content of val
 * is copied (or moved) to the new element.
 *
 * This effectively increases the container size by one, which causes an automatic reallocation
 * of the allocated storage space if -and only if- the new vector size surpasses the current vector
 * capacity.
 *
 * \param[in] the element to be added
 */
template<typename T>
void Vector<T>::push_back(const T & p_value) {
	if (m_size == m_capacity) {
		reserve(2 * m_capacity + 1);
	}
	m_objects[m_size] = p_value;
	m_size++;
}

/*
 * \brief Remove the last element in the vector
 * \return The element at the end (by value)
 */
template<typename T>
T Vector<T>::pop_back() {
	m_size--;
	return m_objects[m_size];
}
/*
 * \brief Resize the vector
 *
 * Resizes the container to contain "p_size" elements.
 * If the current size is greater than count, the container is reduced to its first count elements
 * as if by repeatedly calling pop_back()
 *
 * If the current size is less than count, additional elements are appended and initialized with
 * copies of value.
 */
template<typename T>
void Vector<T>::resize(int p_size, T p_value) {
	if (p_size > m_size) {
		reserve(p_size);
		std::fill_n(m_objects + m_size, p_size - m_size, p_value);
	}
	m_size = p_size;
}

/*
 * \brief Request a change in capacity.
 *
 * If the new capacity is smaller than the current size, only "p_capabity" elements are kept.
 * \param[in] New capacity
 */
template<typename T>
void Vector<T>::reserve(int p_capacity) {
	if (p_capacity == m_size)
		return;

	T * newObjects = new T[p_capacity];
	m_size = std::min(m_size, p_capacity);
	if (!empty()) {
		for (int i = 0; i < m_size; i++) {
			newObjects[i] = m_objects[i];
		}
		delete[] m_objects;
	}
	m_capacity = p_capacity;
	m_objects = newObjects;
}

/*
 * \brief Return iterator to end
 * \return Iterator on last element
 */
template<typename T>
typename Vector<T>::iterator Vector<T>::end() {
	return m_objects + m_size;
}

/*
 * \brief Supprime tous les éléments du conteneur sans changer la capacité.
 *  Les itérateurs past-the-end ne sont pas invalidés.
 */
template<typename T>
inline void Vector<T>::clear() {
	m_size = 0;
}

/*
 * \brief Return const_iterator to end
 * \return const_iterator on last element
 */
template<typename T>
typename Vector<T>::const_iterator Vector<T>::end() const {
	return m_objects + m_size;
}

/*
 * \brief Return iterator to beginning
 * \return Iterator on first element
 */
template<typename T>
typename Vector<T>::iterator Vector<T>::begin() {
	return m_objects;
}

/*
 * \brief Return const_iterator to beginning
 * \return const_iterator on first element
 */
template<typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const {
	return m_objects;
}

/*
 * \brief Insert an element at iterator's position
 *
 * It is the responsibility of the user to ensure that there is enough capacity.
 *
 * \param[in] iterator pointing to the wanted position
 * \param[in] element to be added
 * \return iterator at the position of the newly added element
 */
template<typename T>
typename Vector<T>::iterator Vector<T>::insert(iterator p_iter, const T& p_elem) {
	if (m_size == 0 || p_iter == end()) {
		push_back(p_elem);
		return end() - 1;
	}

	int pos = p_iter - begin();            // Position where to add the element
	push_back (m_objects[m_size - 1]); // The last element is moved of one position
	// This ensure that we have enough space
	for (int i = m_size - 2; i > pos; --i) { // Moving the others
		m_objects[i] = m_objects[i - 1];
	}
	m_objects[pos] = p_elem;  // The element is inserted at the correct position

	return &m_objects[pos]; // Remark: p_iter could be invalid at this point
}

/*
 * \brief Access element
 *
 * A similar member function, vector::at, has the same behavior as this operator function,
 * except that vector::at is bound-checked and signals if the requested position is out of
 * range by throwing an out_of_range exception.
 *
 * \param[in] position of query
 * \return Reference to the element at wanted position
 */
template<typename T>
T & Vector<T>::operator[](const int & p_pos) {
	return m_objects[p_pos];
}

/*
 * \brief Access element (const)
 *
 * A similar member function, vector::at, has the same behavior as this operator function,
 * except that vector::at is bound-checked and signals if the requested position is out of
 * range by throwing an out_of_range exception.
 *
 * \param[in] position of query
 * \return const reference to the element at wanted position
 */
template<typename T>
const T & Vector<T>::operator[](const int & p_pos) const {
	return m_objects[p_pos];
}

/*
 * \brief Access element at wanted position
 *
 * This function verifies the validity of the index
 *
 * \param[in] position of query
 * \exception std::out_of_range if wanted position is bad
 * \return Reference to the element at wanted position in the vector.
 */
template<typename T>
T & Vector<T>::at(const int & p_pos) {
	if (p_pos < 0 || p_pos >= size()) {
		throw std::out_of_range("Indice en erreur\n");
	}

	return m_objects[p_pos];
}

/*
 * \brief Access element (const) at wanted position
 *
 * This function verifies the validity of the index
 *
 * \param[in] position of query
 * \exception std::out_of_range if wanted position is bad
 * \return const reference to the element at wanted position in the vector.
 */
template<typename T>
const T & Vector<T>::at(const int & pos) const {
	if (pos < 0 || pos >= size()) {
		throw std::out_of_range("Indice en erreur\n");
	}

	return m_objects[pos];
}

/*
 * \brief Access last element
 *
 * Unlike member vector::end, which returns an iterator just past this element, this function
 * returns a direct reference. Calling this function on an empty container causes undefined behavior.
 *
 * \return Reference to the last element in the vector.
 */
template<typename T>
const T & Vector<T>::back() const {
	return m_objects[m_size - 1];
}
