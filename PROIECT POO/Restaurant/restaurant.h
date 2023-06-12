#ifndef RESTAURANT_H_INCLUDED
#define RESTAURANT_H_INCLUDED

#include "masa.h"
#include "meniu.h"
#include "Librarii.h"

class Restaurant
{
public:
    Restaurant();
    virtual ~Restaurant();
    ///void Adauga_In_Meniu(Meniu menu);
    list<Meniu> Info_Meniu();
    ///void Sterge_Din_Meniu(list<Meniu> list_meniu, string _id);
    void Afisare_Meniu(list<Meniu> list_meniu);

    list<Mese> Info_Mese();
    void Afisare_Mese(list<Mese> list_mese);
    void Modificare_Status_Mese(list<Mese> list_mese, string _id, int tip_de_ocupare);

protected:

private:
};

#endif // RESTAURANT_H_INCLUDED
