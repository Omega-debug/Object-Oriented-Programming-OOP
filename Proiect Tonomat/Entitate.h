//
// Created by vladm on 5/1/2023.
//

#ifndef LAB_9_8_HAIDE_ENTITATE_H
#define LAB_9_8_HAIDE_ENTITATE_H
#pragma once
#include <string>
using namespace std;
#include <iostream>


class Entitate {
public:
    int cod;
    char *nume;
    int pret;
    Entitate();
    Entitate(int cod,char *nume,int pret);
    Entitate(const Entitate &otherEntitate);
    Entitate(Entitate &&other);

    ~Entitate();

    Entitate &operator=(const Entitate &otherEntitate);
    bool operator ==(const Entitate &e);

    int getCod() const;
    char *getNume() const;
    int getPret() const;


    void setCod(int cod);
    void setNume(char *nume);
    void setPret(int pret);

    friend ostream& operator<<(ostream& os, const Entitate& entitate){
        os << entitate.getCod() << ' ' << entitate.getNume() << ' ' << entitate.getPret() << endl;
        return os;
    }
    friend istream& operator>>(istream& is,Entitate entitate){
        is >> entitate.cod >> entitate.nume >> entitate.pret;
        return is;
    }


};


#endif //LAB_9_8_HAIDE_ENTITATE_H
