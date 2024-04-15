//
// Created by vladm on 5/2/2023.
//
#include <vector>
#include "RepoEntitate.h"


void RepoEntitate::addEntitate(Entitate &entitate) {
    this ->entitati.push_back(entitate);
}

vector <Entitate> RepoEntitate::getAll() {
    return this->entitati;
}

void RepoEntitate::stergeEntitate(int pos) {
    this->entitati.erase(entitati.begin()+pos);
}

void RepoEntitate::modificaEntitate(int pos, int cod, char *nume, int pret) {
    entitati[pos].setCod(cod);
    entitati[pos].setNume(nume);
    entitati[pos].setPret(pret);
}

Entitate RepoEntitate::getEntitateByPosition(int pos) {
    return this->entitati[pos];
}