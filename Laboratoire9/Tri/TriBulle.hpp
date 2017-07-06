#include <vector>

namespace labTris {

template<typename E>
void triBulle(std::vector<E> & p_v) {
	for (size_t i = 0; i < p_v.size(); i++) {
		for (size_t j = 0; j < p_v.size() - i - 1; j++) {
			if (p_v[j] > p_v[j + 1]) {
				std::swap(p_v[j], p_v[j + 1]);
			}
		}
	}
}

} // Fin namespace
