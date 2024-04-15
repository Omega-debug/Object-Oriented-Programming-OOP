//
// Created by vladm on 5/3/2023.
//

#include "Service.h"
using namespace std;
#include <cstring>
#include<vector>
#include <iostream>
#include <algorithm>
#include "CodValidator.h"
#include "NumeValidator.h"
#include "PretValidator.h"


void Service::calculateChange(int productPrice, int banknoteValue) {
    int denominations[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    int numDenominations = sizeof(denominations) / sizeof(denominations[0]);

    bool isValidBanknote = false;
    int validDenomination = 0;

    for (int i = 0; i < numDenominations; i++) {
        if (denominations[i] == banknoteValue) {
            isValidBanknote = true;
            validDenomination = i;
            break;
        }
    }

    if (!isValidBanknote) {
        cout << "Invalid banknote value!" << endl;
        return;
    }

    int change = banknoteValue - productPrice;
    if (change < 0) {
        cout << "Insufficient funds!" << endl;
        return;
    }

    cout << "Change: " << change << endl;

    vector<int> changeDenominations(numDenominations, 0);

    for (int i = validDenomination; i < numDenominations; i++) {
        int numNotes = change / denominations[i];
        change = change % denominations[i];
        changeDenominations[i] = numNotes;
    }

    for (int i = 0; i < numDenominations; i++) {
        if (changeDenominations[i] > 0) {
            cout << denominations[i] << " note(s): " << changeDenominations[i] << endl;
        }
    }
}



Service::Service(RepoFile &otherRepo) : repo(otherRepo) {}

void Service::addEntitate(Entitate entit) {
    this->repo.addEntitate(entit);
}


vector <Entitate> Service::getAll() {
    return this->repo.getAll();
}

void Service::sterge(int pos) {
    this->repo.stergeEntitate(pos);
}

void Service::modifica(int pos, int cod, char *nume, int pret) {
    this->repo.modificaEntitate(pos,cod,nume,pret);
}

Entitate Service::getEntitatiByStudent(int pos) {
    this->repo.getEntitateByPosition(pos);
}

bool cmp(Entitate &a,Entitate &b){
    if(a.getPret() == b.getPret()){
        return a.getCod()>b.getCod();
    }
    return a.getPret()>b.getPret();
}


vector<Entitate> Service::sortare() {
    vector<Entitate>lista = repo.getAll();
    sort(lista.begin(),lista.end(), cmp);
    return lista;
}


vector<Entitate> Service::filterByPrice(int pret) {
    vector<Entitate> results;

    for(auto entitate: this->repo.getAll()){
        if(entitate.getPret()>pret){
            results.push_back(entitate);
        }
    }
    return results;
}



bool Service::valideazaCod(int cod) {
    if(CodValidator::validate(cod)){
        return true;
    }
    return false;
}

bool Service::valideazaNume(const char *nume) {
    if(NumeValidator::validate(nume)){
        return true;
    }
    return false;
}

bool Service::valideazaPret(int pret) {
    if(PretValidator::validate(pret)){
        return true;
    }
    return false;
}