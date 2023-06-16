/*
*
* Proyecto Simulacion AOT clase Soldado
* Andrea Medina Rico 
* A01705541
* 16/06/2023
* versio: 4
* Esta clase define objeto de tipo Soldado
* Exploracion, Guarnicion y Militar heredan de Soldado
*/

#ifndef SOLDADO_H_
#define SOLDADO_H_

#include <iostream> 
#include <string>
#include <sstream>

using namespace std;

// Clase PADRE ABSTRACTA Soldado
class Soldado {
    // Atributos protegidos para que clases hijas puedan acceder a ellas
    protected:
        string nombre;
        string tipo;
        int edad;
        int nivel;
        int vida = 100;

    public:
        Soldado(): nombre(""), edad(0), nivel(0) {};
        Soldado(string nom, int ed, int niv): nombre(nom), edad(ed), nivel(niv) {};

        void setNombre() {
            cout << "Nombre: "; cin >> nombre;
        }
        void setEdad() {
            cout << "Edad: "; cin >> edad;
        }
        void setNivel() {
            cout << "Nivel: "; cin >> nivel;
        }

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
        string getTipo() {
            return tipo;
        }


        void setVida(int vid) {
            vida = vid;
        }
        void bajarVida(int dano) {
            vida = vida - dano;
        }

        virtual void imprimir() {
            cout << "No hay informacion";
        }
        virtual void crear(){
            setNombre();
            setEdad();
            setNivel();
        };

        // Se declara como clase abstracta
        virtual int atacar() = 0;
};


// Clase Exploracion que hereda de Soldado 
class Exploracion: public Soldado {
    private:
        string tipo = "Exploracion";
        int hab_corte;

    public:
        Exploracion(): hab_corte(0), Soldado() {};
        Exploracion(string nom, int ed, int niv, int cor): hab_corte(cor), Soldado(nom, ed, niv) {};

        void setCorte() {
            cout << "Habilidad de corte: "; cin >> hab_corte;
        }

        int getCorte() {
            return hab_corte;
        }

        int atacar();
        int cortar();
        void crear();
        void imprimir();
};

/**
* atacar() calcula el daño de un ataque
*
* calcula experiencia dependiendo de la edad y multiplica
* por cierto valor para luego sumarse al nivel y regresar 
* valor del ataque
*
* cambia dependiendo de la clase hija por lo que cumple
* con sobrescritura 
*
* @param
* @return int valor del ataque
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
* regresa el valor de la habilidad de corte
* 
* @param
* @return int valor de corte
*/
int Exploracion::cortar() {
    cout << "El corte de " << nombre << " es de: " << hab_corte << "." << endl;
    return hab_corte;
}

/**
* crear() cambia los datos de un objeto
*
* funciona como conjunto de setters y rellena un objeto vacío
* 
* @param
* @return 
*/
void Exploracion::crear() {
    setNombre();
    setEdad();
    setNivel();
    setCorte();
}

/**
* imprimir() muestra los valores de los atributos
*
* los muestra con cout
* 
* @param
* @return 
*/
void Exploracion::imprimir() {
    cout << "\n Nombre: " << nombre << 
            "\n Edad: " << edad << 
            "\n Nivel: " << nivel << 
            "\n Vida: " << vida << 
            "\n Habilidad de corte: " << hab_corte << endl;
}


// Objeto Guarnicion que hereda de Soldado
class Guarnicion: public Soldado {
    private:
        string tipo = "Guarnicion";
        int hab_deteccion;
    public:
        Guarnicion(): hab_deteccion(0), Soldado() {};
        Guarnicion(string nom, int ed, int niv, int det): hab_deteccion(det), Soldado(nom, ed, niv) {};

        void setDeteccion() {
            cout << "Habilidad de deteccion: "; cin >> hab_deteccion;
        }

        int getDeteccion() {
            return hab_deteccion;
        }
    
        int atacar();
        int atacar_lejano();
        void crear();
        void imprimir();
};

/**
* atacar() calcula el daño de un ataque
*
* calcula experiencia dependiendo de la edad y multiplica
* por cierto valor para luego sumarse al nivel y regresar 
* valor del ataque
*
* cambia dependiendo de la clase hija por lo que cumple
* con sobrescritura 
*
* @param
* @return int valor del ataque
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
* atacar_lejano() calcula el daño de un ataque especial lejano
* 
* Suma la habilidad de detección con el nivel para calcular
* el ataque
* 
* @param 
* @return int valor del ataque
*/
int Guarnicion::atacar_lejano() {
    int ataque = 0;

    ataque = hab_deteccion + nivel;
    cout << "El ataque de " << nombre << " con cañon es de: " << ataque << ".";
    return ataque;
}

/**
* crear() cambia los datos de un objeto
*
* funciona como conjunto de setters y rellena un objeto vacío
* se sobre escribe con el método de las otras clases hijas
* 
* @param
* @return 
*/
void Guarnicion::crear() {
    setNombre();
    setEdad();
    setNivel();
    setDeteccion();
}

/**
* imprimir() muestra los valores de los atributos
*
* los muestra con cout, se sobre escribe con los otros 
* métodos de imprimir
* 
* @param
* @return 
*/
void Guarnicion::imprimir() {
    cout << "\n Nombre: " << nombre << 
            "\n Edad: " << edad << 
            "\n Nivel: " << nivel << 
            "\n Vida: " << vida << 
            "\n Habilidad de deteccion: " << hab_deteccion << endl;
}


// Objeto Militar que hereda de Soldado
class Militar: public Soldado {
    private:
        string tipo = "Militar";
        int hab_salvacion;
    public:
        Militar(): hab_salvacion(0), Soldado() {};
        Militar(string nom, int ed, int niv, int sal):hab_salvacion(sal), Soldado(nom, ed, niv) {};

        void setSalvacion() {
            cout << "Habilidad de salvacion: "; cin >> hab_salvacion;
        }
        int getSalvacion() {
            return hab_salvacion;
        }

        int atacar();
        void crear();
        void imprimir();
};

/**
* atacar() calcula el daño de un ataque
*
* calcula experiencia dependiendo de la edad (y del tipo de clase hija)
* y multiplica por cierto valor (en este caso 10) para luego sumarse 
* al nivel y regresar valor del ataque
*
* cambia dependiendo de la clase hija por lo que cumple
* con sobrescritura
*
* @param
* @return int valor del ataque
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

/**
* crear() cambia los datos de un objeto
*
* funciona como conjunto de setters y rellena un objeto vacío
* se sobre escribe con el método de las otras clases hijas
* 
* @param
* @return 
*/
void Militar::crear() {
    setNombre();
    setEdad();
    setNivel();
    setSalvacion();
}

/**
* imprimir() muestra los valores de los atributos
*
* los muestra con cout, se sobre escribe con los otros 
* métodos de imprimir
* 
* @param
* @return 
*/
void Militar::imprimir() {
    cout << "Nombre: " << nombre << "\n" <<
            "Edad: " << edad << "\n" <<
            "Nivel: " << nivel << "\n" <<
            "Vida: " << vida << "\n" <<
            "Habilidad de salvacion: " << hab_salvacion << endl;
}

#endif