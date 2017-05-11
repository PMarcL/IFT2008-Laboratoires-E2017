#include <iostream>

using namespace std;

int somme(int, int);
float somme(float, float);
int* somme(int[10], int[10]);

int main() {
	int a = 5;
	int b = 10;
	cout << "Somme d'entiers:" << endl;
	cout << "5 + 10 = " << somme(a, b) << endl;

	cout << endl;

	float x = 3.4;
	float y = 5.7;
	cout << "Somme de réels :" << endl;
	cout << "3.4 + 5.7 = " << somme(x, y) << endl;

	cout << endl;

	int t1[10];
	int t2[10];
	for (auto i = 0; i < 10; i++) {
		t1[i] = i;
		t2[i] = 2 * i;
	}

	cout << "Somme de tableaux :" << endl;
	int *resultat = somme(t1, t2);
	cout << "[ ";
	for (auto i = 0; i < 10; i++) {
		cout << *(resultat + i) << " ";
	}
	cout << "]" << endl;

	cout << endl;

	short s1 = 6;
	short s2 = 7;
	cout << "Somme de short :" << endl;
	cout << "6 + 7 = " << somme(s1, s2) << endl;

	return 0;
}

int somme(int a, int b) {
	cout << "Somme version int!" << endl;
	return a + b;
}

float somme(float a, float b) {
	cout << "Somme version float!" << endl;
	return a + b;
}

int* somme(int t1[10], int t2[10]) {
	cout << "Somme version tableaux!" << endl;
	static int resultat[10];
	for (auto i = 0; i < 10; i++) {
		resultat[i] = t1[i] + t2[i];
	}
	return resultat;
}
