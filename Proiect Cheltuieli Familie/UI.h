//
// Created by vladm on 4/30/2023.
//

#ifndef LAB_7_FULL_EDITION_UI_H
#define LAB_7_FULL_EDITION_UI_H
#include "Service.h"

class UI {
private:
    Service service;
    Service undo;



public:
    UI(Service &otherService);
    ~UI() = default;
    int printMeniu();
    void addCheltuiala();
    void printAll();
    void modificaCheltuiala();
    void modificaDupaZI();
    void modificaDupaIntervalZi();
    void afiseazaListaDupaCheltuiala();
    void Undo2();
    void sumaTipCheltuieli();
    void filtrareListaDupaTip();


    void start();
};


#endif //LAB_7_FULL_EDITION_UI_H
