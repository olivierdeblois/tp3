/**
 * \file main.cpp
 * \brief fonction principale
 * \author Olivier Deblois
 * \date 2018-02-28
 */

#include <iostream>
#include "Client.h"
using namespace std;
using namespace util;
using namespace banque;

/**
 * \brief fonction principale pour la fabrication d'un client
 * \return un objet client
 */

int main(){
/*	bool validiteFolio=false;
	bool validitePrenom=false;
	bool validiteNom=false;
	bool validiteTelephone=false;
	bool validiteNouveauTelephone=false;
	string prenom;
	string nom;
	string telephone;
	string nouveauTelephone;
	int noFolio;

	cout<<"Bienvenue a l'outil client"<<endl;
	cout<<"----------------------------------------"<<endl;

	while(!validiteFolio){

		cout<<"Entrez le numero de folio du client [1000, 10000[ : "<<endl;
		cin>>noFolio;
		if (noFolio>=1000 && noFolio<10000) validiteFolio=true;

		else                             // folio non valide
		{

			cout<<"Le numero de folio n'est pas entre 1000 et 10000 exclusivement"<<endl;
			cout<<endl;
		}
		}
	getline(cin, prenom);
	while(!validitePrenom){

		cout<<"Entrez le prenom: "<<endl;

		getline(cin, prenom);
		if (validerFormatNom(prenom)) validitePrenom=true;
		else                                            // prenom non valide
		{
			cout<<"Le prénom n’est pas valide"<<endl;
			cout<<endl;
		}
		}


	while(!validiteNom){

		cout<<"Entrez le nom: "<<endl;
		getline(cin, nom);
		if (validerFormatNom(nom)) validiteNom=true;
		else                                            // nom non valide
		{
			cout<<"Le nom n’est pas valide"<<endl;
			cout<<endl;
		}
		}


	while(!validiteTelephone){

		cout<<"Entrez le numero de telephone XXX CCC-CCCC: "<<endl;
		getline(cin, telephone);
		if (validerTelephone(telephone)) validiteTelephone=true;
		else                                            // telephone non valide
		{
			cout<<"Le numero de telephone n'est pas valide."<<endl;
			cout<<endl;
		}
		}

	cout<<"Fiche client"<<endl;
	cout<<"------------------------------------------------"<<endl;


	Client client(noFolio, nom, prenom, telephone); // creation d'un objet client
	cout<< client.reqClientFormate()<<endl;
	while(!validiteNouveauTelephone){

		cout<< "Entrez un nouveau numero de telephone XXX CCC-CCCC: "<<endl;
		getline(cin, nouveauTelephone);
		if (validerTelephone(nouveauTelephone)){
			validiteNouveauTelephone=true;
			client.asgTelephone(nouveauTelephone);
		}

		else                                            // telephone non valide
		{
			cout<<"Le numero de telephone n'est pas valide."<<endl;
			cout<<endl;
		}
		}
	cout<<"Fiche client"<<endl;
	cout<<"------------------------------------------------"<<endl;
	cout<< client.reqClientFormate()<<endl;
	cout<< "Fin du programme!"<<endl;*/

	cout<< "test des nouvelles classes"<< endl;
	//Compte compte(1111, 3.2, -1000, "nimportekoi");
	Cheque lol(1234, 1.2, -3000, 4, 0.3, "Mon compte courant"); // ajouter pour TP3
	//cout<< compte.reqCompteFormate()<<endl;
	cout<< lol.reqCompteFormate()<<endl;
	cout<< lol.calculerInteret()<<endl;
	lol.asgNombreTransactions(30);
	lol.asgSolde(55000);
	cout<< lol.reqCompteFormate();
	cout<< lol.calculerInteret()<<endl;
	//cout << compte.reqDateOuverture()<< endl;
	//cout << compte.reqDateOuverture().reqDateFormatee() << endl;
	cout<< endl;
	cout<< endl;
	cout<< endl;
	cout<< endl;
	cout<< endl;
	cout<< endl;
	cout<< "2iem partie de test"<<endl;
	cout<< lol.reqSolde()<< endl;
	Epargne epargne(2222, 0.3, 3000);
	cout<< epargne.reqCompteFormate()<<endl;
	cout<< epargne.reqNoCompte()<<endl;
	Client client(1234, "Deblois", "Olivier", "418 576-0789", util::Date(04,05,1992));
	cout<< client.reqClientFormate()<<endl;

	return 0;

}


