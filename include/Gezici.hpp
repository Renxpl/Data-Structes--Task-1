#ifndef GEZICI_HPP
#define GEZICI_HPP
#include "Dugum.hpp"


class Gezici{
    private:
        Dugum *suankiDugum;
        int kacinciDugum;





    public:

        Gezici(Dugum*, int);
        ~Gezici();
        
        void Sifirla(Dugum*);

        Dugum* Git(int);

        Dugum* TerseGit(char);


};











#endif