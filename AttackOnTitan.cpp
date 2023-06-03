/*
 * Proyecto simulación AOT
 * Andrea Medina Rico
 * A01705541
 * 02/06/2023
 *
 * Este es un proyecto demo para la clase TC1030 Programación Orientado a
 * Objetos. Es un programa que captura diferentes tipos de soldados con 
 * sus características y simula su interacción con titanes creeados.
 */

#include "Soldado.h"
#include "Titan.h"

#include <iostream>
using namespace std;

int main() {
    // SOLDADOS DE EXPLORACIÓN
    Soldado *exploracion[10];
    exploracion[0] = new Exploracion("Eren Jaeger", 19, 65, 55);
    exploracion[1] = new Exploracion("Mikasa Ackerman", 18, 75, 50);

    // SOLDADOS DE GUARNICIÓN
    Soldado *guarnicion[10];
    guarnicion[0] = new Guarnicion("Pixis", 50, 45, 55);
    guarnicion[1] = new Guarnicion("Hannes", 35, 30, 25);

    // SOLDADOS POLIICA MILITAR 
    Soldado *militar[10];
    militar[0] = new Militar("Annie Leonhart", 18, 70, 50);
    militar[1] = new Militar("Hitch", 17, 55, 40);

    // TITANES 
    Titan *titan1 = new Titan(3.5);
    Titan *titan2 = new Titan(3.0);
    Titan *titan3 = new Titan(4.2);

    // INTERACCIONES 
    titan1 -> atacar(guarnicion[0]);
    titan1 -> atacado(guarnicion[0] -> atacar());

    titan2 -> atacar(exploracion[0]);
    titan2 -> atacado( ( (Exploracion*)exploracion[1] ) -> cortar() );

    titan3 -> atacar(militar[1], ( (Militar*)militar[0] ) -> salvar());

}