//
// Created by vladm on 5/8/2023.
//

#include "RepoFile.h"
#include "Entitate.h"
#include <fstream>


RepoFile::RepoFile(std::string fileName) {
    this->fileName = fileName;
    this->loadFromFile();
}

RepoFile::~RepoFile() {

}

void RepoFile::addEntitate(Entitate &e) {
    RepoEntitate::addEntitate(e);
    this->saveToFile();

}

void RepoFile::modificaEntitate(int pos,int cod,char *nume,int pret) {
    RepoEntitate::modificaEntitate(pos,cod,nume,pret);
    this->saveToFile();
}

void RepoFile::stergeEntitate(int pos) {
    RepoEntitate::stergeEntitate(pos);
    this->saveToFile();
}


void RepoFile::loadFromFile() {
    ifstream f(this->fileName);
    if(f.is_open()){
        int cod,pret;
        char nume[101];
        while(f >> cod){
            f >> nume >> pret;
            Entitate e(cod,nume,pret);
            this->addEntitate(e);
            }
        }
    }

void RepoFile::saveToFile() {
    ofstream f(this->fileName);
    if(f.is_open()) {
        for (auto itr: this->getAll())
            f << itr.getCod() << ' ' << itr.getNume() << ' ' << itr.getPret() << endl;
        f.close();
    }
    else {
        cout << "Error opening file: " << this->fileName << endl;
    }

}
