//
// Created by vladm on 5/2/2023.
//

#include "Teste.h"
#include "Entitate.h"
#include "RepoEntitate.h"
#include <iostream>
#include <assert.h>
#include "Service.h"
using namespace std;



void Teste(){

    //TEST ENTITATE

    Entitate n1;
    assert(n1.getNume()== nullptr);
    assert(n1.getCod()==0);
    assert(n1.getPret()==0);

    Entitate n2(200,"masina",3);
    assert(n2.getCod()==200);
    assert(n2.getPret()==3);




// TEST REPOSITORY
    RepoEntitate repo;

    repo.addEntitate(n2);

    for(auto entitate:repo.getAll()){
        cout<<entitate.getCod()<<" "<< entitate.getNume()<< " "<< entitate.getPret() << endl;
    }

    Entitate n3(300,"jeleu",4);


    repo.addEntitate(n3);

/*
    Service service(repo);



    service.sterge(1);
    service.modifica(0,505,"masina",200);
    for(auto entitate:service.getAll()){
        cout<<entitate.getCod()<<" "<< entitate.getNume()<< " "<< entitate.getPret() << endl;
    }


*/
}