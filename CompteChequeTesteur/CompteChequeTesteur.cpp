/**
 * \file CompteChequeTesteur.cpp
 * \brief
 * \author etudiant
 * \date 2018-04-06
 */

#include <gtest/gtest.h>
#include "Cheque.h"

/**
 * \test Test du constructeur
 * 		Cas valide: Creation d'un objet Cheque et verification de l'assignation de tous les attributs
 * 		Cas invalides:
 * 			nobre de transactions > 0
 * 			relation d'ordre taux interet minimum et taux interet non respectee
 * 		Constructeur avec parametres par defaut
 */
TEST(Cheque, constructeurAvecParametresValides){
	Cheque monCheque(1234, 1.1, 1000, 22, 0.2, "mon cheque");
	ASSERT_EQ(1234, monCheque.reqNoCompte());
	ASSERT_EQ(1.1, monCheque.reqTauxInteret());
	ASSERT_EQ(1000, monCheque.reqSolde());
	ASSERT_EQ(22, monCheque.reqNombreTransactions());
	ASSERT_EQ(0.2, monCheque.reqTauxInteretMinimum());
	ASSERT_EQ("mon cheque", monCheque.reqDescription());
}
TEST(Cheque, constructeurAvecParametresParDefaut){
	Cheque monCheque(1234, 1.1, 1000, 22);
	ASSERT_EQ("Cheque", monCheque.reqDescription());
	ASSERT_EQ(0.1, monCheque.reqTauxInteretMinimum());
}
/**
 * cas invalide
 */
TEST(Compte, ConstructeurAvecNombreDeTransactionSNonValide){    // test le nombre de transaction > 40
	ASSERT_THROW(Cheque monCheque(1234, 1.1, 1000, 44, 0.2, "mon cheque"), PreconditionException);
}


/**
 * cas invalide
 */
TEST(Compte, ConstructeurAvecTauxInteretMinimumNonValides){    // test le taux d'interet minimum > Taux d'interet
	ASSERT_THROW(Cheque monCheque(1234, 1.1, 1000, 22, 2.0, "mon cheque"), PreconditionException);
}

/**
 * \brief Creation d'une fixture a utiliser pour les methodes public de la class de test
 */

class monCheque: public ::testing::Test{
public:
	monCheque():
		cheque(1234, 1.1, -1000, 22, 0.2, "mon cheque")
	{}
	Cheque cheque;
};

TEST_F(monCheque, reqNombreTransactions){
	ASSERT_EQ(22, cheque.reqNombreTransactions());
}

TEST_F(monCheque, reqTauxInteretMinimum){
	ASSERT_EQ(0.2, cheque.reqTauxInteretMinimum());
}

/**
 * cas invalide
 */
TEST_F(monCheque, asgNombreTransactions){
	cheque.asgNombreTransactions(33);
	ASSERT_EQ(33, cheque.reqNombreTransactions());
}

/**
 * cas invalide
 */
TEST_F(monCheque, asgNombreTrasactionsInvalide){
	ASSERT_THROW(cheque.asgNombreTransactions(44), PreconditionException);
}

TEST_F(monCheque, calculerInteret0a10transactions){
	cheque.asgNombreTransactions(1);
	ASSERT_EQ(cheque.reqSolde()*cheque.reqTauxInteretMinimum()*-0.01, cheque.calculerInteret());
}

TEST_F(monCheque, calculerInteret11a25transactions){
	cheque.asgNombreTransactions(11);
	ASSERT_EQ(cheque.reqSolde()*cheque.reqTauxInteret()*-0.01*0.4, cheque.calculerInteret());
}

TEST_F(monCheque, calculerInteret26a35transactions){
	cheque.asgNombreTransactions(26);
	ASSERT_EQ(cheque.reqSolde()*cheque.reqTauxInteret()*-0.01*0.8, cheque.calculerInteret());
}

TEST_F(monCheque, calculerInteret36a40transactions){
	cheque.asgNombreTransactions(40);
	ASSERT_EQ(cheque.reqSolde()*cheque.reqTauxInteret()*-0.01, cheque.calculerInteret());
}

TEST_F(monCheque, reqCompteFormate){
	double a = cheque.calculerInteret();
	stringstream ss;
	ss << a;
	string str = ss.str();
	ASSERT_EQ("Compte Cheque\nnumero: 1234\nDescription: mon cheque\nDate d'ouverture: "+ cheque.reqDateOuverture().reqDateFormatee() +"\nTaux d'interet: 1.1\nSolde: -1000$\nnombre de transactions: 22\nTaux d'interet minimum: 0.2\nInteret: " + str + "$\n" , cheque.reqCompteFormate());
}


