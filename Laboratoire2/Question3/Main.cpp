#include <iostream>
#include "Date.h"

int main() {

	// Cas normal utilisant l'appel par référence constante
	std::cout << "***** APPEL PAR RÉFÉRENCE CONSTANTE *****" << std::endl;
	const Date dateConstante{ 14, 5, 2017 };
	Date* ptrDemain = Date::ajouterUneJourneeDepuisReferenceConstante(dateConstante);
	std::cout << "\t" << "La date constante n'a pas changé : " << dateConstante;
	std::cout << "\t" << "La date de demain : " << *ptrDemain;

	// Cas avec changement de mois en utilisant l'appel par référence.
	std::cout << "***** APPEL PAR RÉFÉRENCE *****" << std::endl;
	Date dateParReference{ 31, 5, 2017 };
	std::cout << "\t" << "Avant l'appel : " << dateParReference;
	Date::ajouterUneJourneeDepuisUneReference(dateParReference);
	std::cout << "\t" << "Après l'appel : " << dateParReference;

	// Cas avec changement d'année en utilisant l'appel par valeur.
	std::cout << "***** APPEL PAR VALEUR *****" << std::endl;
	Date dateParValeur { 31, 12, 2017 };
	std::cout << "\t" << "Avant l'appel : " << dateParValeur;
	Date demain = Date::ajouterUneJourneeDepuisUneCopie(dateParValeur);
	std::cout << "\t" << "La date originale n'a pas été changé :" << dateParValeur;
	std::cout << "\t" << demain;

	return 0;
}
