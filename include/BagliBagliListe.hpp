#ifndef BAGLIBAGLILISTE_HPP
#define BAGLIBAGLILISTE_HPP
#include "BagliListe.hpp"
#include "ListeGezici.hpp"


class BagliBagliListe{
    private:
        BagliListe *basBagliListe;
        int buyukluk;
        ListeGezici *gezici;


    public:

        BagliBagliListe(BagliListe*);
        ~BagliBagliListe();

        void Ekle(BagliListe*);

        void Cikar();

        void Yazdir();

        void Carprazlama(int,int);

        void Mutasyon(int sira, int genSira);
        
        void EkranaYazdir();






};










#endif