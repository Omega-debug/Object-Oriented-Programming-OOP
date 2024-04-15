//
// Created by vladm on 5/20/2023.
//

#ifndef LAB_11_12_PRETVALIDATOR_H
#define LAB_11_12_PRETVALIDATOR_H
#include <iostream>
using namespace std;

class PretValidator {
public:
    static bool validate(int pret);
    static bool isInteger(int value);
    static bool isInteger(const std::string& value);
};


#endif //LAB_11_12_PRETVALIDATOR_H
