#include "ContratException.h"

namespace labPileFile {

// À compléter ...

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

}//Fin du namespace
