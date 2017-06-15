#include <cmath>
#include "ContratException.h"

namespace labTableHachage {

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::TableHachage(size_t taille) :
		m_tab(_prochainPremier(taille)), m_cardinalite(0), m_nInsertions(0), m_nCollisions(0) {
	vider();
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
void TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::vider() {
	m_cardinalite = 0;
	for (size_t i = 0; i < m_tab.size(); i++) {
		m_tab[i].m_info = VACANT;
	}
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
void TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::inserer(const TypeClef & clef,
		const TypeElement & element) {
	PRECONDITION(!contient(clef));

	size_t position = _trouverPositionLibre(clef);

	m_tab[position] = EntreeHachage(clef, element, OCCUPE);
	++m_cardinalite;

	if (_doitEtreRehachee()) {
		rehacher();
	}
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
bool TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::_doitEtreRehachee() const {
	return static_cast<double>(m_cardinalite) / static_cast<double>(m_tab.size()) >= TAUX_MAX;
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
void TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::enlever(const TypeClef & clef) {
	PRECONDITION(contient(clef));
	size_t position = _trouverPositionClef(clef);
	m_tab[position].m_info = EFFACE;
	--m_cardinalite;
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
TypeElement TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::element(
		const TypeClef & clef) const {
	PRECONDITION(contient(clef));
	size_t position = _trouverPositionClef(clef);
	return m_tab[position].m_el;
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
size_t TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::_trouverPositionLibre(
		const TypeClef & clef) {
	unsigned long i = 0;
	size_t position = _distribution(clef, i);
	while (!_estVacante(position) && !_estEffacee(position)) {
		i++;
		position = _distribution(clef, i);
	}
	m_nCollisions += i;
	m_nInsertions++;
	return position;
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
size_t TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::_distribution(const TypeClef & clef,
		unsigned long i) const {
	size_t h2 = m_hachage2(clef);
	if (h2 % m_tab.size() == 0) {
		h2 = 1;
	}
	return (m_hachage1(clef) + i * h2) % m_tab.size();
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
size_t TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::taille() const {
	return m_cardinalite;
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
bool TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::contient(const TypeClef & clef) const {
	size_t position = _trouverPositionClef(clef);
	return _estOccupee(position);
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
size_t TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::_trouverPositionClef(
		const TypeClef & clef) const {
	unsigned long i = 0;
	size_t position = _distribution(clef, i);
	while (!_estVacante(position) && !_clefExiste(position, clef)) {
		i++;
		position = _distribution(clef, i);
	}
	return position;
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
bool TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::_clefExiste(size_t position,
		const TypeClef & clef) const {
	return m_tab[position].m_clef == clef;
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
void TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::rehacher() {
	std::vector < EntreeHachage > entreesActives;
	for (size_t i = 0; i < m_tab.size(); i++) {
		if (_estOccupee(i)) {
			entreesActives.push_back(m_tab[i]);
		}
	}

	m_tab.resize(m_tab.size() * 2);
	vider();

	for (size_t i = 0; i < entreesActives.size(); i++) {
		inserer(entreesActives[i].m_clef, entreesActives[i].m_el);
	}
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
double TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::statistiques() const {
	PRECONDITION(m_nInsertions > 0);
	return static_cast<double>(m_nCollisions) / static_cast<double>(m_nInsertions);
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
bool TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::_estEffacee(size_t position) const {
	return m_tab[position].m_info == EFFACE;
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
bool TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::_estOccupee(size_t position) const {
	return m_tab[position].m_info == OCCUPE;
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
bool TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::_estVacante(size_t position) const {
	return m_tab[position].m_info == VACANT;
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
void TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::afficher(std::ostream & p_out) const {
	p_out << "{";
	for (size_t i = 0; i < m_tab.size(); ++i) {
		if (m_tab[i].m_info == OCCUPE) {
			p_out << m_tab[i] << ",";
		}
	}
	p_out << "}";
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
int TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::_prochainPremier(int p_entier) const {
	if (p_entier % 2 == 0) {
		p_entier++;
	}
	while (!_estPremier(p_entier)) {
		p_entier += 2;
	}
	return p_entier;
}

template<typename TypeClef, typename TypeElement, class FoncteurHachage1, class FoncteurHachage2>
bool TableHachage<TypeClef, TypeElement, FoncteurHachage1, FoncteurHachage2>::_estPremier(int p_entier) const {
	if (p_entier <= 1) {
		return false;
	}
	if (p_entier == 2) { // le seul nombre premier pair
		return true;
	}
	if (p_entier % 2 == 0) { // sinon, ce n'est pas un nombre premier
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

template<typename TClef, typename TElement, class FHachage1, class FHachage2>
std::ostream& operator<<(std::ostream& p_out, const TableHachage<TClef, TElement, FHachage1, FHachage2> & p_source) {
	p_source.afficher(p_out);
	return p_out;
}

} //Fin du namespace

