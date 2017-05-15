#ifndef DATE_H_
#define DATE_H_

namespace dateUtils {

	/** Le mois de janvier commence à l'indice 1. */
	static int NOMBRE_JOURS_PAR_MOIS[13] = { 0, 31, 28, 31, 30, 31, 30, 30, 31, 30,
			31, 30, 31 };
	static int NUMERO_MOIS_FEVRIER { 2 };

	static int NUMERO_JOURNEE_29_FEVRIER { 29 };
}


struct Date {
	int m_jour;

	/* Le numéro du mois. Conservé sous un entier de 1 à 12 inclusivement.*/
	int m_mois;

	int m_annee;

	// Si aucunes valeurs ne sont fournis, on instancie la date à "epoch";
	Date(int p_jour=1, int p_mois=1, int p_annee=1970) : m_jour{p_jour}, m_mois{p_mois}, m_annee{p_annee} {
	}



	/** Retourne une nouvelle instance de date
	 * représentant la journée de cette instance à laquelle
	 * on ajoute une journée.
	 */
	Date* ajouterUneJournee() const;

	friend std::ostream& operator<<(std::ostream& os, const Date& dt);

};

#endif /* DATE_H_ */
