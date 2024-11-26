#include "ListeGezici.hpp"



ListeGezici::ListeGezici(BagliListe* basListe)
{
    this->suankiBagliListe = basListe;
    this->kacinciListe = 0;
}

ListeGezici::~ListeGezici()
{
    delete suankiBagliListe;
}

void ListeGezici::Sifirla(BagliListe* basListe)
{
    this->suankiBagliListe = basListe;
    this->kacinciListe = 0;

}




BagliListe* ListeGezici::Git(int hedef)
{
    while(suankiBagliListe->sira != hedef && suankiBagliListe->sonrakiBagliListe != nullptr){

        suankiBagliListe= suankiBagliListe->sonrakiBagliListe;



    }

    if(suankiBagliListe->sira==hedef){
        return suankiBagliListe;
    }
    else {
        throw runtime_error("Hedef dugum bulunamadi.");
    }



    
}

BagliListe* ListeGezici::ListeGetir()
{
    
    return suankiBagliListe;



}
