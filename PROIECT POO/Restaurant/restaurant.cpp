#include "restaurant.h"
#include <bits/stdc++.h>

Restaurant::Restaurant()
{
    // ctor
}

Restaurant::~Restaurant()
{
    //dtor
}

/*void Restaurant::Adauga_In_Meniu(Meniu meniu) // adaugare in fisier text meniu.txt
{
    ofstream file;
    file.open(FISIER_MENIU, std::ios_base::app);
    if(file.fail())
    {
        cout << "Eroare la deschiderea fisierului!";
        return;
    }
    else
        file << meniu.ToStringInFile();
    file.close();
}*/

list<Meniu> Restaurant::Info_Meniu() // citeste din fisierul meniu.txt campurile
{
    list<Meniu> list_meniu;
    Meniu meniu;
    string linie_fisier, id, denumire;
    int pret;
    ifstream file;
    file.open(FISIER_MENIU);
    if( file.fail() )
        cout << "Eroare la deschiderea fisierului!";
    else
    {
        while(getline(file, linie_fisier))
        {
            std::istringstream in_linie(linie_fisier);
            in_linie >> id >> pret >> denumire;

            meniu.ID(id);
            meniu.Pret(pret);
            meniu.Denumire(denumire);

            list_meniu.push_back(meniu);
        }
    }
    return list_meniu;
}

/*void Restaurant::Sterge_Din_Meniu(list<Meniu> list_meniu, string _id) // sterge din list_meniu, linia ce contine pret si denumire la fel ca parametrii primiti
{
    ofstream file;
    file.open(FISIER_MENIU);
    for(list<Meniu>::iterator it = list_meniu.begin(); it!= list_meniu.end(); it++)
        if( it-> ID() != _id )
            file << it->ToStringInFile()<<endl;
}*/

void Restaurant::Afisare_Meniu(list<Meniu> list_meniu) // afiseaza la consola datele primite prin parametru
{
    for (list<Meniu>::iterator it = list_meniu.begin(); it != list_meniu.end(); it++)
    {
        string id = it->ID();
        string _pret ; stringstream ss; ss<<it->Pret(); ss>>_pret;
        string den = it->Denumire();


        if(den.size() > 2 )
        {
            for(int i = 0; i < den.length(); i++)
                if(den[i] == '_')
                    den[i] = ' ';
        }
        if( it->Pret() < 10 )
            cout << "Nr. crt. " << id << "\tPret: " << _pret << "\t\tProdus: " << den << endl;
        else
            cout << "Nr. crt. " << id << "\tPret: " << _pret << "\tProdus: " << den << endl;
    }
}


list<Mese> Restaurant::Info_Mese()
{
    list<Mese> list_mese;
    Mese mese;
    string linie_fisier, id, locuri, ocupat;
    ifstream file;
    file.open(FISIER_MESE);
    if( file.fail() )
        cout << "Eroare la deschiderea fisierului!";
    else
    {
        while(getline(file, linie_fisier))
        {
            std::istringstream cin_linie(linie_fisier);
            cin_linie >> id >> locuri >> ocupat;
            mese.ID(id);
            mese.Locuri(locuri);
            mese.Ocupat(ocupat);
            list_mese.push_back(mese);
        }
    }
    return list_mese;
}

void Restaurant::Afisare_Mese(list<Mese> list_mese)
{
    for (list<Mese>::iterator it = list_mese.begin(); it != list_mese.end(); it++)
    {
        cout << it->ToString() << "\n";
    }
}

void Restaurant::Modificare_Status_Mese(list<Mese> list_mese, string _id, int tip_de_ocupare) /// tip de ocupare = 1 --> din liber in rezervat ... tip de ocupare = 2 --> din rezervat in liber
{
    ofstream file;
    file.open(FISIER_MESE);
    for (list<Mese>::iterator it = list_mese.begin(); it != list_mese.end(); it++)
    {
        if( it->ID() == _id )
        {
            if( tip_de_ocupare == 1)
                file << it->ID() << " " << it->Locuri() << " rezervat\n";
            else if( tip_de_ocupare == 2)
                file << it->ID() << " " << it->Locuri() << " liber\n";
        }
        else
            file << it->ID() << " " << it->Locuri() << " " << it->Ocupat() << "\n";
    }
}
