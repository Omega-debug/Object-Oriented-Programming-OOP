//
// Created by vladm on 4/24/2023.
//
#include <cstring>
#include "Cheltuieli.h"
#include <iostream>
#include "string"
using namespace std;

Cheltuieli::Cheltuieli() {
    cout << "Default constructor" << endl;
    this->tip = NULL;
    this->suma = 0;
    this->zi = 0;
}

Cheltuieli::Cheltuieli(char *tip,int suma,int zi) {
    cout << "Parameters constructor" << endl;

    this->tip = new char[strlen(tip) + 1];
    strncpy(this->tip, tip, strlen(tip));
    this ->suma = suma;
    this -> zi = zi;

}

Cheltuieli::Cheltuieli(const Cheltuieli &otherCheltuiala) {
    this->tip = new char [strlen(otherCheltuiala.tip) + 1];
    strncpy(this->tip, otherCheltuiala.tip,strlen(otherCheltuiala.tip));

    this -> suma = otherCheltuiala.suma;
    this -> zi = otherCheltuiala.zi;
}

Cheltuieli::~Cheltuieli(){
    delete[] this ->tip;
}

Cheltuieli &Cheltuieli::operator=(const Cheltuieli &otherCheltuiala) {
    cout << "Using = operator" << endl;
    if(this == &otherCheltuiala){
        return *this;
    }

    this ->tip = new char [strlen(otherCheltuiala.tip) + 1];
    strncpy(this -> tip,otherCheltuiala.tip,strlen(otherCheltuiala.tip));
    this->suma = otherCheltuiala.suma;
    this->zi = otherCheltuiala.zi;

    return *this;
}


bool Cheltuieli::operator==(const Cheltuieli &c) {
    return ((strcmp(this->tip,c.tip)==0) && (this->suma == c.suma) && (this->zi == c.zi));

}

char *Cheltuieli::getTip(){
    return this->tip;
}

int Cheltuieli::getSuma() {
    return this->suma;
}

int Cheltuieli::getZi() {
    return this->zi;
}

void Cheltuieli::setTip(char *tip) {
    if(this->tip){
        delete []this->tip;
    }

    this->tip = new char[strlen(tip) + 1];
    strncpy(this->tip, tip, strlen(tip));
}

void Cheltuieli::setSuma(int suma) {
    this->suma = suma;
}

void Cheltuieli::setZi(int zi) {
    this->zi = zi;
}

Cheltuieli::Cheltuieli(Cheltuieli &&other) : tip(nullptr),suma(0),zi(0) {
    cout << "move constructor" << endl;
    tip = other.tip;
    suma = other.suma;
    zi = other.zi;


    other.tip = nullptr;
    other.suma = 0;
    other.zi = 0;
}