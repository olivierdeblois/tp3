/**
 * \file ProgrammePrincial.cpp
 * \brief
 * \author etudiant
 * \date 2018-04-09
 */
#include "Client.h"
#include "validationFormat.h"
using namespace std;
using namespace util;
using namespace banque;

int main(){


	//variable pour l'outil client

	bool validiteFolio=false;
	bool validitePrenom=false;
	bool validiteNom=false;
	bool validiteTelephone=false;
	bool validiteDateNaissance=false;
	string prenom;
	string nom;
	string telephone;
	string nouveauTelephone;
	int noFolio;
	long jour = 01;
	long mois = 01;
	long annee = 1970;
	string dateNaissance;

	 // variables pour l'outil compte cheque

	int noCompte;
	double tauxInteret;
	double solde;
	int nombreTransactions;
	double tauxInteretMinimum;
	string description;
	bool noCompteValide = false;
	bool tauxInteretValide = false;
	bool nombreTransactionValide= false;
	bool tauxInteretMinimumValide = false;

	 //variable pour l'outil compte epargne

	double soldeEpargne;
	int noCompteEpargne;
	double tauxInteretEpargne;
	string descriptionEpargne;
	bool tauxInteretEpargneValide = false;
	bool noCompteEpargneValide = false;


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
	cout << "Date de Naissance du CLient: " << endl;

	while(!validiteDateNaissance){
		cout << "Entrez le jour de la date de naissance format(jj): ";
		cin >> jour;
		cout << "Entrez le mois de la date de naissance format(mm): ";
		cin >> mois;
		cout << "Entrez l'annee de la date de naissance format(aaaa): ";
		cin >> annee;

		if (Date::validerDate(jour,mois,annee)) validiteDateNaissance = true;
		else{
			cout << "La date de Naissance est Invalide."<< endl;
			cout << endl;
		}

	}
	Client monclient(noFolio, nom, prenom, telephone, util::Date(jour, mois, annee));

//**************************************************************************************

	cout<<"Bienvenue a l'outil Compte Cheque"<<endl;
	cout<<"----------------------------------------"<<endl;
	while(!noCompteValide){
		cout << " Entrez le numero du compte cheque: ";
		cin >> noCompte;
		if (noCompte > 0) noCompteValide = true;
		else{
			cout << "Le numero de compte doit etre positif.";
		}
	}
	while(!tauxInteretValide){
		cout << " Entrez le taux d'interet du compte cheque: ";
		cin >> tauxInteret;
		if(tauxInteret >= 0.0 && tauxInteret < 100.0) tauxInteretValide = true;
		else{
			cout << "Le taux d'interet est invalide";
			cout<<endl;
		}
	}

	cout << " Entrez le solde du compte cheque: "<<endl;
	cin >> solde;

	while(!nombreTransactionValide){
		cout << " Entrez le nombre de transactions du compte cheque: ";
		cin >> nombreTransactions;
		if(nombreTransactions > 0 && nombreTransactions <= 40) nombreTransactionValide =true;
		else{
			cout << "Le nombre de transactions est invalide";
			cout<<endl;
		}
	}

	while(!tauxInteretMinimumValide){
		cout << " Entrez le taux d'interet minimum du compte cheque: ";
		cin >> tauxInteretMinimum;
		if(tauxInteretMinimum < tauxInteret) tauxInteretMinimumValide = true;
		else{
			cout << "Le taux d'interet minimum est plus grand que le taux d'interet du compte.";
		}
	}
	cin.ignore();
	while(description.empty()){
	cout << "Entrez la description du compte cheque: ";
	getline(cin, description);
		if(description.empty()){
			cout << "La description est invalide.";
		}

	}

	Cheque cheque1(noCompte, tauxInteret, solde, nombreTransactions,tauxInteretMinimum, description);

//**********************************************************************************************

	cout<<"Bienvenue a l'outil Compte Epargne"<<endl;
	cout<<"----------------------------------------"<<endl;

	while(!noCompteEpargneValide){
		cout << " Entrez le numero du compte Epargne: ";
		cin >> noCompteEpargne;
		if (noCompteEpargne > 0) noCompteEpargneValide = true;
		else{
			cout << "Le numero de compte doit etre positif.";
		}
	}
	while(!tauxInteretEpargneValide){
		cout << " Entrez le taux d'interet du compte Epargne: ";
		cin >> tauxInteretEpargne;
		if(tauxInteretEpargne >= 0.1 && tauxInteretEpargne < 3.5) tauxInteretEpargneValide = true;
		else{
			cout << "Le taux d'interet est invalide";
			cout<<endl;
		}
	}

	cout << " Entrez le solde du compte Epargnee: "<<endl;
	cin >> soldeEpargne;

	cin.ignore();
	while(descriptionEpargne.empty()){
		cout << "Entrez la description du compte Epargne: ";
		getline(cin, descriptionEpargne);
		if(descriptionEpargne.empty()){
			cout << "La description est invalide.";
		}

	}


	Epargne epargne1(noCompteEpargne, tauxInteretEpargne, soldeEpargne, descriptionEpargne);

//**************************************************************************************

	monclient.ajouterCompte(cheque1);
	monclient.ajouterCompte(epargne1);
	cout << endl;
	cout << "************************************************************" << endl;
	cout << monclient.reqReleves();

	return 0;
}


