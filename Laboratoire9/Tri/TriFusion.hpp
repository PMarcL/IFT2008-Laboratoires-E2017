#include <vector>

namespace labTris {

template<typename E>
void triFusionRecursif(std::vector<E> & v, size_t debut, size_t fin);

template<typename E>
void fusionner(std::vector<E> & v, size_t debut, size_t milieu, size_t fin);

template<typename E>
void triFusion(std::vector<E> & p_v) {
	triFusionRecursif(p_v, 0, p_v.size() - 1);
}

template<typename E>
void triFusionRecursif(std::vector<E> & v, size_t debut, size_t fin) {
	if (debut >= fin) {
		return;
	}

	size_t milieu = (debut + fin) / 2;

	triFusionRecursif(v, debut, milieu);
	triFusionRecursif(v, milieu + 1, fin);
	fusionner(v, debut, milieu, fin);
}

template<typename E>
void fusionner(std::vector<E> & v, size_t debut, size_t milieu, size_t fin) {
	std::vector<E> temp;
	size_t a = debut;
	size_t b = milieu + 1;

	while (a <= milieu && b <= fin) {
		if (v[a] < v[b]) {
			temp.push_back(v[a]);
			a++;
		} else {
			temp.push_back(v[b]);
			b++;
		}
	}

	while (a <= milieu) {
		temp.push_back(v[a]);
		a++;
	}

	while (b <= fin) {
		temp.push_back(v[b]);
		b++;
	}

	for (size_t i = 0; i < temp.size(); i++) {
		v[debut + i] = temp[i];
	}
}

} // Fin namespace
