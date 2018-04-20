/**
 * \file Epargne.h
 * \brief Interface de la classe Epargne derivee de la classe compte
 * \author Olivier Deblois
 * \date 2018-03-27
 */

#ifndef EPARGNE_H_
#define EPARGNE_H_
#include "Compte.h"  // herite de la classe compte

using namespace std;

/**
 * \class Epargne
 * \brief  une classe derivee de la classe Compte
 */
class Epargne: public Compte {
public:
	Epargne(int p_noCompte, double p_tauxInteret, double p_solde, const std::string& p_description="Epargne");
	virtual double calculerInteret() const;
	virtual std::string reqCompteFormate() const;
	virtual Compte* clone() const;
	virtual ~Epargne ();
private:
	void verifieInvariant() const;
};

#endif /* EPARGNE_H_ */
