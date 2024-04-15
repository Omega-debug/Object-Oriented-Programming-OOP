//
// Created by vladm on 5/8/2023.
//

#ifndef LAB_9_8_HAIDE_REPOFILE_H
#define LAB_9_8_HAIDE_REPOFILE_H
#pragma once
#include "RepoEntitate.h"
#include <cstring>
#include "string"


class RepoFile: public RepoEntitate{
private:
    string fileName;
public:
    RepoFile(string fileName);
    ~RepoFile();

    void addEntitate(Entitate &e);
    void modificaEntitate(int pos,int cod,char *nume,int pret);
    void stergeEntitate(int pos);

private:
    void loadFromFile();
    void saveToFile();

};


#endif //LAB_9_8_HAIDE_REPOFILE_H
