/**
 * \file Compte.cpp
 * \brief Implementation de la classe Compte
 * \author Olivier Deblois
 * \date 2018-03-27
 */

#include "Compte.h"

/**
 * \brief Constructeur avec parametres pour la classe Compte
 * \param[in] p_noCompte Le numero de compte
 * \param[in] p_tauxInteret Le taux d'interet du compte
 * \param[in] p_solde Le solde du compte
 * \param[in] p_description La description du compte
 * \return Un objet Compte
 */

Compte::Compte(int p_noCompte, double p_tauxInteret, double p_solde,
		const std::string& p_description): m_noCompte (p_noCompte), m_tauxInteret(p_tauxInteret), m_solde(p_solde),
				m_description(p_description), m_dateOuverture(util::Date())
{
	PRECONDITION( p_noCompte >= 0 && !p_description.empty() );
	POSTCONDITION( m_noCompte == p_noCompte && m_description == p_description && m_dateOuverture == util::Date());
	INVARIANTS();
}



/**
 * \brief un destructeur pour l'objet compte
 */

Compte::~Compte(){}

/**
 * \brief Acceseur pour le numero de compte
 * \return m_noCompte le numero de compte de l'objet
 */

int Compte::reqNoCompte() const {
	return m_noCompte;
}

/**
 * \brief Acceseur pour le taux d'interet du compte
 * \return m_tauxInteret le taux d'interet de l'objet
 */

double Compte::reqTauxInteret() const {
	return m_tauxInteret;
}

/**
 * \brief Acceseur pour le solde du compte
 * \return m_solde le solde de l'objet
 */

double Compte::reqSolde() const {
	return m_solde;
}

/**
 * \brief Acceseur pour la description du compte
 * \return m_description la description de l'objet
 */

const std::string Compte::reqDescription() const {
	return m_description;
}

/**
 * \brief Acceseur pour la Date de creation
 * \return m_dateOuverture la Date de creation de l'objet
 */

const util::Date Compte::reqDateOuverture() const {
	return  m_dateOuverture;
}

/**
 * \brief Mutateur pour la taux d'interet, modifie le taux d'interet
 * \param[in] p_tauxInteret , le nouveau taux d'interet du compte
 */

void Compte::asgTauxInteret(double p_tauxInteret) {
	m_tauxInteret = p_tauxInteret;
}

/**
 * \brief Mutateur pour le solde, modifie le solde du compte
 * \param[in] p_solde, le nouveau solde du compte
 */

void Compte::asgSolde(double p_solde) {
	m_solde = p_solde;
}

/**
 * \brief Mutateur pour la description, modifie la description du compte
 * \param[in] p_description, la nouvelle description du compte
 */

void Compte::asgDescription(const std::string& p_description) {

	PRECONDITION(!p_description.empty());
	m_description = p_description;
	POSTCONDITION(m_description == p_description);
	INVARIANTS();
}

/**
 * \brief Retourne des chaines de caractere qui contient l'information de l'objet compte
 * \return des string qui contient l'information
 */

std::string Compte::reqCompteFormate() const {
	ostringstream os;
	os<<"numero: " << m_noCompte << endl;
	os<<"Description: " << m_description << endl;
	os<<"Date d'ouverture: " << m_dateOuverture.reqDateFormatee() << endl;
	os<<"Taux d'interet: " << m_tauxInteret << endl;
	os<<"Solde: " << m_solde << "$";
	return os.str();
}

/**
 * \brief Verifie les invariants de la classe
 */

void Compte::verifieInvariant() const {
	INVARIANT( m_noCompte >= 0 );
	INVARIANT(!m_description.empty());
	INVARIANT(m_dateOuverture == util::Date());
}

//double Compte::calculerInteret() const {
	//return 0;
//}
