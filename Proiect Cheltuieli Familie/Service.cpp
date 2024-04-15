//
// Created by vladm on 4/24/2023.
//
#include <cstring>
#include "Service.h"
#include <iostream>
using namespace std;



Service::Service(RepoCheltuiala &otherRepo) {
    this->repo = otherRepo;
}

vector <Cheltuieli> Service::getAll() {
    return this->repo.getAll();
}

void Service::addCheltuieli(Cheltuieli cheltuiala) {
    this-> repo.addCheltuiala(cheltuiala);
}

Cheltuieli Service::getCheltuialaByPosition(int position) {
    return this->repo.getCheltuialaAtPosition(position);
}

void Service::modifica(int pos, char *tip, int suma, int zi) {
    this ->repo.modificaCheltuieli(pos,tip,suma,zi);
}

void Service::stergeDupaZi(int zi) {
    vector <Cheltuieli> cheltuieli = this ->repo.getAll();
    int i = 0;
    for(auto cheltuiala: cheltuieli){
        if(cheltuiala.getZi() == zi) {
            this->repo.stergeCheltuieli(i);
            break;
        }
        i++;
    }
}


void Service::stergeDupaIntervalZile(int primaZi, int ultimaZi) {
    vector <Cheltuieli> cheltuieli = this ->repo.getAll();
    int i = 0;
    for(auto cheltuiala: cheltuieli){
        if(cheltuiala.getZi() >=primaZi && cheltuiala.getZi() <=ultimaZi){
            this ->repo.stergeCheltuieli(i);
        }
        i++;
    }
}

vector <Cheltuieli> Service::afisareCheltuieliLuna(char *tip) {
    vector <Cheltuieli> cheltuieli = this ->repo.getAll();
    vector <Cheltuieli> rezultat;

    for(auto cheltuiala: cheltuieli){
        char* res = cheltuiala.getTip();
        if(strcmp(res,tip)==0){
            rezultat.push_back(cheltuiala);
        }
    }
    return rezultat;
}



vector <Cheltuieli> Service::filtrareListaDupaTip(char *tip) {
    vector <Cheltuieli> cheltuieli = this->repo.getAll();
    vector<Cheltuieli> rezultat;
    for(auto cheltuiala:cheltuieli){
        char* res = cheltuiala.getTip();
        if(strcmp(res,tip)==0){
            rezultat.push_back(cheltuiala);
        }
    }
    return rezultat;
}

int Service::afiseazaSumaDupaTip(char *tip) {
    vector <Cheltuieli> cheltuieli = this ->repo.getAll();
    int suma = 0;
    for(auto cheltuiala:cheltuieli){
        char* res = cheltuiala.getTip();
        if(strcmp(res,tip)==0){
            suma = suma + cheltuiala.getSuma();
        }
    }
    return suma;
}