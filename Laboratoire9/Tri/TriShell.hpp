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

}

} // Fin namespace
