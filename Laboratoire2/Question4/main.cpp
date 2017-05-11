#include <iostream>

using namespace std;

int main() {
	int x = 15;
	const int y = 17;

	int *p = new int(5);
	const int *q = new int(10);
	int * const r = &x;
	int &s = x;
	const int & g = y;

	int *t[10];
	for (auto i = 0; i < 10; i++) {
		t[i] = new int;
		*(t[i]) = i;
	}
	for (auto i = 0; i < 10; i++) {
		delete t[i];
		t[i] = 0;
	}

	return 0;
}

