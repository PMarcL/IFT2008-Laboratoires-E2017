#include <cmath>
#include "ContratException.h"

namespace labTableHachage {


template<typename TypeClef, typename TypeElement, class FoncteurHachage>
void TableHachage<TypeClef, TypeElement, FoncteurHachage>::afficher(
		std::ostream & p_out) const {
	p_out << "{";
	for (size_t i = 0; i < m_tab.size(); ++i) {
		if (m_tab[i].m_info == OCCUPE) {
			p_out << m_tab[i] << ",";
		}
	}
	p_out << "}";
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage>
int TableHachage<TypeClef, TypeElement, FoncteurHachage>::_prochainPremier(
		int p_entier) const {
	if (p_entier % 2 == 0) {
		p_entier++;
	}
	while (!_estPremier(p_entier)) {
		p_entier += 2;
	}
	return p_entier;
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage>
bool TableHachage<TypeClef, TypeElement, FoncteurHachage>::_estPremier(
		int p_entier) const {
	if (p_entier <= 1) {
		return false;
	}
	if (p_entier == 2) {             // le seul nombre premier pair
		return true;
	}
	if (p_entier % 2 == 0) {   // sinon, ce n'est pas un nombre premier
		return false;
	}

	int divisor = 3;
	int upperLimit = static_cast<int>(sqrt((float) p_entier) + 1);

	while (divisor <= upperLimit) {
		if (p_entier % divisor == 0) {
			return false;
		}
		divisor += 2;
	}
	return true;
}

template<typename TClef, typename TElement, class FHachage>
std::ostream& operator<<(std::ostream& p_out,
		const TableHachage<TClef, TElement, FHachage> & p_source) {
	p_source.afficher(p_out);
	return p_out;
}

} //Fin du namespace

