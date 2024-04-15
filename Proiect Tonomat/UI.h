//
// Created by vladm on 5/3/2023.
//

#ifndef LAB_9_8_HAIDE_UI_H
#define LAB_9_8_HAIDE_UI_H
#include "Service.h"

class UI {
private:
    Service service;
public:
    UI(Service &otherService);
    ~UI() = default;
    int printMenu();
    void addEntitate();
    void printAll();
    void stergeEntitate();
    void modificaEntitate();
    void sortare();
    void filterPrice();



    void start();


};


#endif //LAB_9_8_HAIDE_UI_H
