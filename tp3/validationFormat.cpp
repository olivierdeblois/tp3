/**
 * \file validationFormat.cpp
 * \brief implementation des fonctions de validation
 * \author Olivier Deblois
 * \date 2018-02-28
 */
using namespace std;
#include"validationFormat.h"

namespace util{
bool validerFormatNom(const std::string& p_nom) {
	bool nom = true;
	int longueurNom = p_nom.length();
	int espace = 0;
	for (int i = 0 ; i<longueurNom ; i++){
		if (p_nom[i] == ' ')
			espace++;
	}
	if (espace == longueurNom)
		nom=false;
	if (p_nom.empty()){
		nom=false;
	}
	for (int i = 0; i < longueurNom; i++)
	{
		if (nom
				&& !((p_nom[i] <= 'z' && p_nom[i] >= 'a')
						|| (p_nom[i] <= 'Z' && p_nom[i] >= 'A')
						|| (p_nom[i] == ' '))) {
			nom = false;
		}
	}
	return nom;
}

bool validerTelephone(const std::string& p_telephone) {
	bool numero = false;
	int longueur = p_telephone.length();
	if (longueur != NUM)
	{
		numero = false;
	}
	 else
	 {
		string region = p_telephone.substr(0, 3); // region = les 3 premier chiffres (code regional)
		string septChiffres = p_telephone.substr(4, 8); // septChiffres = le reste du numero de telephone
		string codeRegion[] = { "403", "780", "604", "236", "250", "778", "902",
				"204", "506", "902", "905", "519", "289", "705", "613", "807",
				"416", "647", "438", "514", "450", "579", "418", "581", "819",
				"306", "709", "867", "800", "866", "877", "888", "855" };
		string payant = p_telephone.substr(0,1); // payant = le premier chiffre du num tel ( il devra etre un "9" )
		int c = 33; // nombre de code regional different
		int l = region.length();
		int L = septChiffres.length();

		if(payant.compare("9") == 0){
			numero = true;
		}
		for (int i = 0; i < c ; i++) // verification des 3 premiers chiffres (code regional)
		{

			if (region.compare(codeRegion[i]) == 0)
			{
				numero = true;
			}
		}


		for (int i = 0; i < l; i++)       // seulement des chiffres
		{
			if (numero&& !((region[i] <= '9' && septChiffres[i] >= '0')))
			{
				numero = false;
			}
		}


		for (int i = 0; i < L; i++) // seulement des chiffres ou '-'
		{
			if (numero&& !((septChiffres[i] <= '9' && septChiffres[i] >= '0')
							|| (septChiffres[i] == '-')))
			{
				numero = false;
			}
		}

		if (p_telephone[7] != '-')    // verification du '-' a la bonne position
		{
			numero = false;
		}
		if (p_telephone[3] != ' ') // verification de l'espace apres les 3 premier chiffres
		{
			numero = false;
		}
	}

	return numero;
}

bool validerFormatFichier(std::istream& p_is) {

	bool validite=true;
	int nombreComptesCheques=0;
	int nombreComptesEpargnes=0;
	int nblignes=0;
	int lignesTotal=0;

	char buffer[256];
	string nom;
	p_is.getline(buffer, 255);
	nom = buffer;
	validerFormatNom(nom);
	bool is_nom = validerFormatNom(nom);
	if(is_nom == false) validite = false;


	string prenom;
	p_is.getline(buffer, 255);
	prenom = buffer;
	validerFormatNom(prenom);
	bool is_prenom = validerFormatNom(prenom);
	if(is_prenom == false) validite = false;

	int jour;
	p_is >> jour;
	if(jour<=0)
		validite = false;

	int moi;
	p_is >> moi;
	if(moi<=0)
		validite = false;

	int annee;
	p_is >> annee;
	if(annee<=0)
		validite = false;

	p_is.ignore();         // retour au buffer

	string telephone;
	p_is.getline(buffer, 255);
	telephone = buffer;
	validerTelephone(telephone);
	bool is_telephone = validerTelephone(telephone);
	if(is_telephone == false) validite = false;

	string folio;                        // rien a valider ici
	p_is.getline(buffer, 255);
	folio = buffer;
	//if (folio.empty()) validite = false;

	string ligne;
	while (p_is.getline(buffer,255)){
		lignesTotal++;
		ligne = buffer;
		if (ligne == "cheque"){
			nombreComptesCheques++;
			nblignes+=7;
		}
		if(ligne == "epargne"){
			nombreComptesEpargnes++;
			nblignes+=6;
		}
	}
	if (nblignes!=lignesTotal) validite=false;

	cout<<validite<<endl;
	return validite;
}
}
