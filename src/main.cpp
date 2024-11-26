#include "BagliListe.hpp"
#include "BagliBagliListe.hpp"
#include <iostream>
#include <fstream>

using namespace std;


int main(){
    BagliBagliListe *bagliBagliListe;
    BagliListe *bagliListe;
    
    ifstream dnaDosya("./Dna.txt");
    
    if (!dnaDosya) {
        cout<<"Dna.txt dosyasi acilamadi";
        return 1;
    }

    char harf;

    int sayi = 0;

    int hangiDna = 0;

    int hangiIslem = 0;

    while(dnaDosya.get(harf)){

        if(harf == '\n'){
            hangiDna++;
           // cout<<" satir degisti "<<endl;
            sayi = 0;
        }
        else if(harf == ' '){

        }

        else{
            if(sayi == 0){
            if(hangiDna == 0){
                bagliListe = new BagliListe(harf, nullptr,0);
                bagliBagliListe = new BagliBagliListe(bagliListe);
            }
            else{
                bagliListe = new BagliListe(harf, nullptr,hangiDna);
                bagliBagliListe->Ekle(bagliListe);
            }   


            //bagliListe->Yazdir();
            }
            else{
            bagliListe->Ekle(harf);
            }


            //cout<<harf;
            sayi++;
        }


    }
    //cout<< "Guncel Gorunum" << endl;
    //bagliBagliListe->Yazdir();
    //bagliBagliListe->EkranaYazdir();
    /*
    bagliBagliListe->Mutasyon(1,2);
    bagliBagliListe->Carprazlama(2, 3);
    bagliBagliListe->Carprazlama(4, 5);
    bagliBagliListe->Yazdir();
    */
    
    int menuSecim = 0;
    int ilkSayi= 0;
    int ikinciSayi = 0;
    ifstream islemlerDosya("./Islemler.txt");
    if (!islemlerDosya) {
        cout<<"Islemler.txt dosyasi acilamadi";
        return 1;
    }
    while(menuSecim != 5){
        cout << "1-Carprazlama\n2-Mutasyon\n3-Otomatik Islemler\n4-Ekrana Yazdir\n5-Cikis" << endl;
        cin >> menuSecim;
        switch(menuSecim){

            case 1:
                cout << "ilk listenin sira numarasini giriniz: ";
                cin >> ilkSayi; 
                cout << "ikinci listenin sira numarasini giriniz: ";
                cin >> ikinciSayi;
                bagliBagliListe->Carprazlama(ilkSayi,ikinciSayi);
                cout << "Yeni Gorunum"<< endl;
                bagliBagliListe->Yazdir();
                //carprazlama
            


                break;
            case 2:
                cout << "listenin sira numarasini giriniz: ";
                cin >> ilkSayi; 
                cout << "mutasyon icin eleman sira numarasi giriniz: ";
                cin >> ikinciSayi;
                bagliBagliListe->Mutasyon(ilkSayi,ikinciSayi);
                cout << "Yeni Gorunum"<< endl;
                bagliBagliListe->Yazdir();
                //mutasyon
                break;

            case 3:
                //otomatik islemler
                sayi = 0;

                hangiDna = 0;
    
                while(islemlerDosya.get(harf)){

                    if(harf == '\n'){
                    hangiDna++;
                    hangiIslem = 0;
                    // cout<<" satir degisti "<<endl;
                    sayi = 0;
                    }
                    else if(harf == ' '){

                    }

                    else{
                        if(sayi == 0){
                            if(harf == 'C'){
                                hangiIslem = 1;
                                //carprazlama
                            }
                            else if(harf == 'M'){
                                hangiIslem = 2;
                                //mutasyon
                            }   
                            else{

                                //hata var(tanınmayan harf komutu)

                            }
                            
                   
                        }
                        else if(sayi == 1){

                            //sayi kisimlari
                            ilkSayi = harf - '0';

                            //baglibagli liste boyutunda mı? hayırsa hata

                        }
                        else if(sayi == 2){
                            ikinciSayi = harf - '0';
                            //sayi kisimlari
                            //bagli liste boyutunda mı? hayırsa hata
                            if(hangiIslem == 1){
                                bagliBagliListe->Carprazlama(ilkSayi,ikinciSayi);

                            }

                            else if(hangiIslem == 2){
                                bagliBagliListe->Mutasyon(ilkSayi,ikinciSayi);
                            }

                        }
                        else{

                            //hata var(kurala uymayan input)
                        }

                        //cout<<harf;
                        sayi++;
                    }


                }
                bagliBagliListe->Yazdir();
                break;
        

             case 4:
            //ekrana yazdir
                bagliBagliListe->EkranaYazdir();
                break;
            case 5:
            //cikis
                cout<< "Program Sonlandiriliyor."<< endl;
                break;
            default:
            //hata ele alma
                cout <<"gecersiz input girisi. Tekrar giriniz" << endl;
                break;


        }


        

    }

    delete bagliBagliListe;


    islemlerDosya.close();
    dnaDosya.close();


}