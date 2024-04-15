//
// Created by vladm on 4/24/2023.
//

#include "Teste.h"
#include "Cheltuieli.h"
#include "RepoCheltuiala.h"
#include <assert.h>
#include "Service.h"
#include <iostream>
using namespace std;

void Teste(){

    // TEST CHELTUIELI

    Cheltuieli n1;
    assert(n1.getTip() == nullptr);
    assert(n1.getZi()== 0);
    assert(n1.getSuma() == 0);

    Cheltuieli n2("masina",200,21);
    char *x = n2.getTip();
    cout<<x;
    assert(n2.getTip() == x);
    assert(n2.getZi()== 21);
    assert(n2.getSuma() == 200);
    Cheltuieli n5("cabana",32,21);


    //TEST REPOSITORY



    RepoCheltuiala repo;



    repo.addCheltuiala(n2);
    Cheltuieli n3(repo.getCheltuialaAtPosition(0));

    repo.addCheltuiala(n5);

    char* y = n3.getTip();
    cout<<y<<endl;


    assert(n3.getSuma() == n2.getSuma());
    assert(n3.getZi() == n2.getZi());


    for(auto Cheltuiala: repo.getAll()){
        cout<< Cheltuiala.getTip() << " " << Cheltuiala.getZi()<< " "<<Cheltuiala.getSuma() << endl;
    }
    cout<<endl;
    repo.modificaCheltuieli(1,"cabana",700,10);
    for(auto Cheltuiala: repo.getAll()){
        cout<< Cheltuiala.getTip() << " " << Cheltuiala.getZi()<< " "<<Cheltuiala.getSuma() << endl;
    }

    //Service

    Service service(repo);

    Cheltuieli n9("cabana",2,10);

    service.addCheltuieli(n9);

    for(auto Cheltuiala: service.getAll()){
        cout<< Cheltuiala.getTip() << " " << Cheltuiala.getZi()<< " "<<Cheltuiala.getSuma() << endl;
    }


    Cheltuieli n11("internet",200,8);
    cout << n11.getTip()<< endl;
    char* m = n11.getTip();
    cout<<m <<endl;

    service.addCheltuieli(n11);
    service.stergeDupaZi(8);

    int i = 0;
    for(auto Cheltuiala: service.getAll()){
        cout<< Cheltuiala.getTip() << " " << Cheltuiala.getZi()<< " "<<Cheltuiala.getSuma() << endl;
        i++;
    }


    cout<<i<<endl;


    int suma;
    suma = service.afiseazaSumaDupaTip("cabana");





















}