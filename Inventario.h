/*
*
* Proyecto Simulacion AOT clase INventario
* Andrea Medina Rico 
* A01705541
* 16/06/2023
* versio: 1
* Esta clase genera objetos tipo Inventario, dedicados a
* almacenar los objetos creados de soldados y titán, así 
* como agregarlos, imprimirlos y buscarlos
*/

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Titan.h"

using namespace std;

class Inventario {
    private:
        Soldado *soldExp[10];
        Soldado *soldGua[10];
        Soldado *soldMil[10];
        Titan *titanes[10];

        int contSold = 0;
        int contExp = 0;
        int contGua = 0;
        int contMil = 0;
        int contTit = 0;
    public:
        void agregar(Soldado *sold, string tip);
        void agregar(Titan *tit);
        void imprimir(string tip);
        void imprimir();
        int buscarNombre(string tip, string nom);
};

/**
 * agregar añade un soldado a un arreglo
 *
 * añade al soldado a un arreglo diferente (establecidos como atributos)
 * dependiendo del tipo que sea
 *
 * @param Soldado objeto apuntador soldado
 * @param string tipo de soldado
 * @return 
 */
void Inventario::agregar(Soldado *sold, string tip) {
     if (tip == "Exploracion") {
        soldExp[contExp] = sold;
        contExp++;
        contSold++;
     } else if (tip == "Guarnicion") {
        soldGua[contGua] = sold;
        contGua++;
        contSold++;
     } else if (tip == "Militar") {
        soldMil[contMil] = sold;
        contMil++;
        contSold++;
     }
}

/**
 * agregar añade un titán a un arreglo
 *
 * añade al titán al arreglo respectivo establecido como atributo
 * recibe un solo parametro tipo titán, por lo que funciona como
 * sobrecarga con el método anterior
 *
 * @param Titan objeto titan
 * @return 
 */
void Inventario::agregar(Titan *tit) {
    titanes[contTit] = tit;
    contTit++;
}

/**
 * imprimir imprime lista de soldados
 *
 * dependiendo del tipo indicado, imprime los soldados que 
 * están en el respectivo arreglo mediante un ciclo for
 *
 * @param string tipo de soldado
 * @return 
 */
void Inventario::imprimir(string tip) {
    if (tip == "Exploracion") {
        for (int i=0; i < contExp; i++) {
            cout << "Soldado: " << i + 1 << endl;
            soldExp[i] -> imprimir();
        }
    } else if (tip == "Guarnicion") {
        for (int i=0; i < contGua; i++) {
            cout << "Soldado: " << i + 1 << endl;
            soldGua[i] -> imprimir();
        }
    } else if (tip == "Militar") {
        for (int i=0; i < contMil; i++) {
            cout << "Soldado: " << i + 1 << endl;
            soldMil[i] -> imprimir();
        }
    } 
}

/**
 * imprimir imprime lista de titanes
 *
 * no recibe parametros, por lo que funciona como sobrecarga con 
 * el método anterior mediante un ciclo for
 *
 * @param
 * @return 
 */
void Inventario::imprimir() {
    for (int i=0; i < contTit; i++) {
        cout << "Titan: " << i + 1 << endl;
        titanes[i] -> imprimirTitan();
    }
}

/**
 * buscarNombre busca a los soldados por su nombre
 *
 * dependiendo del tipo de soldado, compara nombre indicado con nombre
 * de cada objeto en el arreglo y guarda el índice en el que se encuentra
 * 
 * @param string tipo de soldado 
 * @param string nombre del soldado 
 * @return int indice del objeto deseado en el arreglo 
 */
int Inventario::buscarNombre(string tip, string nom) {
    int num = 0;

    if (tip == "Exploracion") {
        cout << "Hola";

        for (int i=0; i < contExp; i++) {
            if ( (soldExp[i] -> getNombre()) == nom ) {
                cout << "Holaaaa";
                num = i;
                cout << num;
            }
        }
    } else if (tip ==  "Guarnicion") {
        for (int i=0; i < contGua; i++) {
            if ( (soldGua[i] -> getNombre()) == nom ) {
                num = i;
            }
        }
    } else if (tip == "Militar") {
        for (int i=0; i < contMil; i++) {
            if ( (soldMil[i] -> getNombre()) == nom ) {
                num = i;
            }
        }
    } 

    return num;
}

#endif