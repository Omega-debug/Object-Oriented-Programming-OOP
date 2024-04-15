#include <iostream>
#include "Teste.h"
#include "UI.h"

int main() {
    Teste();
    //RepoEntitate repoEntitate;
    RepoFile repoEntitate("teste.txt");
    Service service(repoEntitate);
    UI ui(service);
    ui.start();

    return 0;
}
