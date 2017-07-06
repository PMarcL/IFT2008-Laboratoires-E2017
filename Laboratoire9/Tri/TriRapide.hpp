#include <vector>

namespace labTris {

template<typename E>
void triRapideRecursif(std::vector<E> & v, int debut, int fin);

template<typename E>
int trouverPivot(std::vector<E> & v, int debut, int fin);

template<typename E>
void triRapide(std::vector<E> & p_v) {
	triRapideRecursif(p_v, 0, p_v.size() - 1);
}

template<typename E>
void triRapideRecursif(std::vector<E> & v, int debut, int fin) {
	if (debut >= fin) {
		return;
	}

	auto positionPivot = trouverPivot(v, debut, fin);
	triRapideRecursif(v, debut, positionPivot - 1);
	triRapideRecursif(v, positionPivot + 1, fin);
}

template<typename E>
int trouverPivot(std::vector<E> & v, int debut, int fin) {
	E pivot = v[debut];

	size_t d = debut + 1;
	size_t f = fin;

	while (d < f) {
		while (v[d] <= pivot && d < fin) {
			d++;
		}
		while (v[f] > pivot && f > debut) {
			f--;
		}

		if (d < f && v[d] > pivot && v[f] <= pivot) {
			std::swap(v[d], v[f]);
		}
	}

	if (v[d] > pivot) {
		d--;
	}
	v[debut] = v[d];
	v[d] = pivot;
	return d;
}

} // Fin namespace
