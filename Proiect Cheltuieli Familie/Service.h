//
// Created by vladm on 4/24/2023.
//

#ifndef LAB_7_FULL_EDITION_SERVICE_H
#define LAB_7_FULL_EDITION_SERVICE_H


#include "RepoCheltuiala.h"


class Service{
private:
    RepoCheltuiala repo;
public:
    Service() = default;
    Service(RepoCheltuiala &otherRep);
    ~Service() = default;

    vector<Cheltuieli> getAll();
    void addCheltuieli(Cheltuieli cheltuiala);
    Cheltuieli getCheltuialaByPosition(int position);
    void modifica(int pos,char *tip, int suma, int zi);
    void stergeDupaZi(int zi);
    void stergeDupaIntervalZile(int primaZi,int ultimaZi);
    vector <Cheltuieli> afisareCheltuieliLuna(char *tip);
    vector<Cheltuieli> filtrareListaDupaTip(char* tip);
    int afiseazaSumaDupaTip(char *tip);
};


#endif //LAB_7_FULL_EDITION_SERVICE_H
