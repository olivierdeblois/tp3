/**
 * \file CompteEpargneTesteur.cpp
 * \brief
 * \author etudiant
 * \date 2018-04-09
 */


#include <gtest/gtest.h>
#include "Epargne.h"

/**
 * \test Test du constructeur
 * 		Cas valide: Creation d'un objet Cheque et verification de l'assignation de tous les attributs
 * 		Cas invalides:
 * 			taux interet < 0.1
 * 			taux interet > 3.5
 */
TEST(Epargne, constructeurAvecParametresValides){
	Epargne epargne_test(1234, 1.1, 1000, "description");
	ASSERT_EQ(1234, epargne_test.reqNoCompte());
	ASSERT_EQ(1.1, epargne_test.reqTauxInteret());
	ASSERT_EQ(1000, epargne_test.reqSolde());
	ASSERT_EQ("description", epargne_test.reqDescription());
}
TEST(Eparnge, constructeurAvecParametresParDefaut){
	Epargne epargne_test(1234, 1.1, 1000);
	ASSERT_EQ("Epargne", epargne_test.reqDescription());

}

//Cas invalide
TEST(Epargne, ConstructeurAvecTauxInteretNonValide){
	ASSERT_THROW(Epargne epargne_test(1234, 0.0, 1000, "description"), PreconditionException);
	ASSERT_THROW(Epargne epargne_test(1234, 4.0, 1000, "description"), PreconditionException);
}

/**
 * \brief Creation d'une fixture a utiliser pour les methodes public de la class de test
 */

class unCompteEpargne: public ::testing::Test{
public:
	unCompteEpargne():
		epargne_test(1234, 1.1, 1000, "description")
	{}
	Epargne epargne_test;
};

TEST_F(unCompteEpargne, calculerInteret){
	ASSERT_EQ(epargne_test.reqSolde()*epargne_test.reqTauxInteret()*0.01, epargne_test.calculerInteret());
}

TEST_F(unCompteEpargne, reqCompteFormate){
	double a = epargne_test.calculerInteret();
	stringstream ss;
	ss << a;
	string str = ss.str();
	ASSERT_EQ("Compte Epargne\nnumero: 1234\nDescription: description\nDate d'ouverture: "+ epargne_test.reqDateOuverture().reqDateFormatee() +"\nTaux d'interet: 1.1\nSolde: 1000$\nInteret: " + str + "$\n" , epargne_test.reqCompteFormate());
}




