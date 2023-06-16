/*
 * Proyecto simulacion AOT
 * Andrea Medina Rico
 * A01705541
 * 16/06/2023
 * versio: 2
 * Este es un proyecto demo para la clase TC1030 Programacion Orientado a
 * Objetos. Es un programa que permite al usuario crear distintos soldados con
 * sus respectivas características dependiendo del tipo, y titanes. Además, le
 * permite visualizazr los datos que ha guardado hasta el momento y generar una 
 * interacción soldado-titán para visualizar cuál sería el resultado de una 
 * batalla entre ellos. 
 */

#include "Inventario.h"

using namespace std;

int main() {
    Inventario inv;

    // Arreglos para almacenar objetos
    Soldado *exploracion[10];
    Soldado *guarnicion[10];
    Soldado *militar[10];
    Titan *titanes[10];

    int contExp = 0;
    int contGuar = 0;
    int contMil = 0;
    int contTit = 0;

    int opcion = 0;
    int tipo = 0;
    string nombre = "";
    int indice = 0;
    int titan = 0;

    // While para que regrese al MENU
    while (opcion == 0) {
        cout << "¡Bienvenido a la simulacion de Attack On titan" << endl; 
        cout << "Puedes calcular la probabilidad de que tu soldado sobreviva a un ataque de un titan. \n \n";

        cout << "Opciones: (Introduce el valor de la opcion que deseas)" << endl;
        cout << "1. Crear nuevo soldado \n" << 
                "2. Crear nuevo titan \n" <<
                "3. Ver lista de soldados \n" << 
                "4. Ver lista de titanes \n" << 
                "5. Generar interaccion soldado-titan \n" << endl;

        std::cin >> opcion;

        // OPCIoN 1
        if (opcion == 1) {
            int opcion_1 = 0;

            cout << "¿Que tipo de soldado deseas crear? \n" << 
            "1. Soldado de Exploracion \n" << 
            "2. Soldado de Guarnicion \n" << 
            "3. Soldado de Policia Militar \n" << endl;

            std::cin >> opcion_1;

            if (opcion_1 == 1) {
                exploracion[contExp] = new Exploracion();
                exploracion[contExp] -> crear();
                
                inv.agregar(exploracion[contExp], "Exploracion");
                
            } else if (opcion_1 == 2) {
                guarnicion[contGuar] = new Guarnicion();
                guarnicion[contGuar] -> crear();

                inv.agregar(guarnicion[contGuar], "Guarnicion");

            } else if (opcion_1 == 3) {
                militar[contMil] = new Militar();
                militar[contMil] -> crear();

                inv.agregar(militar[contMil], "Militar");

            } else {
                cout << "Opcion no valida";
            }

        // OPCIoN 2 
        } else if (opcion == 2) {
            int altura = 0;
            cout << "¿Que altura deseas que tenga tu titan? \n" << endl;
            std::cin >> altura;

            titanes[contTit] = new Titan(altura);
            inv.agregar(titanes[contTit]);

        // OPCIoN 3
        } else if (opcion == 3) {
            cout << "¿Que tipo de soldados deseas visualizar \n" <<
                    "1. Exploracion  2. Guarnicion  3. Militar \n" << endl;
            std::cin >> tipo;

            if (tipo == 1) {
                inv.imprimir("Exploracion");
            } else if (tipo == 2) {
                inv.imprimir("Guarnicion");
            } else if (tipo == 3) {
                inv.imprimir("Militar");
            }

        // OPCIoN 4
        } else if (opcion == 4) {
            inv.imprimir();

        // OPCIoN 5
        } else if (opcion == 5) {

            int opcion_5 = 0;

            cout << "¿Que tipo de soldado deseas? \n" <<
            "1. Exploracion  2. Guarnicion  3. Militar \n" << endl;
            std::cin >> tipo;
            cout << "¿Como se llama tu soldado? \n";
            std::cin >> nombre;

            if (tipo == 1) {
                indice = inv.buscarNombre("Exploracion", nombre);
                cout << indice << endl;
                exploracion[indice] -> imprimir();
            } else if (tipo == 2) {
                indice = inv.buscarNombre("Guarnicion", nombre);
                cout << indice << endl;
            } else if (tipo == 3) {
                indice = inv.buscarNombre("Militar", nombre);
                cout << indice << endl;
            }

            cout << "¿Que numero de titan deseas? \n" << "(La cuenta de titanes comienza en 0)" << endl;
            std::cin >> titan;

            while (tipo == 1 && opcion_5 == 0) {
                cout << "¿Que ataque deseas hacer? \n" << 
                        "1. Ataque normal" <<
                        "2. Ataque corte" << endl;
                std::cin >> opcion_5;

                if (opcion_5 == 1) {
                    titanes[titan] -> atacado( exploracion[indice] -> atacar() );
                } else if (opcion_5 == 2) {
                    titanes[titan] -> atacado( ( (Exploracion*)exploracion[indice] )-> cortar() );
                }
                titanes[titan] -> atacar( exploracion[indice] );

                cout << "\n Si deseas continuar con la interaccion, ingresa 0 \n ";
                std::cin >> opcion_5;
            }

            while (tipo == 2 && opcion_5 == 0) {
                cout << "¿Que ataque deseas hacer? \n" << 
                        "1. Ataque normal" <<
                        "2. Ataque lejano" << endl;
                std::cin >> opcion_5;

                if (opcion_5 == 1) {
                    titanes[titan] -> atacado( guarnicion[indice] -> atacar() );
                } else if (opcion_5 == 2) {
                    titanes[titan] -> atacado( ( (Guarnicion*)guarnicion[indice] )-> atacar_lejano() );
                }
                titanes[titan] -> atacar( guarnicion[indice] );

                cout << "\n Si deseas continuar con la interaccion, ingresa 0 \n ";
                std::cin >> opcion_5;
            }

            while (tipo == 3 && opcion_5 == 0) {
                cout << "¿Que ataque deseas hacer? \n" << 
                        "1. Ataque normal (incluye salvar civiles)" << endl;
                std::cin >> opcion_5;

                if (opcion_5 == 1) {
                    titanes[titan] -> atacado( militar[indice] -> atacar() );
                } 
                titanes[titan] -> atacar( militar[indice], ( (Militar*)militar[indice] )-> getSalvacion() );

                cout << "\n Si deseas continuar con la interaccion, ingresa 0 \n ";
                std::cin >> opcion_5;
            }

        } else {
            cout << "Opcion no valida";
        }

        cout << "\n Si deseas regresar al menu, ingresa 0 \n";
        std::cin >> opcion;
    }
}