/*
*
* Proyecto Simulacion AOT clase Titan
* Andrea Medina Rico 
* A01705541
* 16/06/2023
* versio: 3
* Esta clase define objeto de tipo Titan
* 
*/

#ifndef TITAN_H
#define TITAN_H

#include "Soldado.h"

using namespace std;

class Titan {
    private:
        int altura;
        int vida = altura * 100;
        int civiles = 0;
        int cont = 0;
        Soldado *soldados[5];

    public:
        Titan(): altura(0) {};
        Titan(int alt): altura(alt) {};

        int getAltura() {
            return altura;
        };
        void setAltura(int alt) {
            altura = alt;
        };
        
        int atacar(Soldado *sold);
        int atacar(Soldado *sold, int sal);
        void atacado(int ataque);
        void imprimirTitan();
};

/**
 * atacar() calcula el daño del ataque
 *
 * realiza la acción solo si el titán sigue con vida, pues
 * el soldado ataca primero. Actúa dependiendo de si el soldado
 * sigue con vida o no, y su cantidad de soldados derrotados
 * 
 * @param Soldado apuntador objeto soldado
 * @return int vida del soldado 
 */
int Titan::atacar(Soldado *sold) {
    if (vida > 0) {
        sold -> bajarVida(altura * 15);
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
            cout << "El titan ha derrotado a 5 soldados. Se considera de un nivel " <<
            "superior, puede que sea anormal. " << endl;
            cout << "El titan ataco a " << civiles << " civiles." << endl;
        }
    }

    cout << "El titan ya fue derrotado, ya no puede atacar." << "\n \n";
    return sold -> getVida();
}

/**
 * atacar() calcula el daño del ataque de un titan 
 *
 * especificamente para los soldados tipo de guarnición, recibe
 * uno de sus atributos para detectar si el soldado se salva
 * Funciona con sobrescritura con el método anterior. El resto de 
 * condiciones las comparte con método anterior
 * 
 * @param Soldado apuntador
 * @param int capacidad de salvar
 * @return int vida del soldado 
 */
int Titan::atacar(Soldado *sold, int sal) {
    
    if (vida > 0) {
        if (sal > altura * 50) {
            cout << "El soldado " << sold -> getNombre() << " se ha salvado junto con un civil." << endl;
            civiles--;

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
                cout << "El titan ha derrotado a 5 soldados." << endl;
                cout << "El titan ataco a " << civiles << " civiles." << endl;
            }
        }
    } else {
        cout << "El titan no ataco porque ha sido derrotado. ";
    }
    
    return sold -> getVida();
}

/**
 * atacado() calcula si un ataque derrota o no a un titan
 *
 * Depende de si el ataque supera la vida del titán
 * @param int ataque
 * @return
 */
void Titan::atacado(int ataque) {
    if (ataque >= vida) {
        cout << "El titan fue derrotado." << endl;
        vida = 0;
    } else {
        cout << "El titan resistio el ataque." << endl;
    }
}

/**
 * imprimirTitan() muestra valores de un titán
 *
 * Imprime mediante cout
 * @param 
 * @return
 */
void Titan::imprimirTitan() {
    cout << "Altura: \n" << altura << "\n" <<
            "Vida: \n" << vida << "\n" <<
            "Civiles atacados: \n" << civiles << "\n" <<
            "Soldados derrotados: \n" << cont << "\n \n";
}

#endif