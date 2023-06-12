#ifndef MENIU_H_INCLUDED
#define MENIU_H_INCLUDED

#include "Librarii.h"

class Meniu
{
    public:
        Meniu();
        Meniu(string _id, int _pret, string _denumire);
        virtual ~Meniu();

        void ID(string _id){id = _id;}
        string ID(){return id;}

        void Pret(int _pret){ pret = _pret; }
        int Pret(){return pret;}

        void Denumire(string den) { denumire = den; }
        string Denumire(){return denumire;}

        string ToStringInFile(){string _pret ; stringstream ss; ss<<pret; ss>>_pret;  return id + " " + _pret + " " + denumire + "\n";}
    private:
        string id, denumire;
        int pret;

};


#endif // MASA_H_INCLUDED
