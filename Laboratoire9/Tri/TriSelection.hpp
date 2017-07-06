#include <vector>

namespace labTris {

template<typename E>
void triSelection(std::vector<E> & p_v) {
	for (size_t i = 0; i < p_v.size(); i++) {
		auto min = i;
		for (size_t j = i + 1; j < p_v.size(); j++) {
			if (p_v[j] < p_v[min]) {
				min = j;
			}
		}
		std::swap(p_v[i], p_v[min]);
	}
}

} // Fin namespace

