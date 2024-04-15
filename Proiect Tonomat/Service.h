//
// Created by vladm on 5/3/2023.
//

#ifndef LAB_9_8_HAIDE_SERVICE_H
#define LAB_9_8_HAIDE_SERVICE_H

#include "RepoEntitate.h"
#include "RepoFile.h"
class Service {
private:
    RepoFile repo;
public:
    //Service() = default;
    Service(RepoFile &otherRep);
    ~Service() = default;

    vector <Entitate> getAll();
    void addEntitate(Entitate entit);
    void sterge(int pos);
    void modifica(int pos,int cod,char *nume,int pret);
    Entitate getEntitatiByStudent(int pos);
    vector<Entitate> sortare();
    void calculateChange(int productPrice, int banknoteValue);
    vector<Entitate> filterByPrice(int pret);
    static bool valideazaCod(int cod);
    static bool valideazaNume(const char* nume);
    static bool valideazaPret(int pret);

};


#endif //LAB_9_8_HAIDE_SERVICE_H
