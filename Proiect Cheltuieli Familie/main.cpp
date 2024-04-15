#include <iostream>
#include "Teste.h"
#include "RepoCheltuiala.h"
#include "Service.h"
#include "Cheltuieli.h"
#include "UI.h"
#include <iostream>
using namespace std;


int main() {
    Teste();
    RepoCheltuiala repo;
    Service service(repo);
    UI ui(service);


    ui.start();


    return 0;
}
