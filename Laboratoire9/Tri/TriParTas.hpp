#include <vector>
#include <cmath>

namespace labTris {

template<typename E>
void creerMonceau(std::vector<E> & v);

template<typename E>
void reparerMonceau(std::vector<E> & v, int cardinalite);

template<typename E>
int positionFilsDeValeurMax(std::vector<E> & v, size_t parent, size_t cardinalite);

template<typename E>
void triParTas(std::vector<E> & p_v) {
	creerMonceau(p_v);

	for (size_t i = p_v.size() - 1; i > 0; i--) {
		std::swap(p_v[0], p_v[i]);
		reparerMonceau(p_v, i);
	}
}

template<typename E>
void creerMonceau(std::vector<E> & v) {
	size_t cardinalite = v.size();
	int position = v.size();

	for (size_t i = 0; i < cardinalite; i++) {
		while (position > 0) {
			position--;
			size_t positionParent = std::floor((double) position + 1) / 2 - 1;
			if (v[position] >= v[positionParent]) {
				std::swap(v[position], v[positionParent]);
			}
		}
		position = cardinalite;
	}
}

template<typename E>
void reparerMonceau(std::vector<E> & v, int cardinalite) {
	int positionParent = 0;
	int positionFilsDePlusGrandeValeur = 0;

	while (positionParent < (cardinalite / 2) && positionFilsDePlusGrandeValeur != -1) {
		positionFilsDePlusGrandeValeur = positionFilsDeValeurMax(v, positionParent, cardinalite);
		if (positionFilsDePlusGrandeValeur != -1) {
			std::swap(v[positionParent], v[positionFilsDePlusGrandeValeur]);
			positionParent = positionFilsDePlusGrandeValeur;
		}
	}
}

template<typename E>
int positionFilsDeValeurMax(std::vector<E> & v, size_t parent, size_t cardinalite) {
	size_t filsGauche = 2 * parent + 1;
	size_t filsDroit = 2 * parent + 2;

	E valeurGauche = filsGauche < cardinalite ? v[filsGauche] : v[parent];
	E valeurDroit = filsDroit < cardinalite ? v[filsDroit] : v[parent];

	if (std::max(valeurGauche, valeurDroit) > v[parent]) {
		if (valeurGauche > valeurDroit) {
			return filsGauche;
		}
		return filsDroit;
	}

	return -1;
}

} // Fin namespace
