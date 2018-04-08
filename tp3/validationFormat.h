/**
 * \file validationFormat.h
 * \brief interface des fonctions de validation
 * \author Olivier Deblois
 * \date 2018-02-28
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
static const int NUM = 12;

namespace util
{

bool validerFormatNom(const std::string& p_nom);

bool validerTelephone(const std::string& p_telephone);

bool validerFormatFichier(std::istream& p_is);
}
#endif /* VALIDATIONFORMAT_H_ */
