#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

struct sDate {
	// les 3 attributs de la structure qui seront mémorisée
	int m_jour;
	int m_mois;
	int m_annee;

	sDate(long p_jour, long p_mois, long p_annee) :
			m_jour(p_jour), m_mois(p_mois), m_annee(p_annee) {
	}

	void ajouteUneJournee() {
		m_jour += 1;
	}

	string reqDateEnregistree() const {
		ostringstream os;
		os << m_jour << "/" << m_mois << "/" << m_annee;
		return os.str();
	}
};

string fctRecevantLaStructure(const sDate &sd) {

	cout << "la structure est passe a la fonction par reference" << endl;
	string date = sd.reqDateEnregistree();
	return date;
}

string fctRecevantLaStructure(const sDate *sd) {

	cout << "la structure est passe a la fonction par pointeur" << endl;
	string date = sd->reqDateEnregistree();
	return date;
}

int main() {

	sDate sdate(20, 01, 2017);

	sDate *ptr(0);
	ptr = &sdate;

	cout << fctRecevantLaStructure(sdate) << endl;
	ptr->ajouteUneJournee();
	cout << fctRecevantLaStructure(ptr) << endl;

	return 0;
}

