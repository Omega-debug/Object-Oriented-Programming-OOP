//
// Created by vladm on 4/30/2023.
//

#include <iostream>
using namespace std;

#include "UI.h"

UI::UI(Service &otherService){
    this ->service = otherService;
    this ->undo = otherService;
}

int UI::printMeniu() {
    cout<<"Alege o optiune: "<< endl;
    cout<<"1. Adauga un student"<<endl;
    cout<<"2.Afiseaza toti studentii" << endl;
    cout<<"3.Modifica optiune" << endl;
    cout<<"4.Modifica dupa zi"<<endl;
    cout<<"5.Modifica dupa interval"<<endl;
    cout<<"6.Afiseaza dupa tipul de cheltuiala"<<endl;
    cout<<"7.Suma dupa un tip de cheltuiala"<<endl;
    cout<<"8.Filtrare lista dupa tip"<<endl;
    cout<<"9.Undo"<<endl;
    cout<<"10.Iesi din aplicatie"<<endl;
    cout<< "Introdu o optiune" << endl;
    int option;
    cin >> option;
    cout << endl;
    return option;
}

void UI::addCheltuiala() {
    undo = service;
    char tip[100];
    int suma;
    int zi;
    cout<< "Adauga tipul cheltuielii: ";
    cin >> tip;
    cout<< "Adauga suma cheltuielii: ";
    cin >> suma;
    cout << "Adauga zi cheltuielii: ";
    cin >> zi;
    cout<<endl;

    this ->service.addCheltuieli(Cheltuieli(tip,suma,zi));
}



void UI::start() {
    int option;

    while (true){
        option = this ->printMeniu();

        switch (option) {
            case 1:
                this -> addCheltuiala();
                break;
            case 2:
                this ->printAll();
                break;
            case 3:
                this ->modificaCheltuiala();
                break;
            case 4:
                this ->modificaDupaZI();
                break;
            case 5:
                this ->modificaDupaIntervalZi();
                break;
            case 6:
                this ->afiseazaListaDupaCheltuiala();
                break;
            case 7:
                this ->sumaTipCheltuieli();
                break;
            case 8:
                this->filtrareListaDupaTip();
                break;
            case 9:
                this ->Undo2();
                break;
            case 10:
                cout<< "Inchide..." << endl;
                return;
        }
    }
}


void UI::printAll() {
    for(auto cheltuiala: this->service.getAll()){
        cout << cheltuiala.getTip() << " " << cheltuiala.getSuma() << " " << cheltuiala.getZi() << endl;
    }
}

void UI::modificaCheltuiala() {
    undo = service;
    int pos;
    char tip[100];
    int suma;
    int zi;
    cout<< "Alege pozitia pe care vrei sa o modifici: ";
    cin >> pos;
    cout<< "Adauga tipul cheltuielii: ";
    cin >> tip;
    cout<< "Adauga suma cheltuielii: ";
    cin >> suma;
    cout << "Adauga zi cheltuielii: ";
    cin >> zi;
    cout<<endl;

}

void UI::modificaDupaZI() {
    undo = service;
    int zi;
    cout << "Adauga zi cheltuielii: ";
    cin >> zi;
    service.stergeDupaZi(zi);
}

void UI::modificaDupaIntervalZi() {
    undo = service;
    int primaZi,ultimaZi;
    cout<<"Alege prima zi: ";
    cin >> primaZi;
    cout<<"Alege ultima zi: ";
    cin>> ultimaZi;
    service.stergeDupaIntervalZile(primaZi,ultimaZi);
}


void UI::afiseazaListaDupaCheltuiala() {
    undo = service;
    char* tip;
    cout<<"Alege tipul cheltuielii: ";
    cin >> tip;
    vector <Cheltuieli> rezultate;
    rezultate = service.afisareCheltuieliLuna(tip);
    for(auto rezultat:rezultate){
        cout<<rezultat.getTip()<< " " << rezultat.getSuma() << " " << rezultat.getZi()<<endl;
    }

}



void UI::Undo2(){
    service = undo;
    cout<<"Undo realizat cu succes!";
}

void UI::filtrareListaDupaTip() {
    undo = service;
    char* tip;
    cout<<"Alege tipul cheltuielii: ";
    cin>>tip;
    cout<<tip<<endl;
    vector<Cheltuieli> rezultat;
    rezultat = service.filtrareListaDupaTip(tip);
    for(auto rezult:rezultat){
        cout<<rezult.getTip()<<" "<<rezult.getSuma()<<" "<<rezult.getZi()<<endl;
    }

}

void UI::sumaTipCheltuieli() {
    undo = service;
    char tip[100];
    cout<<"Alege tipul cheltuielii: ";
    cin>>tip;
    cout<<tip<<endl;
    int suma = service.afiseazaSumaDupaTip(tip);
    cout<<suma<<endl;
}