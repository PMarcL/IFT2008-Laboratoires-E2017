#include <vector>

namespace labTris {

template<typename E>
void triInsertion(std::vector<E> & p_v) {
	for (size_t i = 1; i < p_v.size(); i++) {
		auto element = i;
		for (size_t j = i; j > 0; j--) {
			if (p_v[j - 1] > p_v[element]) {
				std::swap(p_v[element], p_v[j - 1]);
				element--;
			} else {
				break;
			}
		}
	}
}

} // Fin namespace
