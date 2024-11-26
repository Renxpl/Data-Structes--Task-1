#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>

using namespace std;

struct Dugum{

    Dugum *sonrakiDugum;
    Dugum *oncekiDugum;
    char gen;
    int sira;

    Dugum(char, Dugum*, int);





};


#endif 