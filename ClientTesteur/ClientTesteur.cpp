/**
 * \file ClientTesteur.cpp
 * \brief
 * \author etudiant
 * \date 2018-04-09
 */

#include <gtest/gtest.h>
#include "Client.h"
using namespace banque;
/**
 * \test Test du constructeur
 */
TEST(Client, constructeurAvecParametresValides){
	Client client(1234, "Deblois", "Olivier", "418 999-9999", util::Date(04,05,1992));
	ASSERT_EQ(1234, client.reqNoFolio());
	ASSERT_EQ("Olivier", client.reqPrenom());
	ASSERT_EQ("Deblois", client.reqNom());
	ASSERT_EQ("418 999-9999", client.reqTelephone());
	ASSERT_EQ("Lundi le 04 mai 1992", client.reqDateDeNaissance().reqDateFormatee());
}
TEST(CLient, constructeurAvecParametresNonValides){
	ASSERT_THROW(Client client(100, "Deblois", "Olivier", "418 999-9999", util::Date(04,05,1992)), PreconditionException);
	ASSERT_THROW(Client client(1234, "Deblois4545", "Olivier", "418 999-9999", util::Date(04,05,1992)), PreconditionException);
	ASSERT_THROW(Client client(1234, "Deblois", "Olivie34r", "418 999-9999", util::Date(04,05,1992)), PreconditionException);
	ASSERT_THROW(Client client(1234, "", "", "418 999-9999", util::Date(04,05,1992)), PreconditionException);
	ASSERT_THROW(Client client(1234, "Deblois", "Olivier", "418999-9999", util::Date(04,05,1992)), PreconditionException);
}

/**
 * \brief Creation d'une fixture a utiliser pour les methodes public de la class de test
 */

class unClient: public ::testing::Test{
public:
	unClient():
		client(1234, "Deblois", "Olivier", "418 999-9999", util::Date(04,05,1992))
	{}
	Client client;
};


TEST_F(unClient, reqNoFolio){
	ASSERT_EQ(1234, client.reqNoFolio());
}
TEST_F(unClient, reqNom){
	ASSERT_EQ("Deblois", client.reqNom());
}
TEST_F(unClient, reqPrenom){
	ASSERT_EQ("Olivier", client.reqPrenom());
}
TEST_F(unClient, reqTelephone){
	ASSERT_EQ("418 999-9999", client.reqTelephone());
}
TEST_F(unClient, reqDateNaissance){
	ASSERT_EQ("Lundi le 04 mai 1992", client.reqDateDeNaissance().reqDateFormatee());
}

/**
 * test asg telephone valide
 */
TEST_F(unClient, asgTelephone){
	client.asgTelephone("418 988-8888");
	ASSERT_EQ("418 988-8888",client.reqTelephone());
}
/**
 * test asg telephone Non valide
 */
TEST_F(unClient, asgTelephoneNonValide){
	ASSERT_THROW(client.asgTelephone("4189888888"), PreconditionException);
}

TEST_F(unClient, reqClientFormate){
	ASSERT_EQ("Client numero de folio :1234\nDeblois Olivier\nDate de naissance : Lundi le 04 mai 1992\n418 999-9999\n", client.reqClientFormate());
}
TEST_F(unClient, reqReleves){
	ASSERT_EQ("Client numero de folio :1234\nDeblois Olivier\nDate de naissance : Lundi le 04 mai 1992\n418 999-9999\n", client.reqReleves());
}

TEST_F(unClient, OperatorOrdeDeGrandeur){
	Client client1(1234, "Deblois", "Olivier", "418 999-9999", util::Date(4,5,1992));
	Client client2(1235, "Ouelette", "Nicola", "418 998-8888", util::Date(8,3,1994));
	ASSERT_TRUE(client1.operator <(client2));
	ASSERT_FALSE(client2.operator <(client1));
}

TEST_F(unClient, OperatorEgualite){
	Client client1(1234, "Deblois", "Olivier", "418 999-9999", util::Date(4,5,1992));
	Client client2(1234, "Deblois", "Olivier", "418 999-9999", util::Date(4,5,1992));
	Client client3(1235, "Ouelette", "Nicola", "418 998-8888", util::Date(8,3,1994));
	ASSERT_TRUE(client1.operator ==(client2));
	ASSERT_FALSE(client1.operator ==(client3));
}

TEST_F(unClient, ajouterCompte){
	Epargne epargne1(1234, 1.1, 1000);
	client.ajouterCompte(epargne1);
	ASSERT_EQ("Client numero de folio :1234\nDeblois Olivier\nDate de naissance : Lundi le 04 mai 1992\n418 999-9999\nCompte Epargne\n"
			"numero: 1234\nDescription: Epargne\nDate d'ouverture: " + epargne1.reqDateOuverture().reqDateFormatee() + "\nTaux d'interet: 1.1\nSolde: 1000$\n"
			"Interet: 11$\n", client.reqReleves());
}

TEST_F(unClient, ajouterCompteInvalide){
	Epargne epargne1(1234, 1.1, 1000);
	Cheque cheque1(1234, 1.1, 1000, 22, 0.2, "mon cheque");
	client.ajouterCompte(epargne1);
	client.ajouterCompte(cheque1);
	ASSERT_EQ("Client numero de folio :1234\nDeblois Olivier\nDate de naissance : Lundi le 04 mai 1992\n418 999-9999\nCompte Epargne\n"
			"numero: 1234\nDescription: Epargne\nDate d'ouverture: " + epargne1.reqDateOuverture().reqDateFormatee() + "\nTaux d'interet: 1.1\nSolde: 1000$\n"
			"Interet: 11$\n", client.reqReleves());
}


