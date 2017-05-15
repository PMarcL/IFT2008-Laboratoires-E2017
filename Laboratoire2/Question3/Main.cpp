#include <iostream>
#include "Date.h"

int main() {

	// Cas normal
	Date *ptrDate = new Date { 14, 5, 2017 };
	std::cout << *ptrDate;
	Date *ptrDemain = ptrDate->ajouterUneJournee();
	std::cout << *ptrDemain;
	delete ptrDate;
	delete ptrDemain;
	ptrDate = 0;
	ptrDemain = 0;

	// Cas avec changement de mois.
	ptrDate = new Date { 31, 5, 2017 };
	std::cout << *ptrDate;
	ptrDemain = ptrDate->ajouterUneJournee();
	std::cout << *ptrDemain;
	delete ptrDate;
	delete ptrDemain;
	ptrDate = 0;
	ptrDemain = 0;

	// Cas avec changement d'année.
	ptrDate = new Date { 31, 12, 2017 };
	std::cout << *ptrDate;
	ptrDemain = ptrDate->ajouterUneJournee();
	std::cout << *ptrDemain;
	delete ptrDate;
	delete ptrDemain;
	ptrDate = 0;
	ptrDemain = 0;

	// Cas 28 février d'une année bixestile.
	ptrDate = new Date { 28, 2, 1976 };
	std::cout << *ptrDate;
	ptrDemain = ptrDate->ajouterUneJournee();
	std::cout << *ptrDemain;
	delete ptrDate;
	delete ptrDemain;
	ptrDate = 0;
	ptrDemain = 0;

	// Cas 28 février d'une année non bixestile.
	ptrDate = new Date { 28, 2, 1977 };
	std::cout << *ptrDate;
	ptrDemain = ptrDate->ajouterUneJournee();
	std::cout << *ptrDemain;
	delete ptrDate;
	delete ptrDemain;
	ptrDate = 0;
	ptrDemain = 0;

	return 0;
}
