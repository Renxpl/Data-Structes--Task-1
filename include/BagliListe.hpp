#ifndef BAGLILISTE_HPP
#define BAGLILISTE_HPP
#include <iostream>
#include "Dugum.hpp"
#include "Gezici.hpp"

class BagliListe{

    private:
        Dugum *basDugum;
        Dugum *sonDugum;
        int buyukluk;
        Gezici *gezici;
        

    public:
        int sira;
        BagliListe *sonrakiBagliListe;
        

        BagliListe(char,Dugum*, int);
        ~BagliListe();

        void Ekle(char);

        void Cikar();

        void Yazdir();

        int BuyuklukDon();

        char GenDon(int);

        void GenMutasyonu(int);

        void EkranaYaz();


};







#endif