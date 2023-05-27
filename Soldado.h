/*
*
* Proyecto Simulación AOT clase Soldado
* Andrea Medina Rico 
* A01705541
* 26/05/2023
* versio: 1
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

        string get_nombre() {
            return nombre;
        }
        int get_edad() {
            return edad;
        }
        int get_nivel() {
            return nivel;
        }
        int get_vida() {
            return vida;
        }

        string defender();
};


// Objeto Exploracion que hereda de Soldado 
class Exploracion: public Soldado {
    private:
        int hab_corte;
    public:
        Exploracion(int ko):hab_corte(ko), Soldado() {};

        int get_corte() {
            return hab_corte;
        }

        string atacar();
        string cortar();
};

/**
* atacar() calcula el daño de un ataque
*
*
*
* @param
* @return string con información del nombre y ataque
*/
string Exploracion::atacar() {
    int experiencia = 0;
    int ataque = 0;
    stringstream info;

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
    
    info << "El ataque de " << nombre << " es de: " << ataque << ".";
    return info.str();
}

/**
* cortar() calcula el daño de un corte 
*
*
*
* @param
* @return string con información del nombre y corte
*/
string Exploracion::cortar() {
    stringstream info;
    info << "El corte de " << nombre << " es de: " << hab_corte << ".";
    return info.str();
}


// Objeto Guarnicion que hereda de Soldado
class Guarnicion: public Soldado {
    private:
        int hab_deteccion;
    public:

        Guarnicion(int det): hab_deteccion(det), Soldado() {};

        int get_deteccion() {
            return hab_deteccion;
        }

        string atacar();
        string atacar_lejano(int canon);
};

/**
* atacar() calcula el daño de un ataque
*
*
*
* @param
* @return string con información del nombre y ataque
*/
string Guarnicion::atacar() {
    int experiencia = 0;
    int ataque = 0;
    stringstream info;

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
    
    info << "El ataque de " << nombre << " es de: " << ataque << ".";
    return info.str();
}

/**
* atacar_lejano() calcula el daño de un ataque con cañón
*
*
*
* @param int con el daño del cañón
* @return string con información del nombre y ataque con cañón
*/
string Guarnicion::atacar_lejano(int canon) {
    stringstream info;
    int ataque = 0;

    ataque = canon + nivel;
    info << "El ataque de " << nombre << " con cañón es de: " << ataque << ".";
    return info.str();
}


// Objeto Militar que hereda de Soldado
class Militar: public Soldado {
    private:
        int hab_salvacion;
    public:
        Militar(int sal): hab_salvacion(sal), Soldado() {};

        int get_salvacion() {
            return hab_salvacion;
        }

        string atacar();
        string salvar();
};

/**
* atacar() calcula el daño de un ataque
*
*
*
* @param
* @return string con información del nombre y ataque
*/
string Militar::atacar() {
    int experiencia = 0;
    int ataque = 0;
    stringstream info;

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
    
    info << "El ataque de " << nombre << " es de: " << ataque << ".";
    return info.str();
}

/**
* salvar() muestra la habilidad del soldado para salvar civiles
*
*
*
* @param
* @return string con información del nombre y 
*/
string Militar::salvar() {
    stringstream info;
    int personas = hab_salvacion / 100;

    info << nombre << " puede salvar a " << personas << " personas. Ha salvado a una.";
    return info.str();
}  

#endif