/**
 * \file Client.h
 * \brief interface de la classe Client
 * \author Olivier Deblois
 * \date 2018-02-28
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#include"validationFormat.h"
#include "ContratException.h"
#include "Date.h"
#include "Cheque.h"
#include "Epargne.h"
#include <iostream>
#include <vector>

namespace banque{
/**
 * \class Client
 * \brief Une classe qui permet de construire un objet client.
 */
class Client {
public:
	Client(int p_noFolio, const std::string& p_nom, const std::string& p_prenom, const std::string& p_telephone, const util::Date& p_dateDeNaissance);
	Client(const Client& other);
	int reqNoFolio() const;
	const std::string reqNom() const;
	const std::string reqPrenom() const;
	const std::string reqTelephone() const;
	std::string reqClientFormate() const;
	const util::Date reqDateDeNaissance() const;
	void asgTelephone(const std::string& p_telephone);
	bool operator == (const Client& p_client) const;
	bool operator < (const Client& p_client)const;
	void ajouterCompte (const Compte& p_nouveauCompte);
	std::string reqReleves() const;
	virtual ~Client ();

private:
	int m_noFolio;
	std::string m_nom;
	std::string m_prenom;
	std::string m_telephone;
	util::Date m_dateDeNaissance;
	std::vector<Compte*> m_vComptes;
	void verifieInvariant() const;
	bool compteEstDejaPresent(int p_noCompte) const;
};


}  /* namespace banque */
#endif /* CLIENT_H_ */
