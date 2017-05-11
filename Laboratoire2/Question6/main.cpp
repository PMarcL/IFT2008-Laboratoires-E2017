#include <iostream>

using namespace std;

int main() {
	// Dimensions 2 par 3 par 4
	// numéro 3.
	int **t1[2];
	for (auto i = 0; i < 2; i++) {
		t1[i] = new int*[3];
		for (auto j = 0; j < 3; j++) {
			t1[i][j] = new int[4];
		}
	}
	for (auto i = 0; i < 2; i++) {
		for (auto j = 0; j < 3; j++) {
			delete[] t1[i][j];
		}
		delete[] t1[i];
	}

	// numéro 4.
	int ***t2;
	t2 = new int **[2];
	for (auto i = 0; i < 2; i++) {
		t2[i] = new int *[3];
		for (auto j = 0; j < 3; j++) {
			t2[i][j] = new int[4];
		}
	}
	for (auto i = 0; i < 2; i++) {
		for (auto j = 0; j < 3; j++) {
			delete[] t2[i][j];
		}
		delete[] t2[i];
	}
	delete[] t2;

	// numéro 5.
	int (*t3)[3][4];
	t3 = new int[2][3][4];
	delete[] t3;

	// numéro 6.
	int (**t4)[4];
	t4 = new (int (*[2])[4]);
	for (auto i = 0; i < 2; i++) {
		t4[i] = new int[3][4];
	}
	for (auto i = 0; i < 2; i++) {
		delete[] t4[i];
	}
	delete[] t4;

	// numéro 8.
	int *(*t5)[3];
	t5 = new int *[2][3];
	for (auto i = 0; i < 2; i++) {
		for (auto j = 0; j < 3; j++) {
			t5[i][j] = new int[4];
		}
	}
	for (auto i = 0; i < 2; i++) {
		for (auto j = 0; j < 3; j++) {
			delete[] t5[i][j];
		}
	}
	delete[] t5;

	cout << "Pas de problèmes!" << endl;
}
