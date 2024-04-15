//
// Created by vladm on 5/20/2023.
//

#include "CodValidator.h"
#include "RepoFile.h"
#include <cctype>
RepoFile repo("teste.txt");

bool CodValidator::apartine(int cod) {
    for(auto enti:repo.getAll()){
        if(enti.getCod() == cod) {
            return false;
        }

    }
    return true;
}

bool CodValidator::isInteger(const std::string& value) {
    for (char c : value) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}



bool CodValidator::isInteger(int value)  {
    std::string strValue = std::to_string(value);
    return isInteger(strValue);
}


bool CodValidator::validate(int cod) {
    if(cod>=0 && apartine(cod) && isInteger(cod)){
        return true;
    }
    return false;
}

