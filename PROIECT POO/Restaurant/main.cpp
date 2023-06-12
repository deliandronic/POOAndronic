#include "Librarii.h"
#include "restaurant.h"
#include "masa.h"
#include "meniu.h"

using namespace std;

void Administrator();

string masa_rezervata = "x";
int total_plata = 0;

int main()
{
    while(1)
    {
        Restaurant admin;
        Mese mese;

        list<Meniu> list_meniu;

        list<Mese> list_mese;

        char opt;

        list_meniu = admin.Info_Meniu();

        list_mese = admin.Info_Mese();

        char client_opt;
        system("cls");
        if( masa_rezervata == "x")
            cout<<"\tCLIENT\n";
        else
            cout<<"\tCLIENT \t\t\t\t\t Rezervare la masa [ " << masa_rezervata <<" ] \tTotal plata [ " << total_plata << " ]\n";

        cout<<"\nR. Rezervare masa";
        cout<<"\nC. Comanda";
        cout<<"\n\nX. Parasire restaurant\n\n";
        cout<<"Introduceti optiunea: ";
        cin>>client_opt;
        switch(toupper(client_opt))
        {
        case'R':
        {
            if( masa_rezervata == "x" )
            {
                list_mese = admin.Info_Mese();
                if(list_mese.size() != 0 )
                    admin.Afisare_Mese(list_mese);
                bool ok = true;
                string id;
                do
                {
                    ok = true;
                    cout << "\nIntroduceti numarul mesei libere la care doriti sa stati: ";
                    cin >> id;
                    for(int i = 0; i < id.length(); i++)
                    {
                        if( !isdigit(id[i]) )
                            ok = false;
                    }

                    if( ok == true )
                    {
                        ok = false;
                        for (list<Mese>::iterator it = list_mese.begin(); it != list_mese.end(); it++)
                        {
                            if( id == it->ID())
                            {
                                if( it->Ocupat() == "liber" )
                                {
                                    admin.Modificare_Status_Mese(list_mese, id, 1);
                                    ok = true;
                                    cout << "Masa a fost rezervata!\n";
                                    masa_rezervata = id;
                                    break;
                                }
                            }
                        }
                        if(ok == false)
                            cout << "Numarul introdus nu corespunde cu o masa libera! Incercati din nou!\n";
                    }

                }
                while(ok == false);
            }
            else
                cout<<"\nEste permisa doar o masa spre rezervare per client!\n\n";
            system("pause");
            break;
        }

        case 'C':
            if( masa_rezervata != "x")
            {
                admin.Afisare_Meniu(list_meniu);
                bool ok = true;
                string id;
                do
                {
                    ok = true;
                    cout << "\nIntroduceti numarul produsului dorit: ";
                    cin >> id;
                    for(int i = 0; i < id.length(); i++)
                    {
                        if( !isdigit(id[i]) )
                            ok = false;
                    }

                    if( ok == true )
                    {
                        ok = false;
                        for (list<Meniu>::iterator it = list_meniu.begin(); it != list_meniu.end(); it++)
                        {
                            if( id == it->ID())
                            {
                                total_plata += it->Pret();
                                ok = true;
                                cout << "Produs comandat!\n";
                                break;
                            }
                        }
                        if(ok == false)
                            cout << "Numarul introdus nu corespunde cu produsele din meniu! Incercati din nou!\n";
                    }

                }
                while(ok == false);
            }
            else
                cout<<"\nNu aveti momentan nici o masa rezervata!\n";
            system("pause");
            break;

        case 'X':

            for (list<Mese>::iterator it = list_mese.begin(); it != list_mese.end(); it++) // eliberare masa la parasirea din restaurant
            {
                if( masa_rezervata == it->ID())
                {
                    admin.Modificare_Status_Mese(list_mese, masa_rezervata, 2);
                }
            }

            masa_rezervata = "x";
            total_plata = 0;
            exit(0);
            break;
        default:
            cout<<"Optiunea introdusa nu exista!\n";
            system("pause");
            break;
        }

    }
}

