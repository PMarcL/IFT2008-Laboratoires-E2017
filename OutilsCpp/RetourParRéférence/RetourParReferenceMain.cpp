#include <iostream>
#include <vector>

using namespace std;

int tableau[20]; // variable globale -> à éviter!

// Retourne une référence à un entier
int& nIeme(int i) {
	return tableau[i];
}

// Retourne une référence constante
const int& reqB() {
	static int b = 42;
	//...
	return b;
}

int main() {
	// Qu'est-ce qui se passe ici?
	nIeme(0) = 123;
	nIeme(1) = 456;
	cout << "tableau[0] = " << tableau[0] << endl;
	cout << "++nIeme(1) = " << ++nIeme(1) << endl;

	cout << endl;
	int y;
	int x = reqB();
	cout << "Valeur retournée par reqB : " << x << endl;
	// Est-ce que la prochaine ligne compile? Pourquoi?
	// reqB() = 5;

	return 0;
}

// Trouvez l'erreur:
const int& trouverMaximum(const vector<int> &vecteur) {
	auto valeurMax = vecteur[0];

	for (auto valeur : vecteur) {
		if (valeur > valeurMax) {
			valeurMax = valeur;
		}
	}
	return valeurMax;
}
