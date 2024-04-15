//
// Created by vladm on 4/24/2023.
//

#ifndef LAB_7_FULL_EDITION_CHELTUIELI_H
#define LAB_7_FULL_EDITION_CHELTUIELI_H


class Cheltuieli {
public:
    int suma;
    int zi;
    char *tip;
    Cheltuieli();
    Cheltuieli(char *tip,int suma,int zi);
    Cheltuieli(const Cheltuieli &otherCheltuiala);
    Cheltuieli(Cheltuieli &&other);

    ~Cheltuieli();

    Cheltuieli &operator=(const Cheltuieli &otherCheltuiala);
    bool operator ==(const Cheltuieli &c);


    char *getTip();
    int getSuma();
    int getZi();

    void setTip(char *tip);
    void setSuma(int suma);
    void setZi(int zi);





};


#endif //LAB_7_FULL_EDITION_CHELTUIELI_H
