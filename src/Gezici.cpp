#include "Gezici.hpp"



Gezici::Gezici(Dugum* ilkDugum, int sira)
{
    this->suankiDugum = ilkDugum;
    this->kacinciDugum= sira;


}



void Gezici::Sifirla(Dugum* ilkDugum)
{
    
    this->suankiDugum = ilkDugum;
    this->kacinciDugum= 0;

}

Dugum* Gezici::Git(int hedef)
{

    
    while(suankiDugum->sira != hedef && suankiDugum->sonrakiDugum != nullptr){

        suankiDugum = suankiDugum->sonrakiDugum;

    }

    if(suankiDugum->sira==hedef){
        return suankiDugum;
    }
    else {
        throw runtime_error("Hedef dugum bulunamadi.");
    }


}

Dugum* Gezici::TerseGit(char basDugumGeni)
{
    bool kucukBulundu = false;
    while(suankiDugum->oncekiDugum != nullptr && !kucukBulundu){
       
        if(suankiDugum->gen < basDugumGeni ){
            kucukBulundu = true;
        }
        else{
            suankiDugum = suankiDugum->oncekiDugum;
        }

    }

    return suankiDugum;
}

