#include <list>
#include <vector>
#include <iostream>
#include <chrono>
#include <random>
#include <string>

using namespace std;
using namespace std::chrono;

const size_t TAILLE_COMPARAISON = 10000;

int main() {
	// Classe générique std::list<T>
	// Insertion (début ou fin de la list) en O(1)
	// Accès en O(n) en pire cas
	cout << "Classe std::list<T>:" << endl;
	list<int> uneListe( { 1, 2, 3, 4, 5 });
	uneListe.push_back(6);

	std::list<int>::const_iterator it = uneListe.begin(); // un peu long comme déclaration...
	auto itFin = uneListe.end(); // beaucoup mieux en utilisant l'inférence de type

	cout << "Utilistation des itérateur pour traverser la liste:" << endl;
	for (; it != itFin; ++it) {
		cout << *it << " ";
	}

	cout << endl;

	cout << "Utilisation d'une boucle de type \"for in\" pour traverser la liste:" << endl;
	for (auto element : uneListe) {
		cout << element << " ";
	}

	cout << endl << endl;

	// Classe générique std::vector<T>
	// Tableau de type T contiguë en mémoire
	// Insertion en O(n) au début et en O(1) à la fin (en analyse amortie), réallocation de mémoire possible
	// Accès en O(1)
	cout << "Classe std::vector<T>:" << endl;
	vector<int> unVector(5, 42); // initialise le vecteur avec un tableau contenant 5 fois la valeur 42
	unVector.push_back(43);

	cout << "Utilisation d'une boucle for classique pour accéder à tous les éléments du vector:" << endl;
	for (size_t i = 0; i < unVector.size(); i++) {
		cout << unVector[i] << " ";
	}

	cout << endl << endl;

	cout << "Comparaison des deux classes pour l'insertion de valeurs au début:" << endl;

	cout << "Calcul du temps d'exécution pour 100000 insertions dans un vector:" << endl;
	vector<int> v(TAILLE_COMPARAISON);
	auto debut = high_resolution_clock::now();
	for (auto i = 0; i < 100000; i++) {
		v.insert(v.begin(), 0);
	}
	auto fin = high_resolution_clock::now();
	cout << "Résultat : " << duration_cast < milliseconds > (fin - debut).count() << "ms" << endl;

	cout << "Calcul du temps d'exécution pour 100000 insertions dans une liste:" << endl;
	list<int> l(TAILLE_COMPARAISON);
	debut = high_resolution_clock::now();
	for (auto i = 0; i < 100000; i++) {
		l.insert(l.begin(), 0);
	}
	fin = high_resolution_clock::now();
	cout << "Résultat : " << duration_cast < milliseconds > (fin - debut).count() << "ms" << endl;

}
