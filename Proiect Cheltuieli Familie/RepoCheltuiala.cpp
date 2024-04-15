//
// Created by vladm on 4/24/2023.
//
#include <vector>
#include "RepoCheltuiala.h"
#include <iostream>

Cheltuieli RepoCheltuiala::getCheltuialaAtPosition(int pos) {
    return this->cheltuieli[pos];
}

void RepoCheltuiala::addCheltuiala(Cheltuieli &cheltuiala) {
    this->cheltuieli.push_back(cheltuiala);
}

vector<Cheltuieli> RepoCheltuiala::getAll() {
    return this->cheltuieli;
}

void RepoCheltuiala::stergeCheltuieli(int pos) {
    this->cheltuieli.erase(cheltuieli.begin()+pos);
}

void RepoCheltuiala::modificaCheltuieli(int pos, char *tip, int suma, int zi) {
    cheltuieli[pos].setTip(tip);
    cheltuieli[pos].setSuma(suma);
    cheltuieli[pos].setZi(zi);

}