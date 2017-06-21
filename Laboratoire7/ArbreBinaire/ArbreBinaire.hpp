#include <vector>
#include "ContratException.h"


namespace labParcoursArbre {

// À compléter ...

template<typename E>
Arbre<E>::Arbre(const std::vector<E> & p_visiteSymetrique, const std::vector<E>& p_visitePere) {
	m_racine = _auxPereSym(p_visiteSymetrique.begin(), p_visiteSymetrique.end(), p_visitePere.begin(), p_visitePere.end());
}


template<typename E>
typename Arbre<E>::Noeud*
Arbre<E>::_auxPereSym(constVecItr& p_debutS, constVecItr& p_finS, constVecItr& p_debutP, constVecItr& p_finP) {

	PRECONDITION(std::distance(p_debutS, p_finS) == std::distance(p_debutP, p_finP));

	// Condition d'arret
	if (p_debutS == p_finS)
		return NULL;

	// Le premier element de tabP est la racine de l'arbre
	Noeud* nouveau = new Noeud(*p_debutP);

	// Recherche de la racine de l'arbre dans tabS. Apres cette boucle:
	// - iterS pointe sur la racine de l'arbre dans tabS;
	// - iterP pointe sur la racine du fils droit dans tabP;
	vecItr iterS = p_debutS;
	vecItr iterP = p_debutP + 1;
	while (*iterS != *p_debutP && iterS != p_finS) {
		++iterS;
		++iterP;
	}

	// Construction recursives des sous-arbres gauche et droit
	nouveau->m_gauche = _auxPereSym(p_debutS, iterS, p_debutP + 1, iterP);
	nouveau->m_droite = _auxPereSym(iterS + 1, p_finS, iterP, p_finP);

	return nouveau;
}

}            //Fin du namespace
