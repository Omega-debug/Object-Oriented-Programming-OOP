//
// Created by vladm on 5/20/2023.
//

#ifndef LAB_11_12_CODVALIDATOR_H
#define LAB_11_12_CODVALIDATOR_H
#include <iostream>
using namespace std;

class CodValidator {
public:
    static bool validate(int cod);
    static bool apartine(int cod);
    static bool isInteger(int value);
    static bool isInteger(const std::string& value);
};


#endif //LAB_11_12_CODVALIDATOR_H
