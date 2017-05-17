#include <set>
#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
	// Classe std::set<T, Compare = less<T>, ...>
	// Ensemble ordonné sans doublons d'éléments, implémenté avec des arbres rouge et noir
	// Accès et insertion en O(log(n))
	set<int> s;
	s.insert(2);
	s.insert(5);
	s.insert(2); // doublons -> n'est pas inséré
	s.insert(1); // le set contient donc 1, 2 et 5

	for (auto element : s) {
		cout << element << " ";
	}

	cout << endl;

	// Classe std::unordered_set<T, Hash = hash<key>, ...>
	// Ensemble non ordonné sans doublons d'éléments, implémenté avec une table de hashage
	// Accès et insertion en O(1)
	unordered_set<int> us;
	us.insert(2);
	us.insert(4);
	us.insert(2); // doublons -> n'est pas inséré
	us.insert(1); // le unordered_set contient finalement 1, 2 et 4
	for (auto element : us) {
		cout << element << " ";
	}

}
