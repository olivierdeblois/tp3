/**
 * \file CompteTesteur.cpp
 * \brief
 * \author etudiant
 * \date 2018-03-30
 */

#include <gtest/gtest.h>

#include "Compte.h"
#include<iostream>
using namespace std;

/**
 * \test Test du constructeur
 * 		Cas valide: Creation d'un objet compte et verification de l'assignation de tous les attributs
 * 		Cas invalides:
 * 			noCompte < 0
 * 			description vide
 */


TEST(Compte, ConstructeurAvecParametresValides){ // test un format valide de compte
	Compte unCompte(1234, 3.2, 1500, "description");
	ASSERT_EQ(1234, unCompte.reqNoCompte());
	ASSERT_EQ(3.2, unCompte.reqTauxInteret());
	ASSERT_EQ(1500, unCompte.reqSolde());
	ASSERT_EQ("description", unCompte.reqDescription());
	ASSERT_EQ(util::Date(), unCompte.reqDateOuverture());

}
//Cas invalide
TEST(Compte, ConstructeurAvecNoCompteNonValides){    // test le numero de compte < que 0
	ASSERT_THROW(Compte unCompte(-1, 3.2, 1500, "description"), ContratException);
}
//Cas invalide
TEST(Compte, ConstructeurAvecDescriptionNonValides){  // test la description vide
	ASSERT_THROW(Compte unCompte(1234, 3.2, 1500, ""), ContratException);
}

/**
 * \brief Creation d'une fixture a utiliser pour les methodes public de la class de test
 */

class unCompte: public ::testing::Test{
public:
	unCompte():
		compte(4321, 2.6, 2000, "uneDescription")
	{}
	Compte compte;
};

/**
 * \brief un test pour le numero de compte
 * \return unCompte.reqNoCompte, le numero du compte
 */

TEST_F(unCompte, reqNoCompte){
	ASSERT_EQ(4321, compte.reqNoCompte());
}

/**
 * \brief un test pour le taux d'interet du compte
 * \return unCompte.reqTauxInteret, le taux d'interet
 */

TEST_F(unCompte, reqTauxInteret){
	ASSERT_EQ(2.6, compte.reqTauxInteret());
}

/**
 * \brief un test pour le solde du compte
 * \return unCompte.reqSolde, le solde
 */

TEST_F(unCompte, reqSolde){
	ASSERT_EQ(2000, compte.reqSolde());
}

/**
 * \brief un test pour la description du compte
 * \return unCompte.reqDescription, la description
 */

TEST_F(unCompte, reqDescription){
	ASSERT_EQ("uneDescription", compte.reqDescription());
}

/**
 * \brief un test pour la date d'ouverture du compte
 * \return unCompte.reqDateOuverture, la date d'ouverture
 */

TEST_F(unCompte, reqDateOuverture){
	ASSERT_EQ(util::Date(), compte.reqDateOuverture());
}

/**
 *  \brief tests pour les asg ---- asg valide
 */

TEST_F(unCompte, asgTauxInteretValide){
	compte.asgTauxInteret(2.2);
	ASSERT_EQ(2.2, compte.reqTauxInteret());
}

TEST_F(unCompte, asgSoldeValide){
	compte.asgSolde(55);
	ASSERT_EQ(55, compte.reqSolde());
}

TEST_F(unCompte, asgDescriptionValide){
	compte.asgDescription("nouvelleDescription");
	ASSERT_EQ("nouvelleDescription", compte.reqDescription());
}

/**
 *  \brief tests pour les asg ---- asg non valide
 */
TEST_F(unCompte, asgDescriptionNonValide){

	ASSERT_THROW(compte.asgDescription(""), PreconditionException );
}

/**
 * \brief test reqformate
 */

TEST_F(unCompte, reqCompteFormate){

	ASSERT_EQ("numero :4321\nDescriptionuneDescription\nDate d'ouverture" + compte.reqDateOuverture().reqDateFormatee() + "\nTaux d'interet2.6\nSolde2000\n" , compte.reqCompteFormate());
}
