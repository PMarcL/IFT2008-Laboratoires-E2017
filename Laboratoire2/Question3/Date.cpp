#include <iostream>
#include "Date.h"

using namespace dateUtils;


bool is29Fevrier(int p_jour, int p_mois) {
	return p_mois == NUMERO_MOIS_FEVRIER && p_jour == NUMERO_JOURNEE_29_FEVRIER;
}

bool isAnneeBixestile(int annee)  {
	return (annee % 4 == 0 && !(annee % 100 == 0 && annee % 400 != 0));
}

Date* Date::ajouterUneJournee() const {
	Date* ptrDate = new Date { };
	ptrDate->m_jour = m_jour + 1;
	ptrDate->m_mois = m_mois;
	ptrDate->m_annee = m_annee;

	if (ptrDate->m_jour > NOMBRE_JOURS_PAR_MOIS[ptrDate->m_mois]) {
		if (!(is29Fevrier(ptrDate->m_jour, ptrDate->m_mois)
				&& isAnneeBixestile(ptrDate->m_annee))) {
			ptrDate->m_jour = 1;
			ptrDate->m_mois += 1;
		}

	}

	if (ptrDate->m_mois > 12) {
		ptrDate->m_mois = 1;
		ptrDate->m_annee = m_annee + 1;
	}

	return ptrDate;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
	os << "Date[jour= " << date.m_jour << ", mois= " << date.m_mois << ", année= "
			<< date.m_annee << "]" << std::endl;

	return os;
}

