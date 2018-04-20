/**
 * \file Epargne.cpp
 * \brief Implementation de la classe Epargne derivee de la classe compte
 * \author Olivier Deblois
 * \date 2018-03-27
 */

#include "Epargne.h"


/**
 * \brief Constructeur avec parametres pour la classe Epargne
 * \param[in] p_noCompte Le numero de compte
 * \param[in] p_tauxInteret Le taux d'interet du compte
 * \param[in] p_solde Le solde du compte
 * \param[in] p_description La description du compte
 * \return Un objet Compte Epargne
 */

Epargne::Epargne(int p_noCompte, double p_tauxInteret, double p_solde,
		const std::string& p_description): Compte(p_noCompte, p_tauxInteret, p_solde, p_description) {

	PRECONDITION( p_tauxInteret >= 0.1 && p_tauxInteret <= 3.5 );

}

/**
 * \brief calcule les interets a payer du compte Epargne
 * \return un double, les interet
 */

double Epargne::calculerInteret() const {

	return Compte::reqTauxInteret()*Compte::reqSolde()*0.01 ;
}

/**
 * \brief Retourne des chaines de caractere qui contient l'information de l'objet compte Epargne
 * \return des string qui contient l'information
 */

std::string Epargne::reqCompteFormate() const {
	ostringstream os;
	os << "Compte Epargne" << endl;
	os << Compte::reqCompteFormate() << endl;
	os << "Interet: " << Compte::reqTauxInteret()*Compte::reqSolde() * 0.01 << "$"<< endl;
	return os.str();
}

/**
 * \brief Un constructeur de copie
 */

Compte* Epargne::clone() const {
	return new Epargne(*this); // Appel du constructeur copie
}

/**
 * \brief un destructeur pour l'objet Epargne
 */

Epargne::~Epargne() {
}

/**
 * \brief Verifie les invariants de la classe
 */

void Epargne::verifieInvariant() const {
	//INVARIANT( Compte::reqTauxInteret() >= 0.1 && Compte::reqTauxInteret() <= 3.5 );
}
