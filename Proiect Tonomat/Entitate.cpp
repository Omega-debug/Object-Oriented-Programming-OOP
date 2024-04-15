//
// Created by vladm on 5/1/2023.
//



using namespace std;

#include "Entitate.h"
#include <cstring>
#include <iostream>
#include "string"
#include "CodException.h"
#include "NumeException.h"
#include "PretException.h"

using namespace std;

Entitate::Entitate() {
    cout<<"Default constructor" << endl;
    this->cod = 0;
    this->nume = NULL;
    this->pret = 0;
}

Entitate::Entitate(int cod, char *nume, int pret) {
    cout<< "Parameters constructor" << endl;

    this->cod = cod;
    this->nume = new char[strlen(nume) + 1];
    strncpy(this->nume, nume,strlen(nume));
    this->nume[strlen(nume)] = '\0';
    this->pret = pret;
}


Entitate::Entitate(const Entitate &otherEntitate) {
    this->cod = otherEntitate.cod;
    this->nume = new char[strlen(otherEntitate.nume) + 1];
    strncpy(this->nume,otherEntitate.nume, strlen(otherEntitate.nume));
    this->nume[strlen(otherEntitate.nume)] = '\0';
    this-> pret = otherEntitate.pret;

}

Entitate::~Entitate() {
    delete[] this ->nume;
}


Entitate &Entitate::operator=(const Entitate &otherEntitate) {
    cout<< "Using = operator" << endl;
    if(this == &otherEntitate){
        return *this;
    }

    this -> nume = new char [strlen(otherEntitate.nume) + 1];
    strncpy(this -> nume, otherEntitate.nume,strlen(otherEntitate.nume));
    this->cod = otherEntitate.cod;
    this->pret = otherEntitate.pret;

    return *this;
}


bool Entitate::operator==(const Entitate &e) {
    return ((this->cod ==e.cod) && (strcmp(this->nume,e.nume)==0) && (this->pret == e.pret));
}


int Entitate::getCod() const {
    return this->cod;
}

int Entitate::getPret() const {
    return this->pret;
}


char *Entitate::getNume() const {
    return this->nume;
}


void Entitate::setNume(char *nume) {
    if (nume == nullptr || strlen(nume) == 0) {
        throw NumeException("Numele nu poate fi vid!");
    }
    this->nume = new char[strlen(nume) + 1];
    strncpy(this->nume, nume, strlen(nume));
    this->nume[strlen(nume)] = '\0';

}

void Entitate::setCod(int cod) {
    if (cod < 0) {
        throw CodException("Codul trebuie sa fie un numar pozitiv!");
    }
    this->cod = cod;
}

void Entitate::setPret(int pret) {
    if (pret < 0) {
        throw PretException("Pretul trebuie sa fie un numar pozitiv!");
    }
    this->pret = pret;
}


Entitate::Entitate(Entitate &&other) :cod(0),nume(nullptr),pret(0){
    cout<< "move constructor" << endl;
    cod = other.cod;
    nume = other.nume;
    pret = other.pret;


    other.cod = 0;
    other.nume = nullptr;
    other.pret = 0;
}


