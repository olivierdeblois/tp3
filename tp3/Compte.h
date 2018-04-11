/**
 * \file Compte.h
 * \brief Interface de la classe Compte
 * \author Olivier Deblois
 * \date 2018-03-27
 */

#ifndef COMPTE_H_
#define COMPTE_H_
#include "Date.h"
//#include "Client.h" // ca ca chie
#include <iostream>
#include <sstream>
#include "ContratException.h"
using namespace std;
/**
 * \class Compte
 * \brief Une classe qui permet de construire un objet compte.
 */
class Compte {
public:
	Compte(int p_noCompte, double p_tauxInteret, double p_solde, const std::string& p_description);
	int reqNoCompte () const;
	double reqTauxInteret() const;
	double reqSolde() const;
	const std::string reqDescription() const;            //const std::string& reqDescription() const; ????
	const util::Date reqDateOuverture() const;           //const util::Date& reqDateOuverture() const; ????
	void asgTauxInteret(double p_tauxInteret);
	void asgSolde(double p_solde);
	void asgDescription(const std::string& p_description);
	virtual std::string reqCompteFormate() const;
	virtual double calculerInteret() const = 0;
	virtual Compte* clone() const = 0;
	virtual ~Compte ();
protected:
	int m_noCompte; //(doit être positif)
	double m_tauxInteret;
	double m_solde;
	std::string m_description; //(doit être non vide)
	util::Date m_dateOuverture; //(date à la création du compte)
	void verifieInvariant() const;
};

#endif /* COMPTE_H_ */
