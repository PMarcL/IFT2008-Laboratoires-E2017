#include <iostream>
#include "Date.h"

using namespace dateUtils;

bool is29Fevrier(int, int);
bool isAnneeBixestile(int);
void ajusterMoisEtAnnee(Date &);

Date Date::ajouterUneJourneeDepuisUneCopie(Date date) {
	date.m_jour += 1;
	ajusterMoisEtAnnee(date);
	return date;
}

void Date::ajouterUneJourneeDepuisUneReference(Date &date) {
	date.m_jour += 1;
	ajusterMoisEtAnnee(date);
}

Date* Date::ajouterUneJourneeDepuisReferenceConstante(const Date &date) {
	Date* ptrDate = new Date { };
	ptrDate->m_jour = date.m_jour + 1;
	ptrDate->m_mois = date.m_mois;
	ptrDate->m_annee = date.m_annee;

	ajusterMoisEtAnnee(*ptrDate);
	return ptrDate;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
	os << "Date[jour= " << date.m_jour << ", mois= " << date.m_mois << ", année= " << date.m_annee << "]" << std::endl;

	return os;
}

bool is29Fevrier(int p_jour, int p_mois) {
	return p_mois == NUMERO_MOIS_FEVRIER && p_jour == NUMERO_JOURNEE_29_FEVRIER;
}

bool isAnneeBixestile(int annee) {
	return (annee % 4 == 0 && !(annee % 100 == 0 && annee % 400 != 0));
}

void ajusterMoisEtAnnee(Date &date) {
	if (date.m_jour > NOMBRE_JOURS_PAR_MOIS[date.m_mois]) {
		if (!(is29Fevrier(date.m_jour, date.m_mois) && isAnneeBixestile(date.m_annee))) {
			date.m_jour = 1;
			date.m_mois += 1;
		}
	}

	if (date.m_mois > 12) {
		date.m_mois = 1;
		date.m_annee += 1;
	}
}

