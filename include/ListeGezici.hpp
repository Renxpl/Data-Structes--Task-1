#ifndef LISTEGEZICI_HPP
#define LISTEGEZICI_HPP
#include "BagliListe.hpp"

class ListeGezici{

    private:
        BagliListe *suankiBagliListe;
        int kacinciListe;


    public:
        ListeGezici(BagliListe*);
        void Sifirla(BagliListe*);
        BagliListe* Git(int);
        BagliListe* ListeGetir();





};



#endif