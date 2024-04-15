//
// Created by vladm on 5/2/2023.
//

#ifndef LAB_9_8_HAIDE_REPOENTITATE_H
#define LAB_9_8_HAIDE_REPOENTITATE_H
#include <vector>
#include "Entitate.h"

using namespace std;

class RepoEntitate {
private:
    vector<Entitate> entitati;
public:
    RepoEntitate() = default;
    ~RepoEntitate() = default;

    void addEntitate(Entitate &entitat);
    vector <Entitate> getAll();
    void stergeEntitate(int pos);
    void modificaEntitate(int pos,int cod,char *nume,int pret);
    Entitate getEntitateByPosition(int pos);
};


#endif //LAB_9_8_HAIDE_REPOENTITATE_H
