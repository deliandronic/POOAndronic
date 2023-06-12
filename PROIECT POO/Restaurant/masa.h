#ifndef MASA_H_INCLUDED
#define MASA_H_INCLUDED

#include "Librarii.h"

class Mese
{
    public:
        Mese();
        Mese(string _id, string _locuri, string _ocupat);
        virtual ~Mese();

        void ID(string _id) { id = _id;}
        string ID(){return id;}

        void Locuri(string _locuri){locuri = _locuri;}
        string Locuri(){return locuri;}

        void Ocupat(string _ocupat){ocupat = _ocupat;}
        string Ocupat(){return ocupat;}

        string ToString(){return "ID: " + id + "\tLocuri: " + locuri + "\tStatus: " + ocupat;};
    protected:

    private:
        string id, locuri, ocupat;

};


#endif // MASA_H_INCLUDED
