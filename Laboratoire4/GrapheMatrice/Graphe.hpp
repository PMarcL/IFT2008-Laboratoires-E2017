#include <iostream>
#include <algorithm>
#include "ContratException.h"

using namespace std;

namespace labGrapheListes {

// implémentation ici

template<typename T>
void Graphe<T>::affiche() const {

	for (unsigned int i = 0; i < m_nbSommets; ++i) {
		std::cout << "Sommet " << i << ": ";

		for (unsigned int j = 0; j < m_nbSommets; ++j) {
			if (m_matriceAdj[i][j]) {
				std::cout << i << "->" << j << ", ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

}

} //Fin du namespace
