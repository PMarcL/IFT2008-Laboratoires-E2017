#include <iostream>
#include <algorithm>
#include "ContratException.h"


namespace labGrapheListes {

// TODO: À compléter...

template <typename T>
void Graphe<T>::affiche() const {

	for (unsigned int i = 0; i < m_nbSommets; ++i) {
		std::cout << "Sommet " << i << ": ";

		for (std::list<unsigned int>::const_iterator it = m_listesAdj[i].begin(); it != m_listesAdj[i].end(); ++it) {
			std::cout << i << "->" << *it << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

}

} //Fin du namespace
