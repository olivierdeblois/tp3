/**
 * \file Client.cpp
 * \brief Implementation de la classe Client
 * \author Olivier Deblois
 * \date 2018-02-28
 */

#include "Client.h"
#include "Date.h"

using namespace std;

namespace banque{

/**
 * \brief Constructeur avec parametres
 * \param[in] p_noFolio Le numero de folio du client
 * \param[in] p_nom Le nom du client
 * \param[in] p_prenom Le prenom du client
 * \param[in] p_telephone Le numero de telephone du client
 * \return Un objet Client
 */

Client::Client(int p_noFolio, const std::string& p_nom, const std::string& p_prenom, const std::string& p_telephone, const util::Date& p_dateDeNaissance):
		 m_noFolio(p_noFolio), m_nom(p_nom), m_prenom(p_prenom), m_telephone(p_telephone), m_dateDeNaissance(p_dateDeNaissance)
{
	PRECONDITION(p_noFolio >= 1000 && p_noFolio <= 10000);
	PRECONDITION(util::validerFormatNom(p_nom) && util::validerFormatNom(p_prenom));
	PRECONDITION(util::validerTelephone(p_telephone));
	POSTCONDITION(m_noFolio == p_noFolio && m_nom == p_nom && m_prenom == p_prenom && m_telephone == p_telephone && m_dateDeNaissance == p_dateDeNaissance);
	INVARIANTS();
}

/**
 * \brief Acceseur pour le numero de folio
 * \return m_noFolio le numero de folio de l'objet
 */

int Client::reqNoFolio() const {
	return m_noFolio;
}

/**
 * \brief Acceseur pour le nom
 * \return m_nom le nom de l'objet
 */

const std::string Client::reqNom() const {
	return m_nom;
}

/**
 * \brief Acceseur pour le prenom
 * \return m_prenom le prenom de l'objet
 */

const std::string Client::reqPrenom() const {
	return m_prenom;
}

/**
 * \brief Acceseur pour le prenom
 * \return m_telephone le numero de telephone de l'objet
 */

const std::string Client::reqTelephone() const {
	return m_telephone;
}

/**
 * \brief Mutateur pour numero de telephone, modifie le numero de telephone
 */

void Client::asgTelephone(const std::string& p_telephone) {
	PRECONDITION(util::validerTelephone(p_telephone));
	m_telephone = p_telephone;
	POSTCONDITION(m_telephone == p_telephone);
	INVARIANTS();
}

/**
 * \brief Retourne des chaines de caractere qui contient l'information de l'objet client
 * \return des string qui contient l'information
 */

std::string Client::reqClientFormate() const {
	ostringstream os;
	os<<"Client numero de folio :"<< m_noFolio<<endl;
	os<<m_nom<<" "<<m_prenom<<endl;
	os<<"Date de naissance :"<<" "<< reqDateDeNaissance().reqDateFormatee()<<endl;
	os<<m_telephone<<endl;
	return os.str();

}

/**
 * \brief Retourne la comparaison entre deux objets client
 * \return un bool
 */

bool Client::operator ==(const Client& p_client) const{
	bool x;
	if (m_noFolio == p_client.m_noFolio && m_nom == p_client.m_nom
			&& m_prenom == p_client.m_prenom && m_telephone == p_client.m_telephone &&
			m_dateDeNaissance == p_client.m_dateDeNaissance) x=true;
	else x=false;
	return x;
}

/**
 * \brief Retourne une comparaison entre deux objet client
 * \return un bool
 */

bool Client::operator <(const Client& p_client) const{
	return m_noFolio < p_client.m_noFolio;
}

/**
 * \brief Acceseur pour la date de naissance
 * \return m_dateDeNaissance, la date de naissance de l'objet
 */

const util::Date Client::reqDateDeNaissance() const {
	return m_dateDeNaissance;
}

/**
 * \brief un destructeur pour l'objet Client
 */

Client::~Client() {
}

/**
 * \brief une fonction d'ajout de comptes pour l'objet Client
 */

void Client::ajouterCompte(const Compte& p_nouveauCompte) {
	m_vComptes.push_back(p_nouveauCompte.clone());
}

/**
 * \brief Retourne des chaines de caractere qui contient les releves de l'objet client
 * \return des string qui contient l'information
 */

std::string Client::reqReleves() const {
	ostringstream os;
	os << Client::reqClientFormate();
	for(unsigned int i = 0; i < m_vComptes.size(); i++ ){
		os << m_vComptes[i]->reqCompteFormate();
	}
	return os.str();
}

bool Client::compteEstDejaPresent(int p_noCompte) const {
	bool presenceDeCompte = false;
	for(unsigned int i = 0; i < m_vComptes.size(); i++ ){
		if(m_vComptes[i]->reqNoCompte() == p_noCompte){
			presenceDeCompte = true;
	}
	}
	return presenceDeCompte;

}
/**
 * \brief Verifie les invariants de la classe
 */
void Client::verifieInvariant() const
{
	INVARIANT(m_noFolio >= 1000 && m_noFolio <= 10000);
	INVARIANT(util::validerFormatNom(m_nom) && util::validerFormatNom(m_prenom));
	INVARIANT(util::validerTelephone(m_telephone));
}

}


