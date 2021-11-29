/*  Integral A

    Author: Daniel Rodriguez Figueroa
    Matricula: A01612889
*/

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include "phonebook.h"

using namespace std;

int opcion;
int contact;
int new_contact;
int lada;
string strNum;
int length;

int main(){
    List<int> contactos;
    BST<int> ladas;

    while (1==1)
    {
    cout<<"----------- PHONEBOOK ------------"<<endl;
    cout<<"\n1 ..... Agregar Contactos"<<endl;
    cout<<"2 ..... Borrar Contacto"<<endl;
    cout<<"3 ..... Cambiar numero de contacto"<<endl; 
    cout<<"4 ..... Buscar lada"<<endl;
    cout<<"5 ..... Ordenar contactos"<<endl;
    cout<<"6 ..... Mostrar Contactos"<<endl;
    cout<<"7 ..... Mostrar Ladas"<<endl;
    cout<<"8 ..... Salir"<<endl;
    cout<<" "<<endl;
    cout<<"Opcion: ";
    cin>> opcion;

    switch (opcion)
    {
    case 1:

        cout<<"\nInserte el nuevo contacto (7 numeros, sin Lada): ";
        cin>> contact;
        strNum = to_string(contact); 
        length = strNum.length(); 
        if (length!=7)
        {
            cout<<"\nEl numero introducido no contiene 7 numeros, intentelo de nuevo."<<endl;
            break;
        }
        
        contactos.insertion(contact);
        cout<<"\nInserte la lada del contacto (3 numeros, ej: 442): ";
        cin>> lada;
        strNum = to_string(lada); 
        length = strNum.length(); 
        if (length!=3)
        {
            cout<<"\nEl numero introducido no contiene 3 numeros, intentelo de nuevo."<<endl;
            break;
        }

        ladas.add(lada);
        
        break;

    case 2:

        cout<<"\nLista de contactos disponibles:"<<endl;
        cout<<" "<<endl;
        cout<<contactos.toString()<<endl;
        cout<<"\nInserte el contacto a borrar: ";
        cin>> contact;
        contactos.deleteAt(contactos.search(contact));
        cout<<"\nEL contacto ha sido eliminado"<<endl;
        break;

    case 3:

        cout<<"\nLista de contactos disponibles:"<<endl;
        cout<<" "<<endl;
        cout<<contactos.toString()<<endl;
        cout<<"\nInserte el contacto a cambiar: ";
        cin>> contact;
            strNum = to_string(contact); 
            length = strNum.length(); 

            if (length!=7)
            {
                cout<<"\nEl numero introducido no contiene 7 numeros, intentelo de nuevo."<<endl;
                break;
            }

        if (contactos.search(contact)==-1)
        {
            cout<<"No existe dicho contacto"<<endl;
        }
        else{
            cout<<"\nInserte el nuevo contacto: ";
            cin>> new_contact;

                strNum = to_string(new_contact); 
                length = strNum.length(); 
                if (length!=7)
                {
                    cout<<"\nEl numero introducido no contiene 7 numeros, intentelo de nuevo."<<endl;
                    break;
                }

            contactos.update(contactos.search(contact), new_contact);
        }
        break;

    case 4:

        cout<<"\nInserte la lada que desea buscar (ej: 442): ";
        cin>> lada;
        ladas.find(lada);

        break;

    case 5:
        contactos.insertionSort(contactos.head);
        break;

    case 6:

        cout<<"\nLista de contactos:"<<endl;
        cout<<contactos.toString()<<endl;
        break;

    case 7:

        cout<<ladas.inorder()<<endl;

        break;

    case 8:
        cout<<"\nHasta la vista benji!"<<endl;
        cout<<" "<<endl;
        exit(EXIT_SUCCESS);
        break;

    default:
        cout<<"Opcion no valida en el menu, intente de nuevo"<<endl;
        break;
    }
    }



return 0;
}

