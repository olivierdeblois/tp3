/**
 * \file ProgrammePrincial.cpp
 * \brief
 * \author etudiant
 * \date 2018-04-09
 */
#include "Client.h"
int main(){
	banque::Client monclient(1500, "Deblois", "Olivier", "418 576-0789", util::Date(04,05,1992));
	cout << monclient.reqClientFormate();

	return 0;
}

