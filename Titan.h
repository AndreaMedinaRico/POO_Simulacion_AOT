/*
*
* Proyecto Simulación AOT clase Titán
* Andrea Medina Rico 
* A01705541
* 09/06/2023
* versio: 2
* Esta clase define objeto de tipo Titán
* 
*/

#ifndef TITAN_H
#define TITAN_H

#include "Soldado.h"

#include <iostream> 
#include <string>
#include <sstream>

using namespace std;

class Titan {
    private:
        float altura;
        int civiles = 0;
        int cont = 0;
        Soldado *soldados[5];

    public:
        Titan(): altura(0) {};
        Titan(float alt): altura(alt) {};

        int getAltura() {
            return altura;
        };
        void setAltura(int alt) {
            altura = alt;
        };
        
        int atacar(Soldado *sold);
        int atacar(Soldado *sold, int sal);
        void atacado(int ataque);
};

/**
 * atacar() calcula el daño del ataque de un titán 
 *
 * @param Soldado apuntador
 * @return int de la vida del soldado 
 */
int Titan::atacar(Soldado *sold) {
    sold -> bajarVida(altura * 10);
    civiles++;

    if (sold -> getVida() <= 0) {
        sold -> setVida(0);
        soldados[cont] = sold;
        cout << "El soldado " << sold -> getNombre() << " ha sido derrotado." << endl;

        cont++;

    } else {
        cout << "El soldado " << sold -> getNombre() << " ha sido atacado." << endl;
        cout << "Su vida es de " << sold -> getVida() << "." << endl;
    }

    if (cont == 4) {
        cout << "El titán ha derrotado a 5 soldados." << endl;
        cout << "El titán atacó a " << civiles << " civiles." << endl;
    }

    return sold -> getVida();
}

/**
 * atacar() calcula el daño del ataque de un titán 
 *
 * @param Soldado apuntador
 * @param int capacidad de salvar
 * @return int de la vida del soldado 
 */
int Titan::atacar(Soldado *sold, int sal) {
    if (sal > altura * 50) {
        cout << "El soldado " << sold -> getNombre() << " se ha salvado junto con un civil." << endl;

    } else {
        cout << "El soldado " << sold -> getNombre() << " no pudo salvar a nadie." << endl;
        sold -> bajarVida(altura * 10);
        civiles++;

        if (sold -> getVida() <= 0) {
            sold -> setVida(0);
            soldados[cont] = sold;
            cout << "El soldado " << sold -> getNombre() << " ha sido derrotado." << endl;

            cont++;

        } else {
            cout << "El soldado " << sold -> getNombre() << " ha sido atacado." << endl;
            cout << "Su vida es de " << sold -> getVida() << "." << endl;
        }

        if (cont == 4) {
            cout << "El titán ha derrotado a 5 soldados." << endl;
            cout << "El titán atacó a " << civiles << " civiles." << endl;
        }
    }
    return sold -> getVida();
}

/**
 * atacado() calcula si un ataque derrota o no a un titán
 *
 * @param int ataque
 * @return
 */
void Titan::atacado(int ataque) {
    if (ataque >= altura*100) {
        cout << "El titán fue derrotado." << endl;
    } else {
        cout << "El titán resistió el ataque." << endl;
    }
}

#endif