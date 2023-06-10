/*
*
* Proyecto Simulación AOT clase Soldado
* Andrea Medina Rico 
* A01705541
* 09/06/2023
* versio: 3
* Esta clase define objeto de tipo Soldado
* Exploración, Guarnición y Militar
*/

#ifndef SOLDADO_H_
#define SOLDADO_H_

#include <iostream> 
#include <string>
#include <sstream>

using namespace std;

class Soldado {
    protected:
        string nombre;
        int edad;
        int nivel;
        int vida = 100;

    public:
        Soldado(): nombre(""), edad(0), nivel(0) {};
        Soldado(string nom, int ed, int niv): nombre(nom), edad(ed), nivel(niv) {};

        string getNombre() {
            return nombre;
        }
        int getEdad() {
            return edad;
        }
        int getNivel() {
            return nivel;
        }
        int getVida() {
            return vida;
        }

        void setEdad(int ed) {
            edad = ed;
        }
        void setNivel(int niv) {
            nivel = niv;
        }
        void setVida(int vid) {
            vida = vid;
        }
        void bajarVida(int dano) {
            vida = vida - dano;
        }

        // Se declara como clase abstracta
        virtual int atacar() = 0;
};


// Clase Exploracion que hereda de Soldado 
class Exploracion: public Soldado {
    private:
        int hab_corte;

    public:
        Exploracion(): hab_corte(0), Soldado() {};
        Exploracion(string nom, int ed, int niv, int cor): hab_corte(cor), Soldado(nom, ed, niv) {};

        int getCorte() {
            return hab_corte;
        }
        void setCorte(int cort) {
            hab_corte = cort;
        };

        int atacar();
        int cortar();
};

/**
* atacar() calcula el daño de un ataque
*
* @param
* @return int con valor del ataque
*/

int Exploracion::atacar() {
    int experiencia = 0;
    int ataque = 0;

    if (edad <= 18) {
        experiencia = 30;
    } else if (edad > 18 && edad <= 30) {
        experiencia = 50;
    } else if (edad > 30 && edad <= 50) {
        experiencia = 60;
    } else {
        experiencia = 10;
    }

    experiencia = experiencia * 15;
    ataque = experiencia + nivel;
    
    cout << "El ataque de " << nombre << " es de: " << ataque << "." << endl;
    return ataque;
}

/**
* cortar() regresa el daño de un corte
*
* @param
* @return int con valor dek corte
*/
int Exploracion::cortar() {
    cout << "El corte de " << nombre << " es de: " << hab_corte << "." << endl;
    return hab_corte;
}


// Objeto Guarnicion que hereda de Soldado
class Guarnicion: public Soldado {
    private:
        int hab_deteccion;
    public:
        Guarnicion(): hab_deteccion(0), Soldado() {};
        Guarnicion(string nom, int ed, int niv, int det): hab_deteccion(det), Soldado(nom, ed, niv) {};

        int getDeteccion() {
            return hab_deteccion;
        }
        void setDeteccion(int det) {
            hab_deteccion = det;
        }

        int atacar();
        int atacar_lejano();
};

/**
* atacar() calcula el daño de un ataque
*
* @param
* @return int con valor del ataque
*/
int Guarnicion::atacar() {
    int experiencia = 0;
    int ataque = 0;

    if (edad <= 18) {
        experiencia = 20;
    } else if (edad > 18 && edad <= 30) {
        experiencia = 35;
    } else if (edad > 30 && edad <= 50) {
        experiencia = 45;
    } else {
        experiencia = 5;
    }

    experiencia = experiencia * 5;
    ataque = experiencia + nivel;
    
    cout << "El ataque de " << nombre << " es de: " << ataque << "." << endl;
    return ataque;
}

/**
* atacar_lejano() calcula el daño de un ataque con cañón
*
* @param 
* @return int con valor del ataque
*/
int Guarnicion::atacar_lejano() {
    int ataque = 0;

    ataque = hab_deteccion + nivel;
    cout << "El ataque de " << nombre << " con cañón es de: " << ataque << ".";
    return ataque;
}


// Objeto Militar que hereda de Soldado
class Militar: public Soldado {
    private:
        int hab_salvacion;
    public:
        Militar(int sal): hab_salvacion(sal), Soldado() {};
        Militar(string nom, int ed, int niv, int sal):hab_salvacion(sal), Soldado(nom, ed, niv) {};

        int atacar();

        int salvar() {
            return hab_salvacion;
        };
};

/**
* atacar() calcula el daño de un ataque
*
* @param
* @return int con valor del ataque
*/
int Militar::atacar() {
    int experiencia = 0;
    int ataque = 0;

    if (edad <= 18) {
        experiencia = 25;
    } else if (edad > 18 && edad <= 30) {
        experiencia = 40;
    } else if (edad > 30 && edad <= 50) {
        experiencia = 55;
    } else {
        experiencia = 10;
    }

    experiencia = experiencia * 10;
    ataque = experiencia + nivel;
    
    cout << "El ataque de " << nombre << " es de: " << ataque << "." << endl;
    return ataque;
}

#endif