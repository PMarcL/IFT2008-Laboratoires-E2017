/**
 *
 * Les gaps choisis sont 2^k - 1 :
 * [1, 3, 7, 15, 31, 63, ... , 2^floor(log(N)/log(2)) - 1]
 *
 * Ces gaps donnent une complexité de O(N^1.5).
 *
 * REMARQUE
 *
 * Lorsque gap = 1, le tri shell devient exactement le tri insertion!
 */
#include <vector>
#include <cmath>

namespace labTris {

template<typename E>
void triShell(std::vector<E> & p_v) {
	size_t j;
	E x;
	int k = std::floor(std::log2((double) p_v.size()));
	for (unsigned int saut = std::pow(2, k) - 1; k > 0; k--, saut = std::pow(2, k) - 1) {
		for (size_t i = 0; i < p_v.size(); i += saut) {
			j = i;
			x = p_v[i];
			while (j >= saut && x < p_v[j - saut]) {
				p_v[j] = p_v[j - saut];
				j -= saut;
			}
			p_v[j] = x;
		}
	}
}

} // Fin namespace
