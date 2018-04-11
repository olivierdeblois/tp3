/**
 * \file Cheque.cpp
 * \brief Implementation de la classe cheque derivee de la classe compte
 * \author Olivier Deblois
 * \date 2018-03-27
 */

#include "Cheque.h"

/**
 * \brief Constructeur avec parametres pour la classe Cheque
 * \param[in] p_noCompte Le numero de compte
 * \param[in] p_tauxInteret Le taux d'interet du compte
 * \param[in] p_solde Le solde du compte
 * \param[in] p_nombreTransactions Le nombre de transactions du compte
 * \param[in] p_tauxInteretMinimum Le taux d'interet minimum du compte
 * \param[in] p_description La description du compte
 * \return Un objet Compte Cheque
 */

Cheque::Cheque(int p_noCompte, double p_tauxInteret, double p_solde, int p_nombreTransactions,
		double p_tauxInteretMinimum, const std::string& p_description): Compte(p_noCompte, p_tauxInteret, p_solde, p_description),
		 m_nombreTransactions(p_nombreTransactions), m_tauxInteretMinimum(p_tauxInteretMinimum) {

	PRECONDITION( p_nombreTransactions <= 40 && p_tauxInteretMinimum <= p_tauxInteret);
	POSTCONDITION(m_nombreTransactions == p_nombreTransactions && m_tauxInteretMinimum == p_tauxInteretMinimum);
	INVARIANTS();
}

/**
 * \brief un destructeur pour l'objet Cheque
 */


Cheque::~Cheque() {
}

/**
 * \brief Acceseur pour le taux d'interet mininum du compte cheque
 * \return m_tauxInteretMinimum, le taux d'interet minimum de l'objet
 */

double Cheque::reqTauxInteretMinimum() const {
	return m_tauxInteretMinimum;
}

/**
 * \brief Acceseur pour le nombre de transactions du compte cheque
 * \return m_nombreTransactions le nombre de transactions de l'objet
 */

int Cheque::reqNombreTransactions() const {
	return m_nombreTransactions;
}

/**
 * \brief Mutateur pour le nombre de transactions, modifie le nombre de transactions du compte cheque
 */

void Cheque::asgNombreTransactions(int p_nombreTransactions) {
	PRECONDITION(p_nombreTransactions <= 40);
	m_nombreTransactions = p_nombreTransactions;
	POSTCONDITION(m_nombreTransactions == p_nombreTransactions);
	INVARIANTS();
}

/**
 * \brief calcule les interets a payer du compte cheque
 * \return interet, les interet
 */

double Cheque::calculerInteret() const {
	double interet;
	if (Compte::reqSolde() >= 0){
		interet = 0;
	}
	else{
		if (m_nombreTransactions >= 0 && m_nombreTransactions <= 10){
			interet = m_tauxInteretMinimum * Compte::reqSolde()*-0.01;
		}
		if (m_nombreTransactions >= 11 && m_nombreTransactions <= 25){
			interet = Compte::reqTauxInteret() * 0.4 * Compte::reqSolde()*-0.01 ;
		}
		if (m_nombreTransactions >= 26 && m_nombreTransactions <= 35){
			interet = Compte::reqTauxInteret() * 0.8 * Compte::reqSolde()*-0.01;
		}
		if (m_nombreTransactions >= 36){
			interet = Compte::reqTauxInteret() * Compte::reqSolde()*-0.01 ;
		}
	}
	return interet;
}



/**
 * \brief Retourne des chaines de caractere qui contient l'information de l'objet compte cheque
 * \return des string qui contient l'information
 */

std::string Cheque::reqCompteFormate() const {
	ostringstream os;
	os << "Compte Cheque" << endl;
	os << Compte::reqCompteFormate() << endl;
	os << "nombre de transactions: " << m_nombreTransactions << endl;
	os << "Taux d'interet minimum: " <<  m_tauxInteretMinimum << endl;
	os << "Interet: " << calculerInteret() <<"$" << endl;
	return os.str();
}

/**
 * \brief Un constructeur de copie
 */

Compte* Cheque::clone() const {
	return new Cheque(*this); // Appel du constructeur copie
}

/**
 * \brief Verifie les invariants de la classe
 */

void Cheque::verifieInvariant() const {
	INVARIANT(m_nombreTransactions <= 40);
	INVARIANT(m_tauxInteretMinimum <= Compte::reqTauxInteret());
}
