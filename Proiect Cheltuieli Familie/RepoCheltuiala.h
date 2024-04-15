//
// Created by vladm on 4/24/2023.
//

#ifndef LAB_7_FULL_EDITION_REPOCHELTUIALA_H
#define LAB_7_FULL_EDITION_REPOCHELTUIALA_H
#include <vector>
#include "Cheltuieli.h"

using namespace std;

class RepoCheltuiala {
private:
    vector<Cheltuieli> cheltuieli;
public:
    RepoCheltuiala() = default;
    ~RepoCheltuiala() = default;

    void addCheltuiala(Cheltuieli &cheltuiala);
    Cheltuieli getCheltuialaAtPosition(int pos);
    vector<Cheltuieli> getAll();
    void stergeCheltuieli(int pos);
    void modificaCheltuieli(int pos,char *tip,int suma,int zi);


};


#endif //LAB_7_FULL_EDITION_REPOCHELTUIALA_H
