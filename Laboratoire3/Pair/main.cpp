#include <utility>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
	// Classe générique std::pair<T,G>
	// Insertion et accès en O(1)
	// Utile lorsque combinée avec un autre conteneur pour avoir une structure de type clé, valeur.
	pair<int, string> unePaire = make_pair(5, "hello");
	cout << "unePaire : < " << unePaire.first << ", " << unePaire.second << " >" << endl;
	return 0;
}

