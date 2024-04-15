//
// Created by vladm on 5/3/2023.
//
#include <limits>
#include "UI.h"
#include "iostream"
#include "CodException.h"
#include "NumeException.h"
#include "PretException.h"
#include "CodValidator.h"
#include "NumeValidator.h"
#include "PretValidator.h"
using namespace std;


UI::UI(Service &otherService) : service(otherService) {

}

int UI::printMenu() {
    cout<<"Alege o optiune: "<<endl;
    cout<<"1.Adauga un produs"<<endl;
    cout<<"2.Afiseaza produsele"<<endl;
    cout<<"3.Modifica un produs"<<endl;
    cout<<"4.Sterge un produs"<<endl;
    cout<<"5.Sortare dupa pret"<<endl;
    cout<<"6.Filtreaza dupa pret"<<endl;
    cout<<"7.Iesi din aplicatie"<<endl;
    int option;
    cout<<"Introdu o optiune"<<endl;
    cin >> option;
    cout<< endl;
    return option;
}


void UI::addEntitate() {
    int cod;
    char nume[100];
    int pret;

    cout << "Adauga un cod" << endl;
    if (!(cin >> cod)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Codul introdus nu este valid. Te rog sa introduci un numar intreg.\n";
        return;
    }

    cout << "Adauga un produs" << endl;
    cin >> nume;

    cout << "Adauga un pret" << endl;
    if (!(cin >> pret)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Pretul introdus nu este valid. Te rog sa introduci un numar intreg.\n";
        return;
    }

    cout << endl;

    try {
        if (!Service::valideazaCod(cod)) {
            throw CodException("Codul este deja sau este mai mic ca zero");
        }

        if (!Service::valideazaNume(nume)) {
            throw NumeException("Numele este introdus gresit!");
        }

        if (!Service::valideazaPret(pret)) {
            throw PretException("Pretul trebuie sa fie un numar pozitiv!");
        }

        service.addEntitate(Entitate(cod, nume, pret));

        int bancnota;
        cout << "Introdu bancnota: " << endl;
        cin >> bancnota;
        cout << endl;
        service.calculateChange(pret, bancnota);
    } catch (const CodException& e) {
        cout << "Eroare la adaugarea entitatii: " << e.what() << endl;
    } catch (const NumeException& e) {
        cout << "Eroare la adaugarea entitatii: " << e.what() << endl;
    } catch (const PretException& e) {
        cout << "Eroare la adaugarea entitatii: " << e.what() << endl;
    }
}





void UI::printAll() {
    for(auto entitate:service.getAll()){
        cout<<entitate.getCod()<<" "<<entitate.getNume()<< " "<<entitate.getPret()<<endl;
    }
}

void UI::modificaEntitate() {
    try {
        int pos, cod, pret;
        char nume[100];
        cout << "Alege pozitia: " << endl;
        cin >> pos;
        cout << "Adauga un cod" << endl;
        cin >> cod;
        cout << "Adauga un produs" << endl;
        cin >> nume;
        cout << "Adauga un pret" << endl;
        cin >> pret;
        cout << endl;

        service.modifica(pos, cod, nume, pret);
    } catch (const CodException& e) {
        cout << "Eroare la adaugarea entitatii: " << e.what() << endl;
    } catch (const NumeException& e) {
        cout << "Eroare la adaugarea entitatii: " << e.what() << endl;
    } catch (const PretException& e) {
        cout << "Eroare la adaugarea entitatii: " << e.what() << endl;
    }
}


void UI::stergeEntitate() {
    int pos;
    cout<<"Alege pozitia: "<<endl;
    cin>>pos;
    service.sterge(pos);

}

void UI::sortare() {
    for(auto entitate:service.sortare()){
        cout<<entitate.getCod()<<" "<<entitate.getNume()<< " "<<entitate.getPret()<<endl;
    }
}

void UI::filterPrice() {
    int pret;
    cout<<"Alege un pret pentru care exista produse care costa mai mult de acest pret: "<<endl;
    cin>>pret;
    for(auto entitate:service.filterByPrice(pret)){
        cout<<entitate.getCod()<<" "<<entitate.getNume()<< " "<<entitate.getPret()<<endl;
    }

}




void UI::start() {
    int option;

    while(true){
        option = printMenu();

        switch(option){
            case 1:
                this ->addEntitate();
                break;
            case 2:
                this ->printAll();
                break;
            case 3:
                this ->modificaEntitate();
                break;
            case 4:
                this ->stergeEntitate();
                break;
            case 5:
                this->sortare();
                break;
            case 6:
                this->filterPrice();
                break;
            case 7:
                cout<<"Inchide..."<<endl;
                return;
        }
    }


}