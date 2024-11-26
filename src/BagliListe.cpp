#include "BagliListe.hpp"

BagliListe::BagliListe(char gen,Dugum* sonrakiDugum, int sira)
{
    basDugum = new Dugum(gen,sonrakiDugum,0);
    basDugum->oncekiDugum = nullptr;
    buyukluk = 1;
    gezici = new Gezici(basDugum,0);
    this->sira= sira;
    
    


}

BagliListe::~BagliListe()
{
    
    delete gezici;
    do{
        Dugum* sonraki = basDugum->sonrakiDugum;
        delete basDugum;
        basDugum = sonraki;

    } while(basDugum->sira != buyukluk - 1);
}


void BagliListe::Ekle(char gen)
{
    //ek yap
    //gezici->Sifirla(basDugum);
    Dugum *yeniDugum = new Dugum(gen,nullptr,buyukluk);
    gezici->Git(buyukluk-1)->sonrakiDugum = yeniDugum;
    yeniDugum->oncekiDugum = gezici->Git(buyukluk-1);
    yeniDugum->sira = buyukluk;
    sonDugum = yeniDugum;
    buyukluk++;


}

void BagliListe::Cikar()
{
    gezici->Sifirla(basDugum);

    buyukluk--;


}

void BagliListe::Yazdir()
{
    gezici->Sifirla(basDugum);

    for(int i=0; i< buyukluk; i++){

        cout << gezici->Git(i)->gen << ' ';



    }

    //cout<< basDugum->gen;


}

int BagliListe::BuyuklukDon()
{
    return buyukluk;
}

char BagliListe::GenDon(int sira)
{
    gezici->Sifirla(basDugum);
    return gezici->Git(sira)->gen;
}

void BagliListe::GenMutasyonu(int sira)
{
    gezici->Sifirla(basDugum);
    gezici->Git(sira)->gen = 'X';
}

void BagliListe::EkranaYaz()
{
    gezici->Sifirla(sonDugum);
    cout << gezici->TerseGit(basDugum->gen)->gen <<endl;

}


