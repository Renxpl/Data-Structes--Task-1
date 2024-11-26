#include "BagliBagliListe.hpp"




BagliBagliListe::BagliBagliListe(BagliListe *ilkListe)
{
    this->basBagliListe = ilkListe;
    buyukluk = 1;
    gezici = new ListeGezici(basBagliListe);

}

BagliBagliListe::~BagliBagliListe()
{
    while(basBagliListe != nullptr){
        BagliListe* sonraki = basBagliListe->sonrakiBagliListe;
        delete basBagliListe;
        basBagliListe= sonraki;

    } 


    delete gezici;

}

void BagliBagliListe::Ekle(BagliListe* eklenecekListe)
{
    //ek yap
    //gezici->Sifirla(basBagliListe);
    gezici->Git(buyukluk-1)->sonrakiBagliListe = eklenecekListe;
    eklenecekListe->sira = buyukluk;
    buyukluk++;





}

void BagliBagliListe::Cikar()
{
    gezici->Sifirla(basBagliListe);

}

void BagliBagliListe::Yazdir()
{
    gezici->Sifirla(basBagliListe);

    for(int i=0; i< buyukluk; i++){

        gezici->Git(i)->Yazdir();
        cout << endl;



    }

    
}

void BagliBagliListe::Carprazlama(int ilkDna,int ikinciDna)
{
    gezici->Sifirla(basBagliListe);
    gezici->Git(ilkDna);
    int solListeBuyukluk = gezici->ListeGetir()->BuyuklukDon();
    if(solListeBuyukluk % 2 == 0){
        solListeBuyukluk= solListeBuyukluk / 2 - 1;
    }
    else{
        solListeBuyukluk = (solListeBuyukluk - 1) / 2 - 1;
    }

    BagliListe* eklenecekBagliListe = new BagliListe (gezici->ListeGetir()->GenDon(0), nullptr,0);
    for(int i = 1; i<= solListeBuyukluk;i++){
        eklenecekBagliListe->Ekle(gezici->ListeGetir()->GenDon(i));


    }

    

    gezici->Sifirla(basBagliListe);
    gezici->Git(ikinciDna);
    int sagListeBuyukluk = gezici->ListeGetir()->BuyuklukDon();
    if(sagListeBuyukluk % 2 == 0){
        sagListeBuyukluk= (sagListeBuyukluk / 2);
    }
    else{
        sagListeBuyukluk = (sagListeBuyukluk + 1) / 2;
    }

    for(int i = sagListeBuyukluk; i<= (gezici->ListeGetir()->BuyuklukDon() - 1);i++){
        eklenecekBagliListe->Ekle(gezici->ListeGetir()->GenDon(i));


    }
    
    Ekle(eklenecekBagliListe);


}

void BagliBagliListe::Mutasyon(int sira, int genSira)
{
    gezici->Sifirla(basBagliListe);
    gezici->Git(sira);
    gezici->ListeGetir()->GenMutasyonu(genSira);
}

void BagliBagliListe::EkranaYazdir()
{
    gezici->Sifirla(basBagliListe);

    for(int i = 0;i <buyukluk;i++){

       gezici->Git(i)->EkranaYaz();
       

    }



}


