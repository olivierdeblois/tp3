/**
 * \file Cheque.h
 * \brief Interface de la classe cheque derivee de la classe compte
 * \author Olivier Deblois
 * \date 2018-03-27
 */

#ifndef CHEQUE_H_
#define CHEQUE_H_
#include "Compte.h"   // herite de la classe compte
/**
 * \class Cheque
 * \brief une classe derivee de la classe Compte
 */
class Cheque: public Compte {
public:
	Cheque(int p_noCompte, double p_tauxInteret, double p_solde,
			int p_nombreTransactions, double p_tauxInteretMinimum = 0.1, const std::string& p_description = "Cheque");
	double reqTauxInteretMinimum() const;
	int reqNombreTransactions() const;
	void asgNombreTransactions (int p_nombreTransactions);
	virtual double calculerInteret() const;
	virtual std::string reqCompteFormate() const;
	virtual Compte* clone() const;
	virtual ~Cheque ();

private:
	int m_nombreTransactions;
	double m_tauxInteretMinimum;
	void verifieInvariant() const;
};

#endif /* CHEQUE_H_ */
